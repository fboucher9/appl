/* See LICENSE for license details */

/*

*/

/* Assert configuration */
#include <misc/appl_assert_debug.h>

/* Reverse include guard */
enum guard_appl_debug_handle_h
{
    inc_appl_debug_handle_h =
        /* Header file dependencies */
        inc_appl_status_h
};

#include <misc/appl_extern_c_begin.h>

enum appl_status
appl_debug_break(
    struct appl_context * const
        p_context);

enum appl_status
appl_debug_print(
    struct appl_context * const
        p_context,
    unsigned char const * const
        p_msg_min,
    unsigned char const * const
        p_msg_max);

enum appl_status
appl_debug_print0(
    struct appl_context * const
        p_context,
    char const * const
        p_msg_0);

enum appl_status
appl_debug_print_number(
    struct appl_context * const
        p_context,
    signed long int const
        i_value,
    int const
        e_flags,
    unsigned int const
        i_width);

#include <misc/appl_extern_c_end.h>

/* end-of-file: appl_debug_handle.h */
