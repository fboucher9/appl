/* See LICENSE for license details */

/*

*/

#define INC_APPL_QUEUE_TEST_H

/* Reverse include guard */
enum guard_appl_queue_test_h
{
    inc_appl_queue_test_h = 1
        /* Header file dependency */
};

struct appl_context;

#if defined __cplusplus
extern "C" {
#endif /* #if defined __cplusplus */

void
    appl_queue_test_1(
        struct appl_context * const
            p_context);

#if defined __cplusplus
} /* extern "C" */
#endif /* #if defined __cplusplus */

/* end-of-file: appl_queue_test.h */
