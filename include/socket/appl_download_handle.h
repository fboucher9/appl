/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_download_handle_h
{
    inc_appl_download_handle_h = 1
        /* Header file dependencies */
        + inc_appl_status_h
        + inc_appl_types_h
};

/*

*/
enum appl_download_status
{
    appl_download_status_ok = 1,

    appl_download_status_disconnected = 2,

    appl_download_status_canceled = 3,

    appl_download_status_fail = 4,

    appl_download_status_timeout = 5

};

/*

*/
struct appl_download_descriptor
{
    appl_ull_t
        i_bit_rate;

    /* -- */

    enum appl_status
        (* p_notify_length)(
            void * const
                p_callback_context,
            appl_ull_t const
                i_length);

    enum appl_status
        (* p_notify_type)(
            void * const
                p_callback_context,
            unsigned char const * const
                p_type_min,
            unsigned char const * const
                p_type_max);

    /* -- */

    enum appl_status
        (* p_notify_content)(
            void * const
                p_callback_context,
            unsigned char const * const
                p_buffer_min,
            unsigned char const * const
                p_buffer_max);

    enum appl_status
        (* p_notify_status)(
            void * const
                p_callback_context,
            enum appl_download_status const
                e_download_status);

    /* -- */

    void *
        p_callback_context;

    void *
        pv_padding[1u];

    /* -- */

    unsigned char const *
        p_url_min;

    unsigned char const *
        p_url_max;

    /* -- */

    unsigned char const *
        p_connect_min;

    unsigned char const *
        p_connect_max;

    /* -- */

    unsigned short int
        i_connect_port;

    unsigned short int
        us_padding[3u];

}; /* struct appl_download_descriptor */

#include <misc/appl_extern_c_begin.h>

enum appl_status
    appl_download_create(
        struct appl_context * const
            p_context,
        struct appl_download_descriptor const * const
            p_descriptor,
        struct appl_download * * const
            r_handle);

enum appl_status
    appl_download_destroy(
        struct appl_download * const
            p_handle);

enum appl_status
    appl_download_cancel(
        struct appl_download * const
            p_handle);

enum appl_status
    appl_download_wait(
        struct appl_download * const
            p_handle,
        unsigned long int const
            i_timeout_msec,
        enum appl_download_status * const
            r_status);

#include <misc/appl_extern_c_end.h>

/* end-of-file: appl_download_handle.h */
