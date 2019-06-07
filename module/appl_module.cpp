/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_module_handle.h>

#include <appl_object.h>

#include <module/appl_module.h>

#include <appl_unused.h>

#include <appl_allocator_handle.h>

#include <file/appl_file_node.h>

#include <appl_buf.h>

#include <appl_convert.h>

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

enum appl_status
    appl_module::v_push(
        struct appl_packet * const
            p_packet)
{
    appl_unused(
        p_packet);

    return
        appl_raise_not_implemented();

}

enum appl_status
    appl_module::v_pull(
        struct appl_packet * * const
            r_packet)
{
    appl_unused(
        r_packet);

    return
        appl_raise_not_implemented();

}

//
//
//
enum appl_status
    appl_module::v_release(
        struct appl_packet * const
            p_packet)
{
    appl_unused(
        p_packet);

    return
        appl_raise_not_implemented();

} // v_release()

appl_module::appl_module(
    struct appl_context * const
        p_context) :
    appl_object(
        p_context)
{
}

appl_module::~appl_module()
{
}

enum appl_status
    appl_file_source_module::s_create(
        struct appl_allocator * const
            p_allocator,
        struct appl_file_source_module_descriptor const * const
            p_file_source_module_descriptor,
        struct appl_file_source_module * * const
            r_instance)
{
    return
        appl_new(
            p_allocator,
            p_file_source_module_descriptor,
            r_instance);

}

appl_file_source_module::appl_file_source_module(
    struct appl_context * const
        p_context) :
    appl_module(
        p_context),
    m_file_source_descriptor()
{
}

appl_file_source_module::~appl_file_source_module()
{
}

enum appl_status
    appl_file_source_module::f_init(
        struct appl_file_source_module_descriptor const * const
            p_file_source_module_descriptor)
{
    m_file_source_descriptor =
        *(
            p_file_source_module_descriptor);

    return
        appl_status_ok;

}

enum appl_status
    appl_file_source_module::f_step(void)
{
    enum appl_status
        e_status;

    // Read chunk from input file
    unsigned long int
        i_count;

    e_status =
        m_file_source_descriptor.p_file->v_read(
            m_chunk,
            m_chunk + sizeof(m_chunk),
            &(
                i_count));

    if (
        appl_status_ok
        == e_status)
    {
        // Send this chunk to sink
        struct appl_packet
            o_packet;

        o_packet.p_buf_min =
            m_chunk;

        o_packet.p_buf_max =
            m_chunk + i_count;

        o_packet.e_type =
            APPL_PACKET_TYPE_BINARY;

        e_status =
            m_file_source_descriptor.p_sink->v_push(
                &(
                    o_packet));

        if (
            appl_status_ok
            == e_status)
        {
            // Send a flush
            o_packet.p_buf_min =
                m_chunk;

            o_packet.p_buf_max =
                m_chunk;

            o_packet.e_type =
                APPL_PACKET_TYPE_FLUSH;

            e_status =
                m_file_source_descriptor.p_sink->v_push(
                    &(
                        o_packet));
        }
    }

    return
        e_status;

}

appl_size_t
    appl_file_source_module::v_cleanup(void)
{
    return
        sizeof(struct appl_file_source_module);
}

enum appl_status
    appl_file_source_module::v_push(
        struct appl_packet * const
            p_packet)
{
    return
        appl_module::v_push(
            p_packet);

}

enum appl_status
    appl_file_source_module::v_pull(
        struct appl_packet * * const
            r_packet)
{
    return
        appl_module::v_pull(
            r_packet);

}

//
//
//
enum appl_status
    appl_hex_convert_module::s_create(
        struct appl_allocator * const
            p_allocator,
        struct appl_hex_convert_module_descriptor const * const
            p_hex_convert_module_descriptor,
        struct appl_hex_convert_module * * const
            r_instance)
{
    return
        appl_new(
            p_allocator,
            p_hex_convert_module_descriptor,
            r_instance);

}

//
//
//
appl_hex_convert_module::appl_hex_convert_module(
    struct appl_context * const
        p_context) :
    appl_module(
        p_context),
    m_hex_convert_descriptor(),
    m_offset(),
    m_count()
{
}

//
//
//
appl_hex_convert_module::~appl_hex_convert_module()
{
}

//
//
//
enum appl_status
    appl_hex_convert_module::f_init(
        struct appl_hex_convert_module_descriptor const * const
            p_hex_convert_module_descriptor)
{
    enum appl_status
        e_status;

    m_hex_convert_descriptor =
        *(
            p_hex_convert_module_descriptor);

    if (
        m_hex_convert_descriptor.i_columns < 1u)
    {
        m_hex_convert_descriptor.i_columns = 1u;
    }
    else if (
        m_hex_convert_descriptor.i_columns > 16u)
    {
        m_hex_convert_descriptor.i_columns = 16u;
    }

    m_offset =
        m_hex_convert_descriptor.i_offset;

    m_count =
        0u;

    e_status =
        appl_status_ok;

    return
        e_status;

} // f_init()

appl_size_t
    appl_hex_convert_module::v_cleanup(void)
{
    return
        sizeof(struct appl_hex_convert_module);

}

enum appl_status
    appl_hex_convert_module::v_push(
        struct appl_packet * const
            p_packet)
{
    enum appl_status
        e_status;

    if (
        APPL_PACKET_TYPE_BINARY == p_packet->e_type)
    {
        unsigned char *
            p_buf_iterator;

        p_buf_iterator =
            p_packet->p_buf_min;

        e_status =
            appl_status_ok;

        while (
            (
                appl_status_ok
                == e_status)
            && (
                p_buf_iterator
                < p_packet->p_buf_max))
        {
            // Copy data into column cache
            if (
                m_count
                < m_hex_convert_descriptor.i_columns)
            {
                m_columns[m_count] =
                    *(
                        p_buf_iterator);

                p_buf_iterator ++;

                m_count ++;
            }

            // Do flush of column cache
            if (
                m_count
                >= m_hex_convert_descriptor.i_columns)
            {
                e_status =
                    f_flush();
            }
        }
    }
    else if (
        APPL_PACKET_TYPE_FLUSH == p_packet->e_type)
    {
        e_status =
            f_flush();

        if (
            appl_status_ok
            == e_status)
        {
            e_status =
                m_hex_convert_descriptor.p_sink->v_push(
                    p_packet);
        }
    }
    else
    {
        e_status =
            appl_status_fail;
    }

    return
        e_status;

}

enum appl_status
    appl_hex_convert_module::v_pull(
        struct appl_packet * * const
            r_packet)
{
    return
        appl_module::v_pull(
            r_packet);

}

enum appl_status
    appl_hex_convert_module::f_flush(void)
{
    enum appl_status
        e_status;

    if (
        m_count)
    {
        unsigned char *
            p_line_iterator;

        p_line_iterator =
            m_line_buffer;

        // Build line prefix
        p_line_iterator =
            appl_buf_print_number(
                p_line_iterator,
                m_line_buffer + sizeof(m_line_buffer),
                appl_convert::to_signed(
                    m_offset),
                appl_buf_print_flag_hex
                | appl_buf_print_flag_zero
                | appl_buf_print_flag_unsigned,
                8u);

        p_line_iterator =
            appl_buf_write(
                p_line_iterator,
                m_line_buffer + sizeof(m_line_buffer),
                ':');

        // Build hex dump section
        {
            unsigned short int
                i_column_iterator;

            i_column_iterator =
                0u;

            while (
                i_column_iterator
                < m_count)
            {
                unsigned char const
                    i_data =
                    m_columns[i_column_iterator];

                unsigned long int const
                    l_data =
                    i_data;

                p_line_iterator =
                    appl_buf_print_number(
                        p_line_iterator,
                        m_line_buffer + sizeof(m_line_buffer),
                        appl_convert::to_signed(
                            l_data),
                        appl_buf_print_flag_hex
                        | appl_buf_print_flag_zero
                        | appl_buf_print_flag_unsigned,
                        2u);

                p_line_iterator =
                    appl_buf_write(
                        p_line_iterator,
                        m_line_buffer + sizeof(m_line_buffer),
                        ' ');

                i_column_iterator ++;
            }

            while (
                i_column_iterator
                < m_hex_convert_descriptor.i_columns)
            {
                static unsigned char const g_filler[3u] =
                {
                    ' ',
                    ' ',
                    ' '
                };

                p_line_iterator =
                    appl_buf_copy(
                        p_line_iterator,
                        m_line_buffer + sizeof(m_line_buffer),
                        g_filler,
                        g_filler + sizeof(g_filler));

                i_column_iterator ++;
            }
        }

        p_line_iterator =
            appl_buf_write(
                p_line_iterator,
                m_line_buffer + sizeof(m_line_buffer),
                '|');

        // Build ascii dump section
        {
            unsigned short int
                i_column_iterator;

            i_column_iterator =
                0u;

            while (
                i_column_iterator
                < m_count)
            {
                unsigned char const
                    i_data =
                    m_columns[i_column_iterator];

                if (
                    (
                        32 <= i_data)
                    && (
                        127 > i_data))
                {
                    p_line_iterator =
                        appl_buf_write(
                            p_line_iterator,
                            m_line_buffer + sizeof(m_line_buffer),
                            i_data);
                }
                else
                {
                    p_line_iterator =
                        appl_buf_write(
                            p_line_iterator,
                            m_line_buffer + sizeof(m_line_buffer),
                            '.');
                }
                i_column_iterator ++;
            }
        }

        // Complete the line
        p_line_iterator =
            appl_buf_write(
                p_line_iterator,
                m_line_buffer + sizeof(m_line_buffer),
                '\n');

        if (
            p_line_iterator
            != m_line_buffer)
        {
            struct appl_packet
                o_packet;

            o_packet.p_buf_min =
                m_line_buffer;

            o_packet.p_buf_max =
                p_line_iterator;

            o_packet.e_type =
                APPL_PACKET_TYPE_TEXT;

            e_status =
                m_hex_convert_descriptor.p_sink->v_push(
                    &(
                        o_packet));
        }
        else
        {
            e_status =
                appl_status_ok;
        }

        m_offset +=
            m_count;

        m_count =
            0;
    }
    else
    {
        e_status =
            appl_status_ok;
    }

    return
        e_status;

}

//
//
//
enum appl_status
    appl_file_sink_module::s_create(
        struct appl_allocator * const
            p_allocator,
        struct appl_file_sink_module_descriptor const * const
            p_file_sink_module_descriptor,
        struct appl_file_sink_module * * const
            r_instance)
{
    return
        appl_new(
            p_allocator,
            p_file_sink_module_descriptor,
            r_instance);

}

//
//
//
appl_file_sink_module::appl_file_sink_module(
    struct appl_context * const
        p_context) :
    appl_module(
        p_context),
    m_file_sink_descriptor()
{
}

//
//
//
appl_file_sink_module::~appl_file_sink_module()
{
}

//
//
//
enum appl_status
    appl_file_sink_module::f_init(
        struct appl_file_sink_module_descriptor const * const
            p_file_sink_module_descriptor)
{
    m_file_sink_descriptor =
        *(
            p_file_sink_module_descriptor);

    return
        appl_status_ok;

}

//
//
//
appl_size_t
    appl_file_sink_module::v_cleanup(void)
{
    return
        sizeof(struct appl_file_sink_module);
}

//
//
//
enum appl_status
    appl_file_sink_module::v_push(
        struct appl_packet * const
            p_packet)
{
    enum appl_status
        e_status;

    unsigned long int
        i_count;

    unsigned char *
        p_buf_iterator;

    p_buf_iterator =
        p_packet->p_buf_min;

    e_status =
        appl_status_ok;

    while (
        (
            appl_status_ok
            == e_status)
        && (
            p_buf_iterator
            < p_packet->p_buf_max))
    {
        // Write buffer to file
        e_status =
            m_file_sink_descriptor.p_file->v_write(
                p_packet->p_buf_min,
                p_packet->p_buf_max,
                &(
                    i_count));

        if (
            appl_status_ok
            == e_status)
        {
            if (
                i_count)
            {
                p_buf_iterator +=
                    i_count;
            }
            else
            {
                e_status =
                    appl_status_fail;
            }
        }
    }

    return
        e_status;

}

//
//
//
enum appl_status
    appl_file_sink_module::v_pull(
        struct appl_packet * * const
            r_packet)
{
    return
        appl_module::v_pull(
            r_packet);
}

//
//
//
enum appl_status
    appl_custom_module::s_create(
        struct appl_allocator * const
            p_allocator,
        struct appl_custom_module_descriptor const * const
            p_custom_module_descriptor,
        struct appl_custom_module * * const
            r_instance)
{
    return
        appl_new(
            p_allocator,
            p_custom_module_descriptor,
            r_instance);

}

//
//
//
appl_custom_module::appl_custom_module(
    struct appl_context * const
        p_context) :
    appl_module(
        p_context),
    m_custom_module_descriptor()
{
}

//
//
//
appl_custom_module::~appl_custom_module()
{
}

//
//
//
enum appl_status
    appl_custom_module::f_init(
        struct appl_custom_module_descriptor const * const
            p_custom_module_descriptor)
{
    appl_unused(
        p_custom_module_descriptor);
    return
        appl_status_fail;
}

//
//
//
appl_size_t
    appl_custom_module::v_cleanup(void)
{
    return
        sizeof(struct appl_custom_module);
}

//
//
//
enum appl_status
    appl_custom_module::v_push(
        struct appl_packet * const
            p_packet)
{
    return
        appl_module::v_push(
            p_packet);

}

//
//
//
enum appl_status
    appl_custom_module::v_pull(
        struct appl_packet * * const
            r_packet)
{
    return
        appl_module::v_pull(
            r_packet);

}

//
//
//
enum appl_status
    appl_null_module::s_create(
        struct appl_allocator * const
            p_allocator,
        struct appl_null_module * * const
            r_instance)
{
    return
        appl_new(
            p_allocator,
            r_instance);

}

//
//
//
appl_null_module::appl_null_module(
    struct appl_context * const
        p_context) :
    appl_module(
        p_context)
{
}

//
//
//
appl_null_module::~appl_null_module()
{
}

//
//
//
enum appl_status
    appl_null_module::f_init(void)
{
    return
        appl_status_ok;
}

//
//
//
appl_size_t
    appl_null_module::v_cleanup(void)
{
    return
        sizeof(struct appl_null_module);
}

//
//
//
enum appl_status
    appl_null_module::v_push(
        struct appl_packet * const
            p_packet)
{
    return
        appl_module::v_push(
            p_packet);

}

//
//
//
enum appl_status
    appl_null_module::v_pull(
        struct appl_packet * * const
            r_packet)
{
    return
        appl_module::v_pull(
            r_packet);

}

/* end-of-file: appl_module.cpp */
