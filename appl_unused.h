/* See LICENSE for license details */

/*

*/

/* Assert compiler */
#include <appl_assert_cplusplus.h>

//
//
//
template<typename T_instance>
static
void
appl_unused(
    T_instance object, ...)
{
    static_cast<void>(
        object);
}

/* end-of-file: appl_unused.h */
