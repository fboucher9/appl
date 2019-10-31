/* See LICENSE for license details */

/*

*/

#include <env/appl_env_w32_defs.h>

#include <misc/appl_unused.h>

#if defined APPL_OS_LINUX

DWORD
GetEnvironmentVariableA(
    char const * const
        lpName,
    char * const
        lpBuffer,
    DWORD const
        nSize)
{
    appl_unused(
        lpName,
        lpBuffer,
        nSize);

    return
        0;

}

int
SetEnvironmentVariableA(
    char const * const
        lpName,
    char const * const
        lpValue)
{
    appl_unused(
        lpName,
        lpValue);

    return
        0;

}

#endif /* #if defined APPL_OS_LINUX */

/* end-of-file: appl_env_w32_defs.cpp */
