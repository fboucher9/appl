/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_markup_object_h
{
    inc_appl_markup_object_h = 1
        /* Header file dependencies */
        + inc_appl_status_h
        + inc_appl_predefines_h
        /* ... */
}; /* enum guard_appl_markup_object_h */

/* Predefine markup object */
struct appl_markup_object;

/* Predefine markup element */
struct appl_markup_element;

/*

*/
struct appl_markup_enumerate_callback
{
    enum appl_status
        (* p_callback)(
            void * const
                p_void,
            struct appl_markup_element * const
                p_element);

    void * const
        p_void;

}; /* struct appl_markup_enumerate_callback */

#include <misc/appl_extern_c_begin.h>

enum appl_status
    appl_markup_object_create(
        struct appl_context * const
            p_context,
        struct appl_markup_object * * const
            r_instance);

enum appl_status
    appl_markup_object_destroy(
        struct appl_markup_object * const
            p_instance);

enum appl_status
    appl_markup_object_write(
        struct appl_markup_object * const
            p_instance,
        struct appl_markup_element const * const
            p_element);

enum appl_status
    appl_markup_object_enumerate(
        struct appl_markup_object const * const
            p_instance,
        struct appl_markup_enumerate_callback const * const
            p_callback);

#include <misc/appl_extern_c_end.h>

/* end-of-file: appl_markup_object.h */
