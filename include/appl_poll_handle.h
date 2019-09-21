/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_poll_handle_h
{
    inc_appl_poll_handle_h =
        /* Header file dependencies */
        inc_appl_status_h
};

#include <appl_extern_c_begin.h>

enum appl_status
appl_poll_create(
    struct appl_context * const
        p_context,
    struct appl_poll_descriptor const * const
        p_poll_descriptor,
    struct appl_poll * * const
        r_poll);

#include <appl_extern_c_end.h>

/* end-of-file: appl_poll_handle.h */
