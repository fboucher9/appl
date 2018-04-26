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

    e_status =
        p_parent->v_alloc(
            sizeof(
                class appl_heap_dbg),
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

        e_status =
            appl_object::s_init(
                static_cast<struct appl_context *>(
                    0),
                p_placement,
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

static unsigned char const g_appl_heap_dbg_header_magic =
static_cast<unsigned char>(0xA1u);

static unsigned char const g_appl_heap_dbg_footer_magic =
static_cast<unsigned char>(0x8Du);

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

struct appl_heap_dbg_footer
{
    unsigned char
        a_footer[8u];

}; /* struct appl_heap_dbg_footer */

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
                struct appl_heap_dbg_header *
                    p_header;

                p_header =
                    static_cast<struct appl_heap_dbg_header *>(
                        o_iterator.o_cur.p_node);

                printf(" - allocation at %p of %lu bytes\n",
                    static_cast<void *>(
                        p_header + 1),
                    static_cast<unsigned long int>(
                        p_header->i_buf_len));

#if defined APPL_OS_LINUX
                backtrace_symbols_fd(
                    p_header->a_backtrace,
                    static_cast<int>(
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
        static_cast<void *>(
            this);

    delete
        this;

    p_parent->v_free(
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
            static_cast<appl_size_t>(
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
            struct appl_heap_dbg_header *
                p_header;

            pthread_mutex_lock(
                &(
                    m_lock));

            p_header =
                static_cast<struct appl_heap_dbg_header *>(
                    p_allocation);

            appl_list_init(
                p_header);

            appl_list_join(
                p_header,
                &(
                    m_list));

            p_header->i_buf_len =
                i_buf_len;

#if defined APPL_OS_LINUX
            /* Grab a backtrace */
            p_header->i_backtrace_count =
                backtrace(
                    p_header->a_backtrace,
                    8);
#endif /* #if defined APPL_OS_LINUX */

            {
                unsigned int i_header_iterator;
                for (i_header_iterator = 0u;
                    i_header_iterator < sizeof(p_header->a_header);
                    i_header_iterator ++)
                {
                    p_header->a_header[i_header_iterator] =
                        g_appl_heap_dbg_header_magic;
                }
            }

            struct appl_heap_dbg_footer *
                p_footer;

            p_footer =
                reinterpret_cast<struct appl_heap_dbg_footer *>(
                    p_header->a_header + 8 + i_buf_len);

            {
                unsigned int i_footer_iterator;
                for (i_footer_iterator = 0u;
                    i_footer_iterator < sizeof(p_footer->a_footer);
                    i_footer_iterator ++)
                {
                    p_footer->a_footer[i_footer_iterator] =
                        g_appl_heap_dbg_footer_magic;
                }
            }

            m_alloc_count ++;

            pthread_mutex_unlock(
                &(
                    m_lock));

            *(
                r_buf) =
                static_cast<void *>(
                    p_header + 1);

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
        void * const
            p_buf)
{
    enum appl_status
        e_status;

    {
        struct appl_heap_dbg_header *
            p_header;

        pthread_mutex_lock(
            &(
                m_lock));

        p_header =
            static_cast<struct appl_heap_dbg_header *>(
                p_buf)
            - 1;

        appl_list_join(
            p_header,
            p_header);

        {
            unsigned int i_header_iterator;
            for (i_header_iterator = 0u;
                i_header_iterator < sizeof(p_header->a_header);
                i_header_iterator ++)
            {
                if (
                    g_appl_heap_dbg_header_magic
                    == p_header->a_header[i_header_iterator])
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
            static_cast<void *>(
                p_header);

        struct appl_heap_dbg_footer *
            p_footer;

        p_footer =
            reinterpret_cast<struct appl_heap_dbg_footer *>(
                static_cast<unsigned char *>(
                    p_buf)
                + p_header->i_buf_len);

        {
            unsigned int i_footer_iterator;
            for (i_footer_iterator = 0u;
                i_footer_iterator < sizeof(p_footer->a_footer);
                i_footer_iterator ++)
            {
                if (
                    g_appl_heap_dbg_footer_magic
                    == p_footer->a_footer[i_footer_iterator])
                {
                }
                else
                {
                }
            }
        }

        m_parent->v_free(
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
            struct appl_heap_dbg_header const *
                p_header;

            p_header =
                static_cast<struct appl_heap_dbg_header const *>(
                    p_old_buf)
                - 1;

            appl_size_t
                i_copy_len;

            i_copy_len =
                p_header->i_buf_len;

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
