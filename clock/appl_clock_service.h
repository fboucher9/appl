/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_CLOCK_SERVICE_H
#error include appl_clock_service.h once
#endif /* #if defined INC_APPL_CLOCK_SERVICE_H */

#define INC_APPL_CLOCK_SERVICE_H

/* Header file dependency */
#if ! defined INC_APPL_STATUS_H
#error include appl_status.h before
#endif /* #if ! defined INC_APPL_STATUS_H */

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