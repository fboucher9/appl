/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_poll_service_h
{
    inc_appl_poll_service_h =
        /* Header file dependencies */
        inc_appl_status_h
};

/* Assert compiler */
#include <misc/appl_assert_cplusplus.h>

//
//
//
class appl_poll_service
{
    public:

        static
        enum appl_status
        create_handle(
            struct appl_context* const
                p_context,
            struct appl_poll_descriptor const * const
                p_poll_descriptor,
            struct appl_poll* * const
                r_poll);

}; // class appl_poll_service

/* end-of-file: appl_poll_service.h */
