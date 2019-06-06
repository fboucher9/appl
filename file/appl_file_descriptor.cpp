/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_file_descriptor.h>

#include <appl_heap_handle.h>

#include <appl_context_handle.h>

#include <appl_allocator_handle.h>

#include <appl_object.h>

#include <file/appl_file_std_descriptor.h>

//
//
//
appl_file_descriptor::appl_file_descriptor(
    struct appl_context * const
        p_context) :
    appl_object(
        p_context),
    p_name_min(),
    p_name_max(),
    e_type(),
    e_mode()
{
}

//
//
//
appl_file_descriptor::~appl_file_descriptor()
{
}

//
//
//
enum appl_status
    appl_file_descriptor::f_init(void)
{
    enum appl_status
        e_status;

    e_status =
        appl_status_ok;

    return
        e_status;

} // f_init()

//
//
//
appl_size_t
    appl_file_descriptor::v_cleanup(void)
{
    return
        sizeof(struct appl_file_descriptor);

} // v_cleanup()

//
//
//
enum appl_status
appl_file_descriptor_create(
    struct appl_context * const
        p_context,
    struct appl_file_descriptor * * const
        r_file_descriptor)
{
    enum appl_status
        e_status;

    struct appl_file_descriptor *
        p_file_descriptor;

    e_status =
        appl_new(
            p_context,
            &(
                p_file_descriptor));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_file_descriptor) =
            p_file_descriptor;
    }

    return
        e_status;

} // _create()

//
//
//
enum appl_status
appl_file_descriptor_destroy(
    struct appl_file_descriptor * const
        p_file_descriptor)
{
    struct appl_context * const
        p_context =
        p_file_descriptor->get_context();

    appl_delete(
        p_context,
        p_file_descriptor);

    return
        appl_status_ok;

} // _destroy()

//
//
//
enum appl_status
appl_file_descriptor_set_type(
    struct appl_file_descriptor * const
        p_file_descriptor,
    enum appl_file_type const
        e_type)
{
    p_file_descriptor->e_type =
        e_type;

    return
        appl_status_ok;

} // _set_type()

//
//
//
enum appl_status
appl_file_descriptor_set_mode(
    struct appl_file_descriptor * const
        p_file_descriptor,
    enum appl_file_mode const
        e_mode)
{
    p_file_descriptor->e_mode =
        e_mode;

    return
        appl_status_ok;

} // _set_mode()

//
//
//
enum appl_status
appl_file_descriptor_set_name(
    struct appl_file_descriptor * const
        p_file_descriptor,
    unsigned char const * const
        p_name_min,
    unsigned char const * const
        p_name_max)
{
    p_file_descriptor->p_name_min =
        p_name_min;

    p_file_descriptor->p_name_max =
        p_name_max;

    return
        appl_status_ok;

} // _set_name()

/* end-of-file: appl_file_descriptor.cpp */
