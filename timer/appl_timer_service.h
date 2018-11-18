/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_TIMER_SERVICE_H
#error include appl_timer_service.h once
#endif /* #if defined INC_APPL_TIMER_SERVICE_H */

#define INC_APPL_TIMER_SERVICE_H

/* Predefine */
struct appl_context;

/* Predefine */
struct appl_timer;

/* Predefine */
struct appl_timer_descriptor;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
class appl_timer_service
{
    public:

        static
        enum appl_status
        s_create(
            struct appl_context * const
                p_context,
            struct appl_timer * * const
                r_timer);

        static
        struct appl_object *
        s_parent(
            struct appl_timer * const
                p_timer);

        static
        enum appl_status
        s_schedule(
            struct appl_timer * const
                p_timer,
            struct appl_timer_descriptor const * const
                p_timer_descriptor);

}; // class appl_timer_service

/* end-of-file: appl_timer_service.h */
