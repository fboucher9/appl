/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_thread_descriptor.h>

#include <appl_buf.h>

#include <thread/appl_thread_descriptor_impl.h>

//
//
//
appl_thread_descriptor::appl_thread_descriptor(
    struct appl_context * const
        r_context) :
    appl_object(
        r_context),
    b_callback(),
    b_name(),
    o_callback(),
    o_name()
{
}

//
//
//
appl_thread_descriptor::~appl_thread_descriptor()
{
}

//
//
//
enum appl_status
    appl_thread_descriptor::f_init(void)
{
    return
        appl_status_ok;

} // f_init()

//
//
//
appl_size_t
    appl_thread_descriptor::v_cleanup(void)
{
    return
        sizeof(struct appl_thread_descriptor);

} // v_cleanup()

//
//
//
void
    appl_thread_descriptor::f_set_callback(
        struct appl_thread_callback const * const
            p_thread_callback)
{
    b_callback =
        1;

    o_callback =
        *(
            p_thread_callback);

} // f_set_callback()

//
//
//
void
    appl_thread_descriptor::f_set_name(
        struct appl_buf const * const
            p_name)
{
    b_name =
        1;

    o_name =
        *(
            p_name);

} // f_set_name()

//
//
//
void
    appl_thread_descriptor::f_copy(
        struct appl_thread_descriptor const * const
            p_src_descriptor)
{
    if (
        p_src_descriptor->b_callback)
    {
        b_callback =
            1;

        o_callback =
            p_src_descriptor->o_callback;
    }

    if (
        p_src_descriptor->b_name)
    {
        b_name =
            1;

        o_name =
            p_src_descriptor->o_name;
    }

} // f_copy()

//
//
//
void
    appl_thread_descriptor::f_dispatch(void)
{
    if (o_callback.p_entry)
    {
        (*(o_callback.p_entry))(
            o_callback.p_context);
    }

} // f_dispatch()

//
//
//
bool
    appl_thread_descriptor::f_get_callback(
        struct appl_thread_callback * const
            p_thread_callback) const
{
    bool
        b_result;

    if (
        b_callback)
    {
        *(
            p_thread_callback) =
            o_callback;

        b_result =
            true;
    }
    else
    {
        b_result =
            false;
    }

    return
        b_result;

} // f_get_callback()

//
//
//
bool
    appl_thread_descriptor::f_get_name(
        struct appl_buf * const
            p_name) const
{
    bool
        b_result;

    if (
        b_name)
    {
        *(
            p_name) =
            o_name;

        b_result =
            true;
    }
    else
    {
        b_result =
            false;
    }

    return
        b_result;

} // f_get_name()

/* end-of-file: appl_thread_descriptor_impl.cpp */
