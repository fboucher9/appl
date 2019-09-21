/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_predefines.h>

#include <appl_types.h>

#include <appl_object.h>

#include <random/appl_random_mgr.h>

#include <random/appl_random.h>

#include <random/appl_random_pseudo.h>

#include <appl_random_handle.h>

#include <appl_unused.h>

#include <context/appl_context.h>

#include <appl_allocator_handle.h>

//
//
//
enum appl_status
appl_random_mgr::v_create_node(
    struct appl_random_descriptor const * const
        p_descriptor,
    struct appl_random * * const
        r_node)
{
    appl_unused(
        p_descriptor,
        r_node);

    return
        appl_status_not_implemented;

} // v_create_node()

//
//
//
enum appl_status
appl_random_mgr::v_destroy_node(
    struct appl_random * const
        p_node)
{
    appl_unused(
        p_node);

    return
        appl_status_not_implemented;

} // v_destroy_node()

//
//
//
appl_random_mgr::appl_random_mgr(
    struct appl_context * const
        p_context) :
    appl_object(
        p_context)
{
}

//
//
//
appl_random_mgr::~appl_random_mgr()
{
}

//
//
//
enum appl_status
    appl_random_mgr::f_create_pseudo_node(
        unsigned long int const
            i_seed,
        struct appl_random * * const
            r_node)
{
    enum appl_status
        e_status;

    e_status =
        appl_random_pseudo::s_create(
            m_context->v_allocator(),
            i_seed,
            r_node);

    return
        e_status;

} // f_create_pseudo_node()

/* end-of-file: appl_random_mgr.cpp */
