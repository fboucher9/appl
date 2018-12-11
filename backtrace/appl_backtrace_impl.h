/* See LICENSE for license details */

/*

*/

/* Included. */
#define INC_APPL_BACKTRACE_IMPL_H

/* Reverse include guard */
enum guard_appl_backtrace_impl_h
{
    inc_appl_backtrace_impl_h = 1
        /* Header file dependencies */
        + inc_appl_status_h
        + inc_appl_types_h
};

//
//
//
class appl_backtrace_impl
{
    public:

        static
        enum appl_status
            s_capture(
                void const * * const
                    p_buffer,
                appl_size_t const
                    i_count_max,
                appl_size_t * const
                    r_count);

        static
        enum appl_status
            s_report(
                void const * const * const
                    p_buffer,
                appl_size_t const
                    i_count);

        static
        enum appl_status
            s_ouch(
                char const * const
                    p_header0);

}; // class appl_backtrace_impl

/* end-of-file: appl_backtrace_impl.h */
