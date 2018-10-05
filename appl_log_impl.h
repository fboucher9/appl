/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_LOG_IMPL_H
#error include appl_log_impl.h once
#endif /* #if defined INC_APPL_LOG_IMPL_H */

#define INC_APPL_LOG_IMPL_H

struct appl_context;

/* Header file dependency */
#if ! defined INC_APPL_LOG_HANDLE_H
#error include appl_log_handle.h before
#endif /* #if ! defined INC_APPL_LOG_HANDLE_H */

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
class appl_log_impl
{
    public:

        appl_log_impl();

        ~appl_log_impl();

        enum appl_status
            f_print(
                struct appl_context * const
                    p_context,
                enum appl_log_level const
                    e_level,
                unsigned char const * const
                    p_message_min,
                unsigned char const * const
                    p_message_max);

}; // class appl_log_impl

/* end-of-file: appl_log_impl.h */
