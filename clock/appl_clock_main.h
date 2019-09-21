/* See LICENSE for license details */

/*

*/

enum guard_appl_clock_main_h
{
    inc_appl_clock_main_h = 1
        + inc_appl_status_h
};

#include <appl_extern_c_begin.h>

enum appl_status
    appl_clock_main(
        struct appl_context * const
            p_context,
        struct appl_options const * const
            p_options,
        unsigned long int const
            i_shift);

#include <appl_extern_c_end.h>

/* end-of-file: appl_clock_main.h */
