/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_mutex_defs_h
{
    inc_appl_mutex_defs_h = 1
        /* Header file dependencies */
        /* ... */
}; /* enum guard_appl_mutex_defs_h */

#if defined APPL_OS_LINUX

#include <errno.h>

#include <pthread.h>

struct CRITICAL_SECTION
{
    void * pv_reserved[2u];
};

#include <misc/appl_extern_c_begin.h>

void InitializeCriticalSection(
    CRITICAL_SECTION * const p_private_windows);
void DeleteCriticalSection(
    CRITICAL_SECTION * const p_private_windows);
void EnterCriticalSection(
    CRITICAL_SECTION * const p_private_windows);
void LeaveCriticalSection(
    CRITICAL_SECTION * const p_private_windows);

#include <misc/appl_extern_c_end.h>

#else /* #if defined APPL_OS_Xx */

#undef WINVER
#define WINVER 0x601

#undef _WIN32_WINNT
#define _WIN32_WINNT 0x601

#include <windows.h>

struct pthread_mutex_t
{
    void * pv_reserved[2u];
};

#include <misc/appl_extern_c_begin.h>

int pthread_mutex_init(
    pthread_mutex_t * const p_private_linux,
    void * const p_attributes);
int pthread_mutex_destroy(
    pthread_mutex_t * const p_private_linux);
int pthread_mutex_lock(
    pthread_mutex_t * const p_private_linux);
int pthread_mutex_unlock(
    pthread_mutex_t * const p_private_linux);

#include <misc/appl_extern_c_end.h>

#endif /* #if defined APPL_OS_Xx */

/* end-of-file: appl_mutex_defs.h */
