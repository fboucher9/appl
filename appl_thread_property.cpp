/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_thread_property.h"

#include "appl_object_handle.h"

#include "appl_property_handle.h"

/* unique identifier for thread descriptor structure */
/* echo -n "appl_thread_descriptor" | md5sum | cut -b1-8 */
#define APPL_THREAD_DESCRIPTOR_GUID (unsigned long int)(0x7c92e304ul)

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

    /* maximum number of property ids */
    appl_thread_property_id_max = 5

}; /* enum appl_thread_property_id */

/*

*/
enum appl_status
appl_thread_property_create(
    struct appl_context_handle * const
        p_context_handle,
    struct appl_property_handle * * const
        r_property_handle)
{
    enum appl_status
        e_status;

    struct appl_property_handle *
        p_property_handle;

    e_status =
        appl_property_create(
            p_context_handle,
            appl_thread_property_id_max,
            &(
                p_property_handle));

    if (
        appl_status_ok
        == e_status)
    {
        appl_property_set_ulong(
            p_property_handle,
            appl_thread_property_id_guid,
            APPL_THREAD_DESCRIPTOR_GUID);

        *(
            r_property_handle) =
            p_property_handle;
    }

    return
        e_status;

} /* appl_thread_property_create() */

/*

*/
#if defined APPL_DEBUG
static
void
appl_thread_property_assert_guid(
    struct appl_property_handle const * const
        p_property_handle)
{
    unsigned long int
        u_value;

    if (
        (
            appl_status_ok
            == appl_property_get_ulong(
                p_property_handle,
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
    struct appl_property_handle * const
        p_property_handle,
    void * (* p_thread_callback)(
        void * const
            p_thread_context))
{
#if defined APPL_DEBUG
    appl_thread_property_assert_guid(
        p_property_handle);
#endif /* #if defined APPL_DEBUG */

    return
        appl_property_set_pfn(
            p_property_handle,
            appl_thread_property_id_callback,
            p_thread_callback);

} /* appl_thread_property_set_callback() */

/*

*/
enum appl_status
appl_thread_property_set_context(
    struct appl_property_handle * const
        p_property_handle,
    void * const
        p_thread_context)
{
#if defined APPL_DEBUG
    appl_thread_property_assert_guid(
        p_property_handle);
#endif /* #if defined APPL_DEBUG */

    return
        appl_property_set_ptr(
            p_property_handle,
            appl_thread_property_id_context,
            p_thread_context);

} /* appl_thread_property_set_context() */

/*

*/
enum appl_status
appl_thread_property_get_callback(
    struct appl_property_handle const * const
        p_property_handle,
    void * (* * r_thread_callback)(
        void * const
            p_thread_context))
{
#if defined APPL_DEBUG
    appl_thread_property_assert_guid(
        p_property_handle);
#endif /* #if defined APPL_DEBUG */

    return
        appl_property_get_pfn(
            p_property_handle,
            appl_thread_property_id_callback,
            r_thread_callback);

} /* appl_thread_property_get_callback() */

/*

*/
enum appl_status
appl_thread_property_get_context(
    struct appl_property_handle const * const
        p_property_handle,
    void * * const
        r_thread_context)
{
#if defined APPL_DEBUG
    appl_thread_property_assert_guid(
        p_property_handle);
#endif /* #if defined APPL_DEBUG */

    return
        appl_property_get_ptr(
            p_property_handle,
            appl_thread_property_id_context,
            r_thread_context);

} /* appl_thread_property_get_context() */

/* end-of-file: appl_thread_property.cpp */
