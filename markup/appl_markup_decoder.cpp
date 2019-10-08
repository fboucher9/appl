/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_predefines.h>

#include <markup/appl_markup_decoder.h>

#include <appl_unused.h>

//
//
//
enum appl_status
appl_markup_decoder_create(
    struct appl_context * const
        p_context,
    struct appl_markup_decoder_descriptor const * const
        p_descriptor,
    struct appl_markup_decoder * * const
        r_instance)
{
    appl_unused(
        p_context,
        p_descriptor,
        r_instance);

    return
        appl_raise_not_implemented();

} // _create()

//
//
//
enum appl_status
appl_markup_decoder_destroy(
    struct appl_markup_decoder * const
        p_instance)
{
    appl_unused(
        p_instance);

    return
        appl_raise_not_implemented();

} // _destroy()

//
//
//
enum appl_status
appl_markup_decoder_write(
    struct appl_markup_decoder * const
        p_instance,
    struct appl_buf * const
        p_buf_iterator)
{
    appl_unused(
        p_instance,
        p_buf_iterator);

    return
        appl_raise_not_implemented();

} // _write()

/* end-of-file: appl_markup_decoder.cpp */
