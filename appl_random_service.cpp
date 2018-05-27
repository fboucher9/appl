/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_random_service.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_random.h>

#include <appl_random_mgr.h>

#include <appl_context.h>

#include <appl_unused.h>

//
//
//
enum appl_status
appl_random_service::s_generate_seed(
    struct appl_context * const
        p_context,
    unsigned long int * const
        r_seed)
{
    return
        p_context->m_random_mgr->v_generate_seed(
            r_seed);

} // s_generate_seed()

//
//
//
enum appl_status
appl_random_service::s_create(
    struct appl_context * const
        p_context,
    unsigned long int const
        i_seed,
    struct appl_random * * const
        r_random)
{
    return
        p_context->m_random_mgr->v_create_node(
            i_seed,
            r_random);

} // s_create()

//
//
//
struct appl_object *
appl_random_service::s_parent(
    struct appl_random * const
        p_random)
{
    return
        p_random;

} // s_parent()

//
//
//
struct appl_object const *
appl_random_service::s_const_parent(
    struct appl_random const * const
        p_random)
{
    return
        p_random;

} // s_const_parent()

//
//
//
enum appl_status
appl_random_service::s_pick(
    struct appl_random * const
        p_random,
    unsigned long int const
        i_value_max,
    unsigned long int * const
        r_value)
{
    return
        p_random->v_pick(
            i_value_max,
            r_value);

} // s_pick()

/* end-of-file: appl_random_service.cpp */
