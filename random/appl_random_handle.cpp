/* See LICENSE for license details */

/*

Module: appl_random_handle.cpp

Description:

    Pseudo-random number generator.

*/

#include <appl_status.h>

#include <appl_random_handle.h>

#include <random/appl_random_service.h>

/*

*/
enum appl_status
appl_random_create(
    struct appl_context * const
        p_context,
    struct appl_random_descriptor const * const
        p_descriptor,
    struct appl_random * * const
        r_random)
{
    return
        appl_random_service::s_create(
            p_context,
            p_descriptor,
            r_random);

} /* create() */

/*

*/
struct appl_object *
appl_random_parent(
    struct appl_random * const
        p_random)
{
    return
        appl_random_service::s_parent(
            p_random);

} /* parent() */

/*

*/
struct appl_object const *
appl_random_const_parent(
    struct appl_random const * const
        p_random)
{
    return
        appl_random_service::s_const_parent(
            p_random);

} /* const_parent() */

/*

*/
enum appl_status
appl_random_pick(
    struct appl_random * const
        p_random,
    unsigned long int const
        i_value_max,
    unsigned long int * const
        r_value)
{
    return
        appl_random_service::s_pick(
            p_random,
            i_value_max,
            r_value);

} /* pick() */

/* end-of-file: appl_random_handle.cpp */
