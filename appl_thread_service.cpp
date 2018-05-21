/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_thread_service.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_context.h>

#include <appl_thread_mgr.h>

#include <appl_thread_node.h>

#include <appl_property_types.h>

#include <appl_property.h>

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
enum appl_status
appl_thread_service::s_create(
    struct appl_object const * const
        p_object,
    struct appl_thread_property const * const
        p_thread_property,
    struct appl_thread * * const
        r_thread)
{
    enum appl_status
        e_status;

    struct appl_context * const
        p_context =
        p_object->get_context();

    class appl_thread_mgr * const
        p_thread_mgr =
        p_context->m_thread_mgr;

    struct appl_thread *
        p_thread_node;

    e_status =
        p_thread_mgr->v_create(
            p_context,
            p_thread_property,
            &(
                p_thread_node));

    if (
        appl_status_ok == e_status)
    {
        *(
            r_thread) =
            p_thread_node;
    }

    return
        e_status;

} // s_create()

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
appl_thread_service::s_start(
    struct appl_thread * const
        p_thread)
{
    enum appl_status
        e_status;

    e_status =
        p_thread->v_start();

    return
        e_status;

} // s_start()

//
//
//
enum appl_status
appl_thread_service::s_detach(
    struct appl_thread * const
        p_thread)
{
    enum appl_status
        e_status;

    e_status =
        p_thread->v_detach();

    return
        e_status;

} // s_detach()


//
//
//
enum appl_status
appl_thread_service::s_stop(
    struct appl_thread * const
        p_thread,
    unsigned long int const
        i_wait_freq,
    unsigned long int const
        i_wait_count,
    void * * const
        r_thread_result)
{
    enum appl_status
        e_status;

    e_status =
        p_thread->v_stop(
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
