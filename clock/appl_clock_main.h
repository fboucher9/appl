/* See LICENSE for license details */

/*

*/

enum guard_appl_clock_main_h
{
    inc_appl_clock_main_h = 1
        + inc_appl_status_h
};

#if defined __cplusplus
extern "C" {
#endif /* #if defined __cplusplus */

enum appl_status
    appl_clock_main(
        struct appl_context * const
            p_context,
        struct appl_options const * const
            p_options,
        unsigned long int const
            i_shift);

#if defined __cplusplus
} /* extern "C" */
#endif /* #if defined __cplusplus */

/* end-of-file: appl_clock_main.h */
