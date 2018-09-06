/* See LICENSE for license details */

/*

*/

#if defined APPL_DEBUG

#include <pthread.h>

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#if defined APPL_OS_LINUX

#include <unistd.h>

#include <execinfo.h>

#endif /* #if defined APPL_OS_LINUX */

#include <appl_status.h>

#include <appl_buf.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_heap.h>

#include <appl_list.h>

#include <appl_heap_dbg.h>

#include <appl_convert.h>

//
//
//
struct appl_heap_dbg_descriptor
{
    class appl_heap *
        p_parent;

}; // struct appl_heap_dbg_descriptor

//
//
//
enum appl_status
    appl_heap_dbg::create_instance(
        class appl_heap * const
            p_parent,
        class appl_heap * * const
            r_heap)
{
    enum appl_status
        e_status;

    void *
        p_placement;

    appl_size_t
        i_placement_len;

    i_placement_len =
        sizeof(
            class appl_heap_dbg);

    e_status =
        p_parent->v_alloc(
            i_placement_len,
            &(
                p_placement));

    if (
        appl_status_ok
        == e_status)
    {
        class appl_heap_dbg *
            p_heap_dbg;

        struct appl_heap_dbg_descriptor
            o_descriptor;

        o_descriptor.p_parent =
            p_parent;

        struct appl_context *
            p_dummy_context =
            0;

        e_status =
            appl_object::s_init(
                p_dummy_context,
                p_placement,
                i_placement_len,
                (&
                    appl_heap_dbg::placement_new),
                (&
                    appl_heap_dbg::init),
                &(
                    o_descriptor),
                &(
                    p_heap_dbg));

        if (
            appl_status_ok
            == e_status)
        {
            *(
                r_heap) =
                p_heap_dbg;
        }
        else
        {
            p_parent->v_free(
                i_placement_len,
                p_placement);
        }
    }

    return
        e_status;

} // create_instance()

//
//
//
appl_heap_dbg::appl_heap_dbg() :
    appl_heap(),
    m_parent(),
    m_list(),
    m_lock(),
    m_alloc_count(0)
{
}

//
//
//
appl_heap_dbg::~appl_heap_dbg()
{
}

//
//
//
void
    appl_heap_dbg::placement_new(
        void * const
            p_placement)
{
    new (p_placement)
        class appl_heap_dbg;

} // placement_new()

static unsigned char const g_appl_heap_dbg_header_magic = (0xA1u);

static unsigned char const g_appl_heap_dbg_footer_magic = (0x8Du);

struct appl_heap_dbg_header : public appl_list
{
    void *
        a_backtrace[8u];

    /* -- */

    appl_size_t
        i_buf_len;

    appl_size_t
        i_backtrace_count;

    /* -- */

    unsigned char
        a_header[8u];

}; /* struct appl_heap_dbg_header */

union appl_heap_dbg_header_ptr
{
    void *
        p_void;

    unsigned char *
        p_uchar;

    struct appl_list *
        p_node;

    struct appl_heap_dbg_header *
        p_header;

}; /* union appl_heap_dbg_header_ptr */

struct appl_heap_dbg_footer
{
    unsigned char
        a_footer[8u];

}; /* struct appl_heap_dbg_footer */

union appl_heap_dbg_footer_ptr
{
    void *
        p_void;

    unsigned char *
        p_uchar;

    struct appl_heap_dbg_footer *
        p_footer;

}; /* union appl_heap_dbg_footer_ptr */

//
//
//
enum appl_status
    appl_heap_dbg::init(
        struct appl_heap_dbg_descriptor const * const
            p_descriptor)
{
    enum appl_status
        e_status;

    class appl_heap * const
        p_parent =
        p_descriptor->p_parent;

    m_parent =
        p_parent;

    appl_list_init(
        &(
            m_list));

    pthread_mutex_init(
        &(
            m_lock),
        NULL);

    e_status =
        appl_status_ok;

    return
        e_status;

} // init()

//
//
//
enum appl_status
    appl_heap_dbg::v_cleanup(void)
{
    enum appl_status
        e_status;

    if (
        0
        != m_alloc_count)
    {
        printf("*** detected %ld memory leaks ***\n", m_alloc_count);

        /* Iterate list of allocations ... */
        {
            struct appl_iterator
                o_iterator;

            appl_iterator_init(
                &(
                    o_iterator),
                &(
                    m_list));

            while (
                appl_iterator_next(
                    &(
                        o_iterator)))
            {
                union appl_heap_dbg_header_ptr
                    o_header_ptr;

                o_header_ptr.p_node =
                    o_iterator.o_cur.p_node;

                struct appl_heap_dbg_header *
                    p_header;

                p_header =
                    o_header_ptr.p_header;

                void * const
                    pv_allocation =
                    p_header + 1;

                unsigned long int const
                    ul_buf_len =
                    appl_convert::to_ulong(
                        p_header->i_buf_len);

                printf(" - allocation at %p of %lu bytes\n",
                    pv_allocation,
                    ul_buf_len);

#if defined APPL_OS_LINUX
                backtrace_symbols_fd(
                    p_header->a_backtrace,
                    appl_convert::to_int(
                        p_header->i_backtrace_count),
                    STDOUT_FILENO);
#endif /* #if defined APPL_OS_LINUX */
            }
        }
    }
    else
    {
        printf("*** no memory leaks ***\n");
    }

    class appl_heap * const
        p_parent =
        m_parent;

    m_parent =
        0;

    e_status =
        appl_status_fail;

    void * const
        p_placement =
        this;

    delete
        this;

    p_parent->v_free(
        sizeof(
            class appl_heap_dbg),
        p_placement);

    return
        e_status;

} // v_cleanup()

//
//
//
enum appl_status
    appl_heap_dbg::v_alloc(
        appl_size_t const
            i_buf_len,
        void * * const
            r_buf)
{
    enum appl_status
        e_status;

    {
        void *
            p_allocation;

        appl_size_t
            i_total_buf_len;

        i_total_buf_len =
            (
                i_buf_len
                + sizeof(
                    struct appl_heap_dbg_header)
                + sizeof(
                    struct appl_heap_dbg_footer));

        e_status =
            m_parent->v_alloc(
                i_total_buf_len,
                &(
                    p_allocation));

        if (
            appl_status_ok
            == e_status)
        {
            union appl_heap_dbg_header_ptr
                o_header_ptr;

            pthread_mutex_lock(
                &(
                    m_lock));

            o_header_ptr.p_void =
                p_allocation;

            appl_list_init(
                o_header_ptr.p_header);

            appl_list_join(
                o_header_ptr.p_header,
                &(
                    m_list));

            o_header_ptr.p_header->i_buf_len =
                i_buf_len;

#if defined APPL_OS_LINUX
            /* Grab a backtrace */
            o_header_ptr.p_header->i_backtrace_count =
                appl_convert::to_unsigned(
                    backtrace(
                        o_header_ptr.p_header->a_backtrace,
                        8));
#endif /* #if defined APPL_OS_LINUX */

            {
                unsigned int i_header_iterator;
                for (i_header_iterator = 0u;
                    i_header_iterator < sizeof(o_header_ptr.p_header->a_header);
                    i_header_iterator ++)
                {
                    o_header_ptr.p_header->a_header[i_header_iterator] =
                        g_appl_heap_dbg_header_magic;
                }
            }

            union appl_heap_dbg_footer_ptr
                o_footer_ptr;

            o_footer_ptr.p_uchar =
                o_header_ptr.p_header->a_header + 8 + i_buf_len;

            {
                unsigned int i_footer_iterator;
                for (i_footer_iterator = 0u;
                    i_footer_iterator < sizeof(o_footer_ptr.p_footer->a_footer);
                    i_footer_iterator ++)
                {
                    o_footer_ptr.p_footer->a_footer[i_footer_iterator] =
                        g_appl_heap_dbg_footer_magic;
                }
            }

            m_alloc_count ++;

            pthread_mutex_unlock(
                &(
                    m_lock));

            void * const
                pv_allocation =
                o_header_ptr.p_header + 1;

            *(
                r_buf) =
                pv_allocation;

            e_status =
                appl_status_ok;
        }
    }

    return
        e_status;

} // v_alloc()

//
//
//
enum appl_status
    appl_heap_dbg::v_free(
        appl_size_t const
            i_buf_len,
        void * const
            p_buf)
{
    enum appl_status
        e_status;

    {
        union appl_heap_dbg_header_ptr
            o_header_ptr;

        pthread_mutex_lock(
            &(
                m_lock));

        o_header_ptr.p_void =
            p_buf;

        o_header_ptr.p_header --;

        appl_list_join(
            o_header_ptr.p_header,
            o_header_ptr.p_header);

        {
            unsigned int i_header_iterator;
            for (i_header_iterator = 0u;
                i_header_iterator < sizeof(o_header_ptr.p_header->a_header);
                i_header_iterator ++)
            {
                if (
                    g_appl_heap_dbg_header_magic
                    == o_header_ptr.p_header->a_header[i_header_iterator])
                {
                }
                else
                {
                }
            }
        }

        void *
            p_allocation;

        p_allocation =
            o_header_ptr.p_header;

        union appl_heap_dbg_footer_ptr
            o_footer_ptr;

        o_footer_ptr.p_void =
            p_buf;

        o_footer_ptr.p_uchar +=
            o_header_ptr.p_header->i_buf_len;

        {
            unsigned int i_footer_iterator;
            for (i_footer_iterator = 0u;
                i_footer_iterator < sizeof(o_footer_ptr.p_footer->a_footer);
                i_footer_iterator ++)
            {
                if (
                    g_appl_heap_dbg_footer_magic
                    == o_footer_ptr.p_footer->a_footer[i_footer_iterator])
                {
                }
                else
                {
                }
            }
        }

        appl_size_t
            i_total_buf_len;

        i_total_buf_len =
            (
                i_buf_len
                + sizeof(
                    struct appl_heap_dbg_header)
                + sizeof(
                    struct appl_heap_dbg_footer));

        m_parent->v_free(
            i_total_buf_len,
            p_allocation);

        m_alloc_count --;

        pthread_mutex_unlock(
            &(
                m_lock));

        e_status =
            appl_status_ok;
    }

    return
        e_status;

} // v_free()

//
//
//
enum appl_status
    appl_heap_dbg::v_realloc(
        appl_size_t const
            i_old_len,
        void * const
            p_old_buf,
        appl_size_t const
            i_buf_len,
        void * * const
            r_new_buf)
{
    enum appl_status
        e_status;

    {
        void *
            p_new_buf;

        e_status =
            v_alloc(
                i_buf_len,
                &(
                    p_new_buf));

        if (
            appl_status_ok
            == e_status)
        {
            union appl_heap_dbg_header_ptr
                o_header_ptr;

            o_header_ptr.p_void =
                p_old_buf;

            o_header_ptr.p_header --;

            appl_size_t
                i_copy_len;

            i_copy_len =
                i_old_len;

            if (
                i_copy_len > i_buf_len)
            {
                i_copy_len = i_buf_len;
            }

            memcpy(
                p_new_buf,
                p_old_buf,
                i_copy_len);

            v_free(
                i_old_len,
                p_old_buf);

            *(
                r_new_buf) =
                p_new_buf;
        }
    }

    return
        e_status;

} // v_realloc()

#endif /* #if defined APPL_DEBUG */

/* end-of-file: appl_heap_dbg.cpp */
