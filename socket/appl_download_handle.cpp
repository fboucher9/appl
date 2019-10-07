/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <socket/appl_download_handle.h>

#include <socket/appl_download_service.h>

//
//
//
enum appl_status
    appl_download_create(
        struct appl_context * const
            p_context,
        struct appl_download_descriptor const * const
            p_descriptor,
        struct appl_download * * const
            r_handle)
{
    return
        appl_download_service::s_create(
            p_context,
            p_descriptor,
            r_handle);

} // appl_download_create()

//
//
//
enum appl_status
    appl_download_destroy(
        struct appl_download * const
            p_handle)
{
    return
        appl_download_service::s_destroy(
            p_handle);

} // appl_download_destroy()

//
//
//
enum appl_status
    appl_download_cancel(
        struct appl_download * const
            p_handle)
{
    return
        appl_download_service::s_cancel(
            p_handle);

} // appl_download_cancel()

//
//
//
enum appl_status
    appl_download_wait(
        struct appl_download * const
            p_handle,
        unsigned long int const
            i_timeout_msec,
        enum appl_download_status * const
            r_status)
{
    return
        appl_download_service::s_wait(
            p_handle,
            i_timeout_msec,
            r_status);

} // appl_download_wait()

/* end-of-file: appl_download_handle.cpp */
