/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_options.h"

//
//
//
enum appl_status
    appl_options::v_count(
        unsigned long int * const
            r_count) const
{
    static_cast<void>(
        r_count);
    return
        appl_status_not_implemented;
} // v_count()

//
//
//
enum appl_status
    appl_options::v_get(
        unsigned long int const
            i_index,
        unsigned char const * * const
            r_buf_min,
        unsigned char const * * const
            r_buf_max) const
{
    static_cast<void>(
        i_index);
    static_cast<void>(
        r_buf_min);
    static_cast<void>(
        r_buf_max);
    return
        appl_status_not_implemented;
} // v_get()

//
//
//
appl_options::appl_options() :
    appl_object()
{
}

//
//
//
appl_options::~appl_options()
{
}

/* end-of-file: appl_options.cpp */
