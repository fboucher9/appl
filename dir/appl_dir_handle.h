/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_dir_handle_h
{
    inc_appl_dir_handle_h = 1
        /* Header file dependencies */
        + inc_appl_status_h
        + inc_appl_predefines_h
        /* ... */
}; /* enum guard_appl_dir_handle_h */

/* Predefine descriptor */
struct appl_dir_descriptor;

#include <appl_extern_c_begin.h>

enum appl_status
    appl_dir_enumerate(
        struct appl_context * const
            p_context,
        struct appl_dir_descriptor const * const
            p_descriptor);

#include <appl_extern_c_end.h>

/* end-of-file: appl_dir_handle.h */
