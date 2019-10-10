/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_object_handle_h
{
    inc_appl_object_handle_h =
        /* Header file dependency */
        inc_appl_status_h
};

#include <misc/appl_extern_c_begin.h>

struct appl_context *
appl_object_get_context(
    struct appl_object const * const
        p_object);

#include <misc/appl_extern_c_end.h>

/* end-of-file: appl_object_handle.h */
