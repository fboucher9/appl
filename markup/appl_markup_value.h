/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_markup_value_h
{
    inc_appl_markup_value_h = 1
        /* Header file dependencies */
        + inc_appl_status_h
        + inc_appl_predefines_h
        /* ... */
}; /* enum guard_appl_markup_value_h */

/* Predefine value handle */
struct appl_markup_value;

/*

*/
enum appl_markup_value_type
{
    /* Non visible value at top of tree */
    appl_markup_value_type_root = 0,

    /* Value is a leaf data only, no children */
    appl_markup_value_type_data = 1,

    /* Value is a parent, list of children no data */
    appl_markup_value_type_list = 2

}; /* enum appl_markup_value_type */

#include <appl_extern_c_begin.h>

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

enum appl_status
    appl_markup_value_get_data(
        struct appl_markup_value const * const
            p_instance,
        struct appl_buf * const
            r_buf);

struct appl_markup_value *
    appl_markup_value_get_first(
        struct appl_markup_value const * const
            p_instance);

struct appl_markup_value *
    appl_markup_value_get_next(
        struct appl_markup_value const * const
            p_instance);

struct appl_markup_value *
    appl_markup_value_get_parent(
        struct appl_markup_value const * const
            p_instance);

enum appl_status
    appl_markup_value_enumerate(
        struct appl_markup_value const * const
            p_instance,
        enum appl_status (* const p_callback)(
            void * const
                p_void,
            struct appl_markup_value * const
                p_instance),
        void * const
            p_void);

#include <appl_extern_c_end.h>

/* end-of-file: appl_markup_value.h */
