/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined(INC_APPL_THREAD_SERVICE_H)
#error include appl_thread_service.h once
#endif /* #if defined(INC_APPL_THREAD_SERVICE_H) */

#define INC_APPL_THREAD_SERVICE_H

struct appl_thread;

struct appl_thread_property;

struct appl_context;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

class appl_thread_service;

//
//
//
class appl_thread_service
{
    public:

        static
        enum appl_status
        s_create(
            struct appl_object const * const
                p_object,
            struct appl_thread_property const * const
                p_thread_property,
            struct appl_thread * * const
                r_thread);

        static
        struct appl_object *
        s_convert(
            struct appl_thread * const
                p_thread);

        static
        struct appl_object const *
        s_convert(
            struct appl_thread const * const
                p_thread);

        static
        enum appl_status
        s_start(
            struct appl_thread * const
                p_thread,
            void (* const p_callback)(
                void * const
                    p_context),
            void * const
                p_context);

        static
        enum appl_status
        s_detach(
            struct appl_thread * const
                p_thread);

        static
        enum appl_status
        s_stop(
            struct appl_thread * const
                p_thread,
            unsigned long int const
                i_wait_freq,
            unsigned long int const
                i_wait_count);

        static
        enum appl_status
        s_interrupt(
            struct appl_thread * const
                p_thread);

}; // class appl_thread_service

/* end-of-file: appl_thread_service.h */
