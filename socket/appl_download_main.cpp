/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <socket/appl_download_main.h>

#include <appl_types.h>

#include <appl_download_handle.h>

#include <appl_test.h>

#include <appl_buf.h>

#include <appl_unused.h>

//
//
//
static
enum appl_status
on_notify_length(
    void * const
        p_callback_context,
    appl_ull_t const
        i_length)
{
    appl_unused(
        p_callback_context,
        i_length);

    return
        appl_status_ok;

} // on_notify_length()

//
//
//
static
enum appl_status
on_notify_type(
    void * const
        p_callback_context,
    unsigned char const * const
        p_type_min,
    unsigned char const * const
        p_type_max)
{
    appl_unused(
        p_callback_context,
        p_type_min,
        p_type_max);

    return
        appl_status_ok;

} // on_notify_type()

//
//
//
static
enum appl_status
on_notify_content(
    void * const
        p_callback_context,
    unsigned char const * const
        p_buffer_min,
    unsigned char const * const
        p_buffer_max)
{
    appl_unused(
        p_callback_context,
        p_buffer_min,
        p_buffer_max);

    return
        appl_status_ok;

} // on_notify_content()

//
//
//
static
enum appl_status
on_notify_status(
    void * const
        p_callback_context,
    enum appl_download_status const
        e_download_status)
{
    appl_unused(
        p_callback_context,
        e_download_status);

    return
        appl_status_ok;

} // on_notify_status()

//
//
//
enum appl_status
    appl_download_main(
        struct appl_context * const
            p_context,
        struct appl_options const * const
            p_options,
        unsigned long int const
            i_shift)
{
    enum appl_status
        e_status;

    struct appl_download_descriptor
        o_download_descriptor;

    appl_unused(
        p_context,
        p_options,
        i_shift);

    appl_print0("download main\n");

    {
        union appl_buf_ptr
            o_ptr;

        o_ptr.p_void =
            &(
                o_download_descriptor);

        appl_buf_zero(
            o_ptr.p_uchar,
            o_ptr.p_uchar + sizeof(o_download_descriptor));
    }

    o_download_descriptor.i_bit_rate =
        1000000;

    o_download_descriptor.p_notify_length =
        &(
            on_notify_length);

    o_download_descriptor.p_notify_type =
        &(
            on_notify_type);

    o_download_descriptor.p_notify_content =
        &(
            on_notify_content);

    o_download_descriptor.p_notify_status =
        &(
            on_notify_status);

    o_download_descriptor.p_callback_context =
        0;

    // provide url to download instance
    static unsigned char const s_url[] =
    {
        'h',
        't',
        't',
        'p',
        ':',
        '/',
        '/',
        'w',
        'w',
        'w',
        '.',
        'g',
        'o',
        'o',
        'g',
        'l',
        'e',
        '.',
        'c',
        'a'
    };

    o_download_descriptor.p_url_min =
        s_url;

    o_download_descriptor.p_url_max =
        s_url + sizeof(s_url);

    // also provide proxy address and port
    static unsigned char const s_connect[] =
    {
        'g',
        'o',
        'o',
        'g',
        'l',
        'e',
        '.',
        'c',
        'a'
    };

    o_download_descriptor.p_connect_min =
        s_connect;

    o_download_descriptor.p_connect_max =
        s_connect + sizeof(s_connect);

    o_download_descriptor.i_connect_port =
        80;

    struct appl_download *
        p_download;

    e_status =
        appl_download_create(
            p_context,
            &(
                o_download_descriptor),
            &(
                p_download));

    if (
        appl_status_ok
        == e_status)
    {
        enum appl_download_status
            e_download_status;

        /* Wait for download to complete */
        while (
            appl_status_ok
            != appl_download_wait(
                p_download,
                1000ul,
                &(
                    e_download_status)))
        {
        }

        appl_download_destroy(
            p_download);
    }

    return
        e_status;

} // appl_download_main()

/* end-of-file: appl_download_main.cpp */
