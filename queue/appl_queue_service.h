/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_queue_service_h
{
    inc_appl_queue_service_h =
        /* Header file dependencies */
        inc_appl_status_h
};

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
                struct appl_context * const
                    p_context,
                struct appl_queue_descriptor const * const
                    p_descriptor,
                struct appl_queue * * const
                    r_instance);

        static
        enum appl_status
            s_destroy(
                struct appl_queue * const
                    p_queue);

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
