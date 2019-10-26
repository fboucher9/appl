/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_clock_std_h
{
    inc_appl_clock_std_h = 1
        /* Header file dependencies */
        + inc_appl_clock_h
};

/* Assert compiler */
#include <misc/appl_assert_cplusplus.h>

/* Assert OS */
#include <misc/appl_assert_linux.h>

//
//
//
class appl_clock_std : public appl_clock
{
    public:

        static
        enum appl_status
            s_create(
                struct appl_allocator * const
                    p_allocator,
                class appl_clock * * const
                    r_clock);

        static
        enum appl_status
            s_destroy(
                struct appl_allocator * const
                    p_allocator,
                class appl_clock * const
                    p_clock);

        appl_clock_std(
            struct appl_context * const
                p_context);

        virtual
        ~appl_clock_std();

    protected:

    private:

        appl_clock_std(
            class appl_clock_std const & r);

        class appl_clock_std &
            operator =(
                class appl_clock_std const & r);

        virtual
        appl_size_t
        v_cleanup(void);

        virtual
        enum appl_status
        v_read(
            unsigned long int const
                i_time_freq,
            appl_ull_t * const
                p_time_count);

        virtual
        enum appl_status
        v_delay(
            unsigned long int const
                i_time_freq,
            appl_ull_t const
                i_time_count);

        virtual
        enum appl_status
        v_convert(
            unsigned long int const
                i_time_freq,
            appl_ull_t const
                i_time_count,
            struct appl_clock_details * const
                r_clock_details);

}; // class appl_clock_std

/* end-of-file: appl_clock_std.h */
