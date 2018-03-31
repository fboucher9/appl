/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined(INC_APPL_THREAD_DESCRIPTOR_H)
#error include appl_thread_descriptor.h once
#endif /* #if defined(INC_APPL_THREAD_DESCRIPTOR_H) */

#define INC_APPL_THREAD_DESCRIPTOR_H

/* Header file dependency */
#if ! defined INC_APPL_BUF_H
#error include appl_buf.h before
#endif /* #if ! defined INC_APPL_BUF_H */

typedef
void *
(appl_thread_callback)(
    void * const
        p_thread_context);

/*

*/
struct appl_thread_descriptor
{
    appl_thread_callback *
        p_entry;

    void *
        p_context;

    struct appl_buf
        o_name;

    unsigned long int
        i_stack_size;

}; /* struct appl_thread_descriptor */

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

/* end-of-file: appl_thread_descriptor.h */
