/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_event_defs_h
{
    inc_appl_event_defs_h = 1
        /* Header file dependencies */
        /* ... */
}; /* enum guard_appl_event_defs_h */

#if defined APPL_OS_LINUX

#include <errno.h>

#include <pthread.h>

typedef struct CONDITION_VARIABLE
{
    void * pv_reserved[2u];

} CONDITION_VARIABLE;

#else /* #if defined APPL_OS_Xx */

#define WINVER 0x601

#define _WIN32_WINNT 0x601

#include <windows.h>

typedef struct pthread_cond_t
{
    void * pv_reserved[2u];

} pthread_cond_t;

#endif /* #if defined APPL_OS_Xx */

/* end-of-file: appl_event_defs.h */
