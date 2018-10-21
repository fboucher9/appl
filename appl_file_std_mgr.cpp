/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_heap_object.h>

#include <appl_pool_object.h>

#include <appl_file_mgr.h>

#include <appl_file_std_mgr.h>

#include <appl_file_node.h>

#include <appl_file_std_node.h>

#include <appl_object_handle.h>

#include <appl_pool_handle.h>

#include <appl_heap.h>

#if !defined(__cplusplus)
#error use c++ compiler
#endif /* #if !defined(__cplusplus) */

//
//
//
enum appl_status
    appl_file_std_mgr::s_create(
        struct appl_heap * const
            p_heap,
        class appl_file_mgr * * const
            r_file_mgr)
{
    enum appl_status
        e_status;

    class appl_file_std_mgr *
        p_file_std_mgr;

    e_status =
        p_heap->alloc_object(
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
void
    appl_file_std_mgr::s_new(
        void * const
            p_placement)
{
    new (p_placement)
        class appl_file_std_mgr;

} // s_new()

//
//
//
enum appl_status
    appl_file_std_mgr::f_init(void)
{
    enum appl_status
        e_status;

    unsigned long int const
        i_length =
        sizeof(
            class appl_file_std_node);

    e_status =
        appl_pool_create(
            m_context,
            i_length,
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
        appl_object_destroy(
            appl_pool_parent(
                m_pool));

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
