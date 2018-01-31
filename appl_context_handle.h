/* See LICENSE for license details */

/*

*/

#if defined(INC_APPL_CONTEXT_HANDLE_H)
#error include appl_context_handle.h once
#endif /* #if defined(INC_APPL_CONTEXT_HANDLE_H) */

#define INC_APPL_CONTEXT_HANDLE_H

struct appl_context_handle;

struct appl_context_descriptor
{
    char const * const *
        p_arg_min;

    char const * const *
        p_arg_max;

}; /* struct appl_context_descriptor */

struct appl_context_handle
{
    struct appl_object_handle
        o_object_handle;

}; /* struct appl_context_handle */

#if defined(__cplusplus)
extern "C" {
#endif /* #if defined(__cplusplus) */

enum appl_status
appl_context_create(
    struct appl_context_descriptor const * const
        p_client_descriptor,
    struct appl_context_handle * * const
        r_context_handle);

#if defined(__cplusplus)
} /* extern "C" */
#endif /* #if defined(__cplusplus) */

/* end-of-file: appl_context_handle.h */
