/* See LICENSE for license details */

/*

*/

#include <property/appl_property_test.h>

#include <appl_status.h>

#include <appl_property_handle.h>

#include <appl_types.h>

#include <appl_object.h>

#include <property/appl_property_types.h>

#include <property/appl_property.h>

#include <appl_heap_handle.h>

//
//
//
void
    appl_property_test_1(
        struct appl_context * const
            p_context)
{
    // base class
    {
        struct appl_property *
            p_property;

        enum appl_status
            e_status;

        e_status =
            appl_new(
                p_context,
                &(
                    p_property));

        if (
            appl_status_ok
            == e_status)
        {
            p_property->v_set(
                0,
                appl_property_type_ulong,
                0);

            p_property->v_get(
                0,
                appl_property_type_ulong,
                0);

            {
                void *
                    p_value;

                p_property->get_ptr(
                    0,
                    &(
                        p_value));
            }

            {
                unsigned long int
                    i_value;

                p_property->get_ulong(
                    0,
                    &(
                        i_value));
            }

            {
                signed long int
                    i_value;

                p_property->get_long(
                    0,
                    &(
                        i_value));
            }

            appl_delete(
                p_context,
                p_property);
        }
    }

    // sanity check
    {
        enum appl_status
            e_status;

        struct appl_property *
            p_property;

        e_status =
            appl_property_create(
                p_context,
                8u,
                &(
                    p_property));

        if (
            appl_status_ok
            == e_status)
        {
            appl_property_parent(
                p_property);

            appl_property_const_parent(
                p_property);

            static unsigned char g_value[1u] =
            {
                123u
            };

            {
                void *
                    p_value;

                p_value =
                    g_value;

                appl_property_set_ptr(
                    p_property,
                    0u,
                    p_value);

                appl_property_get_ptr(
                    p_property,
                    0ul,
                    &(
                        p_value));

                p_property->get_ptr(
                    0ul,
                    &(
                        p_value));
            }

            {
                unsigned long int
                    i_value;

                i_value =
                    123ul;

                appl_property_set_ulong(
                    p_property,
                    1u,
                    i_value);

                appl_property_get_ulong(
                    p_property,
                    1u,
                    &(
                        i_value));

                p_property->get_ulong(
                    1u,
                    &(
                        i_value));
            }

            {
                signed long int
                    i_value;

                i_value =
                    -77l;

                appl_property_set_long(
                    p_property,
                    2u,
                    i_value);

                appl_property_get_long(
                    p_property,
                    2u,
                    &(
                        i_value));

                p_property->get_long(
                    2u,
                    &(
                        i_value));
            }

            // test set invalid id
            {
                appl_property_set_ulong(
                    p_property,
                    8u,
                    0ul);
            }

            // test get invalid id
            {
                unsigned long int
                    i_value;

                appl_property_get_ulong(
                    p_property,
                    8u,
                    &(
                        i_value));
            }

            // test get invalid type
            {
                unsigned long int
                    i_value;

                appl_property_set_long(
                    p_property,
                    3u,
                    -40l);

                appl_property_get_ulong(
                    p_property,
                    3u,
                    &(
                        i_value));
            }

            appl_property_destroy(
                p_property);
        }
    }

} // appl_property_test_1()

/* end-of-file: appl_property_test.cpp */
