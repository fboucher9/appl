/* See LICENSE for license details */

/*

*/

#include <stdlib.h>

#include <appl_status.h>

#include <appl_list.h>

#if defined APPL_OS_LINUX

#include <pthread.h>

#else /* #if defined APPL_OS_Xx */

#include <windows.h>

#endif /* #if defined APPL_OS_Xx */

#include <appl_types.h>

#include <mutex/appl_mutex_impl.h>

#include <appl_heap_impl.h>

#include <appl_unused.h>

union appl_heap_segment_ptr
{
    void *
        p_void;

    unsigned char *
        p_uchar;

    struct appl_list *
        p_list;

}; /* union appl_heap_segment_ptr */


//
//
//
appl_heap_primary::appl_heap_primary() :
    m_mmap_iterator(),
    m_mmap_end(),
    m_segments()
{
}

//
//
//
appl_heap_primary::~appl_heap_primary()
{
}

//
//
//
enum appl_status
    appl_heap_primary::f_init(
        unsigned char * const
            p_mmap_begin,
        unsigned char * const
            p_mmap_end)
{
    enum appl_status
        e_status;

    m_mmap_iterator =
        p_mmap_begin;

    m_mmap_end =
        p_mmap_end;

    appl_list_init(
        &(
            m_segments));

    e_status =
        appl_status_ok;

    return
        e_status;

} // f_init()

//
//
//
enum appl_status
    appl_heap_primary::f_cleanup(void)
{
    enum appl_status
        e_status;

    // free all segments
    while (m_segments.o_next.p_node != &(m_segments))
    {
        struct appl_list *
            p_segment;

        p_segment =
            m_segments.o_next.p_node;

        appl_list_join(
            p_segment,
            p_segment);

        free(
            p_segment);
    }

    e_status =
        appl_status_ok;

    return
        e_status;

} // f_cleanup()

static
appl_size_t const
    g_appl_heap_primary_segment_length =
    256ul * 1024ul;

static
appl_size_t const
g_appl_heap_primary_max_alloc_length =
    g_appl_heap_primary_segment_length
    - sizeof(struct appl_list);

//
//
//
enum appl_status
    appl_heap_primary::f_alloc(
        appl_size_t const
            i_len,
        void * * const
            r_buf)
{
    enum appl_status
        e_status;

    // Validate len
    if (
        g_appl_heap_primary_max_alloc_length
        >= i_len)
    {
        // Is there room in current segment?
        if (
            (m_mmap_iterator + i_len) > m_mmap_end)
        {
            union appl_heap_segment_ptr
                o_segment_ptr;

            // Add an extra segment
            o_segment_ptr.p_void =
                malloc(
                    g_appl_heap_primary_segment_length);

            if (
                o_segment_ptr.p_void)
            {
                appl_list_init(
                    o_segment_ptr.p_list);

                appl_list_join(
                    o_segment_ptr.p_list,
                    &(
                        m_segments));

                m_mmap_iterator =
                    o_segment_ptr.p_uchar
                    + sizeof(struct appl_list);

                m_mmap_end =
                    o_segment_ptr.p_uchar
                    + g_appl_heap_primary_segment_length;
            }
        }

        if (
            (m_mmap_iterator + i_len) <= m_mmap_end)
        {
            *(
                r_buf) =
                m_mmap_iterator;

            m_mmap_iterator +=
                i_len;

            e_status =
                appl_status_ok;
        }
        else
        {
            e_status =
                appl_status_out_of_memory;
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
appl_heap_impl::appl_heap_impl() :
    m_primary(),
    m_lock(),
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

    m_lock.init();

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

    m_lock.cleanup();

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
        m_lock.lock();

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

        m_lock.unlock();
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
        m_lock.lock();

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

        m_lock.unlock();
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

    void *
        p_buf;

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
        m_lock.lock();

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

                p_buf =
                    o_large_header_ptr.p_header->p_buf;

                /* Return this buffer to free items list */
                o_large_header_ptr.p_header->p_buf =
                    0;

                o_large_header_ptr.p_header->i_len =
                    0;

                f_free_small(
                    sizeof(struct appl_heap_large_header),
                    o_large_header_ptr.p_void);

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

        m_lock.unlock();
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
        m_lock.lock();

    if (
        appl_status_ok
        == e_status)
    {
        appl_unused(
            i_len,
            p_buf);

        e_status =
            appl_status_not_implemented;

        m_lock.unlock();
    }

    return
        e_status;

} // f_free_large()

/* end-of-file: appl_heap_impl.cpp */
