#include <appl_status.h>

#include <appl_types.h>

#include <module/appl_module_handle.h>

#include <module/appl_module_service.h>

struct appl_object *
appl_module_parent(
    struct appl_module * const
        p_module)
{
    return
        appl_module_service::s_parent(
            p_module);

}

struct appl_object const *
appl_module_const_parent(
    struct appl_module const * const
        p_module)
{
    return
        appl_module_service::s_const_parent(
            p_module);

}

enum appl_status
appl_module_push(
    struct appl_module * const
        p_module,
    struct appl_packet * const
        p_packet)
{
    return
        appl_module_service::s_push(
            p_module,
            p_packet);

}

enum appl_status
appl_module_pull(
    struct appl_module * const
        p_module,
    struct appl_packet * * const
        p_packet)
{
    return
        appl_module_service::s_pull(
            p_module,
            p_packet);

}

//
//
//
enum appl_status
appl_module_release(
    struct appl_module * const
        p_module,
    struct appl_packet * const
        p_packet)
{
    return
        appl_module_service::s_release(
            p_module,
            p_packet);

} // appl_module_release()

enum appl_status
appl_file_source_module_create(
    struct appl_context * const
        p_context,
    struct appl_file_source_module_descriptor const * const
        p_file_source_module_descriptor,
    struct appl_file_source_module * * const
        r_instance)
{
    return
        appl_file_source_module_service::s_create(
            p_context,
            p_file_source_module_descriptor,
            r_instance);

}

enum appl_status
appl_file_source_module_destroy(
    struct appl_file_source_module * const
        p_this)
{
    return appl_file_source_module_service::s_destroy(
        p_this);
}

struct appl_module *
appl_file_source_module_parent(
    struct appl_file_source_module * const
        p_this)
{
    return
        appl_file_source_module_service::s_parent(
            p_this);

}

enum appl_status
appl_file_source_module_step(
    struct appl_file_source_module * const
        p_this)
{
    return
        appl_file_source_module_service::s_step(
            p_this);

}

enum appl_status
appl_hex_convert_module_create(
    struct appl_context * const
        p_context,
    struct appl_hex_convert_module_descriptor const * const
        p_hex_convert_module_descriptor,
    struct appl_hex_convert_module * * const
        r_instance)
{
    return
        appl_hex_convert_module_service::s_create(
            p_context,
            p_hex_convert_module_descriptor,
            r_instance);

}

enum appl_status
appl_hex_convert_module_destroy(
    struct appl_hex_convert_module * const
        p_this)
{
    return
        appl_hex_convert_module_service::s_destroy(
            p_this);
}

struct appl_module *
appl_hex_convert_module_parent(
    struct appl_hex_convert_module * const
        p_this)
{
    return
        appl_hex_convert_module_service::s_parent(
            p_this);

}

enum appl_status
appl_file_sink_module_create(
    struct appl_context * const
        p_context,
    struct appl_file_sink_module_descriptor const * const
        p_file_sink_module_descriptor,
    struct appl_file_sink_module * * const
        r_instance)
{
    return
        appl_file_sink_module_service::s_create(
            p_context,
            p_file_sink_module_descriptor,
            r_instance);

}

enum appl_status
appl_file_sink_module_destroy(
    struct appl_file_sink_module * const
        p_this)
{
    return
        appl_file_sink_module_service::s_destroy(
            p_this);
}

struct appl_module *
appl_file_sink_module_parent(
    struct appl_file_sink_module * const
        p_this)
{
    return
        appl_file_sink_module_service::s_parent(
            p_this);

}

enum appl_status
appl_custom_module_create(
    struct appl_context * const
        p_context,
    struct appl_custom_module_descriptor const * const
        p_custom_module_descriptor,
    struct appl_custom_module * * const
        r_instance)
{
    return
        appl_custom_module_service::s_create(
            p_context,
            p_custom_module_descriptor,
            r_instance);

}

struct appl_module *
appl_custom_module_parent(
    struct appl_custom_module * const
        p_custom_module)
{
    return
        appl_custom_module_service::s_parent(
            p_custom_module);

}

enum appl_status
appl_null_module_create(
    struct appl_context * const
        p_context,
    struct appl_null_module * * const
        r_instance)
{
    return
        appl_null_module_service::s_create(
            p_context,
            r_instance);

}

struct appl_module *
appl_null_module_parent(
    struct appl_null_module * const
        p_null_module)
{
    return
        appl_null_module_service::s_parent(
            p_null_module);

}

/* end-of-file: appl_module_handle.cpp */
