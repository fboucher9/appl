/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_mutex_handle_h
{
    inc_appl_mutex_handle_h =
        /* Header file dependencies */
        inc_appl_status_h
};

struct appl_mutex_descriptor
{
    void *
        p_dummy;

}; /* struct appl_mutex_descriptor */

#include <misc/appl_extern_c_begin.h>

enum appl_status
appl_mutex_create(
    struct appl_context * const
        p_context,
    struct appl_mutex_descriptor const * const
        p_mutex_descriptor,
    struct appl_mutex * * const
        r_mutex);

enum appl_status
appl_mutex_destroy(
    struct appl_mutex * const
        p_mutex);

struct appl_object *
appl_mutex_parent(
    struct appl_mutex * const
        p_mutex);

struct appl_object const *
appl_mutex_const_parent(
    struct appl_mutex const * const
        p_mutex);

enum appl_status
appl_mutex_lock(
    struct appl_mutex * const
        p_mutex);

enum appl_status
appl_mutex_unlock(
    struct appl_mutex * const
        p_mutex);

enum appl_status
appl_mutex_sync(
    struct appl_mutex * const
        p_mutex,
    enum appl_status (*
        p_sync_callback)(
        void * const
            p_sync_context),
    void * const
        p_sync_context);

#include <misc/appl_extern_c_end.h>

/* end-of-file: appl_mutex_handle.h */
