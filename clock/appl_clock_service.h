/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_clock_service_h
{
    inc_appl_clock_service_h =
        /* Header file dependency */
        inc_appl_status_h
};

struct appl_context;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

class appl_clock_service;

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
