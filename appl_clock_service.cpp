/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_clock_service.h"

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
enum appl_status
appl_clock_service::s_read(
    struct appl_context_handle * const
        p_context_handle,
    unsigned long int const
        i_time_freq,
    unsigned long int * const
        p_time_count)
{
    enum appl_status
        e_status;

    static_cast<void>(
        p_context_handle);
    static_cast<void>(
        i_time_freq);
    static_cast<void>(
        p_time_count);

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} // s_read()

//
//
//
enum appl_status
appl_clock_service::s_delay(
    struct appl_context_handle * const
        p_context_handle,
    unsigned long int const
        i_time_freq,
    unsigned long int const
        i_time_count)
{
    enum appl_status
        e_status;

    static_cast<void>(
        p_context_handle);
    static_cast<void>(
        i_time_freq);
    static_cast<void>(
        i_time_count);

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} // s_delay()

/* end-of-file: appl_clock_service.cpp */
