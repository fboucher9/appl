/* See LICENSE for license details */

/*

Module: appl_chunk.cpp

Description:

    See appl_chunk.h for more details.

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <chunk/appl_chunk.h>

#include <appl_unused.h>

//
//
//
enum appl_status
appl_chunk::v_write(
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

} // v_write()

//
//
//
enum appl_status
appl_chunk::v_length(
    unsigned long int * const
        r_length) const
{
    appl_unused(
        r_length);

    return
        appl_status_not_implemented;

} // v_length()

//
//
//
enum appl_status
appl_chunk::v_read(
    unsigned char * const
        p_buf_min,
    unsigned char * const
        p_buf_max) const
{
    appl_unused(
        p_buf_min,
        p_buf_max);

    return
        appl_status_not_implemented;

} // v_read()

//
//
//
enum appl_status
appl_chunk::v_reset(void)
{
    return
        appl_status_not_implemented;

} // v_reset()

//
//
//
appl_chunk::appl_chunk(
    struct appl_context * const
        p_context) :
    appl_object(
        p_context)
{
}

//
//
//
appl_chunk::~appl_chunk()
{
}

/* end-of-file: appl_chunk.cpp */
