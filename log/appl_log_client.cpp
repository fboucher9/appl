/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_node.h>

#include <log/appl_log_client.h>

#include <appl_heap_handle.h>

//
//
//
enum appl_status
    appl_log_client::s_create(
        struct appl_context * const
            p_context,
        struct appl_log_client_descriptor const * const
            p_descriptor,
        struct appl_log_client * * const
            r_client)
{
    enum appl_status
        e_status;

    e_status =
        appl_new(
            p_context,
            p_descriptor,
            r_client);

    return
        e_status;

} // s_create()

//
//
//
enum appl_status
    appl_log_client::s_destroy(
        struct appl_log_client * const
            p_client)
{
    enum appl_status
        e_status;

    struct appl_context * const
        p_context =
        p_client->get_context();

    e_status =
        appl_delete(
            p_context,
            p_client);

    return
        e_status;

} // s_destroy()

//
//
//
appl_log_client::appl_log_client(
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
appl_log_client::~appl_log_client()
{
}

//
//
//
enum appl_status
    appl_log_client::f_init(
        struct appl_log_client_descriptor const * const
            p_descriptor)
{
    enum appl_status
        e_status;

    m_descriptor.p_callback =
        p_descriptor->p_callback;

    m_descriptor.p_callback_context =
        p_descriptor->p_callback_context;

    e_status =
        appl_status_ok;

    return
        e_status;

} // f_init()

//
//
//
appl_size_t
    appl_log_client::v_cleanup(void)
{
    return
        sizeof(struct appl_log_client);

} // v_cleanup()

//
//
//
void
    appl_log_client::v_dispatch(
        struct appl_log_record const * const
            p_log_record) const
{
    if (
        m_descriptor.p_callback)
    {
        (*(m_descriptor.p_callback))(
            m_descriptor.p_callback_context,
            p_log_record);
    }

} // v_dispatch()

