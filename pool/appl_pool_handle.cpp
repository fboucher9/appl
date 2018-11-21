/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_pool_handle.h>

#include <pool/appl_pool_service.h>

/*

*/
enum appl_status
    appl_pool_create(
        struct appl_context * const
            p_context,
        struct appl_pool_descriptor const * const
            p_pool_descriptor,
        struct appl_pool * * const
            r_pool)
{
    return
        appl_pool_service::s_create(
            p_context,
            p_pool_descriptor,
            r_pool);

} /* appl_pool_create() */

/*

*/
struct appl_allocator *
    appl_pool_parent(
        struct appl_pool * const
            p_pool)
{
    return
        appl_pool_service::s_parent(
            p_pool);

} /* appl_pool_parent() */

/*

*/
struct appl_allocator const *
    appl_pool_const_parent(
        struct appl_pool const * const
            p_pool)
{
    return
        appl_pool_service::s_const_parent(
            p_pool);

} /* appl_pool_const_parent() */

/*

*/
enum appl_status
    appl_pool_alloc(
        struct appl_pool * const
            p_pool,
        void * * const
            r_buffer)
{
    return
        appl_pool_service::s_alloc(
            p_pool,
            r_buffer);

} /* appl_pool_alloc() */

/*

*/
enum appl_status
    appl_pool_free(
        struct appl_pool * const
            p_pool,
        void * const
            p_buffer)
{
    return
        appl_pool_service::s_free(
            p_pool,
            p_buffer);

} /* appl_pool_free() */

/* end-of-file: appl_pool_handle.cpp */
