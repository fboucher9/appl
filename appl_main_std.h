/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_MAIN_STD_H
#error include appl_main_std.h once
#endif /* #if defined INC_APPL_MAIN_STD_H */

#define INC_APPL_MAIN_STD_H

/* Header file dependencies */
#if ! defined INC_APPL_STATUS_H
#error include appl_status.h before
#endif /* #if ! defined INC_APPL_STATUS_H */

/* Predefine */
struct appl_context;

/* Predefine */
struct appl_options;

#if defined __cplusplus
extern "C" {
#endif /* #if defined __cplusplus */

enum appl_status
    appl_main_std(
        unsigned char const * const * const
            p_arg_min,
        unsigned char const * const * const
            p_arg_max,
        enum appl_status (*
            p_main_callback)(
            struct appl_context * const
                p_context,
            struct appl_options const * const
                p_options));

#if defined __cplusplus
} /* extern "C" */
#endif /* #if defined __cplusplus */

/* end-of-file: appl_main_std.h */
