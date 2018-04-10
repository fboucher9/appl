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

    unsigned long int
        ul_padding[1u];

}; /* struct appl_thread_descriptor */

/* end-of-file: appl_thread_descriptor.h */
