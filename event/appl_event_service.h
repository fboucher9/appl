/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_event_service_h
{
    inc_appl_event_service_h =
        /* Header file dependencies */
        inc_appl_status_h
};

/* Predefine */
struct appl_context;

/* Predefine */
struct appl_mutex;

/* Predefine */
struct appl_event;

/* Predefine */
struct appl_event_descriptor;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

// Predefine
class appl_event_service;

//
//
//
class appl_event_service
{
    public:

        static
        enum appl_status
        s_validate(
            bool const
                b_condition);

        static
        enum appl_status
        s_create(
            struct appl_context * const
                p_context,
            struct appl_event_descriptor const * const
                p_event_descriptor,
            struct appl_event * * const
                r_event);

        static
        enum appl_status
        s_destroy(
            struct appl_event * const
                p_event);

        static
        struct appl_object *
        s_parent(
            struct appl_event * const
                p_event);

        static
        struct appl_object const *
        s_const_parent(
            struct appl_event const * const
                p_event);

        static
        enum appl_status
        s_signal(
            struct appl_event * const
                p_event);

        static
        enum appl_status
        s_wait(
            struct appl_event * const
                p_event,
            struct appl_mutex * const
                p_mutex,
            unsigned long int const
                i_wait_freq,
            unsigned long int const
                i_wait_count);

}; // class appl_event_service

/* end-of-file: appl_event_service.h */
