/* See LICENSE for license details */

/*

*/

/* Assert configuration */
#if ! defined APPL_DEBUG
#error include only from debug build
#endif /* #if ! defined APPL_DEBUG */

#include <appl_extern_c_begin.h>

void
    appl_debug_test_1(
        struct appl_context * const
            p_context);

void
    appl_debug_test_2(
        struct appl_context * const
            p_context);

#include <appl_extern_c_end.h>

/* end-of-file: appl_debug_test.h */
