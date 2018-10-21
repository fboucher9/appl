/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_QUEUE_SERVICE_H
#error include appl_queue_service.h once
#endif /* #if defined INC_APPL_QUEUE_SERVICE_H */

#define INC_APPL_QUEUE_SERVICE_H

/* Header file dependencies */
#if ! defined INC_APPL_STATUS_H
#error include appl_status.h before
#endif /* #if ! defined INC_APPL_STATUS_H */

/* Predefines */
struct appl_context;

/* Predefines */
struct appl_queue_descriptor;

/* Predefines */
struct appl_object;

/* Predefines */
struct appl_queue;

/* Predefines */
struct appl_list;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
class appl_queue_service
{
    public:

        static
        enum appl_status
            s_create(
                struct appl_heap * const
                    p_heap,
                struct appl_queue_descriptor const * const
                    p_descriptor,
                struct appl_queue * * const
                    r_instance);

        static
        struct appl_object *
            s_parent(
                struct appl_queue * const
                    p_queue);

        static
        enum appl_status
            s_push(
                struct appl_queue * const
                    p_queue,
                struct appl_list * const
                    p_node,
                unsigned long int const
                    i_wait_freq,
                unsigned long int const
                    i_wait_count);

        static
        enum appl_status
            s_pop(
                struct appl_queue * const
                    p_queue,
                struct appl_list * * const
                    r_node,
                unsigned long int const
                    i_wait_freq,
                unsigned long int const
                    i_wait_count);

        static
        enum appl_status
            s_interrupt(
                struct appl_queue * const
                    p_queue);

}; // class appl_queue_service

/* end-of-file: appl_queue_service.h */
