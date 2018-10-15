/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_QUEUE_HANDLE_H
#error include appl_queue_handle.h once
#endif /* #if defined INC_APPL_QUEUE_HANDLE_H */

#define INC_APPL_QUEUE_HANDLE_H

/* Header file dependencies */
#if ! defined INC_APPL_STATUS_H
#error include appl_status.h before
#endif /* #if ! defined INC_APPL_STATUS_H */

/* Predefines */
struct appl_context;

/* Predefines */
struct appl_queue;

/* Predefines */
struct appl_list;

/*

*/
struct appl_queue_descriptor
{
    unsigned long int
        i_max_count;

    unsigned long int
        l_padding[1u];

}; /* struct appl_queue_descriptor */

#if defined __cplusplus
extern "C" {
#endif /* #if defined __cplusplus */

extern
enum appl_status
    appl_queue_create(
        struct appl_context * const
            p_context,
        struct appl_queue_descriptor const * const
            p_descriptor,
        struct appl_queue * * const
            r_instance);

extern
struct appl_object *
    appl_queue_parent(
        struct appl_queue * const
            p_queue);

extern
enum appl_status
    appl_queue_push(
        struct appl_queue * const
            p_queue,
        struct appl_list * const
            p_node,
        unsigned long int const
            i_wait_freq,
        unsigned long int const
            i_wait_count);

extern
enum appl_status
    appl_queue_pop(
        struct appl_queue * const
            p_queue,
        struct appl_list * * const
            r_node,
        unsigned long int const
            i_wait_freq,
        unsigned long int const
            i_wait_count);

/* unblock a thread that is waiting for a push or pop */
extern
enum appl_status
    appl_queue_interrupt(
        struct appl_queue * const
            p_queue);

#if defined __cplusplus
} /* extern "C" */
#endif /* #if defined __cplusplus */

/* end-of-file: appl_queue_handle.h */
