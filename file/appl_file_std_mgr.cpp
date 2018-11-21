/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <file/appl_file_mgr.h>

#include <file/appl_file_std_mgr.h>

#include <file/appl_file_node.h>

#include <file/appl_file_std_node.h>

#include <allocator/appl_allocator.h>

#include <pool/appl_pool.h>

#include <pool/appl_pool_mgr.h>

#include <context/appl_context.h>

#include <appl_pool_handle.h>

#if !defined(__cplusplus)
#error use c++ compiler
#endif /* #if !defined(__cplusplus) */

//
//
//
enum appl_status
    appl_file_std_mgr::s_create(
        struct appl_allocator * const
            p_allocator,
        class appl_file_mgr * * const
            r_file_mgr)
{
    enum appl_status
        e_status;

    class appl_file_std_mgr *
        p_file_std_mgr;

    e_status =
        p_allocator->alloc_object(
            &(
                p_file_std_mgr));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_file_mgr) =
            p_file_std_mgr;
    }

    return
        e_status;

} // create_instance()

//
//
//
appl_file_std_mgr::appl_file_std_mgr() :
    appl_file_mgr(),
    m_pool()
{
}

//
//
//
appl_file_std_mgr::~appl_file_std_mgr()
{
}

//
//
//
enum appl_status
    appl_file_std_mgr::f_init(void)
{
    enum appl_status
        e_status;

    struct appl_pool_descriptor
        o_pool_descriptor;

    o_pool_descriptor.i_length =
        sizeof(
            class appl_file_std_node);

    o_pool_descriptor.i_count_min =
        0u;

    o_pool_descriptor.i_count_max =
        0u;

    e_status =
        m_context->m_pool_mgr->v_create_node(
            &(
                o_pool_descriptor),
            &(
                m_pool));

    return
        e_status;

} // f_init()

//
//
//
enum appl_status
    appl_file_std_mgr::v_cleanup(void)
{
    enum appl_status
        e_status;

    if (
        m_pool)
    {
        m_pool->v_destroy();

        m_pool =
            0;
    }

    e_status =
        appl_status_ok;

    return
        e_status;

} // v_cleanup()

//
//
//
enum appl_status
    appl_file_std_mgr::v_create_node(
        struct appl_file_descriptor const * const
            p_file_descriptor,
        struct appl_file * * const
            r_file)
{
    enum appl_status
        e_status;

    // Use a pool to allocate memory for a node
    e_status =
        appl_file_std_node::s_create(
            m_pool,
            p_file_descriptor,
            r_file);

    return
        e_status;

} // v_create_node()

/* end-of-file: appl_file_std_mgr.cpp */
