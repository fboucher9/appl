/* See LICENSE for license details */

/*

*/

#include <appl.h>

#include <event/appl_event_test.h>

#if defined APPL_HAVE_COVERAGE
#include <appl_coverage.h>
#endif /* #if defined APPL_HAVE_COVERAGE */

#include <appl_coverage_test.h>

#include <event/appl_event_node.h>

#include <event/appl_event_mgr.h>

#include <appl_unused.h>

struct appl_event_test
{
    struct appl_context *
        p_context;

    struct appl_mutex *
        p_mutex;

    /* -- */

    struct appl_event *
        p_event;

#define PADDING (APPL_SIZEOF_PTR)
#include <appl_padding.h>

};

union appl_event_test_ptr
{
    void *
        p_callback_context;

    struct appl_event_test *
        p_event_test;

};

static
unsigned long int
    appl_event_test_create_cb(
        void * const
            p_context,
        unsigned long int const
            i_limit)
{
    unsigned long int
        i_count = 0ul;

    enum appl_status
        e_status;

    union appl_event_test_ptr
        o_event_test_ptr;

    struct appl_event_test *
        p_event_test;

    struct appl_event *
        p_event;

    struct appl_event_descriptor
        o_event_descriptor;

#if ! defined APPL_HAVE_COVERAGE
    appl_unused(
        i_limit);
#endif /* #if ! defined APPL_HAVE_COVERAGE */

    o_event_test_ptr.p_callback_context =
        p_context;

    p_event_test =
        o_event_test_ptr.p_event_test;

#if defined APPL_HAVE_COVERAGE
    appl_coverage_start(
        i_limit);
#endif /* #if defined APPL_HAVE_COVERAGE */

    e_status =
        appl_event_create(
            p_event_test->p_context,
            &(
                o_event_descriptor),
            &(
                p_event));

#if defined APPL_HAVE_COVERAGE
    i_count =
        appl_coverage_stop();
#endif /* #if defined APPL_HAVE_COVERAGE */

    if (
        appl_status_ok
        == e_status)
    {
        appl_event_destroy(
            p_event);
    }

    return
        i_count;
}

static
unsigned long int
    appl_event_test_signal_cb(
        void * const
            p_context,
        unsigned long int const
            i_limit)
{
    unsigned long int
        i_count = 0ul;

    union appl_event_test_ptr
        o_event_test_ptr;

    o_event_test_ptr.p_callback_context =
        p_context;

    struct appl_event_test *
        p_event_test =
        o_event_test_ptr.p_event_test;

    enum appl_status
        e_status;

#if ! defined APPL_HAVE_COVERAGE
    appl_unused(
        i_limit);
#endif /* #if ! defined APPL_HAVE_COVERAGE */

#if defined APPL_HAVE_COVERAGE
    appl_coverage_start(
        i_limit);
#endif /* #if defined APPL_HAVE_COVERAGE */

    e_status =
        appl_event_signal(
            p_event_test->p_event);

#if defined APPL_HAVE_COVERAGE
    i_count =
        appl_coverage_stop();
#endif /* #if defined APPL_HAVE_COVERAGE */

    if (
        appl_status_ok
        == e_status)
    {
    }

    return
        i_count;

}

static
unsigned long int
    appl_event_test_wait_cb(
        void * const
            p_context,
        unsigned long int const
            i_limit)
{
    unsigned long int
        i_count = 0ul;

    union appl_event_test_ptr
        o_event_test_ptr;

    o_event_test_ptr.p_callback_context =
        p_context;

    struct appl_event_test *
        p_event_test =
        o_event_test_ptr.p_event_test;

    enum appl_status
        e_status;

#if ! defined APPL_HAVE_COVERAGE
    appl_unused(
        i_limit);
#endif /* #if ! defined APPL_HAVE_COVERAGE */

#if defined APPL_HAVE_COVERAGE
    appl_coverage_start(
        i_limit);
#endif /* #if defined APPL_HAVE_COVERAGE */

    e_status =
        appl_event_wait(
            p_event_test->p_event,
            p_event_test->p_mutex,
            1000ul,
            1ul);

#if defined APPL_HAVE_COVERAGE
    i_count =
        appl_coverage_stop();
#endif /* #if defined APPL_HAVE_COVERAGE */

    if (
        appl_status_ok
        == e_status)
    {
    }

    return
        i_count;

}

static
unsigned long int
    appl_event_test_destroy_cb(
        void * const
            p_context,
        unsigned long int const
            i_limit)
{
    unsigned long int
        i_count = 0ul;

    enum appl_status
        e_status;

#if ! defined APPL_HAVE_COVERAGE
    appl_unused(
        i_limit);
#endif /* #if ! defined APPL_HAVE_COVERAGE */

    union appl_event_test_ptr
        o_event_test_ptr;

    o_event_test_ptr.p_callback_context =
        p_context;

    struct appl_event_test *
        p_event_test =
        o_event_test_ptr.p_event_test;

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
#if defined APPL_HAVE_COVERAGE
        appl_coverage_start(
            i_limit);
#endif /* #if defined APPL_HAVE_COVERAGE */

        e_status =
            appl_event_destroy(
                p_event);

#if defined APPL_HAVE_COVERAGE
        i_count =
            appl_coverage_stop();
#endif /* #if defined APPL_HAVE_COVERAGE */

        if (
            appl_status_ok
            != e_status)
        {
            appl_event_destroy(
                p_event);
        }
    }

    return
        i_count;

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
                if (1)
                {
                    appl_coverage_test(
                        &(
                            appl_event_test_create_cb),
                        &(
                            o_event_test));
                }

                if (1)
                {
                    appl_coverage_test(
                        &(
                            appl_event_test_signal_cb),
                        &(
                            o_event_test));
                }

                if (1)
                {
                    appl_coverage_test(
                        &(
                            appl_event_test_wait_cb),
                        &(
                            o_event_test));
                }

                if (1)
                {
                    appl_coverage_test(
                        &(
                            appl_event_test_destroy_cb),
                        &(
                            o_event_test));
                }

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

/*

*/
void
appl_event_test_2(
    struct appl_context * const
        p_context)
{
    enum appl_status
        e_status;

    {
        struct appl_event *
            p_event_node;

        e_status =
            appl_new(
                p_context,
                &(
                    p_event_node));

        if (
            appl_status_ok
            == e_status)
        {
            p_event_node->v_signal();

            p_event_node->v_wait(
                0,
                0,
                0);

            appl_delete(
                p_context,
                p_event_node);
        }
    }

    {
        class appl_event_mgr *
            p_event_mgr;

        e_status =
            appl_new(
                p_context,
                &(
                    p_event_mgr));

        if (
            appl_status_ok
            == e_status)
        {
            p_event_mgr->v_create_node(
                0,
                0);

            p_event_mgr->v_destroy_node(
                0);

            appl_delete(
                p_context,
                p_event_mgr);
        }
    }

}

/* end-of-file: appl_event_test.c */
