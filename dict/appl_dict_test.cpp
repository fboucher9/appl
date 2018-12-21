/* See LICENSE for license details */

/*

*/

#include <dict/appl_dict_test.h>

#include <appl_status.h>

#include <appl_dict_handle.h>

#include <appl_types.h>

#include <appl_object.h>

#include <dict/appl_dict.h>

#include <appl_heap_handle.h>

//
//
//
void
    appl_dict_test_1(
        struct appl_context * const
            p_context)
{
    // sanity check
    {
        struct appl_dict *
            p_dict;

        enum appl_status
            e_status;

        e_status =
            appl_dict_create(
                p_context,
                &(
                    p_dict));

        if (
            appl_status_ok
            == e_status)
        {
            appl_dict_parent(
                p_dict);

            {
                static unsigned char const g_name[] =
                {
                    'n',
                    'a',
                    'm',
                    'e'
                };

                static unsigned char g_value[1u] =
                {
                    123u
                };

                void *
                    p_value;

                appl_dict_set(
                    p_dict,
                    g_name,
                    g_name + sizeof(g_name),
                    g_value);

                appl_dict_get(
                    p_dict,
                    g_name,
                    g_name + sizeof(g_name),
                    &(
                        p_value));
            }

            appl_dict_destroy(
                p_context,
                p_dict);
        }
    }

    // coverage of dict base class
    {
        struct appl_dict *
            p_dict;

        enum appl_status
            e_status;

        e_status =
            appl_new(
                p_context,
                &(
                    p_dict));

        if (
            appl_status_ok
            == e_status)
        {
            p_dict->v_set(
                0,
                0,
                0);

            p_dict->v_get(
                0,
                0,
                0);

            appl_delete(
                p_context,
                p_dict);
        }
    }

} // appl_dict_test_1()

/* end-of-file: appl_dict_test.cpp */
