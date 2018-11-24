/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <options/appl_options.h>

#include <appl_unused.h>

//
//
//
enum appl_status
    appl_options::v_count(
        unsigned long int * const
            r_count) const
{
    appl_unused(
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
    appl_unused(
        i_index,
        r_buf_min,
        r_buf_max);
    return
        appl_status_not_implemented;
} // v_get()

//
//
//
enum appl_status
    appl_options::v_write(
        unsigned char const * const
            p_buf_min,
        unsigned char const * const
            p_buf_max,
        unsigned long int * const
            p_count,
        char * const
            p_ready)
{
    appl_unused(
        p_buf_min,
        p_buf_max,
        p_count,
        p_ready);

    return
        appl_status_not_implemented;

} // v_write()

//
//
//
enum appl_status
    appl_options::v_append_argument(
        unsigned char const * const
            p_buf_min,
        unsigned char const * const
            p_buf_max)
{
    appl_unused(
        p_buf_min,
        p_buf_max);

    return
        appl_status_not_implemented;

} // v_append_argument()

//
//
//
enum appl_status
    appl_options::v_reset(void)
{
    return
        appl_status_not_implemented;

} // v_reset()

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
