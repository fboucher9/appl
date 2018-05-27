/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_random_mgr.h>

#include <appl_unused.h>

//
//
//
enum appl_status
appl_random_mgr::v_generate_seed(
    unsigned long int * const
        r_seed)
{
    appl_unused(
        r_seed);
    return
        appl_status_not_implemented;
} // v_generate_seed()

//
//
//
enum appl_status
appl_random_mgr::v_create_node(
    unsigned long int const
        i_seed,
    struct appl_random * * const
        r_node)
{
    appl_unused(
        i_seed,
        r_node);
    return
        appl_status_not_implemented;
} // v_create_node()

//
//
//
appl_random_mgr::appl_random_mgr() :
    appl_object()
{
}

//
//
//
appl_random_mgr::~appl_random_mgr()
{
}

/* end-of-file: appl_random_mgr.cpp */
