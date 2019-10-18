/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_predefines.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <list/appl_node.h>

#include <trace/appl_trace_client_list.h>

#include <misc/appl_unused.h>

//
//
//
appl_trace_client_list::appl_trace_client_list(
    struct appl_context * const
        p_context) :
    appl_object(
        p_context),
    m_clients(
        p_context)
{
}

//
//
//
appl_trace_client_list::~appl_trace_client_list()
{
}

//
//
//
enum appl_status
    appl_trace_client_list::f_init(void)
{
    return
        appl_raise_not_implemented();

} // f_init()

//
//
//
appl_size_t
    appl_trace_client_list::v_cleanup(void)
{
    return
        sizeof(
            class appl_trace_client_list);

} // v_cleanup()

//
//
//
enum appl_status
    appl_trace_client_list::f_register(
        struct appl_trace_descriptor const * const
            p_descriptor,
        struct appl_trace_client * * const
            r_instance)
{
    appl_unused(
        p_descriptor,
        r_instance);

    return
        appl_raise_not_implemented();

} // f_register()

//
//
//
enum appl_status
    appl_trace_client_list::f_unregister(
        struct appl_trace_client * const
            p_instance)
{
    appl_unused(
        p_instance);

    return
        appl_raise_not_implemented();

} // f_unregister()

/* end-of-file: appl_trace_client_list.cpp */
