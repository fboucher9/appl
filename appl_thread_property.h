/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_THREAD_PROPERTY_H
#error include appl_thread_property.h once
#endif /* #if defined INC_APPL_THREAD_PROPERTY_H */

#define INC_APPL_THREAD_PROPERTY_H

struct appl_context;

struct appl_property;

struct appl_thread_property;

#if defined __cplusplus
extern "C" {
#endif /* #if defined __cplusplus */

enum appl_status
appl_thread_property_create(
    struct appl_context * const
        p_context,
    struct appl_thread_property * * const
        r_thread_property);

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

#if defined __cplusplus
} /* extern "C" */
#endif /* #if defined __cplusplus */

/* end-of-file: appl_thread_property.h */
