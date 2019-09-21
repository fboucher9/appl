/* See LICENSE for license details */

/*

*/

/* Included. */
#define INC_APPL_ONCE_H

/* Reverse include guard. */
enum guard_appl_once_h
{
    inc_appl_once_h = 1
        /* Header file dependencies */
        + inc_appl_status_h
};

/*

*/
struct appl_once
{
#if defined APPL_OS_LINUX
    pthread_once_t
        o_lnx_impl;
#else /* #if defined APPL_OS_LINUX */
    LONG volatile
        o_w32_impl;
#endif /* #if defined APPL_OS_LINUX */
}; /* struct appl_once */

#if defined APPL_OS_LINUX
#define APPL_ONCE_INIT PTHREAD_ONCE_INIT
#else /* #if defined APPL_OS_LINUX */
#define APPL_ONCE_INIT 0
#endif /* #if defined APPL_OS_LINUX */

#include <appl_extern_c_begin.h>

enum appl_status
appl_once_dispatch(
    struct appl_once * const
        p_once,
    void (* const
        p_once_callback)(void));

#include <appl_extern_c_end.h>

/* end-of-file: appl_once.h */
