/* See LICENSE for license details */

/*

*/

#if defined APPL_OS_WINDOWS

#include <windows.h>

#include <appl_status.h>

#include <appl_predefines.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <library/appl_library_node.h>

#include <library/appl_library_w32_node.h>

#include <library/appl_library_handle.h>

#include <buf/appl_buf0.h>

#include <misc/appl_convert.h>

#include <allocator/appl_allocator_handle.h>

//
//
//
enum appl_status
    appl_library_w32_node::s_create(
        struct appl_allocator * const
            p_allocator,
        struct appl_library_descriptor const * const
            p_library_descriptor,
        struct appl_library * * const
            r_library)
{
    enum appl_status
        e_status;

    class appl_library_w32_node *
        p_library_w32_node;

    e_status =
        appl_new(
            p_allocator,
            p_library_descriptor,
            &(
                p_library_w32_node));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_library) =
            p_library_w32_node;
    }

    return
        e_status;

} // s_create()

//
//
//
enum appl_status
    appl_library_w32_node::s_destroy(
        struct appl_allocator * const
            p_allocator,
        struct appl_library * const
            p_library)
{
    return
        appl_delete(
            p_allocator,
            p_library);

} // s_destroy()

//
//
//
appl_library_w32_node::appl_library_w32_node(
    struct appl_context * const
        p_context) :
    appl_library(
        p_context),
    m_library_handle()
{
}

//
//
//
appl_library_w32_node::~appl_library_w32_node()
{
}

//
//
//
enum appl_status
    appl_library_w32_node::f_init(
        struct appl_library_descriptor const * const
            p_library_descriptor)
{
    enum appl_status
        e_status;

    struct appl_buf0 *
        p_name0;

    e_status =
        appl_buf0_create(
            m_context,
            p_library_descriptor->p_name_min,
            p_library_descriptor->p_name_max,
            &(
                p_name0));

    if (
        appl_status_ok
        == e_status)
    {
        m_library_handle =
            LoadLibraryA(
                appl_convert::to_char_ptr(
                    appl_buf0_get(p_name0)));

        if (
            m_library_handle)
        {
        }
        else
        {
            e_status =
                appl_status_fail;
        }

        appl_buf0_destroy(
            p_name0);
    }

    return
        e_status;

} // f_init()

//
//
//
appl_size_t
    appl_library_w32_node::v_cleanup(void)
{
    return
        sizeof(class appl_library_w32_node);

} // v_cleanup()

//
//
//
enum appl_status
    appl_library_w32_node::v_query(
        unsigned char const * const
            p_symbol_name_min,
        unsigned char const * const
            p_symbol_name_max,
        void * * const
            r_symbol) const
{
    enum appl_status
        e_status;

    struct appl_buf0 *
        p_symbol_name0;

    e_status =
        appl_buf0_create(
            m_context,
            p_symbol_name_min,
            p_symbol_name_max,
            &(
                p_symbol_name0));

    if (
        appl_status_ok
        == e_status)
    {
        union appl_library_w32_symbol_ptr
        {
            void *
                p_symbol;

            FARPROC
                pfn;

        } o_symbol_ptr;

        o_symbol_ptr.pfn =
            GetProcAddress(
                m_library_handle,
                appl_convert::to_char_ptr(
                    appl_buf0_get(p_symbol_name0)));

        *(
            r_symbol) =
            o_symbol_ptr.p_symbol;

        appl_buf0_destroy(
            p_symbol_name0);
    }

    return
        e_status;

} // v_query()

#endif /* #if defined APPL_OS_WINDOWS */

/* end-of-file: appl_library_w32_node.cpp */
