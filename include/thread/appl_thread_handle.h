/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_thread_handle_h
{
    inc_appl_thread_handle_h =
        /* Header file dependencies */
        inc_appl_status_h
};

#include <misc/appl_extern_c_begin.h>

enum appl_status
appl_thread_create(
    struct appl_context * const
        p_context,
    struct appl_thread_descriptor const * const
        p_thread_descriptor,
    struct appl_thread * * const
        r_thread);

enum appl_status
appl_thread_destroy(
    struct appl_thread * const
        p_thread);

struct appl_object *
appl_thread_parent(
    struct appl_thread * const
        p_thread);

struct appl_object const *
appl_thread_const_parent(
    struct appl_thread const * const
        p_thread);

enum appl_status
appl_thread_interrupt(
    struct appl_thread * const
        p_thread);

#include <misc/appl_extern_c_end.h>

/* end-of-file: appl_thread_handle.h */
