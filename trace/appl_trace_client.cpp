/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_predefines.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <list/appl_node.h>

#include <trace/appl_trace_handle.h>

#include <trace/appl_trace_client.h>

//
//
//
appl_trace_client::appl_trace_client(
    struct appl_context * const
        p_context) :
    appl_node(
        p_context),
    m_descriptor()
{
}

//
//
//
appl_trace_client::~appl_trace_client()
{
}

//
//
//
enum appl_status
    appl_trace_client::f_init(
        struct appl_trace_descriptor const * const
            p_trace_descriptor)
{
    m_descriptor =
        *(
            p_trace_descriptor);

    return
        appl_status_ok;

} // f_init()

//
//
//
appl_size_t
    appl_trace_client::v_cleanup(void)
{
    return
        sizeof(
            struct appl_trace_client);

} // v_cleanup()

//
//
//
enum appl_status
    appl_trace_client::f_notify(
        struct appl_trace_message const * const
            p_trace_message)
{
    enum appl_status
        e_status;

    if (
        m_descriptor.p_callback)
    {
        e_status =
            (*(m_descriptor.p_callback))(
                m_descriptor.p_void,
                p_trace_message);
    }
    else
    {
        e_status =
            appl_status_ok;
    }

    return
        e_status;

} // f_notify()

/* end-of-file: appl_trace_client.cpp */
