/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_library_handle.h>

#include <appl_library_service.h>

/*

*/
enum appl_status
appl_library_create(
    struct appl_context * const
        p_context,
    struct appl_library_descriptor const * const
        p_library_descriptor,
    struct appl_library * * const
        r_library)
{
    return
        appl_library_service::s_create(
            p_context,
            p_library_descriptor,
            r_library);

} /* create() */

/*

*/
enum appl_status
appl_library_destroy(
    struct appl_library * const
        p_library)
{
    return
        appl_library_service::s_destroy(
            p_library);

} /* destroy() */

/*

*/
struct appl_object *
appl_library_parent(
    struct appl_library * const
        p_library)
{
    return
        appl_library_service::s_parent(
            p_library);

} /* parent() */

/*

*/
struct appl_object const *
appl_library_const_parent(
    struct appl_library const * const
        p_library)
{
    return
        appl_library_service::s_const_parent(
            p_library);

} /* const_parent() */

/*

*/
enum appl_status
appl_library_query(
    struct appl_library const * const
        p_library,
    unsigned char const * const
        p_symbol_name_min,
    unsigned char const * const
        p_symbol_name_max,
    void * * const
        r_symbol)
{
    return
        appl_library_service::s_query(
            p_library,
            p_symbol_name_min,
            p_symbol_name_max,
            r_symbol);

} /* query() */

/* end-of-file: appl_library_handle.cpp */
