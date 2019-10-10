/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_predefines.h>

#include <appl_types.h>

#include <heap/appl_heap_service.h>

#include <object/appl_object.h>

#include <context/appl_context.h>

#include <allocator/appl_allocator.h>

#include <coverage/appl_validate.h>

//
//
//
enum appl_status
    appl_heap_service::s_alloc(
        struct appl_context const * const
            p_context,
        appl_size_t const
            i_length,
        void * * const
            r_buf)
{
    enum appl_status
        e_status;

    e_status =
        appl_validate(
            (0 != p_context)
            && (0 != i_length)
            && (0 != r_buf));

    if (
        appl_status_ok
        == e_status)
    {
        struct appl_allocator * const
            p_allocator =
            p_context->v_allocator();

        e_status =
            p_allocator->v_alloc(
                i_length,
                r_buf);
    }

    return
        e_status;

} // s_alloc()

//
//
//
enum appl_status
    appl_heap_service::s_free(
        struct appl_context const * const
            p_context,
        appl_size_t const
            i_length,
        void * const
            p_buf)
{
    enum appl_status
        e_status;

    e_status =
        appl_validate(
            (0 != p_context)
            && (0 != i_length)
            && (0 != p_buf));

    if (
        appl_status_ok
        == e_status)
    {
        struct appl_allocator * const
            p_allocator =
            p_context->v_allocator();

        e_status =
            p_allocator->v_free(
                i_length,
                p_buf);
    }

    return
        e_status;

} // s_free()

/* end-of-file: appl_heap_service.cpp */
