/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_trace_service_h
{
    inc_appl_trace_service_h = 1
        /* Header file dependencies */
        | inc_appl_predefines_h
        | inc_appl_status_h
        /* ... */
}; /* enum guard_appl_trace_service_h */

/* Predefine */
struct appl_trace_message;

#include <misc/appl_assert_cplusplus.h>

//
//
//
class appl_trace_service
{
    public:

        static
        enum appl_status
            s_init(
                struct appl_context * const
                    p_context,
                struct appl_trace * const
                    p_trace,
                char const * const
                    p_name0,
                int const
                    e_level);

        static
        enum appl_status
            s_register(
                struct appl_context * const
                    p_context,
                struct appl_trace_descriptor const * const
                    p_descriptor,
                struct appl_trace_client * * const
                    r_instance);

        static
        enum appl_status
            s_unregister(
                struct appl_trace_client * const
                    p_instance);

        static
        enum appl_status
            s_message(
                struct appl_context * const
                    p_context,
                struct appl_trace_message const * const
                    p_trace_message);

        static
        enum appl_status
            s_capture(
                struct appl_context * const
                    p_context,
                char * * const
                    p_capture_array,
                unsigned long int const
                    i_capture_max,
                unsigned long int * const
                    r_capture_count);

        static
        enum appl_status
            s_stack_report_length(
                struct appl_context * const
                    p_context,
                unsigned long int * const
                    r_length);

        static
        enum appl_status
            s_stack_report(
                struct appl_context * const
                    p_context,
                struct appl_buf * const
                    p_iterator);

        static
        enum appl_status
            s_profile_report_length(
                struct appl_context * const
                    p_context,
                unsigned long int * const
                    r_length);

        static
        enum appl_status
            s_profile_report(
                struct appl_context * const
                    p_context,
                struct appl_buf * const
                    p_iterator);

}; // class appl_trace_service

/* end-of-file: appl_trace_service.h */
