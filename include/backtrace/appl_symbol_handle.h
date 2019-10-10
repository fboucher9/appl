/* See LICENSE for license details */

/*

*/

/* Included. */
#define INC_APPL_SYMBOL_HANDLE_H

/* Reverse include guard */
enum guard_appl_symbol_handle_h
{
    inc_appl_symbol_handle_h = 1
        /* Header file dependencies */
        + inc_appl_status_h
};

/*

*/
struct appl_symbol_descriptor
{
    void *
        p_value;

}; /* struct appl_symbol_descriptor */

#include <misc/appl_extern_c_begin.h>

void
    appl_symbol_descriptor_init(
        struct appl_symbol_descriptor * const
            p_descriptor);

void
    appl_symbol_descriptor_set_value(
        struct appl_symbol_descriptor * const
            p_descriptor,
        void * const
            p_value);

enum appl_status
    appl_symbol_create(
        struct appl_symbol_descriptor const * const
            p_descriptor,
        struct appl_symbol * * const
            r_symbol);

enum appl_status
    appl_symbol_destroy(
        struct appl_symbol * const
            p_symbol);

enum appl_status
    appl_symbol_get_text_length(
        struct appl_symbol * const
            p_symbol,
        unsigned long int * const
            r_length);

enum appl_status
    appl_symbol_get_text(
        struct appl_symbol * const
            p_symbol,
        struct appl_buf * const
            p_buf_it);

#include <misc/appl_extern_c_end.h>

/* end-of-file: appl_symbol_handle.h */
