/* See LICENSE for license details */

/*

*/

#include <env/appl_env_std_defs.h>

#include <misc/appl_unused.h>

#if defined APPL_OS_WINDOWS

//
//
//
char const *
getenv(
    char const * const
        p_name)
{
    appl_unused(
        p_name);

    return
        0;

} // getenv()

//
//
//
int
setenv(
    char const * const
        p_name,
    char const * const
        p_value,
    int const
        b_overwrite)
{
    appl_unused(
        p_name,
        p_value,
        b_overwrite);

    return
        -1;

} // setenv()

#endif /* #if defined APPL_OS_WINDOWS */

/* end-of-file: appl_env_std_defs.cpp */
