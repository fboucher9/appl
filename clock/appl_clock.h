/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_clock_h
{
    inc_appl_clock_h = 1
        /* Header file dependency */
        + inc_appl_object_h
        + inc_appl_predefines_h
};

/* Assert compiler */
#include <appl_assert_cplusplus.h>

//
//
//
class appl_clock : public appl_object
{
    public:

        appl_clock(
            struct appl_context * const
                p_context);

        virtual
        ~appl_clock();

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

    protected:

    private:

        appl_clock(
            class appl_clock const & r);

        class appl_clock &
            operator =(
                class appl_clock const & r);

}; // class appl_clock

/* end-of-file: appl_clock.h */
