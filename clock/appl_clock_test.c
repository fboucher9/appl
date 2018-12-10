/* See LICENSE for license details */

/*

*/

#include <appl.h>

#include <clock/appl_clock_test.h>

#if defined APPL_HAVE_COVERAGE
#include <appl_coverage.h>
#endif /* #if defined APPL_HAVE_COVERAGE */

/*

*/
static
void
    appl_clock_test_1_read(
        struct appl_context * const
            p_context)
{
    enum appl_status
        e_status;

    appl_ull_t
        i_clock_value;

    e_status =
        appl_clock_read(
            p_context,
            0u,
            &(
                i_clock_value));

    e_status =
        appl_clock_read(
            p_context,
            1000u,
            &(
                i_clock_value));

    (void)(
        e_status);

} /* appl_clock_test_1_read() */

static
void
    appl_clock_test_1_delay(
        struct appl_context * const
            p_context)
{
    enum appl_status
        e_status;

    e_status =
        appl_clock_delay(
            p_context,
            0u,
            1u);

    e_status =
        appl_clock_delay(
            p_context,
            1000u,
            1u);

    (void)(
        e_status);

} /* appl_clock_test_1_read() */

static
void
    appl_clock_test_1_coverage(
        void (* p_callback)(
            struct appl_context * const
                p_context),
        struct appl_context * const
            p_context)
{
#if defined APPL_HAVE_COVERAGE
    unsigned long int
        i_count;

    unsigned long int
        i_iterator;

    appl_coverage_limit(0u);

    (*p_callback)(
        p_context);

    i_count =
        appl_coverage_query();

    for (
        i_iterator = 1;
        i_iterator <= i_count;
        i_iterator ++)
    {
        appl_coverage_limit(
            i_iterator);

        (*p_callback)(
            p_context);

        appl_coverage_limit(
            0u);
    }

#else /* #if defined APPL_HAVE_COVERAGE */
    (*p_callback)(
        p_context);
#endif /* #if defined APPL_HAVE_COVERAGE */
}

/*

*/
void
    appl_clock_test_1(
        struct appl_context * const
            p_context)
{
    appl_clock_test_1_coverage(
        &(
            appl_clock_test_1_read),
        p_context);

    appl_clock_test_1_coverage(
        &(
            appl_clock_test_1_delay),
        p_context);

} /* appl_clock_test_1() */

/* end-of-file: appl_clock_test.c */
