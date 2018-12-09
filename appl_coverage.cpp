/* See LICENSE for license details */

/*

*/

#if defined APPL_HAVE_COVERAGE

#include <appl_coverage.h>

static unsigned long int g_coverage_count = 0ul;

static unsigned long int g_coverage_limit = 0ul;

/*

*/
void
    appl_coverage_limit(
        unsigned long int const
            i_limit)
{
    g_coverage_count =
        0ul;

    g_coverage_limit =
        i_limit;

} /* appl_coverage_limit() */

/*

*/
unsigned long int
    appl_coverage_query(void)
{
    return
        g_coverage_count;

} /* appl_coverage_query() */

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
            >= g_coverage_limit);
    }
    else
    {
        b_result =
            0;
    }

    return
        b_result;

} /* appl_coverage_check() */

#endif /* #if defined APPL_HAVE_COVERAGE */

/* end-of-file: appl_coverage.cpp */
