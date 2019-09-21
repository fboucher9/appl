/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_thread_property_h
{
    inc_appl_thread_property_h =
        /* Header file dependencies */
        inc_appl_status_h
};

#include <appl_extern_c_begin.h>

enum appl_status
appl_thread_property_create(
    struct appl_context * const
        p_context,
    struct appl_thread_property * * const
        r_thread_property);

enum appl_status
appl_thread_property_destroy(
    struct appl_thread_property * const
        p_thread_property);

struct appl_property *
appl_thread_property_parent(
    struct appl_thread_property * const
        p_thread_property);

struct appl_property const *
appl_thread_property_const_parent(
    struct appl_thread_property const * const
        p_thread_property);

enum appl_status
appl_thread_property_set_detach_state(
    struct appl_thread_property * const
        p_thread_property,
    unsigned char const
        b_detach_state);

enum appl_status
appl_thread_property_get_detach_state(
    struct appl_thread_property const * const
        p_thread_property,
    unsigned char * const
        r_detach_state);

#include <appl_extern_c_end.h>

/* end-of-file: appl_thread_property.h */
