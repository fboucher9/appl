/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_download_handle.h>

#include <appl_object.h>

#include <appl_node.h>

#include <socket/appl_download_node.h>

#include <appl_unused.h>

//
//
//
appl_download::appl_download(
    struct appl_context * const
        p_context) :
    appl_node(
        p_context)
{
}

//
//
//
appl_download::~appl_download()
{
}

//
//
//
enum appl_status
    appl_download::v_cancel(void)
{
    return
        appl_raise_not_implemented();

} // v_cancel()

//
//
//
enum appl_status
    appl_download::v_wait(
        unsigned long int const
            i_timeout_msec,
        enum appl_download_status * const
            r_status)
{
    appl_unused(
        i_timeout_msec,
        r_status);

    return
        appl_raise_not_implemented();

} // v_wait()

/* end-of-file: appl_download_node.cpp */
