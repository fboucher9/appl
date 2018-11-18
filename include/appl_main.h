/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_main_h
{
    inc_appl_main_h =
        /* Header file dependency */
        inc_appl_status_h
};

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
