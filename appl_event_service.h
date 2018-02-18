/* See LICENSE for license details */

/*

*/

struct appl_context_handle;

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
            unsigned long int const
                i_time_freq,
            unsigned long int const
                i_time_count);

}; // class appl_event_service

/* end-of-file: appl_event_service.h */
