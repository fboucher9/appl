/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_callstack_service_h
{
    inc_appl_callstack_service_h = 1
        /* Header file dependencies */
        /* ... */

}; /* enum guard_appl_callstack_service_h */

/* Predefine context handle */
struct appl_context;

/* Predefine callstack handle */
struct appl_callstack_frame;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
class appl_callstack_service
{
    public:

        static
        struct appl_callstack_frame *
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
                    p_context,
                struct appl_callstack_frame * const
                    p_frame);

        static
        unsigned long int
            s_get_report_length(
                struct appl_context * const
                    p_context);

        static
        unsigned char *
            s_read_report(
                struct appl_context * const
                    p_context,
                unsigned char * const
                    p_report_min,
                unsigned char * const
                    p_report_max);

}; // class appl_callstack_service

/* end-of-file: appl_callstack_service.h */
