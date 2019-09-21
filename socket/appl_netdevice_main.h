/* See LICENSE for license details */

/*

*/

struct appl_context;

struct appl_options;

#include <appl_extern_c_begin.h>

enum appl_status
appl_netdevice_main(
    struct appl_context * const
        p_context,
    struct appl_options const * const
        p_options,
    unsigned long int const
        i_shift);

#include <appl_extern_c_end.h>

/* end-of-file: appl_netdevice_main.h */
