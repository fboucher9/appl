/* See LICENSE for license details */

/*

*/

#if defined APPL_OS_WINDOWS

#include <windows.h>

#else /* #if defined APPL_OS_WINDOWS */

typedef int MMRESULT;
typedef unsigned int UINT;
typedef unsigned int DWORD;
typedef int BOOL;
enum BOOL_
{
    FALSE = 0,
    TRUE = 1
};
typedef struct LARGE_INTEGER
{
    appl_ull_t QuadPart;
} LARGE_INTEGER;
static MMRESULT const TIMERR_NOERROR = 0;
static MMRESULT timeBeginPeriod( UINT const uPeriod)
{
    appl_unused( uPeriod);
    return -1;
}
static MMRESULT timeEndPeriod( UINT const uPeriod)
{
    appl_unused( uPeriod);
    return -1;
}
static BOOL QueryPerformanceFrequency( LARGE_INTEGER * pliFreq)
{
    appl_unused( pliFreq);
    return FALSE;
}
static BOOL QueryPerformanceCounter( LARGE_INTEGER * pliCount)
{
    appl_unused( pliCount);
    return FALSE;
}
static DWORD SleepEx(UINT uiCount, BOOL bAlertable)
{
    appl_unused(uiCount, bAlertable);
    return 0;
}

#endif /* #if defined APPL_OS_WINDOWS */

/* end-of-file: appl_clock_w32_defs.h */
