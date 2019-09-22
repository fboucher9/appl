/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_predefines.h>

#include <appl_types.h>

#include <appl_object.h>

#include <buf/appl_bytes.h>

#include <appl_unused.h>

//
//
//
appl_bytes::appl_bytes(
    struct appl_context * const
        p_context) :
    appl_object(
        p_context)
{
}

//
//
//
appl_bytes::~appl_bytes()
{
}

//
//
//
enum appl_status
    appl_bytes::v_write_raw(
        struct appl_buf const * const
            p_buf)
{
    appl_unused(
        p_buf);

    return
        appl_raise_not_implemented();

} // v_write_raw()

//
//
//
enum appl_status
    appl_bytes::v_write_int(
        unsigned char const
            i_count,
        appl_ull_t const
            i_value)
{
    appl_unused(
        i_count,
        i_value);

    return
        appl_raise_not_implemented();

} // v_write_int()

//
//
//
enum appl_status
    appl_bytes::v_write_int8(
        unsigned char const
            i_value)
{
    appl_unused(
        i_value);

    return
        appl_raise_not_implemented();

} // v_write_int8()

//
//
//
enum appl_status
    appl_bytes::v_write_int16(
        unsigned short int const
            i_value)
{
    appl_unused(
        i_value);

    return
        appl_raise_not_implemented();

} // v_write_int16()

//
//
//
enum appl_status
    appl_bytes::v_write_int24(
        unsigned long int const
            i_value)
{
    appl_unused(
        i_value);

    return
        appl_raise_not_implemented();

} // v_write_int24()

//
//
//
enum appl_status
    appl_bytes::v_write_int32(
        unsigned long int const
            i_value)
{
    appl_unused(
        i_value);

    return
        appl_raise_not_implemented();

} // v_write_int32()

//
//
//
enum appl_status
    appl_bytes::v_write_int64(
        appl_ull_t const
            i_value)
{
    appl_unused(
        i_value);

    return
        appl_raise_not_implemented();

} // v_write_int64()

//
//
//
enum appl_status
    appl_bytes::v_read_raw(
        struct appl_buf const * const
            p_buf)
{
    appl_unused(
        p_buf);

    return
        appl_raise_not_implemented();

} // v_read_raw()

//
//
//
enum appl_status
    appl_bytes::v_read_int(
        unsigned char const
            i_count,
        appl_ull_t * const
            r_value)
{
    appl_unused(
        i_count,
        r_value);

    return
        appl_raise_not_implemented();

} // v_read_int()

//
//
//
enum appl_status
    appl_bytes::v_read_int8(
        unsigned char * const
            r_value)
{
    appl_unused(
        r_value);

    return
        appl_raise_not_implemented();

} // v_read_int8()

//
//
//
enum appl_status
    appl_bytes::v_read_int16(
        unsigned short int * const
            r_value)
{
    appl_unused(
        r_value);

    return
        appl_raise_not_implemented();

} // v_read_int16()

//
//
//
enum appl_status
    appl_bytes::v_read_int24(
        unsigned long int * const
            r_value)
{
    appl_unused(
        r_value);

    return
        appl_raise_not_implemented();

} // v_read_int24()

//
//
//
enum appl_status
    appl_bytes::v_read_int32(
        unsigned long int * const
            r_value)
{
    appl_unused(
        r_value);

    return
        appl_raise_not_implemented();

} // v_read_int32()

//
//
//
enum appl_status
    appl_bytes::v_read_int64(
        appl_ull_t * const
            r_value)
{
    appl_unused(
        r_value);

    return
        appl_raise_not_implemented();

} // v_read_int64()

/* end-of-file: appl_bytes.cpp */
