/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_clock_handle.h"

#include "appl_clock_service.h"

/*

*/
enum appl_status
appl_clock_read(
    struct appl_object_handle const * const
        p_object_handle,
    unsigned long int const
        i_time_freq,
    unsigned long int * const
        p_time_count)
{
    enum appl_status
        e_status;

    e_status =
        appl_clock_service::s_read(
            p_object_handle,
            i_time_freq,
            p_time_count);

    return
        e_status;

} /* appl_clock_read() */

/*

*/
enum appl_status
appl_clock_delay(
    struct appl_object_handle const * const
        p_object_handle,
    unsigned long int const
        i_time_freq,
    unsigned long int const
        i_time_count)
{
    enum appl_status
        e_status;

    e_status =
        appl_clock_service::s_delay(
            p_object_handle,
            i_time_freq,
            i_time_count);

    return
        e_status;

} /* appl_clock_delay() */

/* end-of-file: appl_clock_handle.cpp */
