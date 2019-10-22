/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_predefines.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <unique/appl_unique_mgr.h>

#include <unique/appl_unique_std_mgr.h>

//
//
//
appl_unique_std_mgr::appl_unique_std_mgr(
    struct appl_context * const
        p_context) :
    appl_unique_mgr(
        p_context)
{
}

//
//
//
appl_unique_std_mgr::~appl_unique_std_mgr()
{
}

//
//
//
enum appl_status
    appl_unique_std_mgr::f_init(void)
{
    return
        appl_status_ok;

} // f_init()

//
//
//
appl_size_t
    appl_unique_std_mgr::v_cleanup(void)
{
    return
        sizeof(
            class appl_unique_std_mgr);

} // v_cleanup()

//
//
//
enum appl_status
    appl_unique_std_mgr::v_create(
        struct appl_unique * * const
            r_unique)
{
    return
        appl_unique_mgr::v_create(
            r_unique);

} // v_create()

//
//
//
enum appl_status
    appl_unique_std_mgr::v_destroy(
        struct appl_unique * const
            p_unique)
{
    return
        appl_unique_mgr::v_destroy(
            p_unique);

} // v_destroy()

/* end-of-file: appl_unique_std_mgr.cpp */
