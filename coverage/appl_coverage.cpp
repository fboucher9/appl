/* See LICENSE for license details */

/*

*/

#if defined APPL_HAVE_COVERAGE

#include <coverage/appl_coverage.h>

static unsigned long int g_coverage_count = 0ul;

static unsigned long int g_coverage_limit = 0ul;

/*

*/
char
    appl_coverage_check(void)
{
    char
        b_result;

    g_coverage_count ++;

    if (
        g_coverage_limit)
    {
        b_result = (
            g_coverage_count
            == g_coverage_limit);
    }
    else
    {
        b_result =
            0;
    }

    return
        b_result;

} /* appl_coverage_check() */

/*

*/
void
    appl_coverage_start(
        unsigned long int const
            i_limit)
{
    g_coverage_count =
        0ul;

    g_coverage_limit =
        i_limit;

} /* appl_coverage_start() */

/*

*/
unsigned long int
    appl_coverage_stop(void)
{
    unsigned long int
        i_count;

    i_count =
        g_coverage_count;

    g_coverage_limit =
        0ul;

    return
        i_count;

} /* appl_coverage_stop() */

#endif /* #if defined APPL_HAVE_COVERAGE */

/* end-of-file: appl_coverage.cpp */
