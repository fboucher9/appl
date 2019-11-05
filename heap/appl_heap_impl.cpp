/* See LICENSE for license details */

/*

*/

#include <stdlib.h>

#include <appl_status.h>

#include <appl_types.h>

#include <list/appl_list.h>

#include <heap/appl_heap_primary.h>

#include <heap/appl_heap_impl.h>

#include <misc/appl_unused.h>

//
//
//
appl_heap_impl::appl_heap_impl() :
    m_primary(),
    m_free_large()
{
}

//
//
//
appl_heap_impl::~appl_heap_impl()
{
}

//
//
//
enum appl_status
    appl_heap_impl::f_init(
        unsigned char * const
            p_mmap_begin,
        unsigned char * const
            p_mmap_end)
{
    enum appl_status
        e_status;

    m_primary.f_init(
        p_mmap_begin,
        p_mmap_end);

    appl_size_t
        i_index;

    i_index =
        0u;

    while (
        i_index < sizeof(m_free_small) / sizeof(m_free_small[0u]))
    {
        appl_list_init(
            m_free_small + i_index);

        i_index ++;
    }

    appl_list_init(
        &(
            m_free_large));

    e_status =
        appl_status_ok;

    return
        e_status;

} // f_init()

//
//
//
enum appl_status
    appl_heap_impl::f_cleanup(void)
{
    enum appl_status
        e_status;

    m_primary.f_cleanup();

    e_status =
        appl_status_ok;

    return
        e_status;

} // f_cleanup()

//
//
//
enum appl_status
    appl_heap_impl::f_alloc(
        appl_size_t const
            i_len,
        void * * const
            r_buf)
{
    enum appl_status
        e_status;

    if (
        i_len)
    {
        if (
            i_len <= 4096u)
        {
            e_status =
                f_alloc_small(
                    i_len,
                    r_buf);
        }
        else
        {
            e_status =
                f_alloc_large(
                    i_len,
                    r_buf);
        }
    }
    else
    {
        e_status =
            appl_status_fail;
    }

    return
        e_status;

} // f_alloc()

//
//
//
enum appl_status
    appl_heap_impl::f_free(
        appl_size_t const
            i_len,
        void * const
            p_buf)
{
    enum appl_status
        e_status;

    /* Put this node back into free list */

    /* Use madvise to release extra pages */

    if (
        i_len <= 4096u)
    {
        e_status =
            f_free_small(
                i_len,
                p_buf);
    }
    else
    {
        e_status =
            f_free_large(
                i_len,
                p_buf);
    }

    return
        e_status;

} // f_free()

//
//
//
enum appl_status
    appl_heap_impl::f_alloc_small(
        appl_size_t const
            i_len,
        void * * const
            r_buf)
{
    enum appl_status
        e_status;

    e_status =
        appl_status_ok;

    if (
        appl_status_ok
        == e_status)
    {
        appl_size_t const
            i_index =
            ((i_len + 15u) / 16u) - 1u;

        if (
            i_index < (sizeof(m_free_small) / sizeof(m_free_small[0u])))
        {
            struct appl_list * const
                p_free_pool =
                m_free_small + i_index;

            if (
                p_free_pool->o_next.p_node
                != p_free_pool)
            {
                struct appl_list * const
                    p_free_node =
                    p_free_pool->o_next.p_node;

                appl_list_join(
                    p_free_node,
                    p_free_node);

                p_free_node->o_next.p_node =
                    0;

                p_free_node->o_prev.p_node =
                    0;

                *(
                    r_buf) =
                    p_free_node;

                e_status =
                    appl_status_ok;
            }
            else
            {
                e_status =
                    m_primary.f_alloc(
                        i_len,
                        r_buf);
            }
        }
        else
        {
            e_status =
                appl_status_fail;
        }
    }

    return
        e_status;

} // f_alloc_small()

//
//
//
enum appl_status
    appl_heap_impl::f_free_small(
        appl_size_t const
            i_len,
        void * const
            p_buf)
{
    enum appl_status
        e_status;

    e_status =
        appl_status_ok;

    if (
        appl_status_ok
        == e_status)
    {
        appl_size_t const
            i_index =
            ((i_len + 15u) / 16u) - 1u;

        if (
            i_index < (sizeof(m_free_small) / sizeof(m_free_small[0u])))
        {
            struct appl_list * const
                p_free_pool =
                m_free_small + i_index;

            union appl_heap_segment_ptr
                o_segment_ptr;

            o_segment_ptr.p_void =
                p_buf;

            appl_list_init(
                o_segment_ptr.p_list);

            appl_list_join(
                o_segment_ptr.p_list,
                p_free_pool);

            e_status =
                appl_status_ok;
        }
        else
        {
            e_status =
                appl_status_fail;
        }
    }

    return
        e_status;

} // f_free_small()

struct appl_heap_large_header
{
    struct appl_list
        o_list;

    /* -- */

    appl_size_t
        i_len;

}; /* struct appl_heap_large_header */

union appl_heap_large_header_ptr
{
    void *
        p_void;

    struct appl_list *
        p_list;

    struct appl_heap_large_header *
        p_header;

}; /* union appl_heap_large_header_ptr */

//
//
//
enum appl_status
    appl_heap_impl::f_alloc_large(
        appl_size_t const
            i_len,
        void * * const
            r_buf)
{
    enum appl_status
        e_status;

    e_status =
        appl_status_ok;

    if (
        appl_status_ok
        == e_status)
    {
        void *
            p_buf;

        // look for free node of same size
        union appl_heap_large_header_ptr
            o_large_header_ptr;

        bool
            b_found;

        p_buf =
            0;

        o_large_header_ptr.p_list =
            m_free_large.o_next.p_node;

        b_found =
            false;

        while (
            (
                !(
                    b_found)) &&
            (
                o_large_header_ptr.p_list
                != &(
                    m_free_large)))
        {
            if (
                i_len
                == o_large_header_ptr.p_header->i_len)
            {
                /* Reuse existing buffer */
                appl_list_join(
                    &(
                        o_large_header_ptr.p_header->o_list),
                    &(
                        o_large_header_ptr.p_header->o_list));

                /* Return this buffer to free items list */
                o_large_header_ptr.p_header->o_list.o_next.p_node =
                    0;

                o_large_header_ptr.p_header->o_list.o_prev.p_node =
                    0;

                o_large_header_ptr.p_header->i_len =
                    0;

                p_buf =
                    o_large_header_ptr.p_void;

                b_found =
                    true;
            }
            else
            {
                o_large_header_ptr.p_list =
                    o_large_header_ptr.p_list->o_next.p_node;
            }
        }

        if (
            !(
                b_found))
        {
            /* Allocate a new buffer */
            p_buf =
                malloc(
                    i_len);

            if (
                p_buf)
            {
                b_found =
                    true;
            }
        }

        if (
            b_found)
        {
            *(
                r_buf) =
                p_buf;

            e_status =
                appl_status_ok;
        }
        else
        {
            e_status =
                appl_status_out_of_memory;
        }
    }

    return
        e_status;

} // f_alloc_large()

//
//
//
enum appl_status
    appl_heap_impl::f_free_large(
        appl_size_t const
            i_len,
        void * const
            p_buf)
{
    enum appl_status
        e_status;

    e_status =
        appl_status_ok;

    if (
        appl_status_ok
        == e_status)
    {
        union appl_heap_large_header_ptr
            o_large_header_ptr;

        o_large_header_ptr.p_void =
            p_buf;

        appl_list_init(
            &(
                o_large_header_ptr.p_header->o_list));

        o_large_header_ptr.p_header->i_len =
            i_len;

        appl_list_join(
            &(
                o_large_header_ptr.p_header->o_list),
            &(
                m_free_large));

        e_status =
            appl_status_ok;
    }

    return
        e_status;

} // f_free_large()

/* end-of-file: appl_heap_impl.cpp */
