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

struct appl_context;

struct appl_object;

#if defined(__cplusplus)
extern "C" {
#endif /* #if defined(__cplusplus) */

enum appl_status
appl_object_destroy(
    struct appl_object * const
        p_object);

struct appl_context *
appl_object_get_context(
    struct appl_object const * const
        p_object);

#if defined(__cplusplus)
} /* extern "C" */
#endif /* #if defined(__cplusplus) */

/* end-of-file: appl_object_handle.h */
