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

    struct appl_context * const
        p_context =
        (struct appl_context *)(
            p_void);

    appl_ull_t
        i_clock_value;

    e_status =
        appl_clock_read(
            p_context,
            0u,
            &(
                i_clock_value));

#if defined APPL_HAVE_COVERAGE
    appl_coverage_start(i_limit);
#endif /* #if defined APPL_HAVE_COVERAGE */

    e_status =
        appl_clock_read(
            p_context,
            1000u,
            &(
                i_clock_value));

#if defined APPL_HAVE_COVERAGE
    i_count = appl_coverage_stop();
#endif /* #if defined APPL_HAVE_COVERAGE */

    (void)(
        e_status);

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

    enum appl_status
        e_status;

    struct appl_context * const
        p_context =
        (struct appl_context *)(
            p_void);

    e_status =
        appl_clock_delay(
            p_context,
            0u,
            1u);

#if defined APPL_HAVE_COVERAGE
    appl_coverage_start(i_limit);
#endif /* #if defined APPL_HAVE_COVERAGE */

    e_status =
        appl_clock_delay(
            p_context,
            1000u,
            1u);

#if defined APPL_HAVE_COVERAGE
    i_count = appl_coverage_stop();
#endif /* #if defined APPL_HAVE_COVERAGE */

    (void)(
        e_status);

    return
        i_count;

} /* appl_clock_test_1_read() */

/*

*/
void
    appl_clock_test_1(
        struct appl_context * const
            p_context)
{
    appl_coverage_test(
        &(
            appl_clock_test_1_read),
        p_context);

    appl_coverage_test(
        &(
            appl_clock_test_1_delay),
        p_context);

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
