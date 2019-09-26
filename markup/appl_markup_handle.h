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
}; /* enum guard_appl_markup_handle_h */

/*

*/
struct appl_markup_encoder_descriptor
{
    enum appl_status
        (* p_produce)(
            void * const
                p_produce_void,
            unsigned char const
                i_value);

    void *
        p_produce_void;

}; /* struct appl_markup_encoder_descriptor */

/*

*/
enum appl_markup_type
{
    /* Element contains data payload */
    appl_markup_type_data = 1,

    /* Element marks beginning of a recursive object */
    appl_markup_type_object = 2,

    /* Element marks beginning of a recursive array */
    appl_markup_type_array = 3,

    /* Element marks end of object or array */
    appl_markup_type_end = 4

}; /* enum appl_markup_type */

/*

*/
struct appl_markup_element
{
    enum appl_markup_type
        e_type;

#define APPL_PADDING (APPL_SIZEOF_INT)
#include <appl_padding.h>

    /* -- */

    struct appl_buf
        o_data;

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

#include <appl_extern_c_end.h>

/* end-of-file: appl_markup_handle.h */
