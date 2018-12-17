/* See LICENSE for license details */

/*

*/

#include <appl.h>

#include <allocator/appl_allocator_test.h>

#include <allocator/appl_allocator.h>

#include <allocator/appl_allocator_std.h>

#include <appl_coverage_test.h>

#if defined APPL_HAVE_COVERAGE
#include <appl_coverage.h>
#endif /* #if defined APPL_HAVE_COVERAGE */

//
//
//
static
unsigned long int
appl_allocator_test_alloc_cb(
    void * const
        p_context,
    unsigned long int const
        i_limit)
{
    unsigned long int
        i_count = 0ul;

    class appl_allocator_std *
        p_allocator_std =
        (struct appl_allocator_std *)(
            p_context);

    struct appl_allocator * const
        p_allocator =
        p_allocator_std;

    enum appl_status
        e_status;

    void *
        p_buffer;

#if defined APPL_HAVE_COVERAGE
    appl_coverage_start(i_limit);
#endif /* #if defined APPL_HAVE_COVERAGE */

    e_status =
        p_allocator->v_alloc(
            123u,
            &(
                p_buffer));

#if defined APPL_HAVE_COVERAGE
    i_count =
        appl_coverage_stop();
#endif /* #if defined APPL_HAVE_COVERAGE */

    if (
        appl_status_ok
        == e_status)
    {
        p_allocator->v_free(
            123u,
            p_buffer);
    }

    return
        i_count;

}

/*

*/
void
    appl_allocator_test_1(
        struct appl_context * const
            p_context)
{
    struct appl_allocator *
        p_allocator;

    enum appl_status
        e_status;

    p_allocator =
        appl_context_get_allocator(
            p_context);

    {
        class appl_allocator_std *
            p_allocator_std;

        e_status =
            appl_new(
                p_allocator,
                &(
                    p_allocator_std));

        if (
            appl_status_ok
            == e_status)
        {
            {
                struct appl_allocator * const
                    p_allocator_tmp =
                    p_allocator_std;

                p_allocator_tmp->v_alloc(
                    0,
                    0);

                p_allocator_tmp->v_free(
                    0,
                    0);
            }

            appl_coverage_test(
                &(
                    appl_allocator_test_alloc_cb),
                p_allocator_std);

            appl_delete(
                p_allocator,
                p_allocator_std);
        }
    }

    {
        class appl_allocator *
            p_allocator_dummy;

        e_status =
            appl_new(
                p_allocator,
                &(
                    p_allocator_dummy));

        if (
            appl_status_ok
            == e_status)
        {
            {
                struct appl_allocator * const
                    p_allocator_tmp =
                    p_allocator_dummy;

                p_allocator_tmp->v_alloc(
                    0,
                    0);

                p_allocator_tmp->v_free(
                    0,
                    0);
            }

            appl_delete(
                p_allocator,
                p_allocator_dummy);
        }
    }

    {
    }

} /* appl_allocator_test_1() */

/* end-of-file: appl_allocator_test.cpp */