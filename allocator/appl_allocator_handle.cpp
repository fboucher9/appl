/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_allocator_handle.h>

#include <allocator/appl_allocator_service.h>

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
        unsigned long int const
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
        unsigned long int const
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

/* end-of-file: appl_allocator_handle.cpp */
