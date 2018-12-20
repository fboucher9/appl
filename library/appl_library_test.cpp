/* See LICENSE for license details */

/*

*/

#include <appl.h>

#include <library/appl_library_test.h>

#include <library/appl_library_mgr.h>

#include <library/appl_library_node.h>

//
//
//
void
    appl_library_test_1(
        struct appl_context * const
            p_context)
{
    enum appl_status
        e_status;

    struct appl_allocator *
        p_allocator;

    p_allocator =
        appl_context_get_allocator(
            p_context);

    // normal test
    {
        static unsigned char const g_library_name[] =
        {
            'l',
            'i',
            'b',
            'r',
            't',
            '.',
            's',
            'o'
        };

        struct appl_library *
            p_library;

        struct appl_library_descriptor
            o_descriptor;

        o_descriptor.p_name_min =
            g_library_name;

        o_descriptor.p_name_max =
            g_library_name + sizeof(g_library_name);

        e_status =
            appl_library_create(
                p_context,
                &(
                    o_descriptor),
                &(
                    p_library));

        if (
            appl_status_ok
            == e_status)
        {
            appl_library_parent(
                p_library);

            appl_library_const_parent(
                p_library);

            {
                static unsigned char const g_symbol_name[] =
                {
                    'c',
                    'l',
                    'o',
                    'c',
                    'k',
                    '_',
                    'g',
                    'e',
                    't',
                    't',
                    'i',
                    'm',
                    'e'
                };

                void *
                    p_symbol;

                e_status =
                    appl_library_query(
                        p_library,
                        g_symbol_name,
                        g_symbol_name + sizeof(g_symbol_name),
                        &(
                            p_symbol));
            }

            {
                static unsigned char const g_symbol_name[] =
                {
                    'b',
                    'a',
                    'd',
                    '-',
                    's',
                    'y',
                    'm',
                    '!'
                };

                void *
                    p_symbol;

                e_status =
                    appl_library_query(
                        p_library,
                        g_symbol_name,
                        g_symbol_name + sizeof(g_symbol_name),
                        &(
                            p_symbol));
            }

            appl_library_destroy(
                p_library);
        }
    }

    // invalid library name
    {
        static unsigned char const g_library_name[] =
        {
            'b',
            'a',
            'd',
            '.',
            't',
            'x',
            't',
            '_'
        };

        struct appl_library *
            p_library;

        struct appl_library_descriptor
            o_descriptor;

        o_descriptor.p_name_min =
            g_library_name;

        o_descriptor.p_name_max =
            g_library_name + sizeof(g_library_name);

        e_status =
            appl_library_create(
                p_context,
                &(
                    o_descriptor),
                &(
                    p_library));

        e_status =
            (appl_status_ok == e_status)
            ? appl_library_destroy(
                p_library)
            : e_status;
    }

    // base library mgr
    {
        class appl_library_mgr *
            p_library_mgr;

        e_status =
            appl_new(
                p_allocator,
                &(
                    p_library_mgr));

        if (
            appl_status_ok
            == e_status)
        {
            p_library_mgr->v_create_node(
                0,
                0);

            p_library_mgr->v_destroy_node(
                0);

            appl_delete(
                p_allocator,
                p_library_mgr);
        }
    }

    // base library node
    {
        struct appl_library *
            p_library_node;

        e_status =
            appl_new(
                p_allocator,
                &(
                    p_library_node));

        if (
            appl_status_ok
            == e_status)
        {
            p_library_node->v_query(
                0,
                0,
                0);

            appl_delete(
                p_allocator,
                p_library_node);
        }
    }

} // appl_library_test_1()

/* end-of-file: appl_library_test.cpp */
