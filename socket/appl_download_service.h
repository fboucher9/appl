/* See LICENSE for license details */

/*

*/

/* Included. */
#define INC_APPL_DOWNLOAD_SERVICE_H

/* Reverse include guard */
enum guard_appl_download_service_h
{
    inc_appl_download_service_h = 1
        + inc_appl_download_handle_h
};

/* Assert compiler */
#include <appl_assert_cplusplus.h>

//
//
//
class appl_download_service
{
    public:

        static
        enum appl_status
            s_create(
                struct appl_context * const
                    p_context,
                struct appl_download_descriptor const * const
                    p_descriptor,
                struct appl_download * * const
                    r_handle);

        static
        enum appl_status
            s_destroy(
                struct appl_download * const
                    p_handle);

        static
        enum appl_status
            s_cancel(
                struct appl_download * const
                    p_handle);

        static
        enum appl_status
            s_wait(
                struct appl_download * const
                    p_handle,
                unsigned long int const
                    i_timeout_msec,
                enum appl_download_status * const
                    r_status);

}; // class appl_download_service

/* end-of-file: appl_download_service.h */
