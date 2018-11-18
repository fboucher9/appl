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
    char
        b_callback;

    char
        b_name;

    char
        b_stack;

    char
        b_scheduling;

    unsigned char
        uc_reserved[4u];

    /* -- */

    struct appl_thread_descriptor_callback
    {
        void
        (* p_entry)(
            void * const
                p_thread_context);

        void *
            p_context;

    } o_callback;

    /* -- */

    struct appl_thread_descriptor_name
    {
        unsigned char const *
            p_name_min;

        unsigned char const *
            p_name_max;

    } o_name;

    /* -- */

    struct appl_thread_descriptor_stack
    {
        unsigned long int
            i_stack_size;

        unsigned long int
            ul_padding[1u];

    } o_stack;

    /* -- */

    struct appl_thread_descriptor_scheduling
    {
        unsigned long int
            i_scheme;

        unsigned long int
            i_priority;

    } o_scheduling;

    /* -- */

}; /* struct appl_thread_descriptor */

/* end-of-file: appl_thread_descriptor.h */
