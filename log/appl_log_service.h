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

struct appl_context;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
class appl_log_service
{
    public:

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
