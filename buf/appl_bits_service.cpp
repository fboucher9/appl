/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_predefines.h>

#include <buf/appl_bits_service.h>

#include <appl_types.h>

#include <appl_object.h>

#include <buf/appl_bits.h>

#include <buf/appl_bits_handle.h>

#include <appl_buf.h>

#include <buf/appl_bits_descriptor.h>

#include <buf/appl_bits_base.h>

#include <buf/appl_bits_custom.h>

#include <buf/appl_bits_mem.h>

#include <appl_heap_handle.h>

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

    if (
        appl_bits_type_custom
        == p_descriptor->e_type)
    {
        class appl_bits_custom *
            p_bits_custom;

        e_status =
            appl_new(
                p_context,
                &(
                    p_descriptor->u.o_custom_descriptor),
                &(
                    p_bits_custom));

        if (
            appl_status_ok
            == e_status)
        {
            *(
                r_bits) =
                p_bits_custom;
        }
    }
    else if (
        appl_bits_type_mem
        == p_descriptor->e_type)
    {
        struct appl_bits_mem *
            p_bits_mem;

        e_status =
            appl_bits_mem_create(
                p_context,
                &(
                    p_descriptor->u.o_mem_descriptor),
                &(
                    p_bits_mem));

        if (
            appl_status_ok
            == e_status)
        {
            *(
                r_bits) =
                appl_bits_mem_parent(
                    p_bits_mem);
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
    appl_bits_service::s_destroy(
        struct appl_bits * const
            p_bits)
{
    enum appl_status
        e_status;

    struct appl_context * const
        p_context =
        p_bits->get_context();

    e_status =
        appl_delete(
            p_context,
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
