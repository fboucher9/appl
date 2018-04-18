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
    unsigned char const * const *
        p_arg_min;

    unsigned char const * const *
        p_arg_max;

}; /* struct appl_context_descriptor */

struct appl_context;

#if defined(__cplusplus)
extern "C" {
#endif /* #if defined(__cplusplus) */

enum appl_status
appl_context_create(
    struct appl_context_descriptor const * const
        p_client_descriptor,
    struct appl_context * * const
        r_context);

struct appl_object *
appl_context_parent(
    struct appl_context * const
        p_context);

struct appl_object const *
appl_context_const_parent(
    struct appl_context const * const
        p_context);

#if defined(__cplusplus)
} /* extern "C" */
#endif /* #if defined(__cplusplus) */

/* end-of-file: appl_context_handle.h */
