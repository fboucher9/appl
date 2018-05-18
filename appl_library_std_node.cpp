/* See LICENSE for license details */

/*

*/

#if defined APPL_OS_LINUX

#include <dlfcn.h>

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_library_node.h>

#include <appl_library_std_node.h>

#include <appl_library_handle.h>

#include <appl_buf0.h>

#include <appl_convert.h>

#include <appl_unused.h>

//
//
//
enum appl_status
    appl_library_std_node::s_create(
        struct appl_context * const
            p_context,
        struct appl_library_descriptor const * const
            p_library_descriptor,
        struct appl_library * * const
            r_library)
{
    enum appl_status
        e_status;

    class appl_library_std_node *
        p_library_std_node;

    e_status =
        appl_object::s_create(
            p_context,
            (&
                appl_library_std_node::s_new),
            (&
                appl_library_std_node::init),
            p_library_descriptor,
            &(
                p_library_std_node));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_library) =
            p_library_std_node;
    }

    return
        e_status;

} // s_create()

//
//
//
appl_library_std_node::appl_library_std_node() :
    appl_library(),
    m_library_handle()
{
}

//
//
//
appl_library_std_node::~appl_library_std_node()
{
}

//
//
//
enum appl_status
    appl_library_std_node::init(
        struct appl_library_descriptor const * const
            p_library_descriptor)
{
    enum appl_status
        e_status;

    unsigned char *
        p_name0;

    e_status =
        appl_buf0_create(
            this,
            p_library_descriptor->p_name_min,
            p_library_descriptor->p_name_max,
            &(
                p_name0));

    if (
        appl_status_ok
        == e_status)
    {
        void *
            p_dlopen_result;

        p_dlopen_result =
            dlopen(
                appl_convert(
                    p_name0),
                RTLD_LOCAL
                | RTLD_NOW);

        if (
            p_dlopen_result)
        {
            m_library_handle =
                p_dlopen_result;
        }
        else
        {
            e_status =
                appl_status_fail;
        }

        appl_buf0_destroy(
            this,
            p_name0);
    }

    return
        e_status;

} // init()

//
//
//
void
appl_library_std_node::s_new(
    void * const
        p_placement)
{
    new (p_placement)
        class appl_library_std_node;

} // s_new()

//
//
//
enum appl_status
    appl_library_std_node::v_cleanup(void)
{
    enum appl_status
        e_status;

    if (
        m_library_handle)
    {
        dlclose(
            m_library_handle);

        m_library_handle =
            0;
    }

    e_status =
        appl_status_ok;

    return
        e_status;

} // v_cleanup()

//
//
//
enum appl_status
    appl_library_std_node::v_query(
        unsigned char const * const
            p_symbol_name_min,
        unsigned char const * const
            p_symbol_name_max,
        void * * const
            r_symbol) const
{
    enum appl_status
        e_status;

    unsigned char *
        p_name0;

    e_status =
        appl_buf0_create(
            this,
            p_symbol_name_min,
            p_symbol_name_max,
            &(
                p_name0));

    if (
        appl_status_ok
        == e_status)
    {
        void *
            p_dlsym_result;

        p_dlsym_result =
            dlsym(
                m_library_handle,
                appl_convert(
                    p_name0));

        if (
            p_dlsym_result)
        {
            *(
                r_symbol) =
                p_dlsym_result;
        }
        else
        {
            e_status =
                appl_status_fail;
        }

        appl_buf0_destroy(
            this,
            p_name0);
    }

    return
        e_status;

} // v_query()

#endif /* #if defined APPL_OS_LINUX */

/* end-of-file: appl_library_std_node.cpp */
