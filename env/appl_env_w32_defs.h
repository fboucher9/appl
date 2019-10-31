/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_env_w32_defs_h
{
    inc_appl_env_w32_defs_h = 1
        /* Header file dependencies */
        /* ... */
}; /* enum guard_appl_env_w32_defs_h */

#if defined APPL_OS_WINDOWS

#include <windows.h>

#endif /* #if defined APPL_OS_WINDOWS */

#if defined APPL_OS_LINUX

typedef unsigned int DWORD;

#include <misc/appl_extern_c_begin.h>

DWORD
GetEnvironmentVariableA(
    char const * const
        lpName,
    char * const
        lpBuffer,
    DWORD const
        nSize);

int
SetEnvironmentVariableA(
    char const * const
        lpName,
    char const * const
        lpValue);

#include <misc/appl_extern_c_end.h>

#endif /* #if defined APPL_OS_LINUX */

/* end-of-file: appl_env_w32_defs.h */
