/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_pool_service.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_pool.h>

#include <appl_pool_mgr.h>

#include <appl_unused.h>

//
//
//
enum appl_status
    appl_pool_service::s_create(
        struct appl_context * const
            p_context,
        unsigned long int const
            i_length,
        struct appl_pool * * const
            r_pool)
{
    appl_unused(
        p_context,
        i_length,
        r_pool);

    return
        appl_status_not_implemented;

} // s_create()

//
//
//
struct appl_object *
    appl_pool_service::s_parent(
        struct appl_pool * const
            p_pool)
{
    return
        p_pool;

} // s_parent()

//
//
//
struct appl_object const *
    appl_pool_service::s_const_parent(
        struct appl_pool const * const
            p_pool)
{
    return
        p_pool;

} // s_const_parent()

//
//
//
enum appl_status
    appl_pool_service::s_alloc(
        struct appl_pool * const
            p_pool,
        void * * const
            r_buffer)
{
    return
        p_pool->v_alloc(
            r_buffer);

} // s_alloc()

//
//
//
enum appl_status
    appl_pool_service::s_free(
        struct appl_pool * const
            p_pool,
        void * const
            p_buffer)
{
    return
        p_pool->v_free(
            p_buffer);

} // s_free()

/* end-of-file: appl_pool_service.cpp */
