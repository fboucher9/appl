/* See LICENSE for license details */

/*

Module: appl_address_std_node.cpp

Description:
    Standard implementation of address node.

*/

#include "appl_status.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_address_node.h"

#include "appl_address_std_node.h"

//
//
//
enum appl_status
    appl_address_std_node::s_create(
        class appl_context * const
            p_context,
        struct appl_address_descriptor const * const
            p_address_descriptor,
        class appl_address_node * * const
            r_address_node)
{
    return
        appl_object::create_instance(
            p_context,
            static_cast<unsigned long int>(
                sizeof(
                    class appl_address_std_node)),
            &(
                appl_address_std_node::s_new),
            static_cast<void const *>(
                p_address_descriptor),
            reinterpret_cast<class appl_object * *>(
                r_address_node));

} // s_create()

//
//
//
appl_address_std_node::appl_address_std_node() :
    appl_address_node()
{
}

//
//
//
appl_address_std_node::~appl_address_std_node()
{
}

//
//
//
void
    appl_address_std_node::s_new(
        void * const
            p_placement)
{
} // s_new()

/* end-of-file: appl_address_std_node.cpp */
