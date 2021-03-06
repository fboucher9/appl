/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <dict/appl_dict_service.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <dict/appl_dict.h>

#include <list/appl_list.h>

#include <dict/appl_dict_std.h>

#include <context/appl_context_handle.h>

//
//
//
enum appl_status
appl_dict_service::s_create(
    struct appl_context * const
        p_context,
    struct appl_dict * * const
        r_dict)
{
    enum appl_status
        e_status;

    class appl_dict_std *
        p_dict_std;

    struct appl_allocator * const
        p_allocator =
        appl_context_get_allocator(
            p_context);

    e_status =
        appl_dict_std::s_create(
            p_allocator,
            &(
                p_dict_std));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_dict) =
            p_dict_std;
    }

    return
        e_status;

} // s_create()

//
//
//
enum appl_status
appl_dict_service::s_destroy(
    struct appl_context * const
        p_context,
    struct appl_dict * const
        p_dict)
{
    struct appl_allocator * const
        p_allocator =
        appl_context_get_allocator(
            p_context);

    return
        appl_dict_std::s_destroy(
            p_allocator,
            p_dict);

} // s_destroy()

//
//
//
struct appl_object *
appl_dict_service::s_parent(
    struct appl_dict * const
        p_dict)
{
    return
        p_dict;

} // s_parent()

//
//
//
enum appl_status
appl_dict_service::s_set(
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
        p_dict->v_set(
            p_name_min,
            p_name_max,
            p_value);

} // s_set()

//
//
//
enum appl_status
appl_dict_service::s_get(
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
        p_dict->v_get(
            p_name_min,
            p_name_max,
            r_value);

} // s_get()

/* end-of-file: appl_dict_service.cpp */
