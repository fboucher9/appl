/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_predefines.h>

#include <buf/appl_bytes_service.h>

#include <appl_object.h>

#include <buf/appl_buf.h>

#include <buf/appl_bytes_descriptor.h>

#include <buf/appl_bytes.h>

#include <buf/appl_bytes_base.h>

#include <buf/appl_bytes_custom.h>

#include <buf/appl_bytes_mem.h>

#include <misc/appl_unused.h>

#include <appl_heap_handle.h>

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
    enum appl_status
        e_status;

    if (
        appl_bytes_type_custom
        == p_descriptor->e_type)
    {
        class appl_bytes_custom *
            p_bytes_custom;

        e_status =
            appl_new(
                p_context,
                &(
                    p_descriptor->u.o_custom_descriptor),
                &(
                    p_bytes_custom));

        if (
            appl_status_ok
            == e_status)
        {
            *(
                r_instance) =
                p_bytes_custom;
        }
    }
    else if (
        appl_bytes_type_mem
        == p_descriptor->e_type)
    {
        class appl_bytes_mem *
            p_bytes_mem;

        e_status =
            appl_new(
                p_context,
                &(
                    p_descriptor->u.o_mem_descriptor),
                &(
                    p_bytes_mem));

        if (
            appl_status_ok
            == e_status)
        {
            *(
                r_instance) =
                p_bytes_mem;
        }
    }
    else
    {
        e_status =
            appl_status_fail;
    }

    return
        e_status;

} // s_create()

//
//
//
enum appl_status
    appl_bytes_service::s_destroy(
        struct appl_bytes * const
            p_bytes)
{
    enum appl_status
        e_status;

    struct appl_context * const
        p_context =
        p_bytes->get_context();

    e_status =
        appl_delete(
            p_context,
            p_bytes);

    return
        e_status;

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
    enum appl_status
        e_status;

    e_status =
        p_bytes->v_write_raw(
            p_buf);

    return
        e_status;

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
    enum appl_status
        e_status;

    e_status =
        p_bytes->v_write_int(
            i_count,
            i_value);

    return
        e_status;

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
    enum appl_status
        e_status;

    e_status =
        p_bytes->v_write_int8(
            i_value);

    return
        e_status;

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
    enum appl_status
        e_status;

    e_status =
        p_bytes->v_write_int16(
            i_value);

    return
        e_status;

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
    enum appl_status
        e_status;

    e_status =
        p_bytes->v_write_int24(
            i_value);

    return
        e_status;

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
    enum appl_status
        e_status;

    e_status =
        p_bytes->v_write_int32(
            i_value);

    return
        e_status;

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
    enum appl_status
        e_status;

    e_status =
        p_bytes->v_write_int64(
            i_value);

    return
        e_status;

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
    enum appl_status
        e_status;

    e_status =
        p_bytes->v_read_raw(
            p_buf);

    return
        e_status;

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
    enum appl_status
        e_status;

    e_status =
        p_bytes->v_read_int(
            i_count,
            r_value);

    return
        e_status;

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
    enum appl_status
        e_status;

    e_status =
        p_bytes->v_read_int8(
            r_value);

    return
        e_status;

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
    enum appl_status
        e_status;

    e_status =
        p_bytes->v_read_int16(
            r_value);

    return
        e_status;

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
    enum appl_status
        e_status;

    e_status =
        p_bytes->v_read_int24(
            r_value);

    return
        e_status;

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
    enum appl_status
        e_status;

    e_status =
        p_bytes->v_read_int32(
            r_value);

    return
        e_status;

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
    enum appl_status
        e_status;

    e_status =
        p_bytes->v_read_int64(
            r_value);

    return
        e_status;

} // s_read_int64()

/* end-of-file: appl_bytes_service.cpp */

