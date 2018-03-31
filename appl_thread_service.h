/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined(INC_APPL_THREAD_SERVICE_H)
#error include appl_thread_service.h once
#endif /* #if defined(INC_APPL_THREAD_SERVICE_H) */

#define INC_APPL_THREAD_SERVICE_H

struct appl_thread_handle;

struct appl_property_handle;

struct appl_context_handle;

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
            struct appl_context_handle * const
                p_context_handle,
            struct appl_property_handle const * const
                p_property_handle,
            struct appl_thread_handle * * const
                r_thread_handle);

        static
        enum appl_status
        s_start(
            struct appl_thread_handle * const
                p_thread_handle);

        static
        enum appl_status
        s_stop(
            struct appl_thread_handle * const
                p_thread_handle,
            unsigned long int const
                i_wait_freq,
            unsigned long int const
                i_wait_count,
            void * * const
                r_thread_result);

        static
        enum appl_status
        s_interrupt(
            struct appl_thread_handle * const
                p_thread_handle);

}; // class appl_thread_service

/* end-of-file: appl_thread_service.h */
