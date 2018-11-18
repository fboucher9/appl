/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_MAIN_H
#error include appl_main.h once
#endif /* #if defined INC_APPL_MAIN_H */

#define INC_APPL_MAIN_H

/* Header file dependency */
#if ! defined INC_APPL_STATUS_H
#error include appl_status.h before
#endif /* #if ! defined INC_APPL_STATUS_H */

struct appl_context;

struct appl_options;

#if defined(__cplusplus)
extern "C" {
#endif /* #if defined(__cplusplus) */

int
    appl_main(
        int const
            i_arg_count,
        char * * const
            p_arg_vector,
        enum appl_status (*
            p_main_callback)(
            struct appl_context * const
                p_context,
            struct appl_options const * const
                p_options));

#if defined(__cplusplus)
} /* extern "C" */
#endif /* #if defined(__cplusplus) */

/* end-of-file: appl_main.h */
