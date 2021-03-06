/* See LICENSE for license details */

/*

*/

/* Included. */
#define INC_APPL_CONTEXT_HANDLE_H

/* Reverse include guard */
enum guard_appl_context_handle_h
{
    inc_appl_context_handle_h =
        /* Header file dependencies */
        inc_appl_status_h
};

#include <misc/appl_extern_c_begin.h>

enum appl_status
appl_context_create(
    struct appl_context * * const
        r_context);

enum appl_status
appl_context_destroy(
    struct appl_context * const
        p_context);

struct appl_object *
appl_context_parent(
    struct appl_context * const
        p_context);

struct appl_object const *
appl_context_const_parent(
    struct appl_context const * const
        p_context);

struct appl_allocator *
appl_context_get_allocator(
    struct appl_context const * const
        p_context);

#include <misc/appl_extern_c_end.h>

/* end-of-file: appl_context_handle.h */
