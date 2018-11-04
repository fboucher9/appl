/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_TIMER_HANDLE_H
#error include appl_timer_handle.h once
#endif /* #if defined INC_APPL_TIMER_HANDLE_H */

#define INC_APPL_TIMER_HANDLE_H

/* Header file dependency */
#if ! defined INC_APPL_STATUS_H
#error include appl_status.h before
#endif /* #if ! defined INC_APPL_STATUS_H */

/* Header file dependency */
#if ! defined INC_APPL_TYPES_H
#error include appl_types.h before
#endif /* #if ! defined INC_APPL_TYPES_H */

/* Predefine */
struct appl_context;

/* Predefine */
struct appl_timer;

/*

*/
struct appl_timer_descriptor
{
    appl_ull_t
        i_abstime_usec;

    /* -- */

    void
        (* p_timer_callback)(
            void * const p_timer_context);

    void *
        p_timer_context;

}; /* struct appl_timer_descriptor */

#if defined __cplusplus
extern "C" {
#endif /* #if defined __cplusplus */

enum appl_status
appl_timer_create(
    struct appl_context * const
        p_context,
    struct appl_timer * * const
        r_timer);

struct appl_object *
appl_timer_parent(
    struct appl_timer * const
        p_timer);

enum appl_status
appl_timer_schedule(
    struct appl_timer * const
        p_timer,
    struct appl_timer_descriptor const * const
        p_timer_descriptor);

#if defined __cplusplus
} /* extern "C" */
#endif /* #if defined __cplusplus */

/* end-of-file: appl_timer_handle.h */
