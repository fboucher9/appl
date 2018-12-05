/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_allocator_handle.h>

#include <allocator/appl_allocator_service.h>

#include <appl_object.h>

/*

*/
struct appl_object *
    appl_allocator_parent(
        struct appl_allocator * const
            p_allocator)
{
    return
        appl_allocator_service::s_parent(
            p_allocator);

} /* parent() */

/*

*/
enum appl_status
    appl_allocator_alloc(
        struct appl_allocator * const
            p_allocator,
        appl_size_t const
            i_buf_len,
        void * * const
            r_buf)
{
    return
        appl_allocator_service::s_alloc(
            p_allocator,
            i_buf_len,
            r_buf);

} /* alloc() */

/*

*/
enum appl_status
    appl_allocator_free(
        struct appl_allocator * const
            p_allocator,
        appl_size_t const
            i_buf_len,
        void * const
            p_buf)
{
    return
        appl_allocator_service::s_free(
            p_allocator,
            i_buf_len,
            p_buf);

} /* free() */

//
//
//
enum appl_status
    appl_delete(
        struct appl_allocator * const
            p_allocator,
        struct appl_object * const
            p_object)
{
    enum appl_status
        e_status;

    void * const
        p_placement =
        p_object;

    appl_size_t const
        i_placement_length =
        p_object->v_cleanup();

    if (
        i_placement_length)
    {
        delete
            p_object;

        appl_allocator_free(
            p_allocator,
            i_placement_length,
            p_placement);
    }

    e_status =
        appl_status_ok;

    return
        e_status;

} // appl_delete()

/* end-of-file: appl_allocator_handle.cpp */
