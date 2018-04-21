/* See LICENSE for license details */

/*

*/

#if ! defined APPL_DEBUG
#error include only from debug build
#endif /* #if ! defined APPL_DEBUG */

#if defined(INC_APPL_DEBUG_HANDLE_H)
#error include appl_debug_handle.h once
#endif /* #if defined(INC_APPL_DEBUG_HANDLE_H) */

#define INC_APPL_DEBUG_HANDLE_H

struct appl_object;

#if defined(__cplusplus)
extern "C" {
#endif /* #if defined(__cplusplus) */

enum appl_status
appl_debug_break(
    struct appl_object const * const
        p_object);

enum appl_status
appl_debug_print(
    struct appl_object const * const
        p_object,
    unsigned char const * const
        p_msg_min,
    unsigned char const * const
        p_msg_max);

enum appl_status
appl_debug_print0(
    struct appl_object const * const
        p_object,
    unsigned char const * const
        p_msg_0);

enum appl_status
appl_debug_print_number(
    struct appl_object const * const
        p_object,
    signed long int const
        i_value,
    int const
        e_flags,
    unsigned int const
        i_width);

#if defined(__cplusplus)
} /* extern "C" */
#endif /* #if defined(__cplusplus) */

/* end-of-file: appl_debug_handle.h */
