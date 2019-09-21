/* See LICENSE for license details */

/*

*/

/* Included. */
#define INC_APPL_EVENT_TEST_H

/* Reverse include guard */
enum guard_appl_event_test_h
{
    inc_appl_event_test_h = 1
        /* Header file dependencies */
};

#include <appl_extern_c_begin.h>

void
    appl_event_test_1(
        struct appl_context * const
            p_context);

void
    appl_event_test_2(
        struct appl_context * const
            p_context);

#include <appl_extern_c_end.h>

/* end-of-file: appl_event_test.h */
