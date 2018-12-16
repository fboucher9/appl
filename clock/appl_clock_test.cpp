/* See LICENSE for license details */

/*

*/

#include <clock/appl_clock_test.h>

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_clock_handle.h>

#include <appl_context_handle.h>

#include <appl_allocator_handle.h>

#include <clock/appl_clock.h>

#if defined __cplusplus
#endif /* #if defined __cplusplus */

#if defined APPL_HAVE_COVERAGE
#include <appl_coverage.h>
#endif /* #if defined APPL_HAVE_COVERAGE */

#include <appl_coverage_test.h>

#include <stdio.h>

struct appl_clock_test_context
{
    unsigned long int
        i_pass_count;

    unsigned long int
        i_fail_count;

    // --

    unsigned long int
        i_warn_count;

    unsigned long int
        i_total_count;

    // --

    struct appl_context *
        p_context;

#define PADDING (APPL_SIZEOF_PTR)
#include <appl_padding.h>

};

/*

*/
static
unsigned long int
    appl_clock_test_1_read(
        void * const
            p_void,
        unsigned long int const
            i_limit)
{
    unsigned long int
        i_count = 0ul;

    enum appl_status
        e_status;

    struct appl_clock_test_context * const
        p_clock_test_context =
        (struct appl_clock_test_context *)(
            p_void);

    appl_ull_t
        i_clock_value;

#if defined APPL_HAVE_COVERAGE
    appl_coverage_start(i_limit);
#endif /* #if defined APPL_HAVE_COVERAGE */

    e_status =
        appl_clock_read(
            p_clock_test_context->p_context,
            1000u,
            &(
                i_clock_value));

#if defined APPL_HAVE_COVERAGE
    i_count = appl_coverage_stop();
#endif /* #if defined APPL_HAVE_COVERAGE */

    if (
        0ul == i_limit)
    {
        p_clock_test_context->i_pass_count += (appl_status_ok == e_status);
        p_clock_test_context->i_fail_count += (appl_status_ok != e_status);
    }
    else
    {
        p_clock_test_context->i_pass_count += (appl_status_ok != e_status);
        p_clock_test_context->i_warn_count += (appl_status_ok == e_status);
    }
    p_clock_test_context->i_total_count ++;

    return
        i_count;

} /* appl_clock_test_1_read() */

static
unsigned long int
    appl_clock_test_1_delay(
        void * const
            p_void,
        unsigned long int const
            i_limit)
{
    unsigned long int
        i_count = 0ul;

    struct appl_clock_test_context * const
        p_clock_test_context =
        (struct appl_clock_test_context *)(
            p_void);

    enum appl_status
        e_status;

#if defined APPL_HAVE_COVERAGE
    appl_coverage_start(i_limit);
#endif /* #if defined APPL_HAVE_COVERAGE */

    e_status =
        appl_clock_delay(
            p_clock_test_context->p_context,
            1000u,
            1u);

#if defined APPL_HAVE_COVERAGE
    i_count = appl_coverage_stop();
#endif /* #if defined APPL_HAVE_COVERAGE */

    if (
        0ul == i_limit)
    {
        p_clock_test_context->i_pass_count += (appl_status_ok == e_status);
        p_clock_test_context->i_fail_count += (appl_status_ok != e_status);
    }
    else
    {
        p_clock_test_context->i_pass_count += (appl_status_ok != e_status);
        p_clock_test_context->i_warn_count += (appl_status_ok == e_status);
    }
    p_clock_test_context->i_total_count ++;

    return
        i_count;

} /* appl_clock_test_1_read() */

static
void
    appl_clock_test_automatic_1(
        struct appl_clock_test_context * const
            p_clock_test_context)
{
    printf("clock test automatic #1 ...\n");

    appl_ull_t
        i_clock_value;

    enum appl_status const
        e_status =
        appl_clock_read(
            p_clock_test_context->p_context,
            1000u,
            &(
                i_clock_value));

    bool const b_result =
        (appl_status_ok == e_status);

    printf("clock test result %s\n", b_result ? "PASS" : "FAIL");

    p_clock_test_context->i_pass_count += b_result;
    p_clock_test_context->i_fail_count += !b_result;
    p_clock_test_context->i_total_count ++;

    printf("... done\n");
}

static
void
    appl_clock_test_automatic_2(
        struct appl_clock_test_context * const
            p_clock_test_context)
{
    printf("clock test automatic #2 ...\n");

    appl_ull_t
        i_clock_value;

    enum appl_status const
        e_status =
        appl_clock_read(
            p_clock_test_context->p_context,
            0u,
            &(
                i_clock_value));

    bool const b_result =
        (appl_status_ok != e_status);

    printf("clock test result %s\n", b_result ? "PASS" : "FAIL");

    p_clock_test_context->i_pass_count += b_result;
    p_clock_test_context->i_fail_count += !b_result;
    p_clock_test_context->i_total_count ++;

    printf("... done\n");
}

static
void
    appl_clock_test_automatic_3(
        struct appl_clock_test_context * const
            p_clock_test_context)
{
    printf("clock test automatic #3 ...\n");

    enum appl_status const
        e_status =
        appl_clock_delay(
            p_clock_test_context->p_context,
            1000u,
            1u);

    bool const b_result =
        (appl_status_ok == e_status);

    printf("clock test result %s\n", b_result ? "PASS" : "FAIL");

    p_clock_test_context->i_pass_count += b_result;
    p_clock_test_context->i_fail_count += !b_result;
    p_clock_test_context->i_total_count ++;

    printf("... done\n");
}

static
void
    appl_clock_test_automatic_4(
        struct appl_clock_test_context * const
            p_clock_test_context)
{
    printf("clock test automatic #4 ...\n");
    enum appl_status const
        e_status =
        appl_clock_delay(
            p_clock_test_context->p_context,
            0u,
            1u);

    bool const b_result =
        (appl_status_ok != e_status);

    printf("clock test result %s\n", b_result ? "PASS" : "FAIL");

    p_clock_test_context->i_pass_count += b_result;
    p_clock_test_context->i_fail_count += !b_result;
    p_clock_test_context->i_total_count ++;

    printf("... done\n");
}

/*

*/
void
    appl_clock_test_1(
        struct appl_context * const
            p_context)
{
    printf("=== appl_clock_test_1 ===\n");

    struct appl_clock_test_context
        o_clock_test_context;

    o_clock_test_context.i_pass_count =
        0ul;

    o_clock_test_context.i_fail_count =
        0ul;

    o_clock_test_context.i_warn_count =
        0ul;

    o_clock_test_context.i_total_count =
        0ul;

    o_clock_test_context.p_context =
        p_context;

    appl_clock_test_automatic_1(
        &(
            o_clock_test_context));

    appl_clock_test_automatic_2(
        &(
            o_clock_test_context));

    appl_clock_test_automatic_3(
        &(
            o_clock_test_context));

    appl_clock_test_automatic_4(
        &(
            o_clock_test_context));

    appl_coverage_test(
        &(
            appl_clock_test_1_read),
        &(
            o_clock_test_context));

    appl_coverage_test(
        &(
            appl_clock_test_1_delay),
        &(
            o_clock_test_context));

    printf("clock test results: pass=%lu fail=%lu warn=%lu total=%lu\n",
        o_clock_test_context.i_pass_count,
        o_clock_test_context.i_fail_count,
        o_clock_test_context.i_warn_count,
        o_clock_test_context.i_total_count);

    printf("^^^ appl_clock_test_1 ^^^\n");

#if defined __cplusplus
    // base class
    {
        enum appl_status
            e_status;

        class appl_clock *
            p_clock;

        struct appl_allocator *
            p_allocator;

        p_allocator =
            appl_context_get_allocator(
                p_context);

        e_status =
            appl_new(
                p_allocator,
                &(
                    p_clock));

        if (
            appl_status_ok
            == e_status)
        {
            appl_ull_t
                i_count;

            e_status =
                p_clock->v_read(
                    1000u,
                    &(
                        i_count));

            e_status =
                p_clock->v_delay(
                    1000u,
                    100u);

            appl_delete(
                p_allocator,
                p_clock);
        }
    }
#endif /* #if defined __cplusplus */

} /* appl_clock_test_1() */

/* end-of-file: appl_clock_test.c */
