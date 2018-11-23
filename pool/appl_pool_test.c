/* See LICENSE for license details */

/*

*/

#include <stdio.h>

#include <appl.h>

#include <pool/appl_pool_test.h>

/*

*/
char
appl_pool_test_1(
    struct appl_context * const
        p_context)
{
    char
        b_result;

    enum appl_status
        e_status;

    struct appl_pool *
        p_pool;

    struct appl_pool_descriptor
        o_pool_descriptor;

    b_result =
        1;

    o_pool_descriptor.i_length =
        20u;

    o_pool_descriptor.i_count_min =
        0u;

    o_pool_descriptor.i_count_max =
        0u;

    e_status =
        appl_pool_create(
            p_context,
            &(
                o_pool_descriptor),
            &(
                p_pool));

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            appl_object_destroy(
                appl_allocator_parent(
                    appl_pool_parent(
                        p_pool)));

        if (
            appl_status_ok
            == e_status)
        {
        }
        else
        {
            b_result =
                0;
        }
    }
    else
    {
        b_result =
            0;
    }

    return
        b_result;

} /* appl_pool_test_1() */

/*

*/
char
appl_pool_test_2(
    struct appl_context * const
        p_context)
{
    char
        b_result;

    enum appl_status
        e_status;

    struct appl_pool *
        p_pool;

    struct appl_pool_descriptor
        o_pool_descriptor;

    b_result =
        1;

    o_pool_descriptor.i_length =
        20u;

    o_pool_descriptor.i_count_min =
        0u;

    o_pool_descriptor.i_count_max =
        0u;

    e_status =
        appl_pool_create(
            p_context,
            &(
                o_pool_descriptor),
            &(
                p_pool));

    if (
        appl_status_ok
        == e_status)
    {
        void *
            p_alloc;

        e_status =
            appl_pool_alloc(
                p_pool,
                &(
                    p_alloc));

        if (
            appl_status_ok
            == e_status)
        {

            e_status =
                appl_pool_free(
                    p_pool,
                    p_alloc);

            if (
                appl_status_ok
                == e_status)
            {
            }
            else
            {
                b_result =
                    0;
            }
        }
        else
        {
            b_result =
                0;
        }

        e_status =
            appl_object_destroy(
                appl_allocator_parent(
                    appl_pool_parent(
                        p_pool)));

        if (
            appl_status_ok
            == e_status)
        {
        }
        else
        {
            b_result =
                0;
        }
    }
    else
    {
        b_result =
            0;
    }

    return
        b_result;

} /* appl_pool_test_2() */

/*

Verify that maximum number of items is enforced.

Verify that releasing an items allows to allocate another.

*/
char
appl_pool_test_3(
    struct appl_context * const
        p_context)
{
    char
        b_result;

    enum appl_status
        e_status;

    struct appl_pool_descriptor
        o_pool_descriptor;

    struct appl_pool *
        p_pool;

    o_pool_descriptor.i_length =
        20u;

    o_pool_descriptor.i_count_min =
        0u;

    o_pool_descriptor.i_count_max =
        2u;

    e_status =
        appl_pool_create(
            p_context,
            &(
                o_pool_descriptor),
            &(
                p_pool));

    if (
        appl_status_ok
        == e_status)
    {
        void *
            a_table[3u];

        char
            b_table[3u];

        b_table[0u] =
            0;

        b_table[1u] =
            0;

        b_table[2u] =
            0;

        e_status =
            appl_pool_alloc(
                p_pool,
                &(
                    a_table[0u]));

        if (
            appl_status_ok
            == e_status)
        {
            b_table[0u] =
                1;

            e_status =
                appl_pool_alloc(
                    p_pool,
                    &(
                        a_table[1u]));

            if (
                appl_status_ok
                == e_status)
            {
                b_table[1u] =
                    1;

                e_status =
                    appl_pool_alloc(
                        p_pool,
                        &(
                            a_table[2u]));

                if (
                    appl_status_ok
                    == e_status)
                {
                    b_table[2u] =
                        1;

                    b_result =
                        0;
                }
                else
                {
                    e_status =
                        appl_pool_free(
                            p_pool,
                            a_table[0u]);

                    if (
                        appl_status_ok
                        == e_status)
                    {
                        b_table[0u] =
                            0;

                        e_status =
                            appl_pool_alloc(
                                p_pool,
                                &(
                                    a_table[2u]));

                        if (
                            appl_status_ok
                            == e_status)
                        {
                            b_table[2u] =
                                1;

                            b_result =
                                1;
                        }
                        else
                        {
                            b_result =
                                0;
                        }
                    }
                    else
                    {
                        b_result =
                            0;
                    }
                }
            }
            else
            {
                b_result =
                    0;
            }
        }
        else
        {
            b_result =
                0;
        }

        if (
            b_table[0u])
        {
            appl_pool_free(
                p_pool,
                a_table[0u]);

            b_table[0u] =
                0;
        }

        if (
            b_table[1u])
        {
            appl_pool_free(
                p_pool,
                a_table[1u]);

            b_table[1u] =
                0;
        }

        if (
            b_table[2u])
        {
            appl_pool_free(
                p_pool,
                a_table[2u]);

            b_table[2u] =
                0u;
        }

        appl_object_destroy(
            appl_allocator_parent(
                appl_pool_parent(
                    p_pool)));
    }
    else
    {
        b_result =
            0;
    }

    return
        b_result;

} /* appl_pool_test_3() */

/* end-of-file: appl_pool_test.c */
