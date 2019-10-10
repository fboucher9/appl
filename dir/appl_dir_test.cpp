/* See LICENSE for license details */

#include <appl_predefines.h>

#include <dir/appl_dir_test.h>

#include <appl_status.h>

#include <dir/appl_dir_handle.h>

#include <buf/appl_buf.h>

#include <dir/appl_dir_descriptor.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <dir/appl_dir_mgr.h>

#include <heap/appl_heap_handle.h>

#include <misc/appl_unused.h>

#include <test/appl_test.h>

//
//
//
static
enum appl_status
    test_dir_callback(
        void * const
            p_void,
        struct appl_dir_item const * const
            p_item)
{
    static unsigned char const g_delimiter[] =
    {
        ' '
    };

    appl_unused(
        p_void);

    appl_print(
        g_delimiter,
        g_delimiter + sizeof(g_delimiter));

    appl_print(
        p_item->o_name.o_min.pc_uchar,
        p_item->o_name.o_max.pc_uchar);

    return
        appl_status_ok;

} // test_dir_callback()

//
//
//
void
    appl_dir_test_1(
        struct appl_context * const
            p_context)
{
    static unsigned char const g_current_dir_name[] =
    {
        '.'
    };

    enum appl_status
        e_status;

    struct appl_dir_descriptor
        o_descriptor;

    o_descriptor.o_name.o_min.pc_uchar =
        g_current_dir_name;

    o_descriptor.o_name.o_max.pc_uchar =
        g_current_dir_name + sizeof(g_current_dir_name);

    o_descriptor.p_callback =
        & test_dir_callback;

    o_descriptor.p_void =
        p_context;

    e_status =
        appl_dir_enumerate(
            p_context,
            &(
                o_descriptor));

    static unsigned char const g_newline[] =
    {
        '\n'
    };

    appl_print(
        g_newline,
        g_newline + sizeof(g_newline));

    if (
        appl_status_ok
        == e_status)
    {
    }
    else
    {
    }

    static unsigned char const g_bad_dir_name[] =
    {
        '!',
        '$',
        '#',
        '@',
        '^',
        '&',
        '*'
    };

    o_descriptor.o_name.o_min.pc_uchar =
        g_bad_dir_name;

    o_descriptor.o_name.o_max.pc_uchar =
        g_bad_dir_name + sizeof(g_bad_dir_name);

    o_descriptor.p_callback =
        & test_dir_callback;

    o_descriptor.p_void =
        p_context;

    e_status =
        appl_dir_enumerate(
            p_context,
            &(
                o_descriptor));

    if (
        appl_status_ok
        == e_status)
    {
    }
    else
    {
    }

    {
        class appl_dir_mgr *
            p_dir_mgr;

        e_status =
            appl_new(
                p_context,
                &(
                    p_dir_mgr));

        if (
            appl_status_ok
            == e_status)
        {
            e_status =
                p_dir_mgr->v_enumerate(
                    0);

            e_status =
                appl_delete(
                    p_context,
                    p_dir_mgr);
        }
    }

} // appl_dir_test_1()

/* end-of-file: appl_dir_test.cpp */
