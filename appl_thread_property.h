/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_THREAD_PROPERTY_H
#error include appl_thread_property.h once
#endif /* #if defined INC_APPL_THREAD_PROPERTY_H */

#define INC_APPL_THREAD_PROPERTY_H

/* Header file dependency */
#if ! defined INC_APPL_PROPERTY_HANDLE_H
#error include appl_property_handle.h before appl_thread_property.h
#endif /* #if ! defined INC_APPL_PROPERTY_HANDLE_H */

struct appl_context_handle;

struct appl_property_handle;

struct appl_thread_property_handle;

struct appl_thread_property_handle
{
    struct appl_property_handle
        o_property_handle;

};

#if defined __cplusplus
extern "C" {
#endif /* #if defined __cplusplus */

enum appl_status
appl_thread_property_create(
    struct appl_context_handle * const
        p_context_handle,
    struct appl_thread_property_handle * * const
        r_thread_property_handle);

enum appl_status
appl_thread_property_set_callback(
    struct appl_thread_property_handle * const
        p_thread_property_handle,
    void * (* p_thread_callback)(
        void * const
            p_thread_context));

enum appl_status
appl_thread_property_set_context(
    struct appl_thread_property_handle * const
        p_thread_property_handle,
    void * const
        p_thread_context);

enum appl_status
appl_thread_property_get_callback(
    struct appl_thread_property_handle const * const
        p_thread_property_handle,
    void * (* * r_thread_callback)(
        void * const
            p_thread_context));

enum appl_status
appl_thread_property_get_context(
    struct appl_thread_property_handle const * const
        p_thread_property_handle,
    void * * const
        r_thread_context);

#if defined __cplusplus
} /* extern "C" */
#endif /* #if defined __cplusplus */

/* end-of-file: appl_thread_property.h */
