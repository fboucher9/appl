/* See LICENSE for license details */

/*

*/

#if defined APPL_OS_LINUX
#include <pthread.h>
#else /* #if defined APPL_OS_LINUX */
#include <windows.h>
#endif /* #if defined APPL_OS_LINUX */

#include <appl_status.h>

#include <thread/appl_once.h>

/*

*/
#if defined APPL_OS_LINUX
static
enum appl_status
    appl_once_dispatch_lnx(
        struct appl_once * const
            p_once,
        void (* const
            p_once_callback)(void))
{
    enum appl_status
        e_status;

    int
        i_pthread_result;

    i_pthread_result =
        pthread_once(
            &(p_once->o_lnx_impl),
            p_once_callback);

    if (
        0 == i_pthread_result)
    {
        e_status =
            appl_status_ok;
    }
    else
    {
        e_status =
            appl_status_fail;
    }

    return
        e_status;

} /* appl_once_dispatch_lnx() */
#endif /* #if defined APPL_OS_LINUX */

/*

*/
#if defined APPL_OS_WINDOWS
static
enum appl_status
    appl_once_dispatch_w32(
        struct appl_once * const
            p_once,
        void (* const
            p_once_callback)(void))
{
    enum appl_status
        e_status;

    bool
        b_continue;

    b_continue =
        true;

    while (
        b_continue)
    {
        LONG
            lOriginalValue;

        lOriginalValue =
            InterlockedCompareExchange(
                &(p_once->o_w32_impl),
                1,
                0);

        if (
            0
            == lOriginalValue)
        {
            (*p_once_callback)();

            InterlockedExchange(
                &(p_once->o_w32_impl),
                2);

            b_continue =
                false;
        }
        else if (
            1
            == lOriginalValue)
        {
            Sleep(1);
        }
        else if (
            2
            == lOriginalValue)
        {
            b_continue =
                false;
        }
    }

    e_status =
        appl_status_ok;

    return
        e_status;

} /* appl_once_dispatch_w32() */
#endif /* #if defined APPL_OS_WINDOWS */

/*

*/
enum appl_status
appl_once_dispatch(
    struct appl_once * const
        p_once,
    void (* const
        p_once_callback)(void))
{
    enum appl_status
        e_status;

#if defined APPL_OS_LINUX
    e_status =
        appl_once_dispatch_lnx(
            p_once,
            p_once_callback);
#else /* #if defined APPL_OS_LINUX */
    e_status =
        appl_once_dispatch_w32(
            p_once,
            p_once_callback);
#endif /* #if defined APPL_OS_LINUX */

    return
        e_status;

} /* appl_once_dispatch() */

/* end-of-file: appl_once.cpp */
