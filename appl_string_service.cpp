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

#include "appl_context.h"

//
//
//
enum appl_status
appl_string_service::s_create(
    struct appl_object_handle * const
        p_object_handle,
    unsigned char const * const
        p_buf_min,
    unsigned char const * const
        p_buf_max,
    unsigned long int const
        i_alloc_len,
    struct appl_string_handle * * const
        r_string_handle)
{
    struct appl_context_handle * const
        p_context_handle =
        appl_object_get_context_handle(
            p_object_handle);

    class appl_context * const
        p_context =
        appl_context::convert_handle(
            p_context_handle);

    return
        appl_string::s_create(
            p_context,
            p_buf_min,
            p_buf_max,
            i_alloc_len,
            reinterpret_cast<class appl_string * *>(
                r_string_handle));

} // s_create()

//
//
//
enum appl_status
appl_string_service::s_read(
    struct appl_string_handle const * const
        p_string_handle,
    unsigned char const * * const
        r_buf_min,
    unsigned char const * * const
        r_buf_max)
{
    class appl_string const * const
        p_string =
        appl_string::convert_const_handle(
            p_string_handle);

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
    struct appl_string_handle * const
        p_string_handle,
    unsigned char const * const
        p_buf_min,
    unsigned char const * const
        p_buf_max)
{
    class appl_string * const
        p_string =
        appl_string::convert_handle(
            p_string_handle);

    return
        p_string->v_write(
            p_buf_min,
            p_buf_max);

} // s_write()

/* end-of-file: appl_string_service.cpp */
