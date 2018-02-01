/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_object_handle.h"

#include "appl_thread_handle.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_context.h"

#include "appl_thread_mgr.h"

#include "appl_thread_node.h"

/*

*/
enum appl_status
appl_thread_create(
    struct appl_context_handle * const
        p_context_handle,
    struct appl_thread_descriptor const * const
        p_thread_descriptor,
    struct appl_thread_handle * * const
        r_thread_handle)
{
    enum appl_status
        e_status;

    class appl_context *
        p_context;

    p_context =
        reinterpret_cast<class appl_context *>(
            p_context_handle);

    class appl_thread_mgr *
        p_thread_mgr;

    p_thread_mgr =
        p_context->m_thread_mgr;

    class appl_thread_node *
        p_thread_node;

    e_status =
        p_thread_mgr->create_node(
            p_context,
            p_thread_descriptor,
            &(
                p_thread_node));

    if (
        appl_status_ok == e_status)
    {
        *(
            r_thread_handle) =
            reinterpret_cast<struct appl_thread_handle *>(
                p_thread_node);
    }

    return
        e_status;

} /* appl_thread_create() */

/*

*/
enum appl_status
appl_thread_detach(
    struct appl_thread_handle * const
        p_thread_handle)
{
    enum appl_status
        e_status;

    class appl_thread_node *
        p_thread_node;

    p_thread_node =
        reinterpret_cast<class appl_thread_node *>(
            p_thread_handle);

    e_status =
        p_thread_node->detach();

    return
        e_status;

} /* appl_thread_detach() */

/*

*/
enum appl_status
appl_thread_wait_result(
    struct appl_thread_handle * const
        p_thread_handle,
    void * * const
        r_thread_result)
{
    enum appl_status
        e_status;

    class appl_thread_node *
        p_thread_node;

    p_thread_node =
        reinterpret_cast<class appl_thread_node *>(
            p_thread_handle);

    e_status =
        p_thread_node->wait_result(
            r_thread_result);

    return
        e_status;

} /* appl_thread_wait_result() */

/* end-of-file: appl_thread_handle.cpp */
