/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <mutex/appl_mutex_mgr.h>

#include <mutex/appl_mutex_std_mgr.h>

#include <allocator/appl_allocator_handle.h>

#include <pool/appl_pool_handle.h>

/* Assert compiler */
#include <misc/appl_assert_cplusplus.h>

//
//
//
enum appl_status
    appl_mutex_std_mgr::s_create(
        struct appl_allocator * const
            p_allocator,
        class appl_mutex_mgr * * const
            r_mutex_mgr)
{
    enum appl_status
        e_status;

    class appl_mutex_std_mgr *
        p_mutex_std_mgr;

    e_status =
        appl_new(
            p_allocator,
            &(
                p_mutex_std_mgr));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_mutex_mgr) =
            p_mutex_std_mgr;
    }

    return
        e_status;

} // s_create()

//
//
//
enum appl_status
    appl_mutex_std_mgr::s_destroy(
        struct appl_allocator * const
            p_allocator,
        class appl_mutex_mgr * const
            p_mutex_mgr)
{
    return
        appl_delete(
            p_allocator,
            p_mutex_mgr);

} // s_destroy()

//
//
//
appl_mutex_std_mgr::appl_mutex_std_mgr(
    struct appl_context * const
        p_context) :
    appl_mutex_mgr(
        p_context)
{
}

//
//
//
appl_mutex_std_mgr::~appl_mutex_std_mgr()
{
}

appl_size_t
appl_mutex_std_node_sizeof(void);

//
//
//
enum appl_status
    appl_mutex_std_mgr::f_init(void)
{
    enum appl_status
        e_status;

    e_status =
        appl_status_ok;

    return
        e_status;

} // f_init()

//
//
//
appl_size_t
    appl_mutex_std_mgr::v_cleanup(void)
{
    appl_size_t
        i_cleanup_result;

    i_cleanup_result =
        sizeof(class appl_mutex_std_mgr);

    return
        i_cleanup_result;

} // v_cleanup()

enum appl_status
appl_mutex_std_node_create(
    struct appl_allocator * const
        p_allocator,
    struct appl_mutex_descriptor const * const
        p_mutex_descriptor,
    struct appl_mutex * * const
        r_mutex);

enum appl_status
appl_mutex_std_node_destroy(
    struct appl_allocator * const
        p_allocator,
    struct appl_mutex * const
        p_mutex);

//
//
//
enum appl_status
    appl_mutex_std_mgr::v_create_node(
        struct appl_allocator * const
            p_allocator,
        struct appl_mutex_descriptor const * const
            p_mutex_descriptor,
        struct appl_mutex * * const
            r_mutex)
{
    enum appl_status
        e_status;

    e_status =
        appl_mutex_std_node_create(
            p_allocator,
            p_mutex_descriptor,
            r_mutex);

    return
        e_status;

} // v_create_node()

//
//
//
enum appl_status
    appl_mutex_std_mgr::v_destroy_node(
        struct appl_allocator * const
            p_allocator,
        struct appl_mutex * const
            p_mutex)
{
    enum appl_status
        e_status;

    e_status =
        appl_mutex_std_node_destroy(
            p_allocator,
            p_mutex);

    return
        e_status;

} // v_destroy_node()

/* end-of-file: appl_mutex_std_mgr.cpp */
