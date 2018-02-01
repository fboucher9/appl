/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_object_handle.h"

#include "appl_context_handle.h"

#include "appl_types.h"

#include "appl_buf.h"

#include "appl_object.h"

#include "appl_context.h"

#include "appl_heap.h"

#include "appl_heap_std.h"

#include "appl_options.h"

#include "appl_options_std.h"

#include "appl_thread_mgr.h"

#include "appl_thread_std_mgr.h"

static
enum appl_status
appl_context_init_options(
    class appl_context * const
        p_context,
    struct appl_context_descriptor const * const
        p_context_descriptor)
{
    enum appl_status
        e_status;

    struct appl_options_std_descriptor
        o_options_std_descriptor;

    o_options_std_descriptor.p_arg_min =
        p_context_descriptor->p_arg_min;

    o_options_std_descriptor.p_arg_max =
        p_context_descriptor->p_arg_max;

    class appl_options *
        p_options;

    e_status =
        appl_options_std::create_instance(
            p_context,
            &(
                o_options_std_descriptor),
            &(
                p_options));

    if (
        appl_status_ok == e_status)
    {
        p_context->m_options =
            p_options;

    }

    return
        e_status;

} /* appl_context_init_options() */

/*

*/
static
enum appl_status
appl_context_init_thread_mgr(
    class appl_context * const
        p_context)
{
    enum appl_status
        e_status;

    class appl_thread_mgr *
        p_thread_mgr;

    e_status =
        appl_thread_std_mgr::create_instance(
            p_context,
            &(
                p_thread_mgr));

    if (
        appl_status_ok == e_status)
    {
        p_context->m_thread_mgr =
            p_thread_mgr;
    }

    return
        e_status;

} /* appl_context_init_thread_mgr() */

/*

*/
enum appl_status
appl_context_create(
    struct appl_context_descriptor const * const
        p_context_descriptor,
    struct appl_context_handle * * const
        r_context_handle)
{
    enum appl_status
        e_status;

    class appl_heap *
        p_heap;

    e_status =
        appl_heap_std::create_instance(
            &(
                p_heap));

    if (
        appl_status_ok
        == e_status)
    {
        class appl_context *
            p_context;

        e_status =
            appl_context::create_instance(
                p_heap,
                &(
                    p_context));

        if (
            appl_status_ok == e_status)
        {
            // unreference heap, it now belongs to context

            // create the options
            e_status =
                appl_context_init_options(
                    p_context,
                    p_context_descriptor);

            if (
                appl_status_ok == e_status)
            {
                // unreference options, it now belongs to context

                // create the thread manager
                e_status =
                    appl_context_init_thread_mgr(
                        p_context);

                if (
                    appl_status_ok == e_status)
                {
                    // unreference thread manager, it now belongs to context

                    *(
                        r_context_handle) =
                        reinterpret_cast<struct appl_context_handle *>(
                            p_context);
                }
            }

            if (
                appl_status_ok != e_status)
            {
                p_context->destroy();
            }
        }
        else
        {
            p_heap->destroy();
        }
    }

    return
        e_status;

} /* appl_context_create() */

