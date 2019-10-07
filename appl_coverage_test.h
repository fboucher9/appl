/* See LICENSE for license details */

/*

*/

/* Included. */
#define INC_APPL_COVERAGE_TEST

/* Reverse include guard */
enum guard_appl_coverage_test
{
    inc_appl_coverage_test = 1
};

#include <misc/appl_extern_c_begin.h>

unsigned long int
    appl_coverage_test(
        unsigned long int (* const p_callback)(
            void * const
                p_context,
            unsigned long int const
                i_iterator),
        void * const
            p_context);

#include <misc/appl_extern_c_end.h>

/* end-of-file: appl_coverage_test.h */
