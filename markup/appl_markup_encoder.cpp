/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_predefines.h>

#include <appl_types.h>

#include <appl_buf.h>

#include <appl_list.h>

#include <markup/appl_markup_encoder.h>

#include <appl_unused.h>

//
//
//
enum appl_status
    appl_markup_encoder_create(
        struct appl_context * const
            p_context,
        struct appl_markup_encoder_descriptor const * const
            p_descriptor,
        struct appl_markup_encoder * * const
            r_instance)
{
    appl_unused(
        p_context,
        p_descriptor,
        r_instance);

    return
        appl_raise_not_implemented();

} // appl_markup_encoder_create()

//
//
//
enum appl_status
    appl_markup_encoder_destroy(
        struct appl_markup_encoder * const
            p_instance)
{
    appl_unused(
        p_instance);

    return
        appl_raise_not_implemented();

} // appl_markup_encoder_destroy()

//
//
//
enum appl_status
    appl_markup_encoder_write(
        struct appl_markup_encoder * const
            p_instance,
        struct appl_markup_element const * const
            p_element)
{
    appl_unused(
        p_instance,
        p_element);

    return
        appl_raise_not_implemented();

} // appl_markup_encoder_write()

/* end-of-file: appl_markup_encoder.cpp */
