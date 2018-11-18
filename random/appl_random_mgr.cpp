/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <random/appl_random_mgr.h>

#include <random/appl_random.h>

#include <random/appl_random_pseudo.h>

#include <appl_random_handle.h>

#include <appl_unused.h>

#include <appl_context.h>

#include <allocator/appl_allocator.h>

//
//
//
enum appl_status
appl_random_mgr::v_create_node(
    struct appl_random_descriptor const * const
        p_descriptor,
    struct appl_random * * const
        r_node)
{
    enum appl_status
        e_status;

    if (
        appl_random_type_pseudo
        == p_descriptor->e_type)
    {
        e_status =
            appl_random_pseudo::s_create(
                m_context->m_allocator,
                p_descriptor->i_seed,
                r_node);
    }
    else
    {
        e_status =
            appl_status_fail;
    }

    return
        e_status;

} // v_create_node()

//
//
//
appl_random_mgr::appl_random_mgr() :
    appl_object()
{
}

//
//
//
appl_random_mgr::~appl_random_mgr()
{
}

/* end-of-file: appl_random_mgr.cpp */
