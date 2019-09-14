/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <buf/appl_bits_service.h>

#include <appl_types.h>

#include <appl_object.h>

#include <buf/appl_bits.h>

#include <buf/appl_bits_handle.h>

#include <buf/appl_bits_base.h>

#include <buf/appl_bits_std.h>

#include <appl_context_handle.h>

#include <appl_allocator_handle.h>

//
//
//
enum appl_status
    appl_bits_service::s_create(
        struct appl_context * const
            p_context,
        struct appl_bits_descriptor const * const
            p_descriptor,
        struct appl_bits * * const
            r_bits)
{
    enum appl_status
        e_status;

    struct appl_allocator * const
        p_allocator =
        appl_context_get_allocator(
            p_context);

    class appl_bits_std *
        p_bits_std;

    e_status =
        appl_new(
            p_allocator,
            p_descriptor,
            &(
                p_bits_std));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_bits) =
            p_bits_std;
    }

    return
        e_status;

} // s_create()

//
//
//
enum appl_status
    appl_bits_service::s_destroy(
        struct appl_bits * const
            p_bits)
{
    enum appl_status
        e_status;

    struct appl_context * const
        p_context =
        p_bits->get_context();

    struct appl_allocator * const
        p_allocator =
        appl_context_get_allocator(
            p_context);

    e_status =
        appl_delete(
            p_allocator,
            p_bits);

    return
        e_status;

} // s_destroy()

//
//
//
enum appl_status
    appl_bits_service::s_read(
        struct appl_bits * const
            p_bits,
        unsigned char const
            i_count,
        unsigned long int * const
            r_value)
{
    enum appl_status
        e_status;

    e_status =
        p_bits->v_read(
            i_count,
            r_value);

    return
        e_status;

} // s_read()

//
//
//
enum appl_status
    appl_bits_service::s_write(
        struct appl_bits * const
            p_bits,
        unsigned char const
            i_count,
        unsigned long int const
            i_value)
{
    enum appl_status
        e_status;

    e_status =
        p_bits->v_write(
            i_count,
            i_value);

    return
        e_status;

} // s_write()

/* end-of-file: appl_bits_service.cpp */
