/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_thread_descriptor_h
{
    inc_appl_thread_descriptor_h = 1
        /* Header file dependencies */
        + inc_appl_types_h
};

/* Predefine */
struct appl_context;

/* Predefine */
struct appl_thread_descriptor;

/* Predefine */
struct appl_buf;

/*

*/
struct appl_thread_callback
{
    void (* p_entry)(
        void * const
            p_context);

    void *
        p_context;

}; /* struct appl_thread_callback */

#include <appl_extern_c_begin.h>

enum appl_status
    appl_thread_descriptor_create(
        struct appl_context * const
            p_context,
        struct appl_thread_descriptor * * const
            r_thread_descriptor);

enum appl_status
    appl_thread_descriptor_destroy(
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

void
    appl_thread_descriptor_set_name(
        struct appl_thread_descriptor * const
            p_thread_descriptor,
        unsigned char const * const
            p_name_min,
        unsigned char const * const
            p_name_max);

char
    appl_thread_descriptor_get_callback(
        struct appl_thread_descriptor const * const
            p_thread_descriptor,
        struct appl_thread_callback * const
            p_thread_callback);

char
    appl_thread_descriptor_get_name(
        struct appl_thread_descriptor const * const
            p_thread_descriptor,
        struct appl_buf * const
            p_name);

#include <appl_extern_c_end.h>

/* end-of-file: appl_thread_descriptor.h */
