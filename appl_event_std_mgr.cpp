/* See LICENSE for license details */

/*

*/

#include <pthread.h>

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_event_mgr.h>

#include <appl_event_std_mgr.h>

#include <appl_event_node.h>

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

    e_status =
        appl_object::s_create(
            p_context,
            sizeof(
                class appl_event_std_mgr),
            (&
                appl_event_std_mgr::s_new),
            (&
                appl_event_std_mgr::init),
            r_event_mgr);

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
    appl_event_std_mgr::init(void)
{
    return
        appl_status_ok;

} // init()

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
