/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <dict/appl_dict_handle.h>

#include <dict/appl_dict_service.h>

/*

*/
enum appl_status
appl_dict_create(
    struct appl_context * const
        p_context,
    struct appl_dict * * const
        r_dict)
{
    return
        appl_dict_service::s_create(
            p_context,
            r_dict);

} /* _create() */

/*

*/
enum appl_status
appl_dict_destroy(
    struct appl_context * const
        p_context,
    struct appl_dict * const
        p_dict)
{
    return
        appl_dict_service::s_destroy(
            p_context,
            p_dict);

} /* _destroy() */

/*

*/
struct appl_object *
appl_dict_parent(
    struct appl_dict * const
        p_dict)
{
    return
        appl_dict_service::s_parent(
            p_dict);

} /* _parent() */

/*

*/
enum appl_status
appl_dict_set(
    struct appl_dict * const
        p_dict,
    unsigned char const * const
        p_name_min,
    unsigned char const * const
        p_name_max,
    void * const
        p_value)
{
    return
        appl_dict_service::s_set(
            p_dict,
            p_name_min,
            p_name_max,
            p_value);

} /* _set() */

/*

*/
enum appl_status
appl_dict_get(
    struct appl_dict * const
        p_dict,
    unsigned char const * const
        p_name_min,
    unsigned char const * const
        p_name_max,
    void * * const
        r_value)
{
    return
        appl_dict_service::s_get(
            p_dict,
            p_name_min,
            p_name_max,
            r_value);

} /* _get() */

/* end-of-file: appl_dict_handle.cpp */
