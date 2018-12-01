/* See LICENSE for license details */

/*

Module: appl_timer_handle.h

Description:

    Scheduling of application callbacks at specified time.

Example:

    Schedule a timer event in 2 seconds from now:

        static void in2secs_event(void* p_context)
        {
            ...
        }

        void in2secs(
            struct appl_context * p_context,
            struct appl_timer * p_timer)
        {
            appl_ull_t i_now_usec;
            struct appl_timer_descriptor o_descriptor;
            appl_clock_read(p_context, 1000000ul, &i_now_usec);
            o_descriptor.i_abstime_usec = i_now_usec + 2000000ul;
            o_descriptor.p_timer_callback = &in2secs_event;
            o_descriptor.p_timer_context = p_context;
            appl_timer_schedule(p_timer, &o_descriptor);
        }

*/

/* Reverse include guard */
enum guard_appl_timer_handle_h
{
    inc_appl_timer_handle_h =
        /* Header file dependency */
        inc_appl_status_h
        + inc_appl_types_h
};

/* Predefine */
struct appl_context;

/* Predefine */
struct appl_timer;

/*

Structure: appl_timer_descriptor

Description:

    Description of a single timer event.

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

/* Create an instance of a timer, to be used as a manager of events */
enum appl_status
appl_timer_create(
    struct appl_context * const
        p_context,
    struct appl_timer * * const
        r_timer);

enum appl_status
appl_timer_destroy(
    struct appl_timer * const
        p_timer);

/* Get pointer to object */
struct appl_object *
appl_timer_parent(
    struct appl_timer * const
        p_timer);

/* Schedule an event */
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
