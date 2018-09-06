/* See LICENSE for license details */

/*

*/

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <appl_status.h>

#include <appl_buf.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_heap.h>

#include <appl_list.h>

#include <appl_heap_std.h>

#include <appl_unused.h>

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

    appl_size_t
        i_placement_len;

    i_placement_len =
        sizeof(
            class appl_heap_std);

    p_placement =
        malloc(
            i_placement_len);

    if (
        p_placement)
    {
        class appl_heap_std *
            p_heap_std;

        struct appl_context * const
            p_context =
            0;

        e_status =
            appl_object::s_init<appl_heap_std>(
                p_context,
                p_placement,
                i_placement_len,
                (&
                    appl_heap_std::placement_new),
                (&
                    appl_heap_std::init_dummy),
                &(
                    p_heap_std));

        if (
            appl_status_ok
            == e_status)
        {
            *(
                r_heap) =
                p_heap_std;
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

//
//
//
enum appl_status
appl_heap_std::v_cleanup(void)
{
    void * const
        p_placement =
        this;

    delete
        this;

    free(
        p_placement);

    return
        appl_status_fail;

} // v_cleanup()

//
//
//
enum appl_status
    appl_heap_std::v_alloc(
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

        p_allocation =
            malloc(
                i_buf_len);

        if (
            p_allocation)
        {
            *(
                r_buf) =
                p_allocation;

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

} // v_alloc()

//
//
//
enum appl_status
    appl_heap_std::v_free(
        appl_size_t const
            i_buf_len,
        void * const
            p_buf)
{
    enum appl_status
        e_status;

    appl_unused(
        i_buf_len);

    {
        free(
            p_buf);

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
    appl_heap_std::v_realloc(
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

    void *
        p_new_buf;

    appl_unused(
        i_old_len);

    p_new_buf =
        realloc(
            p_old_buf,
            i_buf_len);

    if (
        p_new_buf)
    {
        *(
            r_new_buf) =
            p_new_buf;

        e_status =
            appl_status_ok;
    }
    else
    {
        e_status =
            appl_status_out_of_memory;
    }

    return
        e_status;

} // v_realloc()

/* end-of-file: appl_heap_std.cpp */
