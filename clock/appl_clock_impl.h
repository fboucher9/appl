/* See LICENSE for license details */

/*

*/

/* Included. */
#define INC_APPL_CLOCK_IMPL_H

/* Reverse include guard */
enum guard_appl_clock_impl_h
{
    inc_appl_clock_impl_h = 1
        /* Header file dependencies */
        + inc_appl_status_h
        + inc_appl_types_h
};

//
//
//
class appl_clock_impl
{
    public:

        static
        enum appl_status
            s_read(
                unsigned long int const
                    i_time_freq,
                appl_ull_t * const
                    p_time_count);

        static
        enum appl_status
            s_delay(
                unsigned long int const
                    i_time_freq,
                appl_ull_t const
                    i_time_count);

        static
        enum appl_status
            s_calibrate(
                unsigned long int const
                    i_time_freq,
                appl_ull_t * const
                    p_time_count);

}; // class appl_clock_impl

/* end-of-file: appl_clock_impl.h */
