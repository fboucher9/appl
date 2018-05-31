/* See LICENSE for license details */

/*

*/

#if defined APPL_OS_WINDOWS

#include <windows.h>

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_library_handle.h>

#include <appl_library_node.h>

#include <appl_library_w32_node.h>

#include <appl_library_mgr.h>

#include <appl_library_w32_mgr.h>

#include <appl_buf0.h>

//
//
//
enum appl_status
    appl_library_w32_mgr::s_create(
        struct appl_context * const
            p_context,
        struct appl_library_mgr * * const
            r_library_mgr)
{
    enum appl_status
        e_status;

    class appl_library_w32_mgr *
        p_library_w32_mgr;

    e_status =
        appl_object::s_create(
            p_context,
            (&
                appl_library_w32_mgr::s_new),
            &(
                p_library_w32_mgr));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_library_mgr) =
            p_library_w32_mgr;
    }

    return
        e_status;

} // s_create()

//
//
//
appl_library_w32_mgr::appl_library_w32_mgr() :
    appl_library_mgr()
{
}

//
//
//
appl_library_w32_mgr::~appl_library_w32_mgr()
{
}

//
//
//
void
appl_library_w32_mgr::s_new(
        void * const
            p_placement)
{
    new (p_placement)
        class appl_library_w32_mgr;

} // s_new()

//
//
//
enum appl_status
    appl_library_w32_mgr::v_create_node(
        struct appl_library_descriptor const * const
            p_library_descriptor,
        struct appl_library * * const
            r_library)
{
    return
        appl_library_w32_node::s_create(
            m_context,
            p_library_descriptor,
            r_library);

} // v_create_node()

#endif /* #if defined APPL_OS_WINDOWS */

/* end-of-file: appl_library_w32_mgr.cpp */