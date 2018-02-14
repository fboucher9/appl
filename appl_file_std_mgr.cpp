/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_file_mgr.h"

#include "appl_file_std_mgr.h"

#include "appl_file_node.h"

#include "appl_file_std_node.h"

#if !defined(__cplusplus)
#error use c++ compiler
#endif /* #if !defined(__cplusplus) */

//
//
//
enum appl_status
    appl_file_std_mgr::create_instance(
        class appl_context * const
            p_context,
        class appl_file_mgr * * const
            r_file_mgr)
{
    enum appl_status
        e_status;

    e_status =
        appl_object::create_instance(
            p_context,
            sizeof(
                class appl_file_std_mgr),
            &(
                appl_file_std_mgr::placement_new),
            0,
            reinterpret_cast<class appl_object * *>(
                r_file_mgr));

    return
        e_status;

} // create_instance()

//
//
//
appl_file_std_mgr::appl_file_std_mgr() :
    appl_file_mgr()
{
}

//
//
//
appl_file_std_mgr::~appl_file_std_mgr()
{
}

//
//
//
void
    appl_file_std_mgr::placement_new(
        void * const
            p_placement)
{
    new (p_placement)
        class appl_file_std_mgr;

} // placement_new()

//
//
//
enum appl_status
    appl_file_std_mgr::v_create_node(
        struct appl_file_descriptor const * const
            p_file_descriptor,
        class appl_file_node * * const
            r_file_node)
{
    enum appl_status
        e_status;

    e_status =
        appl_file_std_node::create_instance(
            m_context,
            p_file_descriptor,
            r_file_node);

    return
        e_status;

} // v_create_node()

/* end-of-file: appl_file_std_mgr.cpp */
