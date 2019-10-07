/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_clock_service_h
{
    inc_appl_clock_service_h = 1
        /* Header file dependency */
        + inc_appl_status_h
        + inc_appl_types_h
        + inc_appl_predefines_h
};

/* Assert compiler */
#include <misc/appl_assert_cplusplus.h>

//
//
//
class appl_clock_service
{
    public:

        static
        enum appl_status
        s_read(
            struct appl_context const * const
                p_context,
            unsigned long int const
                i_time_freq,
            appl_ull_t * const
                p_time_count);

        static
        enum appl_status
        s_delay(
            struct appl_context const * const
                p_context,
            unsigned long int const
                i_time_freq,
            appl_ull_t const
                i_time_count);

}; // class appl_clock_service

/* end-of-file: appl_clock_service.h */
