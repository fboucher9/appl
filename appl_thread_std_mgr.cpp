/* See LICENSE for license details */

/*

*/

#include <pthread.h>

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_thread_descriptor.h>

#include <appl_thread_mgr.h>

#include <appl_thread_std_mgr.h>

#include <appl_thread_node.h>

#include <appl_thread_std_node.h>

enum appl_status
    appl_thread_std_mgr::create_instance(
        struct appl_context * const
            p_context,
        class appl_thread_mgr * * const
            r_thread_mgr)
{
    return
        appl_object::s_create(
            p_context,
            sizeof(
                class appl_thread_std_mgr),
            &(
                appl_thread_std_mgr::placement_new),
            r_thread_mgr);

} // create_instance()

appl_thread_std_mgr::appl_thread_std_mgr() :
    appl_thread_mgr()
{
}

appl_thread_std_mgr::~appl_thread_std_mgr()
{
}

void
    appl_thread_std_mgr::placement_new(
        void * const
            p_placement)
{
    new (p_placement)
        class appl_thread_std_mgr;

} // placement_new()

enum appl_status
    appl_thread_std_mgr::v_create(
        struct appl_context * const
            p_context,
        struct appl_thread_property const * const
            p_thread_property,
        struct appl_thread * * const
            r_thread)
{
    enum appl_status
        e_status;

    e_status =
        appl_thread_std_node::create_instance(
            p_context,
            p_thread_property,
            r_thread);

    return
        e_status;

} // v_create()

/* end-of-file: appl_thread_std_mgr.cpp */
