/* See LICENSE for license details */

/*

*/

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
template<typename T_instance>
static
void
appl_unused(
    T_instance object)
{
    static_cast<void>(
        object);
}

/* end-of-file: appl_unused.h */
