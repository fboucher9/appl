/* See LICENSE for license details */

/*

*/

#include <appl_types.h>

#include <appl_thread_descriptor.h>

/*

*/
void
appl_thread_descriptor_init(
    struct appl_thread_descriptor * const
        p_thread_descriptor)
{
    p_thread_descriptor->b_callback =
        0;

    p_thread_descriptor->b_name =
        0;

    p_thread_descriptor->b_stack =
        0;

    p_thread_descriptor->b_scheduling =
        0;

} /* appl_thread_descriptor_init() */

/*

*/
void
appl_thread_descriptor_set_callback(
    struct appl_thread_descriptor * const
        p_thread_descriptor,
    void (* const p_entry)(
        void * const
            p_thread_context),
    void * const
        p_context)
{
    p_thread_descriptor->b_callback =
        1;

    p_thread_descriptor->o_callback.p_entry =
        p_entry;

    p_thread_descriptor->o_callback.p_context =
        p_context;

} /* appl_thread_descriptor_set_callback() */

/* end-of-file: appl_thread_descriptor.cpp */
