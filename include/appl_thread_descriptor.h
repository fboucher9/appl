/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_thread_descriptor_h
{
    inc_appl_thread_descriptor_h =
        inc_appl_types_h
};

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

#define PADDING (APPL_SIZEOF_LONG)
#include <appl_padding.h>

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

#if defined __cplusplus
extern "C" {
#endif /* #if defined __cplusplus */

void
appl_thread_descriptor_init(
    struct appl_thread_descriptor * const
        p_thread_descriptor);

void
appl_thread_descriptor_set_callback(
    struct appl_thread_descriptor * const
        p_thread_descriptor,
    void (* const p_entry)(
        void * const
            p_thread_context),
    void * const
        p_context);

#if defined __cplusplus
} /* extern "C" */
#endif /* #if defined __cplusplus */

/* end-of-file: appl_thread_descriptor.h */
