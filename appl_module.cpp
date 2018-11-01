/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_module_handle.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_module.h>

#include <appl_unused.h>

#include <appl_allocator.h>

#include <appl_file_node.h>

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
        appl_status_not_implemented;

}

enum appl_status
    appl_module::v_pull(
        struct appl_packet * * const
            r_packet)
{
    appl_unused(
        r_packet);

    return
        appl_status_not_implemented;

}

appl_module::appl_module() :
    appl_object()
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
        p_allocator->alloc_object(
            p_file_source_module_descriptor,
            r_instance);

}

appl_file_source_module::appl_file_source_module() :
    appl_module(),
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
    }

    return
        e_status;

}

enum appl_status
    appl_file_source_module::v_cleanup(void)
{
    return
        appl_status_ok;
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
        p_allocator->alloc_object(
            p_hex_convert_module_descriptor,
            r_instance);

}

appl_hex_convert_module::appl_hex_convert_module() :
    appl_module()
{
}

appl_hex_convert_module::~appl_hex_convert_module()
{
}

enum appl_status
    appl_hex_convert_module::f_init(
        struct appl_hex_convert_module_descriptor const * const
            p_hex_convert_module_descriptor)
{
    appl_unused(
        p_hex_convert_module_descriptor);

    return
        appl_status_fail;

}

enum appl_status
    appl_hex_convert_module::v_cleanup(void)
{
    return
        appl_status_ok;

}

enum appl_status
    appl_hex_convert_module::v_push(
        struct appl_packet * const
            p_packet)
{
    return
        appl_module::v_push(
            p_packet);

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
        p_allocator->alloc_object(
            p_file_sink_module_descriptor,
            r_instance);

}

//
//
//
appl_file_sink_module::appl_file_sink_module() :
    appl_module()
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
    appl_unused(
        p_file_sink_module_descriptor);

    return
        appl_status_fail;
}

//
//
//
enum appl_status
    appl_file_sink_module::v_cleanup(void)
{
    return
        appl_status_ok;
}

//
//
//
enum appl_status
    appl_file_sink_module::v_push(
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
        p_allocator->alloc_object(
            p_custom_module_descriptor,
            r_instance);

}

//
//
//
appl_custom_module::appl_custom_module() :
    appl_module(),
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
enum appl_status
    appl_custom_module::v_cleanup(void)
{
    return
        appl_status_ok;
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
        p_allocator->alloc_object(
            r_instance);

}

//
//
//
appl_null_module::appl_null_module() :
    appl_module()
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
enum appl_status
    appl_null_module::v_cleanup(void)
{
    return
        appl_status_ok;
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
