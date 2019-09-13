/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <buf/appl_bits_handle.h>

#include <buf/appl_bits_service.h>

//
//
//
enum appl_status
    appl_bits_create(
        struct appl_context * const
            p_context,
        struct appl_bits_descriptor const * const
            p_descriptor,
        struct appl_bits * * const
            r_bits)
{
    enum appl_status
        e_status;

    e_status =
        appl_bits_service::s_create(
            p_context,
            p_descriptor,
            r_bits);

    return
        e_status;

} // appl_bits_create()

//
//
//
enum appl_status
    appl_bits_destroy(
        struct appl_bits * const
            p_bits)
{
    enum appl_status
        e_status;

    e_status =
        appl_bits_service::s_destroy(
            p_bits);

    return
        e_status;

} // appl_bits_destroy()

//
//
//
enum appl_status
    appl_bits_read(
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
        appl_bits_service::s_read(
            p_bits,
            i_count,
            r_value);

    return
        e_status;

} // appl_bits_read()

//
//
//
enum appl_status
    appl_bits_write(
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
        appl_bits_service::s_write(
            p_bits,
            i_count,
            i_value);

    return
        e_status;

} // appl_bits_write()

/* end-of-file: appl_bits_handle.cpp */
