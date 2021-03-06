/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <pool/appl_pool_mgr.h>

#include <allocator/appl_allocator.h>

#include <allocator/appl_allocator_handle.h>

#include <pool/appl_pool.h>

#include <list/appl_list.h>

#include <pool/appl_pool_handle.h>

#include <pool/appl_pool_std.h>

#include <context/appl_context_handle.h>

/* Assert compiler */
#include <misc/appl_assert_cplusplus.h>

//
//
//
enum appl_status
    appl_pool_mgr::s_create(
        struct appl_allocator * const
            p_allocator,
        class appl_pool_mgr * * const
            r_instance)
{
    enum appl_status
        e_status;

    e_status =
        appl_new(
            p_allocator,
            r_instance);

    return
        e_status;

} // s_create()

//
//
//
enum appl_status
    appl_pool_mgr::s_destroy(
        struct appl_allocator * const
            p_allocator,
        class appl_pool_mgr * const
            p_pool_mgr)
{
    return
        appl_delete(
            p_allocator,
            p_pool_mgr);

} // s_destroy()

//
//
//
enum appl_status
    appl_pool_mgr::v_create_node(
        struct appl_pool_descriptor const * const
            p_pool_descriptor,
        struct appl_pool * * const
            r_pool_node)
{
    enum appl_status
        e_status;

    class appl_pool_std *
        p_pool_std;

    e_status =
        appl_pool_std::s_create(
            appl_context_get_allocator(
                m_context),
            p_pool_descriptor,
            &(
                p_pool_std));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_pool_node) =
            p_pool_std;
    }

    return
        e_status;

} // v_create_node()

//
//
//
enum appl_status
    appl_pool_mgr::v_destroy_node(
        struct appl_pool * const
            p_pool_node)
{
    return
        appl_delete(
            appl_context_get_allocator(
                m_context),
            p_pool_node);

} // v_destroy_node()


//
//
//
appl_pool_mgr::appl_pool_mgr(
    struct appl_context * const
        p_context) :
    appl_object(
        p_context)
{
}

//
//
//
appl_pool_mgr::~appl_pool_mgr()
{
}

//
//
//
appl_size_t
    appl_pool_mgr::v_cleanup(void)
{
    return
        sizeof(class appl_pool_mgr);

} // v_cleanup()

/* end-of-file: appl_pool_mgr.cpp */
