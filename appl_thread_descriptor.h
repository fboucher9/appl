/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined(INC_APPL_THREAD_DESCRIPTOR_H)
#error include appl_thread_descriptor.h once
#endif /* #if defined(INC_APPL_THREAD_DESCRIPTOR_H) */

#define INC_APPL_THREAD_DESCRIPTOR_H

/*

*/
struct appl_thread_descriptor
{
    void
    (* p_entry)(
        void * const
            p_thread_context);

    void *
        p_context;

}; /* struct appl_thread_descriptor */

/* end-of-file: appl_thread_descriptor.h */
