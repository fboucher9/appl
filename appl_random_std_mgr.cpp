/* See LICENSE for license details */

/*

*/

#if defined APPL_OS_LINUX

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_random_mgr.h>

#include <appl_random_std_mgr.h>

#include <appl_random_handle.h>

#include <appl_random.h>

#include <appl_random_std_crypto.h>

#include <appl_unused.h>

#include <appl_context.h>

#include <appl_allocator.h>

//
//
//
enum appl_status
appl_random_std_mgr::s_create(
    struct appl_allocator * const
        p_allocator,
    class appl_random_mgr * * const
        r_random_mgr)
{
    enum appl_status
        e_status;

    class appl_random_std_mgr *
        p_random_std_mgr;

    e_status =
        p_allocator->alloc_object(
            &(
                p_random_std_mgr));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_random_mgr) =
            p_random_std_mgr;
    }

    return
        e_status;

} // s_create()

//
//
//
appl_random_std_mgr::appl_random_std_mgr() :
    appl_random_mgr()
{
}

//
//
//
appl_random_std_mgr::~appl_random_std_mgr()
{
}

//
//
//
enum appl_status
    appl_random_std_mgr::f_init(void)
{
    return
        appl_status_ok;

} // f_init()

//
//
//
enum appl_status
appl_random_std_mgr::v_create_node(
    struct appl_random_descriptor const * const
        p_descriptor,
    struct appl_random * * const
        r_node)
{
    enum appl_status
        e_status;

    if (
        appl_random_type_crypto
        == p_descriptor->e_type)
    {
        e_status =
            appl_random_std_crypto::s_create(
                m_context->m_allocator,
                r_node);
    }
    else
    {
        e_status =
            appl_random_mgr::v_create_node(
                p_descriptor,
                r_node);
    }

    return
        e_status;

} // v_create_node()

#endif /* #if defined APPL_OS_LINUX */

/* end-of-file: appl_random_std_mgr.cpp */
