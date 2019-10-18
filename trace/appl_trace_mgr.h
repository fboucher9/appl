/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_trace_mgr_h
{
    inc_appl_trace_mgr_h = 1
        /* Header file dependencies */
        | inc_appl_object_h
        /* ... */
}; /* enum guard_appl_trace_mgr_h */

#include <misc/appl_assert_cplusplus.h>

//
//
//
class appl_trace_mgr : public appl_object
{
    public:

        appl_trace_mgr(
            struct appl_context * const
                p_context);

        virtual
        ~appl_trace_mgr();

        virtual
        enum appl_status
            v_init(
                struct appl_trace * const
                    p_trace,
                char const * const
                    p_name0,
                int const
                    e_level);

        virtual
        enum appl_status
            v_register(
                struct appl_trace_descriptor const * const
                    p_descriptor,
                struct appl_trace_client * * const
                    r_instance);

        virtual
        enum appl_status
            v_unregister(
                struct appl_trace_client * const
                    p_instance);

        virtual
        enum appl_status
            v_get_levels(
                int * const
                    r_levels) const;

        virtual
        enum appl_status
            v_set_levels(
                int const
                    i_levels);

        virtual
        char
            v_test(
                struct appl_trace * const
                    p_trace) const;

        virtual
        enum appl_status
            v_message(
                struct appl_trace_message const * const
                    p_trace_message);

        virtual
        enum appl_status
            v_capture(
                char * * const
                    p_capture_array,
                unsigned long int const
                    i_capture_max,
                unsigned long int * const
                    r_capture_count);

        virtual
        enum appl_status
            v_stack_report_length(
                unsigned long int * const
                    r_length);

        virtual
        enum appl_status
            v_stack_report(
                struct appl_buf * const
                    p_iterator);

        virtual
        enum appl_status
            v_profile_report_length(
                unsigned long int * const
                    r_length);

        virtual
        enum appl_status
            v_profile_report(
                struct appl_buf * const
                    p_iterator);

    protected:

    private:

        appl_trace_mgr(
            class appl_trace_mgr const & r);

        class appl_trace_mgr &
            operator =(
                class appl_trace_mgr const & r);

}; // class appl_trace_mgr

/* end-of-file: appl_trace_mgr.h */
