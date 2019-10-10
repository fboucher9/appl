/* See LICENSE for license details */

/*

*/

#if defined APPL_OS_LINUX

#include <appl_status.h>

#include <appl_predefines.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <random/appl_random_mgr.h>

#include <random/appl_random_std_mgr.h>

#include <random/appl_random_handle.h>

#include <random/appl_random.h>

#include <random/appl_random_std_crypto.h>

#include <misc/appl_unused.h>

#include <context/appl_context_handle.h>

#include <allocator/appl_allocator_handle.h>

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
        appl_new(
            p_allocator,
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
enum appl_status
appl_random_std_mgr::s_destroy(
    struct appl_allocator * const
        p_allocator,
    class appl_random_mgr * const
        p_random_mgr)
{
    return
        appl_delete(
            p_allocator,
            p_random_mgr);

} // s_destroy()

//
//
//
appl_random_std_mgr::appl_random_std_mgr(
    struct appl_context * const
        p_context) :
    appl_random_mgr(
        p_context)
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

appl_size_t
appl_random_std_mgr::v_cleanup(void)
{
    return
        sizeof(class appl_random_std_mgr);
}

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
                appl_context_get_allocator(
                    m_context),
                r_node);
    }
    else
    {
        e_status =
            appl_random_mgr::f_create_pseudo_node(
                p_descriptor->i_seed,
                r_node);
    }

    return
        e_status;

} // v_create_node()

//
//
//
enum appl_status
appl_random_std_mgr::v_destroy_node(
    struct appl_random * const
        p_random)
{
    enum appl_status
        e_status;

    e_status =
        appl_delete(
            appl_context_get_allocator(
                m_context),
            p_random);

    return
        e_status;

} // v_destroy_node()

#endif /* #if defined APPL_OS_LINUX */

/* end-of-file: appl_random_std_mgr.cpp */
