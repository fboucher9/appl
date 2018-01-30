/* See LICENSE for license details */

#include <stdio.h>

#include "appl.h"

enum appl_status
appl_main(
    struct appl_context_handle * const
        p_context,
    struct appl_options_descriptor * const
        p_options_descriptor,
    int * const
        p_exit_code)
{
    enum appl_status
        e_status;

    /* Print the argument list */
    struct appl_buf *
        p_buf_it;

    p_buf_it =
        p_options_descriptor->p_buf_min;

    unsigned int
        argi;

    argi = 0;

    while (
        p_buf_it < p_options_descriptor->p_buf_max)
    {
        printf(
            "[%3u] [%.*s]\n",
            argi,
            (int)(
                p_buf_it->o_max.pc_uchar
                - p_buf_it->o_min.pc_uchar),
            (char const *)(
                p_buf_it->o_min.pc_uchar));

        argi ++;

        p_buf_it ++;
    }

    (void)(
        p_context);

    *(
        p_exit_code) =
        0;

    e_status =
        appl_status_ok;

    return
        e_status;

}
