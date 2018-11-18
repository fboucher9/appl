/* See LICENSE for license details */

/*

Module: appl_log_handle.h

Description:

*/

/* Reverse include guard */
enum guard_appl_log_handle_h
{
    inc_appl_log_handle_h =
        /* Header file dependency */
        inc_appl_status_h
};

struct appl_context;

enum appl_log_level
{
    appl_log_level_error = 1,

    appl_log_level_warning = 2,

    appl_log_level_info = 3

};

#if defined __cplusplus
extern "C" {
#endif /* #if defined __cplusplus */

enum appl_status
    appl_log_print(
        struct appl_context * const
            p_context,
        enum appl_log_level const
            e_level,
        unsigned char const * const
            p_message_min,
        unsigned char const * const
            p_message_max);

#if defined __cplusplus
} /* extern "C" */
#endif /* #if defined __cplusplus */

/* end-of-file: appl_log_handle.h */
