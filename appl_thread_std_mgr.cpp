/* See LICENSE for license details */

/*

*/

#include <pthread.h>

#include "appl_status.h"

#include "appl_object.h"

#include "appl_thread_mgr.h"

#include "appl_thread_std_mgr.h"

#include "appl_thread_node.h"

#include "appl_thread_std_node.h"

enum appl_status
    appl_thread_std_mgr::create_instance(
        class appl_client * const
            p_client,
        class appl_thread_mgr * * const
            r_thread_mgr)
{
    enum appl_status
        e_status;

    class appl_thread_std_mgr *
        p_thread_std_mgr;

    static_cast<void>(
        p_client);

    p_thread_std_mgr =
        new
            class appl_thread_std_mgr;

    if (
        p_thread_std_mgr)
    {
        *(r_thread_mgr) =
            p_thread_std_mgr;

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

}

appl_thread_std_mgr::appl_thread_std_mgr() :
    appl_thread_mgr()
{
}

appl_thread_std_mgr::~appl_thread_std_mgr()
{
}

enum appl_status
    appl_thread_std_mgr::create_node(
        class appl_client * const
            p_client,
        struct appl_thread_descriptor const * const
            p_thread_descriptor,
        class appl_thread_node * * const
            r_thread_node)
{
    enum appl_status
        e_status;

    e_status =
        appl_thread_std_node::create_instance(
            p_client,
            p_thread_descriptor,
            r_thread_node);

    return
        e_status;

} // create_node()

/* end-of-file: appl_thread_std_mgr.cpp */
