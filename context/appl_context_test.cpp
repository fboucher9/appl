/* See LICENSE for license details */

/*

*/

#include <appl.h>

#include <context/appl_context_test.h>

#include <context/appl_context.h>

#include <appl_unused.h>

void
appl_context_test_1(
    struct appl_context * const
        p_context)
{
    appl_unused(
        p_context);

    // Invalid param for create
    {
        enum appl_status
            e_status;

        e_status =
            appl_context_create(
                0);

        appl_unused(
            e_status);
    }

    // Invalid param for destroy
    {
        enum appl_status
            e_status;

        e_status =
            appl_context_destroy(
                0);

        appl_unused(
            e_status);
    }

    // Invalid param for parent
    {
        struct appl_object *
            p_object;

        p_object =
            appl_context_parent(
                0);

        appl_unused(
            p_object);
    }

    // Invalid param for const parent
    {
        struct appl_object const *
            pc_object;

        pc_object =
            appl_context_const_parent(
                0);

        appl_unused(
            pc_object);
    }

    // Invalid param for get allocator
    {
        struct appl_allocator *
            p_allocator;

        p_allocator =
            appl_context_get_allocator(
                0);

        appl_unused(
            p_allocator);
    }

} // appl_context_test_1()

/* end-of-file: appl_context_test.cpp */
