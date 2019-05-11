/* See LICENSE for license details */

/*

*/

enum guard_appl_random_main_h
{
    inc_appl_random_main_h = 1
        + inc_appl_status_h
};

#define INC_APPL_RANDOM_MAIN_H

#if defined __cplusplus
extern "C" {
#endif /* #if defined __cplusplus */

enum appl_status
    appl_random_main(
        struct appl_context * const
            p_context,
        struct appl_options const * const
            p_options,
        unsigned long int const
            i_shift);

#if defined __cplusplus
} /* extern "C" */
#endif /* #if defined __cplusplus */

/* end-of-file: appl_random_main.h */
