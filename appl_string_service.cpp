/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_string_service.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_buf.h"

#include "appl_string.h"

#include "appl_object_handle.h"

#include "appl_string_handle.h"

#include "appl_context.h"

//
//
//
enum appl_status
appl_string_service::s_create(
    struct appl_object const * const
        p_object,
    unsigned char const * const
        p_buf_min,
    unsigned char const * const
        p_buf_cur,
    unsigned char const * const
        p_buf_max,
    unsigned long int const
        i_alloc_len,
    struct appl_string * * const
        r_string)
{
    struct appl_context * const
        p_context =
        p_object->get_context();

    return
        appl_string::s_create(
            p_context,
            p_buf_min,
            p_buf_cur,
            p_buf_max,
            i_alloc_len,
            r_string);

} // s_create()

//
//
//
enum appl_status
appl_string_service::s_read(
    struct appl_string const * const
        p_string,
    unsigned char const * * const
        r_buf_min,
    unsigned char const * * const
        r_buf_max)
{
    return
        p_string->v_read(
            r_buf_min,
            r_buf_max);

} // s_read()

//
//
//
enum appl_status
appl_string_service::s_write(
    struct appl_string * const
        p_string,
    unsigned char const * const
        p_buf_min,
    unsigned char const * const
        p_buf_max)
{
    return
        p_string->v_write(
            p_buf_min,
            p_buf_max);

} // s_write()

/* end-of-file: appl_string_service.cpp */
