/* See LICENSE for license details */

/*

*/

#if defined APPL_DEBUG

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#if defined APPL_OS_LINUX

#include <pthread.h>

#include <unistd.h>

#else /* #if defined APPL_OS_LINUX */

#include <windows.h>

#endif /* #if defined APPL_OS_LINUX */

#include <appl_status.h>

#include <appl_buf.h>

#include <appl_types.h>

#include <appl_object.h>

#include <allocator/appl_allocator.h>

#include <heap/appl_heap.h>

#include <appl_list.h>

#include <mutex/appl_mutex_impl.h>

#include <heap/appl_heap_dbg.h>

#include <backtrace/appl_backtrace_impl.h>

#include <appl_convert.h>

//
//
//
struct appl_heap_dbg_descriptor
{
    struct appl_heap *
        p_parent;

}; // struct appl_heap_dbg_descriptor

//
//
//
enum appl_status
    appl_heap_dbg::create_instance(
        struct appl_heap * const
            p_parent,
        struct appl_heap * * const
            r_heap)
{
    enum appl_status
        e_status;

    class appl_heap_dbg *
        p_heap_dbg;

    struct appl_heap_dbg_descriptor
        o_descriptor;

    o_descriptor.p_parent =
        p_parent;

    e_status =
        p_parent->alloc_object(
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

    return
        e_status;

} // create_instance()

//
//
//
appl_heap_dbg::appl_heap_dbg() :
    appl_heap(),
    m_parent(),
    m_alloc_count(0),
    m_list(),
    m_lock()
{
}

//
//
//
appl_heap_dbg::~appl_heap_dbg()
{
}

static unsigned char const g_appl_heap_dbg_header_magic = (0xA1u);

static unsigned char const g_appl_heap_dbg_footer_magic = (0x8Du);

struct appl_heap_dbg_header : public appl_list
{
    void const *
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
    appl_heap_dbg::f_init(
        struct appl_heap_dbg_descriptor const * const
            p_descriptor)
{
    enum appl_status
        e_status;

    struct appl_heap * const
        p_parent =
        p_descriptor->p_parent;

    m_parent =
        p_parent;

    appl_list_init(
        &(
            m_list));

    m_lock.f_init();

    e_status =
        appl_status_ok;

    return
        e_status;

} // f_init()

//
//
//
appl_size_t
    appl_heap_dbg::v_cleanup(void)
{
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

                {
                    if (
                        appl_status_ok
                        == appl_backtrace_impl::s_report(
                            p_header->a_backtrace,
                            p_header->i_backtrace_count))
                    {
                    }
                    else
                    {
                        printf("! oops backtrace service failed\n");
                    }
                }
            }
        }
    }
    else
    {
        printf("*** no memory leaks ***\n");
    }

    struct appl_heap * const
        p_parent =
        m_parent;

    m_parent =
        0;

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
        0;

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

            m_lock.f_lock();

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

            /* Grab a backtrace */
            o_header_ptr.p_header->i_backtrace_count =
                0;

            {
                if (
                    appl_status_ok
                    == appl_backtrace_impl::s_capture(
                        o_header_ptr.p_header->a_backtrace,
                        8,
                        &(
                            o_header_ptr.p_header->i_backtrace_count)))
                {
                }
                else
                {
                    printf("! oops backtrace service failed\n");
                }
            }

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

            m_lock.f_unlock();

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

        m_lock.f_lock();

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

        m_lock.f_unlock();

        e_status =
            appl_status_ok;
    }

    return
        e_status;

} // v_free()

#endif /* #if defined APPL_DEBUG */

/* end-of-file: appl_heap_dbg.cpp */
