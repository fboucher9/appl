/* See LICENSE for license details */

/*

*/

#include <appl.h>

#include <object/appl_object_test.h>

#include <stdio.h>

/*

*/
void
    appl_object_test_1(
        struct appl_context * const
            p_context)
{
    printf("=== appl_object_test_1 ===\n");

    struct appl_object *
        p_object;

    p_object =
        appl_context_parent(
            p_context);

    {
        struct appl_context *
            p_result;

        p_result =
            appl_object_get_context(
                p_object);

        (void)(
            p_result);
    }

    {
        static unsigned char g_placement[64u];
        appl_object::operator new(123u);
        appl_object::operator new(123u, g_placement);
        appl_object::operator delete(g_placement, g_placement);
        appl_object::operator delete(g_placement);
    }

    printf("^^^ appl_object_test_1 ^^^\n");

} /* appl_object_test_1() */

/*

*/
void
    appl_object_test_2(
        struct appl_context * const
            p_context)
{
    printf("=== appl_object_test_2 ===\n");

    struct appl_object *
        p_dummy_object;

    enum appl_status
        e_status;

    e_status =
        appl_new(
            p_context,
            &(
                p_dummy_object));

    if (
        appl_status_ok
        == e_status)
    {
        appl_delete(
            p_context,
            p_dummy_object);
    }

    printf("^^^ appl_object_test_2 ^^^\n");

} /* appl_object_test_2() */

/* end-of-file: appl_object_test.cpp */
