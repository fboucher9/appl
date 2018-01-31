/* See LICENSE for license details */

/*

*/

#if defined(INC_APPL_OBJECT_HANDLE_H)
#error include appl_object_handle.h once
#endif /* #if defined(INC_APPL_OBJECT_HANDLE_H) */

#define INC_APPL_OBJECT_HANDLE_H

struct appl_object_handle;

struct appl_object_handle
{
    void *
        reserved;

}; /* struct appl_object_handle */

#if defined(__cplusplus)
extern "C" {
#endif /* #if defined(__cplusplus) */

enum appl_status
appl_object_destroy(
    struct appl_object_handle * const
        p_object);

#if defined(__cplusplus)
} /* extern "C" */
#endif /* #if defined(__cplusplus) */

/* end-of-file: appl_object_handle.h */
