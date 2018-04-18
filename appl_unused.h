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

template<typename T_instance1, typename T_instance2>
static
void
appl_unused(
    T_instance1 object1,
    T_instance2 object2)
{
    static_cast<void>(
        object1);
    static_cast<void>(
        object2);
}

template<typename T_instance1, typename T_instance2, typename T_instance3>
static
void
appl_unused(
    T_instance1 object1,
    T_instance2 object2,
    T_instance3 object3)
{
    static_cast<void>(
        object1);
    static_cast<void>(
        object2);
    static_cast<void>(
        object3);
}

template<typename T_instance1, typename T_instance2, typename T_instance3, typename T_instance4>
static
void
appl_unused(
    T_instance1 object1,
    T_instance2 object2,
    T_instance3 object3,
    T_instance4 object4)
{
    static_cast<void>(
        object1);
    static_cast<void>(
        object2);
    static_cast<void>(
        object3);
    static_cast<void>(
        object4);
}

/* end-of-file: appl_unused.h */
