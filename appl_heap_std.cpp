/* See LICENSE for license details */

/*

*/

#include <stdio.h>

#include <stdlib.h>

#include "appl.h"

#include "appl_object.h"

#include "appl_heap.h"

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
    appl_heap(),
    m_alloc_count(0)
{
}

//
//
//
appl_heap_std::~appl_heap_std()
{
}

void
    appl_heap_std::placement_new(
        void * const
            p_placement)
{
    new (p_placement)
        class appl_heap_std;
}

enum appl_status
    appl_heap_std::cleanup(void)
{
    enum appl_status
        e_status;

    if (
        0
        != m_alloc_count)
    {
        printf("*** detected %ld memory leaks ***\n", m_alloc_count);
    }
    else
    {
        printf("*** no memory leaks ***\n");
    }

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
        unsigned long int const
            i_buf_len)
{
    enum appl_status
        e_status;

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

        m_alloc_count ++;

        e_status =
            appl_status_ok;
    }
    else
    {
        e_status =
            appl_status_fail;
    }

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

    void *
        p_allocation;

    p_allocation =
        p_buf->o_min.p_void;

    m_alloc_count --;

    free(
        p_allocation);

    p_buf->o_max.p_void =
        p_buf->o_min.p_void;

    e_status =
        appl_status_ok;

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
        unsigned long int const
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
