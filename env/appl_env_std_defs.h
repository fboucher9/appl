/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_env_std_defs_h
{
    inc_appl_env_std_defs_h = 1
        /* Header file dependencies */
        /* ... */
}; /* enum guard_appl_env_std_defs_h */

#if defined APPL_OS_LINUX

#include <string.h>

#include <stdlib.h>

#else /* #if defined APPL_OS_Xx */

#include <misc/appl_extern_c_begin.h>

char const *
getenv(
    char const * const
        p_name);

int
setenv(
    char const * const
        p_name,
    char const * const
        p_value,
    int const
        b_overwrite);

#include <misc/appl_extern_c_end.h>

#endif /* #if defined APPL_OS_Xx */

/* end-of-file: appl_env_std_defs.h */
