/* See LICENSE for license details */

/*

*/

#include <heap/appl_heap_test.h>

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <allocator/appl_allocator.h>

#include <heap/appl_heap.h>

#include <appl_heap_handle.h>

#include <appl_context_handle.h>

#if defined APPL_HAVE_COVERAGE
#include <appl_coverage.h>
#endif /* #if defined APPL_HAVE_COVERAGE */

#include <heap/appl_heap_std.h>

#include <appl_list.h>

#if defined APPL_OS_LINUX
#include <pthread.h>
#else
#include <windows.h>
#endif

#include <mutex/appl_mutex_impl.h>

#include <heap/appl_heap_primary.h>

#include <heap/appl_heap_impl.h>

#include <stdio.h>

//
//
//
void
    appl_heap_test_1(
        struct appl_context * const
            p_context)
{
    printf("=== appl_heap_test_1 ===\n");

    enum appl_status
            e_status;

    // Normal heap alloc test
    {
        void *
            p_buffer;

        appl_size_t
            i_buffer_length;

        i_buffer_length =
            123u;

        e_status =
            appl_heap_alloc(
                p_context,
                i_buffer_length,
                &(
                    p_buffer));

        if (
            appl_status_ok
            == e_status)
        {
            appl_heap_free(
                p_context,
                i_buffer_length,
                p_buffer);
        }
    }

    // Test of heap base class
    {
        struct appl_heap *
            p_heap;

        printf("heap base test {...\n");

        e_status =
            appl_new(
                p_context,
                &(
                    p_heap));

        if (
            appl_status_ok
            == e_status)
        {
            printf("heap base test - v_alloc {...\n");

            e_status =
                p_heap->v_alloc(
                    0u,
                    0);

            printf("heap base test - v_alloc ...}\n");

            printf("heap base test - v_free {...\n");

            e_status =
                p_heap->v_free(
                    0u,
                    0);

            printf("heap base test - v_free ...}\n");

            appl_delete(
                p_context,
                p_heap);
        }

        printf("heap base test ...}\n");
    }

    // Coverage testing of alloc and free
#if defined APPL_HAVE_COVERAGE
    {
        unsigned long int n_max;
        unsigned long int i;
        unsigned long int n;
        i = 0u;
        n = 0u;
        n_max = 0u;
        do
        {
            appl_coverage_start(i);

            void *
                p_buffer;

            appl_size_t const
                i_buffer_length =
                123u;

            e_status =
                appl_heap_alloc(
                    p_context,
                    i_buffer_length,
                    &(
                        p_buffer));

            n = appl_coverage_stop();
            if (n_max < n)
            {
                n_max = n;
                printf("appl_heap_alloc max coverage is %lu\n", n_max);
            }

            if (
                appl_status_ok
                == e_status)
            {
                appl_heap_free(
                    p_context,
                    i_buffer_length,
                    p_buffer);
            }

            i++;
        }
        while (
            i <= n_max)
            ;
    }
#endif /* #if defined APPL_HAVE_COVERAGE */

    // Test of std deleting destructor
    {
        class appl_heap_std *
            p_heap_std;

        e_status =
            appl_new(
                p_context,
                &(
                    p_heap_std));

        if (
            appl_status_ok
            == e_status)
        {
            appl_delete(
                p_context,
                p_heap_std);
        }
    }

    // Test of appl_heap_impl module
    {
        class appl_heap_impl
            o_heap_impl;

        static unsigned char g_mmap[2048u];

        e_status =
            o_heap_impl.f_init(
                g_mmap,
                g_mmap + sizeof(g_mmap));

        if (
            appl_status_ok
            == e_status)
        {
            unsigned long int i;

            // Allocate small
            for (i = 0; i < 2; i++)
            {
                void *
                    p_buffer;

                appl_size_t const
                    i_buffer_length =
                    64u;

                e_status =
                    o_heap_impl.f_alloc(
                        i_buffer_length,
                        &(
                            p_buffer));

                if (
                    appl_status_ok
                    == e_status)
                {
                    o_heap_impl.f_free(
                        i_buffer_length,
                        p_buffer);
                }
            }

            // Allocate large
            for (i = 0; i < 2; i++)
            {
                void *
                    p_buffer;

                appl_size_t const
                    i_buffer_length =
                    5000u;

                e_status =
                    o_heap_impl.f_alloc(
                        i_buffer_length,
                        &(
                            p_buffer));

                if (
                    appl_status_ok
                    == e_status)
                {
                    o_heap_impl.f_free(
                        i_buffer_length,
                        p_buffer);
                }
            }

            // Verify grow
            {
                void *
                    p_buffer;

                appl_size_t const
                    i_buffer_length =
                    3000u;

                e_status =
                    o_heap_impl.f_alloc(
                        i_buffer_length,
                        &(
                            p_buffer));

                if (
                    appl_status_ok
                    == e_status)
                {
                    o_heap_impl.f_free(
                        i_buffer_length,
                        p_buffer);
                }
            }

            // Verify grow failure
            {
            }

            o_heap_impl.f_cleanup();
        }
    }

    // Test of leak report
    {
        struct appl_context *
            p_context_temp;

        e_status =
            appl_context_create(
                &(
                    p_context_temp));

        if (
            appl_status_ok
            == e_status)
        {
            void *
                p_buffer;

            appl_heap_alloc(
                p_context_temp,
                123u,
                &(
                    p_buffer));

            appl_context_destroy(
                p_context_temp);
        }
    }

    printf("^^^ appl_heap_test_1 ^^^\n");

} // appl_heap_test_1()

/* end-of-file: appl_heap_test.cpp */
