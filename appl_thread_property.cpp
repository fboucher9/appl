/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_object_handle.h>

#include <appl_property_handle.h>

#include <appl_thread_property.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_property_types.h>

#include <appl_property.h>

/* unique identifier for thread descriptor structure */
/* echo -n "appl_thread_descriptor" | md5sum | cut -b1-8 */
#define APPL_THREAD_DESCRIPTOR_GUID (0x7c92e304ul)

/*

Enumeration: appl_thread_property_id

Description:

*/
enum appl_thread_property_id
{
    /* ulong unique identifier for thread descriptor structure */
    appl_thread_property_id_guid = 0,

    /* pfn for thread callback */
    appl_thread_property_id_callback = 1,

    /* ptr for thread context */
    appl_thread_property_id_context = 2,

    /* buf for name of thread */
    appl_thread_property_id_name = 3,

    /* ulong for initial stack size in bytes */
    appl_thread_property_id_stack_size = 4,

    /* ulong for initial detach state */
    appl_thread_property_id_detach_state = 5,

    /* maximum number of property ids */
    appl_thread_property_id_max = 6

}; /* enum appl_thread_property_id */

union appl_thread_property_callback
{
    void *
        p_value;

    void *
        (* p_thread_callback)(
            void * const
                p_thread_context);

};

//
//
//
struct appl_thread_property : public appl_property
{
};

/*

*/
enum appl_status
appl_thread_property_create(
    struct appl_context * const
        p_context,
    struct appl_thread_property * * const
        r_thread_property)
{
    enum appl_status
        e_status;

    struct appl_property *
        p_property;

    e_status =
        appl_property_create(
            p_context,
            appl_thread_property_id_max,
            &(
                p_property));

    if (
        appl_status_ok
        == e_status)
    {
        appl_property_set_ulong(
            p_property,
            appl_thread_property_id_guid,
            APPL_THREAD_DESCRIPTOR_GUID);

        *(
            r_thread_property) =
            static_cast<struct appl_thread_property *>(
                p_property);
    }

    return
        e_status;

} /* appl_thread_property_create() */

struct appl_property *
appl_thread_property_parent(
    struct appl_thread_property * const
        p_thread_property)
{
    return
        p_thread_property;

} /* parent() */

struct appl_property const *
appl_thread_property_const_parent(
    struct appl_thread_property const * const
        p_thread_property)
{
    return
        p_thread_property;

} /* const_parent() */

/*

*/
#if defined APPL_DEBUG
static
void
appl_thread_property_assert_guid(
    struct appl_thread_property const * const
        p_thread_property)
{
    unsigned long int
        u_value;

    if (
        (
            appl_status_ok
            == appl_property_get_ulong(
                p_thread_property,
                appl_thread_property_id_guid,
                &(
                    u_value)))
        && (
            APPL_THREAD_DESCRIPTOR_GUID == u_value))
    {
        /* valid */
    }
    else
    {
        /* invalid */
    }

} /* appl_thread_property_assert_guid() */
#endif /* #if defined APPL_DEBUG */

/*

*/
enum appl_status
appl_thread_property_set_callback(
    struct appl_thread_property * const
        p_thread_property,
    void * (* p_thread_callback)(
        void * const
            p_thread_context))
{
#if defined APPL_DEBUG
    appl_thread_property_assert_guid(
        p_thread_property);
#endif /* #if defined APPL_DEBUG */

    union appl_thread_property_callback
        o_callback;

    o_callback.p_thread_callback =
        p_thread_callback;

    return
        appl_property_set_ptr(
            p_thread_property,
            appl_thread_property_id_callback,
            o_callback.p_value);

} /* appl_thread_property_set_callback() */

/*

*/
enum appl_status
appl_thread_property_set_context(
    struct appl_thread_property * const
        p_thread_property,
    void * const
        p_thread_context)
{
#if defined APPL_DEBUG
    appl_thread_property_assert_guid(
        p_thread_property);
#endif /* #if defined APPL_DEBUG */

    return
        appl_property_set_ptr(
            p_thread_property,
            appl_thread_property_id_context,
            p_thread_context);

} /* appl_thread_property_set_context() */

/*

*/
enum appl_status
appl_thread_property_set_detach_state(
    struct appl_thread_property * const
        p_thread_property,
    unsigned char const
        b_detach_state)
{
#if defined APPL_DEBUG
    appl_thread_property_assert_guid(
        p_thread_property);
#endif /* #if defined APPL_DEBUG */

    return
        appl_property_set_ulong(
            p_thread_property,
            appl_thread_property_id_detach_state,
            b_detach_state);

} /* appl_thread_property_set_detach_state() */

/*

*/
enum appl_status
appl_thread_property_get_callback(
    struct appl_thread_property const * const
        p_thread_property,
    void * (* * r_thread_callback)(
        void * const
            p_thread_context))
{
    enum appl_status
        e_status;

#if defined APPL_DEBUG
    appl_thread_property_assert_guid(
        p_thread_property);
#endif /* #if defined APPL_DEBUG */

    union appl_thread_property_callback
        o_callback;

    e_status =
        appl_property_get_ptr(
            p_thread_property,
            appl_thread_property_id_callback,
            &(
                o_callback.p_value));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_thread_callback) =
            o_callback.p_thread_callback;
    }

    return
        e_status;

} /* appl_thread_property_get_callback() */

/*

*/
enum appl_status
appl_thread_property_get_context(
    struct appl_thread_property const * const
        p_thread_property,
    void * * const
        r_thread_context)
{
#if defined APPL_DEBUG
    appl_thread_property_assert_guid(
        p_thread_property);
#endif /* #if defined APPL_DEBUG */

    return
        appl_property_get_ptr(
            p_thread_property,
            appl_thread_property_id_context,
            r_thread_context);

} /* appl_thread_property_get_context() */

/*

*/
enum appl_status
appl_thread_property_get_detach_state(
    struct appl_thread_property const * const
        p_thread_property,
    unsigned char * const
        r_detach_state)
{
    enum appl_status
        e_status;

    unsigned long int
        i_value;

#if defined APPL_DEBUG
    appl_thread_property_assert_guid(
        p_thread_property);
#endif /* #if defined APPL_DEBUG */

    e_status =
        appl_property_get_ulong(
            p_thread_property,
            appl_thread_property_id_detach_state,
            &(
                i_value));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_detach_state) =
                i_value ? 1u : 0u;
    }

    return
        e_status;

} /* appl_thread_property_get_detach_state() */

/* end-of-file: appl_thread_property.cpp */
