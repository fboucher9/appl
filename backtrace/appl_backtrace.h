/* See LICENSE for license details */

/*

*/

/* Included. */
#define INC_APPL_BACKTRACE_H

/* Reverse include guard */
enum guard_appl_backtrace_h
{
    inc_appl_backtrace_h = 1
        /* Header file dependencies */
        + inc_appl_object_h
};

//
//
//
class appl_backtrace : public appl_object
{
    public:

        virtual
        enum appl_status
            v_capture(
                void const * * const
                    p_buffer,
                appl_size_t const
                    i_count_max,
                appl_size_t * const
                    r_count);

        virtual
        enum appl_status
            v_report(
                void const * const * const
                    p_buffer,
                appl_size_t const
                    i_count);

        virtual
        enum appl_status
            v_ouch(
                char const * const
                    p_header0);

    protected:

        appl_backtrace(
            struct appl_context * const
                p_context);

        virtual
        ~appl_backtrace();

    private:

        appl_backtrace(
            class appl_backtrace const & r);

        class appl_backtrace &
            operator =(
                class appl_backtrace const & r);

}; // class appl_backtrace

/* end-of-file: appl_backtrace.h */
