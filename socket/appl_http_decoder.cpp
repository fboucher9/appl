/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <socket/appl_http_decoder.h>

#include <appl_context_handle.h>

#include <appl_allocator_handle.h>

#include <appl_chunk_handle.h>

#include <appl_heap_handle.h>

#include <appl_buf.h>

#if defined APPL_DEBUG
#include <appl_debug_handle.h>
#endif /* #if defined APPL_DEBUG */

#include <appl_unused.h>

//
//
//
struct appl_http_decoder : public appl_object
{
    public:

        appl_http_decoder(
            struct appl_context * const
                p_context);

        virtual
        ~appl_http_decoder();

        enum appl_status
            f_init(
                struct appl_http_decoder_descriptor const * const
                    p_descriptor);

        virtual
        appl_size_t
            v_cleanup(void);

        virtual
        enum appl_status
            v_write(
                unsigned char const * const
                    p_buf_min,
                unsigned char const * const
                    p_buf_max);

    protected:

    private:

        struct appl_http_decoder_descriptor
            m_descriptor;

        // --

        struct appl_chunk *
            m_chunk;

        void *
            pv_padding[1u];

        // --

        unsigned long int
            m_content_length;

        unsigned long int
            m_chunk_size;

        // --

        unsigned int
            m_function;

        unsigned int
            ui_padding[3u];

        // --

        bool
            m_chunk_created;

        bool
            m_chunked_transfer_coding;

        unsigned char
            uc_padding[6u];

        // --

        appl_http_decoder(
            struct appl_http_decoder const & r);

        struct appl_http_decoder &
            operator =(
                struct appl_http_decoder const & r);

        enum appl_status
            f_write_char(
                unsigned char const
                    c_data);

        enum appl_status
            f_store_char(
                unsigned char const
                    c_data);

        enum appl_status
            f_flush(
                unsigned char * * const
                    r_buf_min,
                unsigned char * * const
                    r_buf_max);

        void
            f_flush_release(
                unsigned char * const
                    p_buf_min,
                unsigned char * const
                    p_buf_max);

        enum appl_status
            f_flush_header(void);

}; // struct appl_http_decoder

//
//
//
appl_http_decoder::appl_http_decoder(
    struct appl_context * const
        p_context) :
    appl_object(
        p_context),
    m_descriptor(),
    m_chunk(),
    m_content_length(),
    m_chunk_size(),
    m_function(),
    m_chunk_created(),
    m_chunked_transfer_coding()
{
}

//
//
//
appl_http_decoder::~appl_http_decoder()
{
}

//
//
//
enum appl_status
    appl_http_decoder::f_init(
        struct appl_http_decoder_descriptor const * const
            p_descriptor)
{
    enum appl_status
        e_status;

    m_descriptor =
        *(
            p_descriptor);

    e_status =
        appl_chunk_create(
            m_context,
            &(
                m_chunk));

    if (
        appl_status_ok
        == e_status)
    {
        m_chunk_created =
            true;
    }

    return
        e_status;

} // f_init()

//
//
//
appl_size_t
    appl_http_decoder::v_cleanup(void)
{
    // Do flush of body?
    f_flush_header();

    if (
        m_chunk_created)
    {
        appl_chunk_destroy(
            m_chunk);

        m_chunk_created =
            false;
    }

    return
        sizeof(
            struct appl_http_decoder);

} // v_cleanup()

//
//
//
enum appl_status
    appl_http_decoder::v_write(
        unsigned char const * const
            p_buf_min,
        unsigned char const * const
            p_buf_max)
{
    enum appl_status
        e_status;

    unsigned char const *
        p_buf_iterator;

    p_buf_iterator =
        p_buf_min;

    e_status =
        appl_status_ok;

    while (
        (
            appl_status_ok
            == e_status)
        && (
            p_buf_iterator
            < p_buf_max))
    {
        unsigned char const
            c_data =
            *(
                p_buf_iterator);

        e_status =
            f_write_char(
                c_data);

        if (
            appl_status_ok
            == e_status)
        {
            p_buf_iterator ++;
        }
    }

    return
        e_status;

} // v_write()

enum appl_http_decoder_function
{
    http_leading_crlf = 0,
    http_leading_cr,
    http_start_line,
    http_start_line_cr,
    http_start_line_crlf,
    http_header_line,
    http_header_line_cr,
    http_header_line_crlf,
    http_header_line_crlf_cr,
    http_header_line_lws,
    http_body,
    http_error
};

//
//
//
enum appl_status
    appl_http_decoder::f_write_char(
        unsigned char const
            c_data)
{
    enum appl_status
        e_status;

    e_status =
        appl_status_ok;

    if (
        http_leading_crlf
        == m_function)
    {
        // Store data into start-line buffer

        // Once line is complete, parse it

        // Ignore leading CRLF
        if (
            '\r'
            == c_data)
        {
            m_function =
                http_leading_cr;
        }
        else if (
            '\n'
            == c_data)
        {
            m_function =
                http_error;
        }
        else if (
            (
                ' '
                == c_data)
            || (
                '\t'
                == c_data))
        {
            m_function =
                http_error;
        }
        else
        {
            e_status =
                f_store_char(
                    c_data);

            m_function =
                http_start_line;
        }
    }
    else if (
        http_leading_cr
        == m_function)
    {
        if (
            '\n'
            == c_data)
        {
            m_function =
                http_leading_crlf;
        }
        else
        {
            m_function =
                http_error;
        }
    }
    else if (
        http_start_line
        == m_function)
    {
        if (
            '\r'
            == c_data)
        {
            m_function =
                http_start_line_cr;
        }
        else
        {
            e_status =
                f_store_char(
                    c_data);
        }
    }
    else if (
        http_start_line_cr
        == m_function)
    {
        if (
            '\n'
            == c_data)
        {
            // Flush the start line
            f_flush_header();

            // Switch to header mode
            m_function =
                http_start_line_crlf;
        }
        else
        {
            m_function =
                http_error;
        }
    }
    else if (
        http_start_line_crlf
        == m_function)
    {
        if (
            '\r'
            == c_data)
        {
            m_function =
                http_header_line_crlf_cr;
        }
        else if (
            (
                ' '
                == c_data)
            || (
                '\t'
                == c_data))
        {
            //
            m_function =
                http_error;
        }
        else
        {
            e_status =
                f_store_char(
                    c_data);

            m_function =
                http_header_line;
        }
    }
    else if (
        http_header_line_crlf
        == m_function)
    {
        if (
            '\r'
            == c_data)
        {
            f_flush_header();

            m_function =
                http_header_line_crlf_cr;
        }
        else if (
            (
                ' '
                == c_data)
            || (
                '\t'
                == c_data))
        {
            // Continue previous header
            e_status =
                f_store_char(
                    c_data);

            m_function =
                http_header_line_lws;
        }
        else
        {
            // Flush of previous header
            f_flush_header();

            // Start a new header
            e_status =
                f_store_char(
                    c_data);

            m_function =
                http_header_line;
        }
    }
    else if (
        http_header_line_crlf_cr
        == m_function)
    {
        if (
            '\n'
            == c_data)
        {
            // Flush of header


#if defined APPL_DEBUG
            appl_debug_print0(
                m_context,
                "<<end of headers>>\n");
#endif /* #if defined APPL_DEBUG */

            // Switch to body mode
            m_function =
                http_body;
        }
        else
        {
        }
    }
    else if (
        http_header_line
        == m_function)
    {
        if (
            '\r'
            == c_data)
        {
            m_function =
                http_header_line_cr;
        }
        else
        {
            e_status =
                f_store_char(
                    c_data);
        }
    }
    else if (
        http_header_line_cr
        == m_function)
    {
        if (
            '\n'
            == c_data)
        {
            m_function =
                http_header_line_crlf;
        }
    }
    else if (
        http_header_line_lws
        == m_function)
    {
        if (
            '\r'
            == c_data)
        {
            m_function =
                http_header_line_cr;
        }
        else if (
            (
                ' '
                == c_data)
            || (
                '\t'
                == c_data))
        {
            e_status =
                f_store_char(
                    c_data);

            m_function =
                http_header_line_lws;
        }
        else
        {
            e_status =
                f_store_char(
                    c_data);

            m_function =
                http_header_line;
        }
    }
    else if (
        http_error
        == m_function)
    {
#if defined APPL_DEBUG
        appl_debug_print0(
            m_context,
            "error!\n");
#endif /* #if defined APPL_DEBUG */

        e_status =
            appl_status_fail;
    }
    else if (
        http_body
        == m_function)
    {
#if defined APPL_DEBUG
        appl_debug_print0(
            m_context,
            ".");
#endif /* #if defined APPL_DEBUG */

        e_status =
            f_store_char(
                c_data);
    }
    else
    {
    }

    return
        e_status;

} // f_write_char()

//
//
//
enum appl_status
    appl_http_decoder::f_store_char(
        unsigned char const
            c_data)
{
    enum appl_status
        e_status;

    e_status =
        appl_chunk_write(
            m_chunk,
            &(
                c_data),
            &(
                c_data) + 1u);

    return
        e_status;

} // f_store_char()

//
//
//
enum appl_status
    appl_http_decoder::f_flush(
        unsigned char * * const
            r_buf_min,
        unsigned char * * const
            r_buf_max)
{
    enum appl_status
        e_status;

    unsigned long int
        i_count;

    e_status =
        appl_chunk_length(
            m_chunk,
            &(
                i_count));

    if (
        appl_status_ok
        == e_status)
    {
        union appl_buf_ptr
            o_buf_ptr;

        e_status =
            appl_heap_alloc(
                m_context,
                i_count,
                &(
                    o_buf_ptr.p_void));

        if (
            appl_status_ok
            == e_status)
        {
            e_status =
                appl_chunk_read(
                    m_chunk,
                    o_buf_ptr.p_uchar,
                    o_buf_ptr.p_uchar + i_count);

            if (
                appl_status_ok
                == e_status)
            {
                appl_chunk_reset(
                    m_chunk);

                *(
                    r_buf_min) =
                    o_buf_ptr.p_uchar;

                *(
                    r_buf_max) =
                    o_buf_ptr.p_uchar + i_count;
            }
            else
            {
                appl_heap_free(
                    m_context,
                    i_count,
                    o_buf_ptr.p_void);
            }
        }
    }

    return
        e_status;

} // f_flush()

//
//
//
void
    appl_http_decoder::f_flush_release(
        unsigned char * const
            p_line_min,
        unsigned char * const
            p_line_max)
{
    appl_heap_free(
        m_context,
        appl_buf_len(
            p_line_min,
            p_line_max),
        p_line_min);

} // f_flush_release()

//
//
//
enum appl_status
    appl_http_decoder::f_flush_header(void)
{
    enum appl_status
        e_status;

    unsigned char *
        p_line_min;

    unsigned char *
        p_line_max;

    e_status =
        f_flush(
            &(
                p_line_min),
            &(
                p_line_max));

    if (
        appl_status_ok
        == e_status)
    {
#if defined APPL_DEBUG
        appl_debug_print0(
            m_context,
            "header=[");
        appl_debug_print(
            m_context,
            p_line_min,
            p_line_max);
        appl_debug_print0(
            m_context,
            "]\n");
#endif /* #if defined APPL_DEBUG */

        f_flush_release(
            p_line_min,
            p_line_max);
    }

    return
        e_status;

}


//
//
//
class appl_http_decoder_service
{
    public:

        static
        enum appl_status
            s_create(
                struct appl_context * const
                    p_context,
                struct appl_http_decoder_descriptor const * const
                    p_descriptor,
                struct appl_http_decoder * * const
                    r_this);

        static
        enum appl_status
            s_destroy(
                struct appl_http_decoder * const
                    p_this);

        static
        enum appl_status
            s_write(
                struct appl_http_decoder * const
                    p_this,
                unsigned char const * const
                    p_buf_min,
                unsigned char const * const
                    p_buf_max);

}; // class appl_http_decoder_service

//
//
//
enum appl_status
    appl_http_decoder_service::s_create(
        struct appl_context * const
            p_context,
        struct appl_http_decoder_descriptor const * const
            p_descriptor,
        struct appl_http_decoder * * const
            r_this)
{
    struct appl_allocator * const
        p_allocator =
        appl_context_get_allocator(
            p_context);

    return
        appl_new(
            p_allocator,
            p_descriptor,
            r_this);

} // s_create()

//
//
//
enum appl_status
    appl_http_decoder_service::s_destroy(
        struct appl_http_decoder * const
            p_this)
{
    struct appl_context * const
        p_context =
        p_this->get_context();

    struct appl_allocator * const
        p_allocator =
        appl_context_get_allocator(
            p_context);

    return
        appl_delete(
            p_allocator,
            p_this);

} // s_destroy()

//
//
//
enum appl_status
    appl_http_decoder_service::s_write(
        struct appl_http_decoder * const
            p_this,
        unsigned char const * const
            p_buf_min,
        unsigned char const * const
            p_buf_max)
{
    return
        p_this->v_write(
            p_buf_min,
            p_buf_max);

} // s_write()

//
//
//
enum appl_status
    appl_http_decoder_create(
        struct appl_context * const
            p_context,
        struct appl_http_decoder_descriptor const * const
            p_descriptor,
        struct appl_http_decoder * * const
            r_this)
{
    return
        appl_http_decoder_service::s_create(
            p_context,
            p_descriptor,
            r_this);
} // appl_http_decoder_create()

//
//
//
enum appl_status
    appl_http_decoder_destroy(
        struct appl_http_decoder * const
            p_this)
{
    return
        appl_http_decoder_service::s_destroy(
            p_this);
} // appl_http_decoder_destroy()

//
//
//
enum appl_status
    appl_http_decoder_write(
        struct appl_http_decoder * const
            p_this,
        unsigned char const * const
            p_buf_min,
        unsigned char const * const
            p_buf_max)
{
    return
        appl_http_decoder_service::s_write(
            p_this,
            p_buf_min,
            p_buf_max);
} // appl_http_decoder_write()

/* end-of-file: appl_http_decoder.cpp */
