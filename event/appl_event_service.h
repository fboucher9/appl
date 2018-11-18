/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_EVENT_SERVICE_H
#error include appl_event_service.h once
#endif /* #if defined INC_APPL_EVENT_SERVICE_H */

#define INC_APPL_EVENT_SERVICE_H

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
        s_create(
            struct appl_context * const
                p_context,
            struct appl_event_descriptor const * const
                p_event_descriptor,
            struct appl_event * * const
                r_event);

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