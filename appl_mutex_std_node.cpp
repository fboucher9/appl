/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_mutex_node.h"

#include "appl_mutex_std_node.h"

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
enum appl_status
    appl_mutex_std_node::create_instance(
        class appl_context * const
            p_context,
        struct appl_mutex_descriptor const * const
            p_mutex_descriptor,
        class appl_mutex_node * * const
            r_mutex_node)
{
    enum appl_status
        e_status;

    e_status =
        appl_object::create_instance(
            p_context,
            sizeof(
                class appl_mutex_std_node),
            &(
                appl_mutex_std_node::placement_new),
            static_cast<void const *>(
                p_mutex_descriptor),
            reinterpret_cast<class appl_object * *>(
                r_mutex_node));

    return
        e_status;

} // create_instance()

//
//
//
appl_mutex_std_node::appl_mutex_std_node() :
    appl_mutex_node()
{
}

//
//
//
appl_mutex_std_node::~appl_mutex_std_node()
{
}

//
//
//
void
    appl_mutex_std_node::placement_new(
        void * const
            p_placement)
{
    new (p_placement)
        class appl_mutex_std_node;

} // placement_new()

//
//
//
enum appl_status
    appl_mutex_std_node::v_lock(void)
{
    enum appl_status
        e_status;

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} // v_lock()

//
//
//
enum appl_status
    appl_mutex_std_node::v_unlock(void)
{
    enum appl_status
        e_status;

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} // v_unlock()

/* end-of-file: appl_mutex_std_node.cpp */
