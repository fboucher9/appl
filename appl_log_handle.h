/* See LICENSE for license details */

/*

Module: appl_log_handle.h

Description:

*/

/* Reverse include guard */
#if defined INC_APPL_LOG_HANDLE_H
#error include appl_log_handle.h once
#endif /* #if defined INC_APPL_LOG_HANDLE_H */

#define INC_APPL_LOG_HANDLE_H

/* Header file dependency */
#if ! defined INC_APPL_STATUS_H
#error include appl_status.h before
#endif /* #if ! defined INC_APPL_STATUS_H */

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
