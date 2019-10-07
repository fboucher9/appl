/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_log_service_h
{
    inc_appl_log_service_h =
        /* Header file dependency */
        inc_appl_log_handle_h
};

/* Assert compiler */
#include <misc/appl_assert_cplusplus.h>

//
//
//
class appl_log_service
{
    public:

        static
        enum appl_status
            s_register(
                struct appl_context * const
                    p_context,
                appl_log_callback * const
                    p_callback,
                void * const
                    p_callback_context,
                struct appl_log_client * * const
                    r_client);

        static
        enum appl_status
            s_unregister(
                struct appl_context * const
                    p_context,
                struct appl_log_client * const
                    p_client);

        static
        enum appl_status
            s_print(
                struct appl_context * const
                    p_context,
                enum appl_log_level const
                    e_level,
                unsigned char const * const
                    p_message_min,
                unsigned char const * const
                    p_message_max);

}; // class appl_log_service

/* end-of-file: appl_log_service.h */
