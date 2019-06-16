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

struct appl_context;

enum appl_log_level
{
    appl_log_level_error = 1,

    appl_log_level_warning = 2,

    appl_log_level_info = 3

};

/*

*/
struct appl_log_record
{
    unsigned char
        i_level;

    unsigned char
        i_thread_name_length;

    unsigned char
        i_message_length;

    unsigned char
        i_backtrace_count;

    unsigned char
        i_parameter_count;

    unsigned char
        a_parameter_type[3u];

    /* -- */

    appl_ull_t
        i_timestamp_usec;

    /* -- */

    appl_ull_t
        a_parameter_value[3u];

    /* -- */

    void *
        a_backtrace[4u];

    /* -- */

    unsigned char
        a_thread_name[16u];

    /* -- */

    unsigned char
        a_message[40u];

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

#if defined __cplusplus
} /* extern "C" */
#endif /* #if defined __cplusplus */

/* end-of-file: appl_log_handle.h */
