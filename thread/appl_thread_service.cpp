/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_predefines.h>

#include <thread/appl_thread_service.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <context/appl_context.h>

#include <thread/appl_thread_mgr.h>

#include <thread/appl_thread_node.h>

#include <property/appl_property_types.h>

#include <property/appl_property.h>

/* Assert compiler */
#include <misc/appl_assert_cplusplus.h>

//
//
//
enum appl_status
appl_thread_service::s_create(
    struct appl_context * const
        p_context,
    struct appl_thread_descriptor const * const
        p_thread_descriptor,
    struct appl_thread * * const
        r_thread)
{
    enum appl_status
        e_status;

    class appl_thread_mgr *
        p_thread_mgr;

    e_status =
        p_context->v_thread_mgr(
            &(
                p_thread_mgr));

    if (
        appl_status_ok
        == e_status)
    {
        struct appl_thread *
            p_thread_node;

        e_status =
            p_thread_mgr->v_create_node(
                p_thread_descriptor,
                &(
                    p_thread_node));

        if (
            appl_status_ok == e_status)
        {
            *(
                r_thread) =
                p_thread_node;
        }
    }

    return
        e_status;

} // s_create()

//
//
//
enum appl_status
appl_thread_service::s_destroy(
    struct appl_thread * const
        p_thread)
{
    enum appl_status
        e_status;

    struct appl_context * const
        p_context =
        p_thread->get_context();

    class appl_thread_mgr *
        p_thread_mgr;

    e_status =
        p_context->v_thread_mgr(
            &(
                p_thread_mgr));

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            p_thread_mgr->v_destroy_node(
                p_thread);
    }

    return
        e_status;

} // s_destroy()

//
//
//
struct appl_object *
appl_thread_service::s_convert(
    struct appl_thread * const
        p_thread)
{
    return
        p_thread;

}

//
//
//
struct appl_object const *
appl_thread_service::s_convert(
    struct appl_thread const * const
        p_thread)
{
    return
        p_thread;

}

//
//
//
enum appl_status
appl_thread_service::s_interrupt(
    struct appl_thread * const
        p_thread)
{
    enum appl_status
        e_status;

    e_status =
        p_thread->v_interrupt();

    return
        e_status;

} // s_interrupt()

/* end-of-file: appl_thread_service.cpp */
