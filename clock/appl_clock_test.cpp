/* See LICENSE for license details */

/*

*/

#include <appl_predefines.h>

#include <clock/appl_clock_test.h>

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_clock_handle.h>

#include <appl_heap_handle.h>

#include <clock/appl_clock.h>

#if defined APPL_HAVE_COVERAGE
#include <appl_coverage.h>
#endif /* #if defined APPL_HAVE_COVERAGE */

#include <appl_coverage_test.h>

#include <clock/appl_clock_main.h>

#include <appl_test.h>

#include <appl_convert.h>

#include <appl_buf.h>

#include <appl_options_handle.h>

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

    unsigned long int
        i_time_freq;

#define PADDING (APPL_SIZEOF_PTR + APPL_SIZEOF_LONG)
#include <misc/appl_padding.h>

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
        static_cast<struct appl_clock_test_context *>(
            p_void);

    appl_ull_t
        i_clock_value;

#if defined APPL_HAVE_COVERAGE
    appl_coverage_start(i_limit);
#endif /* #if defined APPL_HAVE_COVERAGE */

    e_status =
        appl_clock_read(
            p_clock_test_context->p_context,
            p_clock_test_context->i_time_freq,
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
        static_cast<struct appl_clock_test_context *>(
            p_void);

    enum appl_status
        e_status;

#if defined APPL_HAVE_COVERAGE
    appl_coverage_start(i_limit);
#endif /* #if defined APPL_HAVE_COVERAGE */

    e_status =
        appl_clock_delay(
            p_clock_test_context->p_context,
            p_clock_test_context->i_time_freq,
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
    appl_print0("clock test automatic #1 ...\n");

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

    appl_print0("clock test result ");
    appl_print0(b_result ? "PASS" : "FAIL");

    p_clock_test_context->i_pass_count += b_result;
    p_clock_test_context->i_fail_count += !b_result;
    p_clock_test_context->i_total_count ++;

    appl_print0("\n... done\n");
}

static
void
    appl_clock_test_automatic_2(
        struct appl_clock_test_context * const
            p_clock_test_context)
{
    appl_print0("clock test automatic #2 ...\n");

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

    appl_print0("clock test result ");
    appl_print0(b_result ? "PASS" : "FAIL");

    p_clock_test_context->i_pass_count += b_result;
    p_clock_test_context->i_fail_count += !b_result;
    p_clock_test_context->i_total_count ++;

    appl_print0("\n... done\n");
}

static
void
    appl_clock_test_automatic_3(
        struct appl_clock_test_context * const
            p_clock_test_context)
{
    appl_print0("clock test automatic #3 ...\n");

    enum appl_status const
        e_status =
        appl_clock_delay(
            p_clock_test_context->p_context,
            1000u,
            1u);

    bool const b_result =
        (appl_status_ok == e_status);

    appl_print0("clock test result ");
    appl_print0(b_result ? "PASS" : "FAIL");

    p_clock_test_context->i_pass_count += b_result;
    p_clock_test_context->i_fail_count += !b_result;
    p_clock_test_context->i_total_count ++;

    appl_print0("\n... done\n");
}

static
void
    appl_clock_test_automatic_4(
        struct appl_clock_test_context * const
            p_clock_test_context)
{
    appl_print0("clock test automatic #4 ...\n");
    enum appl_status const
        e_status =
        appl_clock_delay(
            p_clock_test_context->p_context,
            0u,
            1u);

    bool const b_result =
        (appl_status_ok != e_status);

    appl_print0("clock test result ");
    appl_print0(b_result ? "PASS" : "FAIL");

    p_clock_test_context->i_pass_count += b_result;
    p_clock_test_context->i_fail_count += !b_result;
    p_clock_test_context->i_total_count ++;

    appl_print0("\n... done\n");
}

/*

*/
void
    appl_clock_test_1(
        struct appl_context * const
            p_context)
{
    appl_print0("=== appl_clock_test_1 ===\n");

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

    o_clock_test_context.i_time_freq =
        1000ul;

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

    o_clock_test_context.i_time_freq =
        1ul;

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

    o_clock_test_context.i_time_freq =
        1000ul;

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

    o_clock_test_context.i_time_freq =
        1000000ul;

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

    o_clock_test_context.i_time_freq =
        1000000000ul;

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

    appl_print0("clock test results: pass=");
    appl_print_lu(
        o_clock_test_context.i_pass_count);
    appl_print0(" fail=");
    appl_print_lu(
        o_clock_test_context.i_fail_count);
    appl_print0(" warn=");
    appl_print_lu(
        o_clock_test_context.i_warn_count);
    appl_print0(" total=");
    appl_print_lu(
        o_clock_test_context.i_total_count);

    appl_print0("\n^^^ appl_clock_test_1 ^^^\n");

    // base class
    {
        enum appl_status
            e_status;

        class appl_clock *
            p_clock;

        e_status =
            appl_new(
                p_context,
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
                p_context,
                p_clock);
        }
    }

    /* Coverage of appl_clock_main() */
    {
        enum appl_status
            e_status;

        struct appl_options *
            p_options;

        e_status =
            appl_options_create(
                p_context,
                &(
                    p_options));

        if (
            appl_status_ok
            == e_status)
        {
            static unsigned char const s_arg0[] =
            {
                't',
                'e',
                's',
                't',
                '_',
                'c',
                'l',
                'o',
                'c',
                'k'
            };

            static unsigned char const s_arg1[] =
            {
                'f',
                '1',
                '0',
                '0',
                '0'
            };

            static unsigned char const s_arg2[] =
            {
                'r'
            };

            static unsigned char const s_arg3[] =
            {
                'd',
                '1',
                '0',
                '0'
            };

            if (
                appl_status_ok
                == e_status)
            {
                e_status =
                    appl_options_append_argument(
                        p_options,
                        s_arg0,
                        s_arg0 + sizeof(s_arg0));
            }

            if (
                appl_status_ok
                == e_status)
            {
                e_status =
                    appl_options_append_argument(
                        p_options,
                        s_arg1,
                        s_arg1 + sizeof(s_arg1));
            }

            if (
                appl_status_ok
                == e_status)
            {
                e_status =
                    appl_options_append_argument(
                        p_options,
                        s_arg2,
                        s_arg2 + sizeof(s_arg2));
            }

            if (
                appl_status_ok
                == e_status)
            {
                e_status =
                    appl_options_append_argument(
                        p_options,
                        s_arg3,
                        s_arg3 + sizeof(s_arg3));
            }

            if (
                appl_status_ok
                == e_status)
            {
                e_status =
                    appl_options_append_argument(
                        p_options,
                        s_arg2,
                        s_arg2 + sizeof(s_arg2));
            }

            if (
                appl_status_ok
                == e_status)
            {
                e_status =
                    appl_clock_main(
                        p_context,
                        p_options,
                        0u);
            }

            appl_options_destroy(
                p_options);
        }

        if (
            appl_status_ok
            != e_status)
        {
            appl_print0("FAILED appl_clock_main test\n");
        }
        else
        {
            appl_print0("passed appl_clock_main test\n");
        }
    }

} /* appl_clock_test_1() */

/* end-of-file: appl_clock_test.c */
