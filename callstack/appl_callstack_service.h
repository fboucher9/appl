/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_callstack_service_h
{
    inc_appl_callstack_service_h = 1
        /* Header file dependencies */
        + inc_appl_predefines_h
        /* ... */

}; /* enum guard_appl_callstack_service_h */

/* Assert compiler */
#include <appl_assert_cplusplus.h>

//
//
//
class appl_callstack_service
{
    public:

        static
        void
            s_enter(
                struct appl_context * const
                    p_context,
                char const * const
                    p_buffer0);

        static
        void
            s_print0(
                struct appl_context * const
                    p_context,
                char const * const
                    p_buffer0);

        static
        void
            s_print_buffer(
                struct appl_context * const
                    p_context,
                unsigned char const * const
                    p_buffer_min,
                unsigned char const * const
                    p_buffer_max);

        static
        void
            s_print_signed(
                struct appl_context * const
                    p_context,
                signed long int const
                    i_number);

        static
        void
            s_print_unsigned(
                struct appl_context * const
                    p_context,
                unsigned long int const
                    i_number);

        static
        void
            s_print_hexadecimal(
                struct appl_context * const
                    p_context,
                unsigned long int const
                    i_number);

        static
        void
            s_leave(
                struct appl_context * const
                    p_context);

        static
        void
            s_report(
                struct appl_context * const
                    p_context,
                void (* p_callback)(
                    void * const
                        p_callback_data,
                    unsigned char const * const
                        p_report_min,
                    unsigned char const * const
                        p_report_max),
                void * const
                    p_callback_data);

}; // class appl_callstack_service

/* end-of-file: appl_callstack_service.h */
