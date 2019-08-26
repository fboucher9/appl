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

/*

*/
struct appl_log_record
{
    unsigned char
        i_level;

    unsigned char
        i_message_length;

    unsigned char
        uc_padding[6u];

    /* -- */

    unsigned char
        a_message[120u];

}; /* struct appl_log_record */

struct appl_log_client;

#if defined __cplusplus
extern "C" {
#endif /* #if defined __cplusplus */

enum appl_status
    appl_log_register(
        struct appl_context * const
            p_context,
        void (* const p_callback)(
            void * const
                p_callback_context,
            struct appl_log_record const * const
                p_log_record),
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

enum appl_status
    appl_log_enter(
        struct appl_context * const
            p_context,
        char const * const
            p_function0);

enum appl_status
    appl_log_leave(
        struct appl_context * const
            p_context);

#if defined __cplusplus
} /* extern "C" */
#endif /* #if defined __cplusplus */

/* end-of-file: appl_log_handle.h */
