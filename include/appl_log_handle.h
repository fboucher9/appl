/* See LICENSE for license details */

/*

Module: appl_log_handle.h

Description:

*/

/* Reverse include guard */
enum guard_appl_log_handle_h
{
    inc_appl_log_handle_h = 1
        /* Header file dependency */
        + inc_appl_status_h
        + inc_appl_types_h
};

/* Predefine */
struct appl_context;

/*

*/
enum appl_log_level
{
    appl_log_level_error = 1,

    appl_log_level_warning = 2,

    appl_log_level_info = 3,

    appl_log_level_trace = 4

}; /* enum appl_log_level */

struct appl_log_client;

typedef void (appl_log_callback)(
    void * const
        p_callback_context,
    enum appl_log_level const
        e_level,
    unsigned char const * const
        p_message_min,
    unsigned char const * const
        p_message_max);

#include <appl_extern_c_begin.h>

enum appl_status
    appl_log_register(
        struct appl_context * const
            p_context,
        appl_log_callback * const
            p_callback,
        void * const
            p_callback_context,
        struct appl_log_client * * const
            r_client);

enum appl_status
    appl_log_unregister(
        struct appl_context * const
            p_context,
        struct appl_log_client * const
            p_client);

enum appl_status
    appl_log_print(
        struct appl_context * const
            p_context,
        enum appl_log_level const
            e_level,
        unsigned char const * const
            p_message_min,
        unsigned char const * const
            p_message_max);

#include <appl_extern_c_end.h>

/* end-of-file: appl_log_handle.h */
