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

/* mutex */
struct appl_mutex;

struct appl_mutex_descriptor
{
    void *
        p_dummy;

}; /* struct appl_mutex_descriptor */

#if defined(__cplusplus)
extern "C" {
#endif /* #if defined(__cplusplus) */

enum appl_status
appl_mutex_create(
    struct appl_context * const
        p_context,
    struct appl_mutex_descriptor const * const
        p_mutex_descriptor,
    struct appl_mutex * * const
        r_mutex);

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

#if defined(__cplusplus)
} /* extern "C" */
#endif /* #if defined(__cplusplus) */

/* end-of-file: appl_mutex_handle.h */
