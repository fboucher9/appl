/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined(INC_APPL_THREAD_DESCRIPTOR_H)
#error include appl_thread_descriptor.h once
#endif /* #if defined(INC_APPL_THREAD_DESCRIPTOR_H) */

#define INC_APPL_THREAD_DESCRIPTOR_H

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

    /* -- */

    unsigned char const *
        p_name_min;

    unsigned char const *
        p_name_max;

    /* -- */

    unsigned long int
        i_stack_size;

    unsigned long int
        ul_padding[1u];

}; /* struct appl_thread_descriptor */

/* end-of-file: appl_thread_descriptor.h */
