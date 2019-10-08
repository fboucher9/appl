/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_markup_decoder_h
{
    inc_appl_markup_decoder_h = 1
        /* Header file dependencies */
        | inc_appl_status_h
        | inc_appl_predefines_h
        /* ... */
}; /* enum guard_appl_markup_decoder_h */

/* Predefine */
struct appl_markup_decoder;

/* Predefine */
struct appl_markup_element;

/*

*/
struct appl_markup_decoder_descriptor
{
    enum appl_status
        (* p_produce)(
            void * const
                p_void,
            struct appl_markup_element const * const
                p_element);

    void *
        p_void;

}; /* struct appl_markup_decoder_descriptor */

#include <misc/appl_extern_c_begin.h>

enum appl_status
appl_markup_decoder_create(
    struct appl_context * const
        p_context,
    struct appl_markup_decoder_descriptor const * const
        p_descriptor,
    struct appl_markup_decoder * * const
        r_instance);

enum appl_status
appl_markup_decoder_destroy(
    struct appl_markup_decoder * const
        p_instance);

enum appl_status
appl_markup_decoder_write(
    struct appl_markup_decoder * const
        p_instance,
    struct appl_buf * const
        p_buf_iterator);

#include <misc/appl_extern_c_end.h>

/* end-of-file: appl_markup_decoder.h */
