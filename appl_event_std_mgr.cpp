/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_event_mgr.h"

#include "appl_event_std_mgr.h"

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
enum appl_status
    appl_event_std_mgr::s_create(
        class appl_context * const
            p_context,
        class appl_event_mgr * * const
            r_event_mgr)
{
    enum appl_status
        e_status;

    e_status =
        appl_object::create_instance(
            p_context,
            sizeof(
                class appl_event_std_mgr),
            &(
                appl_event_std_mgr::placement_new),
            0,
            reinterpret_cast<class appl_object * *>(
                r_event_mgr));

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
    appl_event_std_mgr::placement_new(
        void * const
            p_placement)
{
    new (p_placement)
        class appl_event_std_mgr;

} // placement_new()

//
//
//
enum appl_status
    appl_event_std_mgr::v_create(
        class appl_context * const
            p_context,
        struct appl_event_descriptor const * const
            p_event_descriptor,
        class appl_event_node * * const
            r_event_node)
{
    enum appl_status
        e_status;

    static_cast<void>(
        p_context);
    static_cast<void>(
        p_event_descriptor);
    static_cast<void>(
        r_event_node);

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} // v_create()

/* end-of-file: appl_event_std_mgr.cpp */
