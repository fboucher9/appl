/* See LICENSE for license details */

/*

*/

#if defined INC_APPL_LIBRARY_HANDLE_H
#error include appl_library_handle.h once
#endif /* #if defined INC_APPL_LIBRARY_HANDLE_H */

#define INC_APPL_LIBRARY_HANDLE_H

struct appl_context;

struct appl_library;

struct appl_library_descriptor
{
    unsigned char const *
        p_name_min;

    unsigned char const *
        p_name_max;

}; /* struct appl_library_descriptor */

#if defined __cplusplus
extern "C" {
#endif /* #if defined __cplusplus */

enum appl_status
appl_library_create(
    struct appl_context * const
        p_context,
    struct appl_library_descriptor const * const
        p_library_descriptor,
    struct appl_library * * const
        r_library);

enum appl_status
appl_library_destroy(
    struct appl_library * const
        p_library);

struct appl_object *
appl_library_parent(
    struct appl_library * const
        p_library);

struct appl_object const *
appl_library_const_parent(
    struct appl_library const * const
        p_library);

enum appl_status
appl_library_query(
    struct appl_library const * const
        p_library,
    unsigned char const * const
        p_symbol_name_min,
    unsigned char const * const
        p_symbol_name_max,
    void * * const
        r_symbol);

#if defined __cplusplus
} /* extern "C" */
#endif /* #if defined __cplusplus */

/* end-of-file: appl_library_handle.h */