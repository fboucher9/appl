/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_unique_handle_h
{
    inc_appl_unique_handle_h = 1
        | inc_appl_status_h
}; /* enum guard_appl_unique_handle_h */

enum appl_status
appl_unique_pick(
    struct appl_context * const
        p_context,
    unsigned long int * const
        r_unique);

/* end-of-file: appl_unique_handle.h */
