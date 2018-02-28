/* See LICENSE for license details */

/*

*/

#if defined APPL_DEBUG

#include <pthread.h>

#endif /* #if defined APPL_DEBUG */

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#if defined APPL_OS_LINUX

#include <unistd.h>

#include <execinfo.h>

#endif /* #if defined APPL_OS_LINUX */

#include "appl_status.h"

#include "appl_buf.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_heap.h"

#include "appl_list.h"

#include "appl_heap_std.h"

//
//
//
enum appl_status
    appl_heap_std::create_instance(
        class appl_heap * * const
            r_heap)
{
    enum appl_status
        e_status;

    void *
        p_placement;

    p_placement =
        malloc(
            sizeof(class appl_heap_std));

    if (
        p_placement)
    {
        class appl_object *
            p_object;

        e_status =
            appl_object::init_instance(
                static_cast<class appl_context *>(
                    0),
                p_placement,
                &(
                    appl_heap_std::placement_new),
                static_cast<void const *>(
                    0),
                &(
                    p_object));

        if (
            appl_status_ok
            == e_status)
        {
            *(
                r_heap) =
                static_cast<class appl_heap *>(
                    reinterpret_cast<class appl_heap_std *>(
                        p_object));
        }
        else
        {
            ::free(
                p_placement);
        }
    }
    else
    {
        e_status =
            appl_status_out_of_memory;
    }

    return
        e_status;

} // create_instance()

//
//
//
appl_heap_std::appl_heap_std() :
    appl_heap()
#if defined APPL_DEBUG
    ,
    m_list(),
    m_lock(),
    m_alloc_count(0)
#endif /* #if defined APPL_DEBUG */
{
}

//
//
//
appl_heap_std::~appl_heap_std()
{
}

//
//
//
void
    appl_heap_std::placement_new(
        void * const
            p_placement)
{
    new (p_placement)
        class appl_heap_std;

} // placement_new()

#if defined APPL_DEBUG

static unsigned char const g_appl_heap_std_header_magic =
static_cast<unsigned char>(0xA1u);

static unsigned char const g_appl_heap_std_footer_magic =
static_cast<unsigned char>(0x8Du);

struct appl_heap_std_header
{
    struct appl_list
        o_list;

    /* -- */

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

}; /* struct appl_heap_std_header */

struct appl_heap_std_footer
{
    unsigned char
        a_footer[8u];

}; /* struct appl_heap_std_footer */

#endif /* #if defined APPL_DEBUG */

//
//
//
enum appl_status
    appl_heap_std::init(
        void const * const
            p_descriptor)
{
    enum appl_status
        e_status;

    static_cast<void>(
        p_descriptor);

#if defined APPL_DEBUG

    appl_list_init(
        &(
            m_list));

    pthread_mutex_init(
        &(
            m_lock),
        NULL);

#endif /* #if defined APPL_DEBUG */

    e_status =
        appl_status_ok;

    return
        e_status;

} // init()

//
//
//
enum appl_status
    appl_heap_std::cleanup(void)
{
    enum appl_status
        e_status;

#if defined APPL_DEBUG

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
                struct appl_heap_std_header *
                    p_header;

                p_header =
                    reinterpret_cast<struct appl_heap_std_header *>(
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

#endif /* #if defined APPL_DEBUG */

    e_status =
        appl_status_ok;

    return
        e_status;

} // cleanup()

//
//
//
enum appl_status
    appl_heap_std::destroy(void)
{
    enum appl_status
        e_status;

    e_status =
        cleanup();

    if (
        appl_status_ok
        == e_status)
    {
        void * const
            p_placement =
            static_cast<void *>(
                this);

        delete
            this;

        free(
            p_placement);
    }

    return
        e_status;

} // destroy()

//
//
//
enum appl_status
    appl_heap_std::alloc_memory(
        struct appl_buf * const
            p_buf,
        appl_size_t const
            i_buf_len)
{
    enum appl_status
        e_status;

#if defined APPL_DEBUG
    {
        void *
            p_allocation;

        appl_size_t
            i_total_buf_len;

        i_total_buf_len =
            static_cast<appl_size_t>(
                i_buf_len
                + sizeof(
                    struct appl_heap_std_header)
                + sizeof(
                    struct appl_heap_std_footer));

        p_allocation =
            malloc(
                i_total_buf_len);

        if (
            p_allocation)
        {
            struct appl_heap_std_header *
                p_header;

            pthread_mutex_lock(
                &(
                    m_lock));

            p_header =
                static_cast<struct appl_heap_std_header *>(
                    p_allocation);

            appl_list_init(
                &(
                    p_header->o_list));

            appl_list_join(
                &(
                    p_header->o_list),
                &(
                    m_list));

            p_header->i_buf_len =
                i_buf_len;

#if defined APPL_OS_LINUX
            /* Grab a backtrace */
            memset(
                p_header->a_backtrace,
                0u,
                sizeof(
                    p_header->a_backtrace));

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
                        g_appl_heap_std_header_magic;
                }
            }

            p_buf->o_min.p_void =
                static_cast<void *>(
                    p_header + 1);

            p_buf->o_max.pc_uchar =
                p_buf->o_min.pc_uchar
                + i_buf_len;

            struct appl_heap_std_footer *
                p_footer;

            p_footer =
                static_cast<struct appl_heap_std_footer *>(
                    p_buf->o_max.p_void);

            {
                unsigned int i_footer_iterator;
                for (i_footer_iterator = 0u;
                    i_footer_iterator < sizeof(p_footer->a_footer);
                    i_footer_iterator ++)
                {
                    p_footer->a_footer[i_footer_iterator] =
                        g_appl_heap_std_footer_magic;
                }
            }

            m_alloc_count ++;

            pthread_mutex_unlock(
                &(
                    m_lock));

            e_status =
                appl_status_ok;
        }
        else
        {
            e_status =
                appl_status_fail;
        }
    }
#else /* #if defined APPL_DEBUG */
    {
        void *
            p_allocation;

        p_allocation =
            malloc(
                i_buf_len);

        if (
            p_allocation)
        {
            p_buf->o_min.p_void =
                p_allocation;

            p_buf->o_max.pc_uchar =
                p_buf->o_min.pc_uchar
                + i_buf_len;

            e_status =
                appl_status_ok;
        }
        else
        {
            e_status =
                appl_status_fail;
        }
    }
#endif /* #if defined APPL_DEBUG */

    return
        e_status;

} // alloc_memory()

//
//
//
enum appl_status
    appl_heap_std::free_memory(
        struct appl_buf * const
            p_buf)
{
    enum appl_status
        e_status;

#if defined APPL_DEBUG
    {
        struct appl_heap_std_header *
            p_header;

        pthread_mutex_lock(
            &(
                m_lock));

        p_header =
            static_cast<struct appl_heap_std_header *>(
                p_buf->o_min.p_void)
            - 1;

        appl_list_join(
            &(
                p_header->o_list),
            &(
                p_header->o_list));

        {
            unsigned int i_header_iterator;
            for (i_header_iterator = 0u;
                i_header_iterator < sizeof(p_header->a_header);
                i_header_iterator ++)
            {
                if (
                    g_appl_heap_std_header_magic
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

        struct appl_heap_std_footer *
            p_footer;

        p_footer =
            reinterpret_cast<struct appl_heap_std_footer *>(
                p_buf->o_min.p_uchar
                + p_header->i_buf_len);

        {
            unsigned int i_footer_iterator;
            for (i_footer_iterator = 0u;
                i_footer_iterator < sizeof(p_footer->a_footer);
                i_footer_iterator ++)
            {
                if (
                    g_appl_heap_std_footer_magic
                    == p_footer->a_footer[i_footer_iterator])
                {
                }
                else
                {
                }
            }
        }

        free(
            p_allocation);

        m_alloc_count --;

        pthread_mutex_unlock(
            &(
                m_lock));

        e_status =
            appl_status_ok;
    }
#else /* #if defined APPL_DEBUG */
    {
        void *
            p_allocation;

        p_allocation =
            p_buf->o_min.p_void;

        free(
            p_allocation);

        p_buf->o_max.p_void =
            p_buf->o_min.p_void;

        e_status =
            appl_status_ok;
    }
#endif /* #if defined APPL_DEBUG */

    return
        e_status;

} // free_memory()

//
//
//
enum appl_status
    appl_heap_std::realloc_memory(
        struct appl_buf * const
            p_buf,
        appl_size_t const
            i_buf_len)
{
    enum appl_status
        e_status;

    if (
        0
        == i_buf_len)
    {
        e_status =
            free_memory(
                p_buf);
    }
    else if (
        p_buf->o_min.p_void
        == p_buf->o_max.p_void)
    {
        e_status =
            alloc_memory(
                p_buf,
                i_buf_len);
    }
    else
    {
        void *
            p_allocation;

        p_allocation =
            realloc(
                p_buf->o_min.p_void,
                i_buf_len);

        if (
            p_allocation)
        {
            p_buf->o_min.p_void =
                p_allocation;

            p_buf->o_max.pc_uchar =
                p_buf->o_min.pc_uchar
                + i_buf_len;

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

} // realloc_memory()

/* end-of-file: appl_heap_std.cpp */
