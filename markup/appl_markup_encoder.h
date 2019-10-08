/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_markup_encoder_h
{
    inc_appl_markup_encoder_h = 1
        /* Header file dependencies */
        + inc_appl_status_h
        + inc_appl_predefines_h
        + inc_appl_types_h
        + inc_appl_buf_h
}; /* enum guard_appl_markup_encoder_h */

/* Predefine */
struct appl_markup_encoder;

/* Predefine */
struct appl_markup_element;

typedef
enum appl_status
(appl_markup_produce_callback)(
    void * const
        p_produce_void,
    unsigned char const
        i_value);

/*

*/
struct appl_markup_encoder_descriptor
{
    appl_markup_produce_callback *
        p_produce;

    void *
        p_produce_void;

}; /* struct appl_markup_encoder_descriptor */

#include <misc/appl_extern_c_begin.h>

enum appl_status
    appl_markup_encoder_create(
        struct appl_context * const
            p_context,
        struct appl_markup_encoder_descriptor const * const
            p_descriptor,
        struct appl_markup_encoder * * const
            r_instance);

enum appl_status
    appl_markup_encoder_destroy(
        struct appl_markup_encoder * const
            p_instance);

enum appl_status
    appl_markup_encoder_write(
        struct appl_markup_encoder * const
            p_instance,
        struct appl_markup_element const * const
            p_element);

#include <misc/appl_extern_c_end.h>

/* end-of-file: appl_markup_encoder.h */
