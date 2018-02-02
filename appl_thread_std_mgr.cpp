/* See LICENSE for license details */

/*

*/

#include <pthread.h>

#include "appl_status.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_thread_mgr.h"

#include "appl_thread_std_mgr.h"

#include "appl_thread_node.h"

#include "appl_thread_std_node.h"

enum appl_status
    appl_thread_std_mgr::create_instance(
        class appl_context * const
            p_context,
        class appl_thread_mgr * * const
            r_thread_mgr)
{
    return
        appl_object::create_instance(
            p_context,
            static_cast<unsigned long int>(
                sizeof(
                    class appl_thread_std_mgr)),
            &(
                appl_thread_std_mgr::placement_new),
            0,
            reinterpret_cast<class appl_object * *>(
                r_thread_mgr));

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
    appl_thread_std_mgr::create_node(
        class appl_context * const
            p_context,
        struct appl_thread_descriptor const * const
            p_thread_descriptor,
        class appl_thread_node * * const
            r_thread_node)
{
    enum appl_status
        e_status;

    e_status =
        appl_thread_std_node::create_instance(
            p_context,
            p_thread_descriptor,
            r_thread_node);

    return
        e_status;

} // create_node()

/* end-of-file: appl_thread_std_mgr.cpp */
