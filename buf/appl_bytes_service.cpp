/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_predefines.h>

#include <buf/appl_bytes_service.h>

#include <appl_unused.h>

//
//
//
enum appl_status
    appl_bytes_service::s_create(
        struct appl_context * const
            p_context,
        struct appl_bytes_descriptor const * const
            p_descriptor,
        struct appl_bytes * * const
            r_instance)
{
    appl_unused(
        p_context,
        p_descriptor,
        r_instance);

    return
        appl_raise_not_implemented();

} // s_create()

//
//
//
enum appl_status
    appl_bytes_service::s_destroy(
        struct appl_bytes * const
            p_bytes)
{
    appl_unused(
        p_bytes);

    return
        appl_raise_not_implemented();

} // s_destroy()

//
//
//
enum appl_status
    appl_bytes_service::s_write_raw(
        struct appl_bytes * const
            p_bytes,
        struct appl_buf const * const
            p_buf)
{
    appl_unused(
        p_bytes,
        p_buf);

    return
        appl_raise_not_implemented();

} // s_write_raw()

//
//
//
enum appl_status
    appl_bytes_service::s_write_int(
        struct appl_bytes * const
            p_bytes,
        unsigned char const
            i_count,
        appl_ull_t const
            i_value)
{
    appl_unused(
        p_bytes,
        i_count,
        i_value);

    return
        appl_raise_not_implemented();

} // s_write_int()

//
//
//
enum appl_status
    appl_bytes_service::s_write_int8(
        struct appl_bytes * const
            p_bytes,
        unsigned char const
            i_value)
{
    appl_unused(
        p_bytes,
        i_value);

    return
        appl_raise_not_implemented();

} // s_write_int8()

//
//
//
enum appl_status
    appl_bytes_service::s_write_int16(
        struct appl_bytes * const
            p_bytes,
        unsigned short int const
            i_value)
{
    appl_unused(
        p_bytes,
        i_value);

    return
        appl_raise_not_implemented();

} // s_write_int16()

//
//
//
enum appl_status
    appl_bytes_service::s_write_int24(
        struct appl_bytes * const
            p_bytes,
        unsigned long int const
            i_value)
{
    appl_unused(
        p_bytes,
        i_value);

    return
        appl_raise_not_implemented();

} // s_write_int24()

//
//
//
enum appl_status
    appl_bytes_service::s_write_int32(
        struct appl_bytes * const
            p_bytes,
        unsigned long int const
            i_value)
{
    appl_unused(
        p_bytes,
        i_value);

    return
        appl_raise_not_implemented();

} // s_write_int32()

//
//
//
enum appl_status
    appl_bytes_service::s_write_int64(
        struct appl_bytes * const
            p_bytes,
        appl_ull_t const
            i_value)
{
    appl_unused(
        p_bytes,
        i_value);

    return
        appl_raise_not_implemented();

} // s_write_int64()

//
//
//
enum appl_status
    appl_bytes_service::s_read_raw(
        struct appl_bytes * const
            p_bytes,
        struct appl_buf const * const
            p_buf)
{
    appl_unused(
        p_bytes,
        p_buf);

    return
        appl_raise_not_implemented();

} // s_read_raw()

//
//
//
enum appl_status
    appl_bytes_service::s_read_int(
        struct appl_bytes * const
            p_bytes,
        unsigned char const
            i_count,
        appl_ull_t * const
            r_value)
{
    appl_unused(
        p_bytes,
        i_count,
        r_value);

    return
        appl_raise_not_implemented();

} // s_read_int()

//
//
//
enum appl_status
    appl_bytes_service::s_read_int8(
        struct appl_bytes * const
            p_bytes,
        unsigned char * const
            r_value)
{
    appl_unused(
        p_bytes,
        r_value);

    return
        appl_raise_not_implemented();

} // s_read_int8()

//
//
//
enum appl_status
    appl_bytes_service::s_read_int16(
        struct appl_bytes * const
            p_bytes,
        unsigned short int * const
            r_value)
{
    appl_unused(
        p_bytes,
        r_value);

    return
        appl_raise_not_implemented();

} // s_read_int16()

//
//
//
enum appl_status
    appl_bytes_service::s_read_int24(
        struct appl_bytes * const
            p_bytes,
        unsigned long int * const
            r_value)
{
    appl_unused(
        p_bytes,
        r_value);

    return
        appl_raise_not_implemented();

} // s_read_int24()

//
//
//
enum appl_status
    appl_bytes_service::s_read_int32(
        struct appl_bytes * const
            p_bytes,
        unsigned long int * const
            r_value)
{
    appl_unused(
        p_bytes,
        r_value);

    return
        appl_raise_not_implemented();

} // s_read_int32()

//
//
//
enum appl_status
    appl_bytes_service::s_read_int64(
        struct appl_bytes * const
            p_bytes,
        appl_ull_t * const
            r_value)
{
    appl_unused(
        p_bytes,
        r_value);

    return
        appl_raise_not_implemented();

} // s_read_int64()

/* end-of-file: appl_bytes_service.cpp */

