/* See LICENSE for license details */

/*

*/

#include <string/appl_string_test.h>

#include <appl_status.h>

#include <string/appl_string_handle.h>

//
//
//
void
    appl_string_test_1(
        struct appl_context * const
            p_context)
{
    // Sanity check
    {
        enum appl_status
            e_status;

        struct appl_string *
            p_string;

        e_status =
            appl_string_create(
                p_context,
                64u,
                &(
                    p_string));

        if (
            appl_status_ok
            == e_status)
        {
            struct appl_string *
                p_string2;

            appl_string_parent(
                p_string);

            appl_string_const_parent(
                p_string);

            {
                unsigned long int
                    i_length;

                appl_string_length(
                    p_string,
                    &(
                        i_length));
            }

            {
                unsigned char *
                    p_buf_min;

                unsigned char *
                    p_buf_max;

                appl_string_get(
                    p_string,
                    &(
                        p_buf_min),
                    &(
                        p_buf_max));
            }

            e_status =
                appl_string_create_dup_object(
                    p_string,
                    &(
                        p_string2));

            if (
                appl_status_ok
                == e_status)
            {
                appl_string_destroy(
                    p_string2);
            }

            e_status =
                appl_string_create_dup_object_n(
                    p_string,
                    32u,
                    &(
                        p_string2));

            if (
                appl_status_ok
                == e_status)
            {
                appl_string_destroy(
                    p_string2);
            }

            static unsigned char const g_ref_buffer[8u] =
            {
                1u,
                2u,
                3u,
                4u,
                5u,
                6u,
                7u,
                8u
            };

            e_status =
                appl_string_create_dup_buffer(
                    p_context,
                    g_ref_buffer,
                    g_ref_buffer + sizeof(g_ref_buffer),
                    &(
                        p_string2));

            if (
                appl_status_ok
                == e_status)
            {
                appl_string_destroy(
                    p_string2);
            }

            e_status =
                appl_string_create_dup_buffer_n(
                    p_context,
                    g_ref_buffer,
                    g_ref_buffer + sizeof(g_ref_buffer),
                    6u,
                    &(
                        p_string2));

            if (
                appl_status_ok
                == e_status)
            {
                appl_string_destroy(
                    p_string2);
            }

            appl_string_destroy(
                p_string);
        }
    }

} // appl_string_test_1()

/* end-of-file: appl_string_test.cpp */
