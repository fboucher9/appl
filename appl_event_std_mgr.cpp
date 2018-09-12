/* See LICENSE for license details */

/*

*/

#if defined APPL_OS_LINUX

#include <pthread.h>

#else /* #if defined APPL_OS_LINUX */

#include <windows.h>

#endif /* #if defined APPL_OS_LINUX */

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_event_mgr.h>

#include <appl_event_std_mgr.h>

#include <appl_event_node.h>

#include <appl_event_impl.h>

#include <appl_event_std_node.h>

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
enum appl_status
    appl_event_std_mgr::s_create(
        struct appl_context * const
            p_context,
        class appl_event_mgr * * const
            r_event_mgr)
{
    enum appl_status
        e_status;

    class appl_event_std_mgr *
        p_event_std_mgr;

    e_status =
        appl_object::s_create(
            p_context,
            (&
                appl_event_std_mgr::s_new),
            &(
                p_event_std_mgr));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_event_mgr) =
            p_event_std_mgr;
    }

    return
        e_status;

} // s_create()

//
//
//
appl_event_std_mgr::appl_event_std_mgr() :
    appl_event_mgr()
{
}

//
//
//
appl_event_std_mgr::~appl_event_std_mgr()
{
}

//
//
//
void
    appl_event_std_mgr::s_new(
        void * const
            p_placement)
{
    new (p_placement)
        class appl_event_std_mgr;

} // s_new()

//
//
//
enum appl_status
    appl_event_std_mgr::v_create(
        struct appl_context * const
            p_context,
        struct appl_event_descriptor const * const
            p_event_descriptor,
        struct appl_event * * const
            r_event)
{
    enum appl_status
        e_status;

    e_status =
        appl_event_std_node::s_create(
            p_context,
            p_event_descriptor,
            r_event);

    return
        e_status;

} // v_create()

/* end-of-file: appl_event_std_mgr.cpp */
