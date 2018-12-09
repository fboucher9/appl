/* See LICENSE for license details */

/*

Module: appl_coverage.h

Description:

    Code coverage utility functions.  In order to acheive 100% code coverage
    we must simulate errors, to cover error handling lines and error handling
    functions.

Comments:

    To use the appl_coverage module from a test application, the first step is
    to detect the number of control points.  This is done by running the test
    with the coverage module disabled and to query the coverage counter.

        appl_coverage_limit( 0);
        appl_test_routine( p_context);
        nb_points = appl_coverage_query();

    The next step is to re-execute the test with the coverage module enabled
    and select a limit.

        for (i=1; i<=nb_points; i++)
        {
            appl_coverage_limit( i);
            appl_test_routine( p_context);
        }

*/

/* Included. */
#define INC_APPL_COVERAGE_H

/* Reverse include guard */
enum guard_appl_coverage_h
{
    inc_appl_coverage_h = 1
        /* Header file dependencies */
};

/* Assert configuration */
#if ! defined APPL_HAVE_COVERAGE
#error "include only if coverage is enabled"
#endif /* #if ! defined APPL_HAVE_COVERAGE */

#if defined __cplusplus
extern "C" {
#endif /* #if defined __cplusplus */

void
    appl_coverage_limit(
        unsigned long int const
            i_limit);

unsigned long int
    appl_coverage_query(void);

char
    appl_coverage_check(void);

#if defined __cplusplus
} /* extern "C" */
#endif /* #if defined __cplusplus */

/* end-of-file: appl_coverage.h */