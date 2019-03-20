/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_env_main_h
{
    inc_appl_env_main_h = 1
        /* Header file dependencies */
        + inc_appl_status_h
};

/* Included. */
#define INC_APPL_ENV_MAIN_H

/* Predefine */
struct appl_context;

/* Predefine */
struct appl_options;

#if defined __cplusplus
extern "C" {
#endif /* #if defined __cplusplus */

enum appl_status
    appl_env_main(
        struct appl_context * const
            p_context,
        struct appl_options const * const
            p_options,
        unsigned long int const
            i_shift);

#if defined __cplusplus
} /* extern "C" */
#endif /* #if defined __cplusplus */

/* end-of-file: appl_env_main.h */
