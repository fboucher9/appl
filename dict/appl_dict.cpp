/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <dict/appl_dict.h>

#include <appl_unused.h>

//
//
//
enum appl_status
    appl_dict::v_set(
        unsigned char const * const
            p_name_min,
        unsigned char const * const
            p_name_max,
        void * const
            p_value)
{
    appl_unused(
        p_name_min,
        p_name_max,
        p_value);

    return
        appl_status_not_implemented;

} // v_set()

//
//
//
enum appl_status
    appl_dict::v_get(
        unsigned char const * const
            p_name_min,
        unsigned char const * const
            p_name_max,
        void * * const
            r_value)
{
    appl_unused(
        p_name_min,
        p_name_max,
        r_value);

    return
        appl_status_not_implemented;

} // v_get()

//
//
//
appl_dict::appl_dict() :
    appl_object()
{
}

//
//
//
appl_dict::~appl_dict()
{
}

/* end-of-file: appl_dict.cpp */
