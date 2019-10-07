/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_markup_handle_h
{
    inc_appl_markup_handle_h = 1
        /* Header file dependencies */
        + inc_appl_status_h
        + inc_appl_predefines_h
        + inc_appl_types_h
        + inc_appl_buf_h
        + inc_appl_list_h
}; /* enum guard_appl_markup_handle_h */

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

/*

*/
enum appl_markup_element_type
{
    /* Element contains data payload */
    appl_markup_element_type_data = 1,

    /* Element marks beginning of a recursive object */
    appl_markup_element_type_list = 2,

    /* Element marks end of object or array */
    appl_markup_element_type_end = 3

}; /* enum appl_markup_element_type */

/*

*/
struct appl_markup_element
{
    struct appl_buf
        o_data;

    /* -- */

    enum appl_markup_element_type
        e_type;

#define PADDING (APPL_SIZEOF_INT)
#include <appl_padding.h>

}; /* struct appl_markup_element */

#include <appl_extern_c_begin.h>

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

enum appl_status
    appl_markup_encoder_convert(
        struct appl_markup_encoder * const
            p_instance,
        struct appl_markup_value const * const
            p_value);

#include <appl_extern_c_end.h>

/* end-of-file: appl_markup_handle.h */
