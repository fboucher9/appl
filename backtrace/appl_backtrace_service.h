/* See LICENSE for license details */

/*

*/

/* Included. */
#define INC_APPL_BACKTRACE_SERVICE_H

/* Reverse include guard */
enum guard_appl_backtrace_service_h
{
    inc_appl_backtrace_service_h = 1
        /* Header file dependencies */
        + inc_appl_status_h
        + inc_appl_types_h
        + inc_appl_predefines_h
};

#include <appl_assert_cplusplus.h>

//
//
//
class appl_backtrace_service
{
    public:

        static
        enum appl_status
            s_capture(
                struct appl_context * const
                    p_context,
                void const * * const
                    p_buffer,
                appl_size_t const
                    i_count_max,
                appl_size_t * const
                    r_count);

        static
        enum appl_status
            s_report(
                struct appl_context * const
                    p_context,
                void const * const * const
                    p_buffer,
                appl_size_t const
                    i_count);

        static
        enum appl_status
            s_ouch(
                struct appl_context * const
                    p_context,
                char const * const
                    p_header0);

}; // class appl_backtrace_service

/* end-of-file: appl_backtrace_service.h */
