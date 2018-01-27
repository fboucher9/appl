/* See LICENSE for license details */

#include "appl.h"

enum appl_status
appl_main(
    struct appl_context * const
        p_context,
    struct appl_options * const
        p_options,
    int * const
        p_exit_code)
{
    enum appl_status
        e_status;

    (void)(
        p_context);
    (void)(
        p_options);

    *(
        p_exit_code) =
        0;

    e_status =
        appl_status_success;

    return
        e_status;

}
