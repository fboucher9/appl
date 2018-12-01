/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <pool/appl_pool_service.h>

#include <appl_types.h>

#include <appl_object.h>

#include <allocator/appl_allocator.h>

#include <pool/appl_pool.h>

#include <pool/appl_pool_mgr.h>

#include <context/appl_context.h>

//
//
//
enum appl_status
    appl_pool_service::s_create(
        struct appl_context * const
            p_context,
        struct appl_pool_descriptor const * const
            p_pool_descriptor,
        struct appl_pool * * const
            r_pool)
{
    return
        p_context->m_pool_mgr->v_create_node(
            p_pool_descriptor,
            r_pool);

} // s_create()

//
//
//
enum appl_status
    appl_pool_service::s_destroy(
        struct appl_pool * const
            p_pool)
{
    struct appl_context * const
        p_context =
        p_pool->get_context();

    return
        p_context->m_pool_mgr->v_destroy_node(
            p_pool);

} // s_destroy()

//
//
//
struct appl_allocator *
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
struct appl_allocator const *
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
            0,
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
            0,
            p_buffer);

} // s_free()

/* end-of-file: appl_pool_service.cpp */
