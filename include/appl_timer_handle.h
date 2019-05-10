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
            struct appl_timer_node * p_timer_node)
        {
            appl_ull_t i_now_usec;
            struct appl_timer_descriptor o_descriptor;
            appl_clock_read(p_context, 1000000ul, &i_now_usec);
            o_descriptor.i_abstime_usec = i_now_usec + 2000000ul;
            o_descriptor.p_timer_callback = &in2secs_event;
            o_descriptor.p_timer_context = p_context;
            appl_timer_node_schedule(p_timer_node, &o_descriptor);
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
struct appl_timer_group;

/* Predefine */
struct appl_timer_node;

/*

Structure: appl_timer_descriptor

Description:

    Description of a single timer event.

*/
struct appl_timer_descriptor
{
    /* Value of zero is used to post a message as soon as possible */
    /* The post message is used to cancel a timer */
    appl_ull_t
        i_abstime_usec;

    /* -- */

    void
        (* p_timer_callback)(
            void * const
                p_timer_context,
            struct appl_timer_node * const
                p_timer_node);

    void *
        p_timer_context;

}; /* struct appl_timer_descriptor */

#if defined __cplusplus
extern "C" {
#endif /* #if defined __cplusplus */

/* Create an instance of a timer, to be used as a manager of events */
/* Timer manager may decide to return the same group */
enum appl_status
appl_timer_group_create(
    struct appl_context * const
        p_context,
    struct appl_timer_group * * const
        r_timer);

enum appl_status
appl_timer_group_destroy(
    struct appl_context * const
        p_context,
    struct appl_timer_group * const
        p_timer_group);

/* Get pointer to object */
struct appl_object *
appl_timer_group_parent(
    struct appl_timer_group * const
        p_timer_group);

struct appl_object const *
appl_timer_group_const_parent(
    struct appl_timer_group const * const
        p_timer_group);

/* Node states */
/* - free */
/* - pending */
/* - ready */
/* - busy */
/* - done */

/* Allocate a node from the free list */
/* A node is assigned to a group, so that all events are synchronized */
/* Two nodes are not guaranteed to be on some group */
enum appl_status
appl_timer_node_create(
    struct appl_timer_group * const
        p_timer_group,
    struct appl_timer_node * * const
        r_timer_node);

/* Return the node to the free list */
/* This may fail if the node is busy */
enum appl_status
appl_timer_node_destroy(
    struct appl_timer_group * const
        p_timer_group,
    struct appl_timer_node * const
        p_timer_node);

struct appl_object *
appl_timer_node_parent(
    struct appl_timer_node * const
        p_timer_node);

struct appl_object const *
appl_timer_node_const_parent(
    struct appl_timer_node const * const
        p_timer_node);

/* Insert the node into the pending list */
enum appl_status
appl_timer_node_schedule(
    struct appl_timer_node * const
        p_timer_node,
    struct appl_timer_descriptor const * const
        p_timer_descriptor);

/* Application is responsible of destroying the node from the callback */
/* Application is responsible for synchronization of destruction */
/* Application may use refcount or events */

#if defined __cplusplus
} /* extern "C" */
#endif /* #if defined __cplusplus */

/* end-of-file: appl_timer_handle.h */
