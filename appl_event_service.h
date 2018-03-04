/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_EVENT_SERVICE_H
#error include appl_event_service.h once
#endif /* #if defined INC_APPL_EVENT_SERVICE_H */

#define INC_APPL_EVENT_SERVICE_H

struct appl_context_handle;

struct appl_mutex_handle;

struct appl_event_handle;

struct appl_event_descriptor;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

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
            struct appl_context_handle * const
                p_context_handle,
            struct appl_event_descriptor const * const
                p_event_descriptor,
            struct appl_event_handle * * const
                r_event_handle);

        static
        enum appl_status
        s_signal(
            struct appl_event_handle * const
                p_event_handle);

        static
        enum appl_status
        s_wait(
            struct appl_event_handle * const
                p_event_handle,
            struct appl_mutex_handle * const
                p_mutex_handle);

}; // class appl_event_service

/* end-of-file: appl_event_service.h */
