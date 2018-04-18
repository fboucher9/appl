/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_env.h"

#include "appl_unused.h"

//
//
//
enum appl_status
    appl_env::v_get(
        unsigned char const * const
            p_name_min,
        unsigned char const * const
            p_name_max,
        struct appl_string * * const
            r_string)
{
    appl_unused(
        p_name_min,
        p_name_max,
        r_string);
    return
        appl_status_not_implemented;
} // v_get()

//
//
//
enum appl_status
    appl_env::v_set(
        unsigned char const * const
            p_name_min,
        unsigned char const * const
            p_name_max,
        unsigned char const * const
            p_value_min,
        unsigned char const * const
            p_value_max)
{
    appl_unused(
        p_name_min,
        p_name_max,
        p_value_min,
        p_value_max);
    return
        appl_status_not_implemented;
} // v_set()

//
//
//
appl_env::appl_env() :
    appl_object()
{
}

//
//
//
appl_env::~appl_env()
{
}

/* end-of-file: appl_env.cpp */
