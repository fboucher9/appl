/* See LICENSE for license details */

/*

Module: appl.c

Description:

    Dispatch of Application Library entry-points.

*/

#if ! defined APPL_BUILD_DLL

#include <appl_status.h>

#include <appl_main_std.h>

#include <appl_main.h>

#include <appl_convert.h>

/*

*/
int
main(
    int argc,
    char * * argv)
{
    int
        i_exit_code;

    enum appl_status
        e_status;

    unsigned char * const *
        p_arg_min;

    unsigned char * const *
        p_arg_max;

    p_arg_min =
        appl_convert::to_uchar_ptr_table(
            argv);

    p_arg_max =
        p_arg_min + argc;

    e_status =
        appl_main_std(
            p_arg_min,
            p_arg_max,
            &(
                appl_main));

    if (
        appl_status_ok
        == e_status)
    {
        i_exit_code =
            0;
    }
    else
    {
        i_exit_code =
            1;
    }

    return
        i_exit_code;

} /* main() */

#else /* #if ! defined APPL_BUILD_DLL */

typedef void appl_dummy;

#endif /* #if ! defined APPL_BUILD_DLL */

/* end-of-file: appl.cpp */
