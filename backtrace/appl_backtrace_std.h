/* See LICENSE for license details */

/*

*/

/* Included. */
#define INC_APPL_BACKTRACE_STD_H

/* Reverse include guard */
enum guard_appl_backtrace_std_h
{
    inc_appl_backtrace_std_h = 1
        /* Header file dependencies */
        + inc_appl_backtrace_h
};

//
//
//
class appl_backtrace_std : public appl_backtrace
{
    public:

        static
        enum appl_status
            s_create(
                struct appl_allocator * const
                    p_allocator,
                class appl_backtrace * * const
                    r_instance);

        static
        enum appl_status
            s_destroy(
                struct appl_allocator * const
                    p_allocator,
                class appl_backtrace * const
                    p_instance);

        appl_backtrace_std();

        virtual
        ~appl_backtrace_std();

        enum appl_status
            f_init(void);

    protected:

    private:

        virtual
        appl_size_t
            v_cleanup(void);

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

        appl_backtrace_std(
            class appl_backtrace_std const & r);

        class appl_backtrace_std &
            operator =(
                class appl_backtrace_std const & r);

}; // class appl_backtrace_std

/* end-of-file: appl_backtrace_std.h */
