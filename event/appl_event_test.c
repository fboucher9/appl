/* See LICENSE for license details */

/*

*/

#include <appl.h>

#include <event/appl_event_test.h>

#if defined APPL_HAVE_COVERAGE
#include <appl_coverage.h>
#endif /* #if defined APPL_HAVE_COVERAGE */

struct appl_event_test
{
    struct appl_context *
        p_context;

    struct appl_mutex *
        p_mutex;

    /* -- */

    unsigned long int
        i_limit;

    unsigned long int
        i_limit_max;

    /* -- */

    struct appl_event *
        p_event;

#define PADDING (APPL_SIZEOF_PTR + APPL_SIZEOF_LONG)
#include <appl_padding.h>

};

static
void
    appl_event_test_create_cb(
        struct appl_event_test * const
            p_event_test)
{
    enum appl_status
        e_status;

    struct appl_event *
        p_event;

    struct appl_event_descriptor
        o_event_descriptor;

#if defined APPL_HAVE_COVERAGE
    appl_coverage_limit(
        p_event_test->i_limit);
#endif /* #if defined APPL_HAVE_COVERAGE */

    e_status =
        appl_event_create(
            p_event_test->p_context,
            &(
                o_event_descriptor),
            &(
                p_event));

#if defined APPL_HAVE_COVERAGE
    {
        unsigned long int
            i_count;

        i_count =
            appl_coverage_query();

        appl_coverage_limit(0ul);

        if (
            p_event_test->i_limit_max < i_count)
        {
            p_event_test->i_limit_max = i_count;
        }
    }
#endif /* #if defined APPL_HAVE_COVERAGE */

    if (
        appl_status_ok
        == e_status)
    {
        appl_event_destroy(
            p_event);
    }
}

static
void
    appl_event_test_signal_cb(
        struct appl_event_test * const
            p_event_test)
{
    enum appl_status
        e_status;

#if defined APPL_HAVE_COVERAGE
    appl_coverage_limit(
        p_event_test->i_limit);
#endif /* #if defined APPL_HAVE_COVERAGE */

    e_status =
        appl_event_signal(
            p_event_test->p_event);

#if defined APPL_HAVE_COVERAGE
    {
        unsigned long int
            i_count;

        i_count =
            appl_coverage_query();

        appl_coverage_limit(0ul);

        if (
            p_event_test->i_limit_max < i_count)
        {
            p_event_test->i_limit_max = i_count;
        }
    }
#endif /* #if defined APPL_HAVE_COVERAGE */

    if (
        appl_status_ok
        == e_status)
    {
    }
}

static
void
    appl_event_test_wait_cb(
        struct appl_event_test * const
            p_event_test)
{
    enum appl_status
        e_status;

#if defined APPL_HAVE_COVERAGE
    appl_coverage_limit(
        p_event_test->i_limit);
#endif /* #if defined APPL_HAVE_COVERAGE */

    e_status =
        appl_event_wait(
            p_event_test->p_event,
            p_event_test->p_mutex,
            1000ul,
            1ul);

#if defined APPL_HAVE_COVERAGE
    {
        unsigned long int
            i_count;

        i_count =
            appl_coverage_query();

        appl_coverage_limit(0ul);

        if (
            p_event_test->i_limit_max < i_count)
        {
            p_event_test->i_limit_max = i_count;
        }
    }
#endif /* #if defined APPL_HAVE_COVERAGE */

    if (
        appl_status_ok
        == e_status)
    {
    }
}

static
void
    appl_event_test_destroy_cb(
        struct appl_event_test * const
            p_event_test)
{
    enum appl_status
        e_status;

    char
        b_event_created;

    struct appl_event *
        p_event;

    struct appl_event_descriptor
        o_event_descriptor;

    e_status =
        appl_event_create(
            p_event_test->p_context,
            &(
                o_event_descriptor),
            &(
                p_event));

    if (
        appl_status_ok
        == e_status)
    {
        b_event_created =
            1;

#if defined APPL_HAVE_COVERAGE
        appl_coverage_limit(
            p_event_test->i_limit);
#endif /* #if defined APPL_HAVE_COVERAGE */

        e_status =
            appl_event_destroy(
                p_event);

        if (
            appl_status_ok
            == e_status)
        {
            b_event_created =
                0;
        }

#if defined APPL_HAVE_COVERAGE
        {
            unsigned long int
                i_count;

            i_count =
                appl_coverage_query();

            appl_coverage_limit(0ul);

            if (
                p_event_test->i_limit_max < i_count)
            {
                p_event_test->i_limit_max = i_count;
            }
        }
#endif /* #if defined APPL_HAVE_COVERAGE */

        if (
            b_event_created)
        {
            appl_event_destroy(
                p_event);

            b_event_created =
                0;
        }
    }
}

static
void
    coverage_loop(
        void (* p_callback)(
            struct appl_event_test * const
                p_event_test),
        struct appl_event_test * const
            p_event_test)
{
    p_event_test->i_limit_max =
        0ul;

    p_event_test->i_limit =
        0ul;

    (*p_callback)(
        p_event_test);

    p_event_test->i_limit ++;

    while (
        p_event_test->i_limit <= p_event_test->i_limit_max)
    {
        (*p_callback)(
            p_event_test);

        p_event_test->i_limit ++;
    }
}

/*

*/
void
    appl_event_test_1(
        struct appl_context * const
            p_context)
{
    enum appl_status
        e_status;

    struct appl_mutex_descriptor
        o_mutex_descriptor;

    struct appl_event_descriptor
        o_event_descriptor;

    struct appl_event_test
        o_event_test;

    o_event_test.p_context =
        p_context;

    e_status =
        appl_mutex_create(
            o_event_test.p_context,
            &(
                o_mutex_descriptor),
            &(
                o_event_test.p_mutex));

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            appl_mutex_lock(
                o_event_test.p_mutex);

        if (
            appl_status_ok
            == e_status)
        {
            e_status =
                appl_event_create(
                    p_context,
                    &(
                        o_event_descriptor),
                    &(
                        o_event_test.p_event));

            if (
                appl_status_ok
                == e_status)
            {
                {
                    struct appl_object *
                        p_object;

                    p_object =
                        appl_event_parent(
                            o_event_test.p_event);

                    (void)(
                        p_object);
                }

                {
                    struct appl_object const *
                        pc_object;

                    pc_object =
                        appl_event_const_parent(
                            o_event_test.p_event);

                    (void)(
                        pc_object);
                }

                {
                    appl_event_signal(
                        o_event_test.p_event);
                }

                {
                    e_status =
                        appl_event_wait(
                            o_event_test.p_event,
                            o_event_test.p_mutex,
                            1000,
                            100);
                }

                /* Coverage tests... */
                coverage_loop(
                    &(
                        appl_event_test_create_cb),
                    &(
                        o_event_test));

                coverage_loop(
                    &(
                        appl_event_test_signal_cb),
                    &(
                        o_event_test));

                coverage_loop(
                    &(
                        appl_event_test_wait_cb),
                    &(
                        o_event_test));

                coverage_loop(
                    &(
                        appl_event_test_destroy_cb),
                    &(
                        o_event_test));

                appl_event_destroy(
                    o_event_test.p_event);
            }

            appl_mutex_unlock(
                o_event_test.p_mutex);
        }

        appl_mutex_destroy(
            o_event_test.p_mutex);
    }

} /* appl_event_test_1() */

/* end-of-file: appl_event_test.c */
