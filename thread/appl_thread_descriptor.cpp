/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_thread_descriptor.h>

#include <appl_object.h>

#include <buf/appl_buf.h>

#include <thread/appl_thread_descriptor_impl.h>

#include <appl_heap_handle.h>

//
//
//
enum appl_status
    appl_thread_descriptor_create(
        struct appl_context * const
            p_context,
        struct appl_thread_descriptor * * const
            r_thread_descriptor)
{
    enum appl_status
        e_status;

    e_status =
        appl_new(
            p_context,
            r_thread_descriptor);

    return
        e_status;

} // _create()

//
//
//
enum appl_status
    appl_thread_descriptor_destroy(
        struct appl_thread_descriptor * const
            p_thread_descriptor)
{
    enum appl_status
        e_status;

    struct appl_context * const
        p_context =
        p_thread_descriptor->get_context();

    e_status =
        appl_delete(
            p_context,
            p_thread_descriptor);

    return
        e_status;

} // _destroy()

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
    struct appl_thread_callback
        o_callback;

    o_callback.p_entry =
        p_entry;

    o_callback.p_context =
        p_context;

    p_thread_descriptor->f_set_callback(
        &(
            o_callback));

} /* appl_thread_descriptor_set_callback() */

//
//
//
void
    appl_thread_descriptor_set_name(
        struct appl_thread_descriptor * const
            p_thread_descriptor,
        unsigned char const * const
            p_name_min,
        unsigned char const * const
            p_name_max)
{
    struct appl_buf
        o_name;

    o_name.o_min.pc_uchar =
        p_name_min;

    o_name.o_max.pc_uchar =
        p_name_max;

    p_thread_descriptor->f_set_name(
        &(
            o_name));

} // _set_name()

//
//
//
char
    appl_thread_descriptor_get_callback(
        struct appl_thread_descriptor const * const
            p_thread_descriptor,
        struct appl_thread_callback * const
            p_thread_callback)
{
    return
        p_thread_descriptor->f_get_callback(
            p_thread_callback) ? 1 : 0;

} // _get_callback()

//
//
//
char
    appl_thread_descriptor_get_name(
        struct appl_thread_descriptor const * const
            p_thread_descriptor,
        struct appl_buf * const
            p_name)
{
    return
        p_thread_descriptor->f_get_name(
            p_name) ? 1 : 0;

} // _get_name()

/* end-of-file: appl_thread_descriptor.cpp */
