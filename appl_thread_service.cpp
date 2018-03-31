/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_thread_service.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_context.h"

#include "appl_thread_mgr.h"

#include "appl_thread_node.h"

#include "appl_buf.h"

#include "appl_property_types.h"

#include "appl_property.h"

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
enum appl_status
appl_thread_service::s_create(
    struct appl_context_handle * const
        p_context_handle,
    struct appl_property_handle const * const
        p_property_handle,
    struct appl_thread_handle * * const
        r_thread_handle)
{
    enum appl_status
        e_status;

    class appl_context * const
        p_context =
        appl_context::convert_handle(
            p_context_handle);

    class appl_property const * const
        p_property =
        appl_property::convert_const_handle(
            p_property_handle);

    class appl_thread_mgr *
        p_thread_mgr;

    p_thread_mgr =
        p_context->m_thread_mgr;

    class appl_thread_node *
        p_thread_node;

    e_status =
        p_thread_mgr->v_create(
            p_context,
            p_property,
            &(
                p_thread_node));

    if (
        appl_status_ok == e_status)
    {
        *(
            r_thread_handle) =
            p_thread_node->get_handle();
    }

    return
        e_status;

} // s_create()

//
//
//
enum appl_status
appl_thread_service::s_start(
    struct appl_thread_handle * const
        p_thread_handle)
{
    enum appl_status
        e_status;

    class appl_thread_node * const
        p_thread_node =
        appl_thread_node::convert_handle(
            p_thread_handle);

    e_status =
        p_thread_node->v_start();

    return
        e_status;

} // s_start()

//
//
//
enum appl_status
appl_thread_service::s_stop(
    struct appl_thread_handle * const
        p_thread_handle,
    unsigned long int const
        i_wait_freq,
    unsigned long int const
        i_wait_count,
    void * * const
        r_thread_result)
{
    enum appl_status
        e_status;

    class appl_thread_node * const
        p_thread_node =
        appl_thread_node::convert_handle(
            p_thread_handle);

    e_status =
        p_thread_node->v_stop(
            i_wait_freq,
            i_wait_count,
            r_thread_result);

    return
        e_status;

} // s_stop()

//
//
//
enum appl_status
appl_thread_service::s_interrupt(
    struct appl_thread_handle * const
        p_thread_handle)
{
    enum appl_status
        e_status;

    class appl_thread_node * const
        p_thread_node =
        appl_thread_node::convert_handle(
            p_thread_handle);

    e_status =
        p_thread_node->v_interrupt();

    return
        e_status;

} // s_interrupt()

/* end-of-file: appl_thread_service.cpp */
