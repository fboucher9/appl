/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_clock_service.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_clock.h>

#include <appl_context.h>

#include <appl_object_handle.h>

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
enum appl_status
appl_clock_service::s_read(
    struct appl_context const * const
        p_context,
    unsigned long int const
        i_time_freq,
    unsigned long int * const
        p_time_count)
{
    enum appl_status
        e_status;

    class appl_clock * const
        p_clock =
        p_context->m_clock;

    e_status =
        p_clock->v_read(
            i_time_freq,
            p_time_count);

    return
        e_status;

} // s_read()

//
//
//
enum appl_status
appl_clock_service::s_delay(
    struct appl_context const * const
        p_context,
    unsigned long int const
        i_time_freq,
    unsigned long int const
        i_time_count)
{
    enum appl_status
        e_status;

    class appl_clock * const
        p_clock =
        p_context->m_clock;

    e_status =
        p_clock->v_delay(
            i_time_freq,
            i_time_count);

    return
        e_status;

} // s_delay()

/* end-of-file: appl_clock_service.cpp */
