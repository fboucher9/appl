/* See LICENSE for license details */

/*

*/

#if defined APPL_OS_LINUX

#include <appl_status.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <library/appl_library_mgr.h>

#include <library/appl_library_std_mgr.h>

#include <library/appl_library_node.h>

#include <library/appl_library_std_node.h>

#include <context/appl_context_handle.h>

#include <allocator/appl_allocator_handle.h>

//
//
//
enum appl_status
    appl_library_std_mgr::s_create(
        struct appl_allocator * const
            p_allocator,
        class appl_library_mgr * * const
            r_library_mgr)
{
    enum appl_status
        e_status;

    class appl_library_std_mgr *
        p_library_std_mgr;

    e_status =
        appl_new(
            p_allocator,
            &(
                p_library_std_mgr));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_library_mgr) =
            p_library_std_mgr;
    }

    return
        e_status;

} // s_create()

//
//
//
appl_library_std_mgr::appl_library_std_mgr(
    struct appl_context * const
        p_context) :
    appl_library_mgr(
        p_context)
{
}

//
//
//
appl_library_std_mgr::~appl_library_std_mgr()
{
}

//
//
//
appl_size_t
    appl_library_std_mgr::v_cleanup(void)
{
    return
        sizeof(class appl_library_std_mgr);

} // v_cleanup()

//
//
//
enum appl_status
    appl_library_std_mgr::v_create_node(
        struct appl_library_descriptor const * const
            p_library_descriptor,
        struct appl_library * * const
            r_library)
{
    return
        appl_library_std_node::s_create(
            appl_context_get_allocator(
                m_context),
            p_library_descriptor,
            r_library);

} // v_create_node()

//
//
//
enum appl_status
    appl_library_std_mgr::v_destroy_node(
        struct appl_library * const
            p_library)
{
    return
        appl_library_std_node::s_destroy(
            appl_context_get_allocator(
                m_context),
            p_library);

} // v_destroy_node()

#endif /* #if defined APPL_OS_LINUX */

/* end-of-file: appl_library_std_mgr.cpp */
