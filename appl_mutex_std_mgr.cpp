/* See LICENSE for license details */

/*

*/

#include <pthread.h>

#include "appl_status.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_mutex_mgr.h"

#include "appl_mutex_std_mgr.h"

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
    appl_mutex_std_mgr::create_instance(
        class appl_context * const
            p_context,
        class appl_mutex_mgr * * const
            r_mutex_mgr)
{
    enum appl_status
        e_status;

    e_status =
        appl_object::s_create(
            p_context,
            sizeof(
                class appl_mutex_std_mgr),
            &(
                appl_mutex_std_mgr::placement_new),
            r_mutex_mgr);

    return
        e_status;

} // create_instance()

//
//
//
appl_mutex_std_mgr::appl_mutex_std_mgr() :
    appl_mutex_mgr()
{
}

//
//
//
appl_mutex_std_mgr::~appl_mutex_std_mgr()
{
}

//
//
//
void
    appl_mutex_std_mgr::placement_new(
        void * const
            p_placement)
{
    new (p_placement)
        class appl_mutex_std_mgr;

} // placement_new()

//
//
//
enum appl_status
    appl_mutex_std_mgr::v_create(
        struct appl_mutex_descriptor const * const
            p_mutex_descriptor,
        class appl_mutex_node * * const
            r_mutex_node)
{
    enum appl_status
        e_status;

    e_status =
        appl_mutex_std_node::create_instance(
            m_context,
            p_mutex_descriptor,
            r_mutex_node);

    return
        e_status;

} // v_create()

/* end-of-file: appl_mutex_std_mgr.cpp */
