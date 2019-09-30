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
enum appl_markup_element_type
{
    /* Element contains data payload */
    appl_markup_element_type_data = 1,

    /* Element marks beginning of a recursive object */
    appl_markup_element_type_object = 2,

    /* Element marks beginning of a recursive array */
    appl_markup_element_type_array = 3,

    /* Element marks end of object or array */
    appl_markup_element_type_end = 4

}; /* enum appl_markup_element_type */

/*

*/
struct appl_markup_element
{
    enum appl_markup_element_type
        e_type;

#define APPL_PADDING (APPL_SIZEOF_INT)
#include <appl_padding.h>

    /* -- */

    struct appl_buf
        o_data;

}; /* struct appl_markup_element */

/*

*/
enum appl_markup_value_type
{
    appl_markup_value_type_data = 1,

    appl_markup_value_type_object = 2,

    appl_markup_value_type_array = 3

};

/*

*/
struct appl_markup_value
{
    struct appl_list
        o_list;

    /* -- */

    enum appl_markup_value_type
        e_type;

#define APPL_PADDING (APPL_SIZEOF_INT)
#include <appl_padding.h>

    /* -- */

    union appl_markup_value_data
    {
        struct appl_buf
            o_data;

        struct appl_list
            o_values;

    } u;

}; /* struct appl_markup_value */

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

enum appl_status
    appl_markup_value_create(
        struct appl_context * const
            p_context,
        struct appl_markup_value * * const
            r_instance);

enum appl_status
    appl_markup_value_destroy(
        struct appl_markup_value * const
            p_instance);

enum appl_status
    appl_markup_value_join(
        struct appl_markup_value * const
            p_parent,
        struct appl_markup_value * const
            p_child);

enum appl_status
    appl_markup_value_set_type(
        struct appl_markup_value * const
            p_instance,
        enum appl_markup_value_type const
            e_type);

enum appl_status
    appl_markup_value_set_data(
        struct appl_markup_value * const
            p_instance,
        struct appl_buf const * const
            p_data);

enum appl_markup_value_type
    appl_markup_value_get_type(
        struct appl_markup_value const * const
            p_instance);

struct appl_buf const *
    appl_markup_value_get_data(
        struct appl_markup_value const * const
            p_instance);

struct appl_markup_value *
    appl_markup_value_get_first(
        struct appl_markup_value const * const
            p_instance);

struct appl_markup_value *
    appl_markup_value_get_next(
        struct appl_markup_value const * const
            p_instance);

#include <appl_extern_c_end.h>

/* end-of-file: appl_markup_handle.h */
