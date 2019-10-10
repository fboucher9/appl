/* See LICENSE for license details */

/*

*/

#include <mutex/appl_mutex_test.h>

#include <appl_status.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <mutex/appl_mutex_handle.h>

#include <heap/appl_heap_handle.h>

#include <mutex/appl_mutex_node.h>

#include <mutex/appl_mutex_mgr.h>

#if defined APPL_HAVE_COVERAGE
#include <coverage/appl_coverage.h>
#endif /* #if defined APPL_HAVE_COVERAGE */

#include <misc/appl_unused.h>

#include <stdio.h>

static
enum appl_status
    appl_mutex_test_sync_callback(
        void * const
            p_sync_context)
{
    (void)(
        p_sync_context);

    printf(
        "%s\n",
        "test mutex sync callback called");

    return
        appl_status_ok;
}

/*

*/
void
    appl_mutex_test_1(
        struct appl_context * const
            p_context)
{
    enum appl_status
        e_status;

    struct appl_mutex_descriptor
        o_mutex_descriptor;

    struct appl_mutex *
        p_mutex;

    struct appl_mutex * * const
        r_mutex_null =
        static_cast<struct appl_mutex * *>(
            0);

    struct appl_mutex * const
        p_mutex_null =
        static_cast<struct appl_mutex *>(
            0);

    struct appl_mutex const * const
        pc_mutex_null =
        static_cast<struct appl_mutex const *>(
            0);

    e_status =
        appl_mutex_create(
            p_context,
            &(
                o_mutex_descriptor),
            r_mutex_null);

    if (
        appl_status_ok
        == e_status)
    {
    }
    else
    {
    }

#if defined APPL_HAVE_COVERAGE
    appl_coverage_start(0ul);
#endif /* #if defined APPL_HAVE_COVERAGE */

    e_status =
        appl_mutex_create(
            p_context,
            &(
                o_mutex_descriptor),
            &(
                p_mutex));

#if defined APPL_HAVE_COVERAGE
    {
        unsigned long int n;
        n = appl_coverage_stop();
        printf(
            "appl_mutex_create has %lu coverage points\n", n);

        {
            unsigned long int i;
            for (i=1; i<=n; i++)
            {
                enum appl_status
                    e_temp_status;

                struct appl_mutex *
                    p_temp_mutex;

                appl_coverage_start(i);

                printf(
                    "appl_mutex_create test #%lu\n", i);

                e_temp_status =
                    appl_mutex_create(
                        p_context,
                        &(
                            o_mutex_descriptor),
                        &(
                            p_temp_mutex));

                appl_coverage_stop();

                if (
                    appl_status_ok
                    == e_temp_status)
                {
                    appl_mutex_destroy(
                        p_temp_mutex);
                }
            }
        }

    }
#endif /* #if defined APPL_HAVE_COVERAGE */

    if (
        appl_status_ok
        == e_status)
    {
        struct appl_object *
            p_object;

        struct appl_object const *
            pc_object;

        p_object =
            appl_mutex_parent(
                p_mutex_null);

        p_object =
            appl_mutex_parent(
                p_mutex);

        (void)(
            p_object);

        pc_object =
            appl_mutex_const_parent(
                pc_mutex_null);

        pc_object =
            appl_mutex_const_parent(
                p_mutex);

        (void)(
            pc_object);

        e_status =
            appl_mutex_lock(
                p_mutex_null);

        if (
            appl_status_ok
            == e_status)
        {
        }
        else
        {
        }

        e_status =
            appl_mutex_lock(
                p_mutex);

        if (
            appl_status_ok
            == e_status)
        {
            e_status =
                appl_mutex_unlock(
                    p_mutex_null);

            if (
                appl_status_ok
                == e_status)
            {
            }

            e_status =
                appl_mutex_unlock(
                    p_mutex);

            if (
                appl_status_ok
                == e_status)
            {
            }
            else
            {
            }
        }

        e_status =
            appl_mutex_sync(
                p_mutex_null,
                &(
                    appl_mutex_test_sync_callback),
                0);

        e_status =
            appl_mutex_sync(
                p_mutex,
                &(
                    appl_mutex_test_sync_callback),
                0);

        e_status =
            appl_mutex_destroy(
                p_mutex_null);

        if (
            appl_status_ok
            == e_status)
        {
        }
        else
        {
        }

        e_status =
            appl_mutex_destroy(
                p_mutex);

        if (
            appl_status_ok
            == e_status)
        {
        }
        else
        {
        }
    }
    else
    {
    }

} /* appl_mutex_test_1() */

//
//
//
void
    appl_mutex_test_2(
        struct appl_context * const
            p_context)
{
    enum appl_status
        e_status;

    {
        class appl_mutex_mgr *
            p_mutex_mgr;

        e_status =
            appl_new(
                p_context,
                &(
                    p_mutex_mgr));

        if (
            appl_status_ok
            == e_status)
        {
            e_status =
                p_mutex_mgr->v_create_node(
                    0,
                    0);

            e_status =
                p_mutex_mgr->v_destroy_node(
                    0);

            appl_delete(
                p_context,
                p_mutex_mgr);
        }
    }

    {
        struct appl_mutex *
            p_mutex_node;

        e_status =
            appl_new(
                p_context,
                &(
                    p_mutex_node));

        if (
            appl_status_ok
            == e_status)
        {
            e_status =
                p_mutex_node->v_lock();

            e_status =
                p_mutex_node->v_unlock();

            e_status =
                p_mutex_node->v_sync(
                    0,
                    0);

            appl_delete(
                p_context,
                p_mutex_node);
        }
    }

} // appl_mutex_test_2()

static
unsigned long int
    appl_mutex_test_3_step(
        struct appl_context * const
            p_context,
        unsigned long int const
            i_limit)
{
    unsigned long int
        i_count;

    enum appl_status
        e_status;

    struct appl_mutex_descriptor
        o_mutex_descriptor;

    struct appl_mutex *
        p_mutex;

#if ! defined APPL_HAVE_COVERAGE
    appl_unused(
        i_limit);
#endif /* #if ! defined APPL_HAVE_COVERAGE */

    i_count =
        0ul;

    e_status =
        appl_mutex_create(
            p_context,
            &(
                o_mutex_descriptor),
            &(
                p_mutex));

    if (
        appl_status_ok
        == e_status)
    {
#if defined APPL_HAVE_COVERAGE
        appl_coverage_start(
            i_limit);
#endif /* #if defined APPL_HAVE_COVERAGE */

        e_status =
            appl_mutex_destroy(
                p_mutex);

#if defined APPL_HAVE_COVERAGE
        i_count =
            appl_coverage_stop();
#endif /* #if defined APPL_HAVE_COVERAGE */

        if (
            appl_status_ok
            != e_status)
        {
            appl_mutex_destroy(
                p_mutex);
        }
    }

    return
        i_count;

}

//
//
//
void
    appl_mutex_test_3(
        struct appl_context * const
            p_context)
{
    unsigned long int
        i_count_max;

    unsigned long int
        i_limit;

    unsigned long int
        i_count;

    i_limit =
        0ul;

    i_count =
        0ul;

    i_count_max =
        0ul;

    do
    {
        i_count =
            appl_mutex_test_3_step(
                p_context,
                i_limit);

        if (
            i_count_max < i_count)
        {
            i_count_max = i_count;
        }

        i_limit ++;
    }
    while (
        i_limit <= i_count_max);

} // appl_mutex_test_3()

/* end-of-file: appl_mutex_test.c */
