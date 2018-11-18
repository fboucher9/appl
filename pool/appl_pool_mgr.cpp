/* See LICENSE for license details */

/*

*/

#if defined APPL_OS_LINUX

#include <pthread.h>

#else /* #if defined APPL_OS_Xx */

#include <windows.h>

#endif /* #if defined APPL_OS_Xx */

#include <appl_status.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <pool/appl_pool_mgr.h>

#include <allocator/appl_allocator.h>

#include <pool/appl_pool.h>

#include <appl_list.h>

#include <mutex/appl_mutex_impl.h>

#include <pool/appl_pool_std.h>

#include <context/appl_context.h>

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

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
        p_allocator->alloc_object(
            r_instance);

    return
        e_status;

} // s_create()

//
//
//
enum appl_status
    appl_pool_mgr::v_create_node(
        appl_size_t const
            i_buf_len,
        struct appl_pool * * const
            r_pool_node)
{
    enum appl_status
        e_status;

    class appl_pool_std *
        p_pool_std;

    e_status =
        appl_pool_std::s_create(
            m_context->m_allocator,
            i_buf_len,
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
appl_pool_mgr::appl_pool_mgr()
{
}

//
//
//
appl_pool_mgr::~appl_pool_mgr()
{
}

/* end-of-file: appl_pool_mgr.cpp */
