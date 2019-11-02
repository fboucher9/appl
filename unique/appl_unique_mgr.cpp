/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_predefines.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <unique/appl_unique_mgr.h>

#include <misc/appl_unused.h>

//
//
//
appl_unique_mgr::appl_unique_mgr(
    struct appl_context * const
        p_context) :
    appl_object(
        p_context)
{
}

//
//
//
appl_unique_mgr::~appl_unique_mgr()
{
}

//
//
//
enum appl_status
    appl_unique_mgr::f_init(void)
{
    return
        appl_status_ok;

} // f_init()

//
//
//
appl_size_t
    appl_unique_mgr::v_cleanup(void)
{
    return
        sizeof(
            class appl_unique_mgr);

} // v_cleanup()

//
//
//
enum appl_status
    appl_unique_mgr::v_pick(
        unsigned long int * const
            r_unique)
{
    appl_unused(
        r_unique);

    return
        appl_raise_not_implemented();

} // v_create()

/* end-of-file: appl_unique_mgr.cpp */
