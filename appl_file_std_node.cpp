/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_file_node.h"

#include "appl_file_std_node.h"

//
//
//
enum appl_status
    appl_file_std_node::create_instance(
        class appl_context * const
            p_context,
        struct appl_file_descriptor const * const
            p_file_descriptor,
        class appl_file_node * * const
            r_file_node)
{
    enum appl_status
        e_status;

    e_status =
        appl_object::create_instance(
            p_context,
            static_cast<unsigned long int>(
                sizeof(
                    class appl_file_std_node)),
            &(
                appl_file_std_node::placement_new),
            p_file_descriptor,
            reinterpret_cast<class appl_object * *>(
                r_file_node));

    return
        e_status;

} // create_instance()

//
//
//
appl_file_std_node::appl_file_std_node() :
    appl_file_node(),
    m_fd()
{
}

//
//
//
appl_file_std_node::~appl_file_std_node()
{
}

//
//
//
void
    appl_file_std_node::placement_new(
        void * const
            p_placement)
{
    new (p_placement)
        class appl_file_std_node;

} // placement_new()

/* end-of-file: appl_file_std_node.cpp */
