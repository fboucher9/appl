/* See LICENSE for license details */

/*

*/

#include <mutex/appl_mutex_defs.h>

#include <misc/appl_unused.h>

#if defined APPL_OS_LINUX

void InitializeCriticalSection(
    CRITICAL_SECTION * const p_private_windows)
{
    appl_unused( p_private_windows);
}
void DeleteCriticalSection(
    CRITICAL_SECTION * const p_private_windows)
{
    appl_unused( p_private_windows);
}
void EnterCriticalSection(
    CRITICAL_SECTION * const p_private_windows)
{
    appl_unused( p_private_windows);
}
void LeaveCriticalSection(
    CRITICAL_SECTION * const p_private_windows)
{
    appl_unused( p_private_windows);
}

#else /* #if defined APPL_OS_Xx */

int pthread_mutex_init(
    pthread_mutex_t * const p_private_linux,
    void * const p_attributes)
{
    appl_unused( p_private_linux, p_attributes);
    return -1;
}
int pthread_mutex_destroy(
    pthread_mutex_t * const p_private_linux)
{
    appl_unused( p_private_linux);
    return -1;
}
int pthread_mutex_lock(
    pthread_mutex_t * const p_private_linux)
{
    appl_unused( p_private_linux);
    return -1;
}
int pthread_mutex_unlock(
    pthread_mutex_t * const p_private_linux)
{
    appl_unused( p_private_linux);
    return -1;
}

#endif /* #if defined APPL_OS_Xx */

/* end-of-file: appl_mutex_defs.cpp */
