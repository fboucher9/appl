/* See LICENSE for license details */

/*

*/

#include <appl.h>

#include <context/appl_context_test.h>

#include <context/appl_context.h>

#include <misc/appl_unused.h>

static void appl_context_test_1_base(
    struct appl_context * const
        p_context)
{
    {
        struct appl_allocator *
            p_allocator;

        p_allocator =
            p_context->v_allocator();

        appl_unused(
            p_allocator);
    }

#if 0
    p_context->v_backtrace(
        0);
#endif

    {
        class appl_backtrace *
            p_backtrace;

        p_context->v_backtrace(
            &(
                p_backtrace));
    }

#if 0
    p_context->v_thread_mgr(
        0);
#endif

    {
        class appl_thread_mgr *
            p_thread_mgr;

        p_context->v_thread_mgr(
            &(
                p_thread_mgr));
    }

#if 0
    p_context->v_mutex_mgr(
        0);
#endif

    {
        class appl_mutex_mgr *
            p_mutex_mgr;

        p_context->v_mutex_mgr(
            &(
                p_mutex_mgr));
    }

#if 0
    p_context->v_file_mgr(
        0);
#endif

    {
        class appl_file_mgr *
            p_file_mgr;

        p_context->v_file_mgr(
            &(
                p_file_mgr));
    }

#if 0
    p_context->v_poll_mgr(
        0);
#endif

    {
        class appl_poll_mgr *
            p_poll_mgr;

        p_context->v_poll_mgr(
            &(
                p_poll_mgr));
    }

#if 0
    p_context->v_clock(
        0);
#endif

    {
        class appl_clock *
            p_clock;

        p_context->v_clock(
            &(
                p_clock));
    }

#if 0
    p_context->v_env(
        0);
#endif

    {
        struct appl_env *
            p_env;

        p_context->v_env(
            &(
                p_env));
    }

#if 0
    p_context->v_library_mgr(
        0);
#endif

    {
        class appl_library_mgr *
            p_library_mgr;

        p_context->v_library_mgr(
            &(
                p_library_mgr));
    }

#if 0
    p_context->v_random_mgr(
        0);
#endif

    {
        class appl_random_mgr *
            p_random_mgr;

        p_context->v_random_mgr(
            &(
                p_random_mgr));
    }

#if 0
    p_context->v_thread_cache_mgr(
        0);
#endif

    {
        class appl_thread_cache_mgr *
            p_thread_cache_mgr;

        p_context->v_thread_cache_mgr(
            &(
                p_thread_cache_mgr));
    }

#if 0
    p_context->v_log(
        0);
#endif

    {
        struct appl_log *
            p_log;

        p_context->v_log(
            &(
                p_log));
    }

#if 0
    p_context->v_pool_mgr(
        0);
#endif

    {
        class appl_pool_mgr *
            p_pool_mgr;

        p_context->v_pool_mgr(
            &(
                p_pool_mgr));
    }

#if 0
    p_context->v_timer_mgr(
        0);
#endif

    {
        class appl_timer_mgr *
            p_timer_mgr;

        p_context->v_timer_mgr(
            &(
                p_timer_mgr));
    }

#if defined APPL_HAVE_XLIB
#if 0
    p_context->v_xlib(
        0);
#endif

    {
        struct appl_xlib *
            p_xlib;

        p_context->v_xlib(
            &(
                p_xlib));
    }
#endif /* #if defined APPL_HAVE_XLIB */

#if 0
    p_context->v_socket_mgr(
        0);
#endif

    {
        class appl_socket_mgr *
            p_socket_mgr;

        p_context->v_socket_mgr(
            &(
                p_socket_mgr));
    }

#if 0
    p_context->v_event_mgr(
        0);
#endif

    {
        class appl_event_mgr *
            p_event_mgr;

        p_context->v_event_mgr(
            &(
                p_event_mgr));
    }

#if defined APPL_DEBUG
#if 0
    p_context->v_debug(
        0);
#endif

    {
        class appl_debug *
            p_debug;

        p_context->v_debug(
            &(
                p_debug));
    }
#endif /* #if defined APPL_DEBUG */

}

void
appl_context_test_1(
    struct appl_context * const
        p_context)
{
    appl_unused(
        p_context);

    // test of api via base class
    {
        appl_context_test_1_base(
            p_context);
    }

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

    // base class
    {
        struct appl_context *
            p_context_base;

        struct appl_allocator *
            p_allocator;

        enum appl_status
            e_status;

        p_allocator =
            appl_context_get_allocator(
                p_context);

        e_status =
            appl_new(
                p_allocator,
                &(
                    p_context_base));

        if (
            appl_status_ok
            == e_status)
        {
            appl_context_test_1_base(
                p_context_base);

            appl_delete(
                p_allocator,
                p_context_base);
        }
    }

    // Verify use after cleanup
    {
        struct appl_context *
            p_context_temp;

        enum appl_status
            e_status;

        e_status =
            appl_context_create(
                &(
                    p_context_temp));

        if (
            appl_status_ok
            == e_status)
        {
            p_context_temp->v_cleanup();

            appl_context_test_1_base(
                p_context_temp);

            appl_context_destroy(
                p_context_temp);
        }
    }

} // appl_context_test_1()

/* end-of-file: appl_context_test.cpp */
