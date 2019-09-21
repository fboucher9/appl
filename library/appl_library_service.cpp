/* See LICENSE for license details */

/*

*/

#if defined APPL_OS_WINDOWS

#include <windows.h>

#endif /* #if defined APPL_OS_WINDOWS */

#include <appl_status.h>

#include <appl_predefines.h>

#include <library/appl_library_service.h>

#include <appl_library_handle.h>

#include <appl_types.h>

#include <appl_object.h>

#include <context/appl_context.h>

#include <appl_allocator_handle.h>

#include <appl_buf.h>

#include <appl_buf0.h>

#include <appl_convert.h>

#include <library/appl_library_node.h>

#include <library/appl_library_mgr.h>

#if defined APPL_OS_LINUX

#include <library/appl_library_std_mgr.h>

#endif /* #if defined APPL_OS_LINUX */

#if defined APPL_OS_WINDOWS

#include <library/appl_library_w32_mgr.h>

#endif /* #if defined APPL_OS_WINDOWS */

extern
enum appl_status
    appl_library_mgr_create(
        struct appl_allocator * const
            p_allocator,
        class appl_library_mgr * * const
            r_library_mgr);

extern
enum appl_status
    appl_library_mgr_destroy(
        struct appl_allocator * const
            p_allocator,
        class appl_library_mgr * const
            p_library_mgr);

//
//
//
enum appl_status
    appl_library_mgr_create(
        struct appl_allocator * const
            p_allocator,
        class appl_library_mgr * * const
            r_library_mgr)
{
    enum appl_status
        e_status;

#if defined APPL_OS_LINUX

    e_status =
        appl_library_std_mgr::s_create(
            p_allocator,
            r_library_mgr);

#elif defined APPL_OS_WINDOWS

    e_status =
        appl_library_w32_mgr::s_create(
            p_allocator,
            r_library_mgr);

#else /* #if definde APPL_OS_Xx */

    e_status =
        appl_raise_not_implemented();

#endif /* #if defined APPL_OS_Xx */

    return
        e_status;

} // appl_library_mgr_create()

//
//
//
enum appl_status
    appl_library_mgr_destroy(
        struct appl_allocator * const
            p_allocator,
        class appl_library_mgr * const
            p_library_mgr)
{
    return
        appl_delete(
            p_allocator,
            p_library_mgr);

} // appl_library_mgr_destroy()

//
//
//
enum appl_status
    appl_library_service::s_create(
        struct appl_context * const
            p_context,
        struct appl_library_descriptor const * const
            p_library_descriptor,
        struct appl_library * * const
            r_library)
{
    enum appl_status
        e_status;

    class appl_library_mgr *
        p_library_mgr;

    e_status =
        p_context->v_library_mgr(
            &(
                p_library_mgr));

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            p_library_mgr->v_create_node(
                p_library_descriptor,
                r_library);
    }

    return
        e_status;

} // s_create()

//
//
//
enum appl_status
    appl_library_service::s_destroy(
        struct appl_library * const
            p_library)
{
    enum appl_status
        e_status;

    struct appl_context * const
        p_context =
        p_library->get_context();

    class appl_library_mgr *
        p_library_mgr;

    e_status =
        p_context->v_library_mgr(
            &(
                p_library_mgr));

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            p_library_mgr->v_destroy_node(
                p_library);
    }

    return
        e_status;

} // s_destroy()

//
//
//
struct appl_object *
    appl_library_service::s_parent(
        struct appl_library * const
            p_library)
{
    return
        p_library;

} // s_parent()

//
//
//
struct appl_object const *
    appl_library_service::s_const_parent(
        struct appl_library const * const
            p_library)
{
    return
        p_library;

} // s_const_parent()

//
//
//
enum appl_status
    appl_library_service::s_query(
        struct appl_library const * const
            p_library,
        unsigned char const * const
            p_symbol_name_min,
        unsigned char const * const
            p_symbol_name_max,
        void * * const
            r_symbol)
{
    return
        p_library->v_query(
            p_symbol_name_min,
            p_symbol_name_max,
            r_symbol);

} // s_query()

/* end-of-file: appl_library_service.cpp */
