/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_predefines.h>

#include <unique/appl_unique_handle.h>

#include <unique/appl_unique_service.h>

//
//
//
enum appl_status
appl_unique_create(
    struct appl_context * const
        p_context,
    struct appl_unique * * const
        r_unique)
{
    return
        appl_unique_service::s_create(
            p_context,
            r_unique);

} // appl_unique_create()

//
//
//
enum appl_status
appl_unique_destroy(
    struct appl_unique * const
        p_unique)
{
    return
        appl_unique_service::s_destroy(
            p_unique);

} // appl_unique_destroy()

//
//
//
struct appl_object *
appl_unique_parent(
    struct appl_unique * const
        p_unique)
{
    return
        appl_unique_service::s_parent(
            p_unique);

} // appl_unique_parent()

//
//
//
struct appl_object const *
appl_unique_const_parent(
    struct appl_unique const * const
        p_unique)
{
    return
        appl_unique_service::s_const_parent(
            p_unique);

} // appl_unique_const_parent()

//
//
//
unsigned long int
appl_unique_get(
    struct appl_unique const * const
        p_unique)
{
    return
        appl_unique_service::s_get(
            p_unique);

} // appl_unique_get()

/* end-of-file: appl_unique_handle.cpp */
