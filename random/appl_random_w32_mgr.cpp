/* See LICENSE for license details */

/*

*/

#if defined APPL_OS_WINDOWS

#include <appl_status.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <random/appl_random_mgr.h>

#include <random/appl_random_w32_mgr.h>

#include <appl_random_handle.h>

#include <random/appl_random.h>

#include <random/appl_random_w32_crypto.h>

#include <allocator/appl_allocator.h>

#include <context/appl_context.h>

//
//
//
enum appl_status
appl_random_w32_mgr::s_create(
    struct appl_allocator * const
        p_allocator,
    class appl_random_mgr * * const
        r_random_mgr)
{
    enum appl_status
        e_status;

    class appl_random_w32_mgr *
        p_random_w32_mgr;

    e_status =
        p_allocator->alloc_object(
            &(
                p_random_w32_mgr));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_random_mgr) =
            p_random_w32_mgr;
    }

    return
        e_status;

} // s_create()

//
//
//
appl_random_w32_mgr::appl_random_w32_mgr() :
    appl_random_mgr()
{
}

//
//
//
appl_random_w32_mgr::~appl_random_w32_mgr()
{
}

//
//
//
enum appl_status
    appl_random_w32_mgr::f_init(void)
{
    return
        appl_status_ok;

} // f_init()

//
//
//
enum appl_status
appl_random_w32_mgr::v_create_node(
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
            appl_random_w32_crypto::s_create(
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

#endif /* #if defined APPL_OS_WINDOWS */

/* end-of-file: appl_random_w32_mgr.cpp */
