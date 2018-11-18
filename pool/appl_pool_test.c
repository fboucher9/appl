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

    b_result =
        1;

    e_status =
        appl_pool_create(
            p_context,
            20u,
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

    b_result =
        1;

    e_status =
        appl_pool_create(
            p_context,
            20u,
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

/* end-of-file: appl_pool_test.c */
