/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <module/appl_module_handle.h>

#include <module/appl_module_service.h>

#include <object/appl_object.h>

#include <module/appl_module.h>

#include <context/appl_context_handle.h>

#include <allocator/appl_allocator_handle.h>

/* Assert compiler */
#include <misc/appl_assert_cplusplus.h>

//
//
//
struct appl_object *
appl_module_service::s_parent(
    struct appl_module * const
        p_module)
{
    return
        p_module;

}

//
//
//
struct appl_object const *
appl_module_service::s_const_parent(
    struct appl_module const * const
        p_module)
{
    return
        p_module;

}

//
//
//
enum appl_status
appl_module_service::s_push(
    struct appl_module * const
        p_module,
    struct appl_packet * const
        p_packet)
{
    return
        p_module->v_push(
            p_packet);

}

//
//
//
enum appl_status
appl_module_service::s_pull(
    struct appl_module * const
        p_module,
    struct appl_packet * * const
        r_packet)
{
    return
        p_module->v_pull(
            r_packet);
}

//
//
//
enum appl_status
appl_module_service::s_release(
    struct appl_module * const
        p_module,
    struct appl_packet * const
        p_packet)
{
    return
        p_module->v_release(
            p_packet);

} // s_release()


//
//
//
enum appl_status
appl_file_source_module_service::s_create(
    struct appl_context * const
        p_context,
    struct appl_file_source_module_descriptor const * const
        p_file_source_module_descriptor,
    struct appl_file_source_module * * const
        r_instance)
{
    return
        appl_file_source_module::s_create(
            appl_context_get_allocator(p_context),
            p_file_source_module_descriptor,
            r_instance);

}

enum appl_status
appl_file_source_module_service::s_destroy(
    struct appl_file_source_module * const
        p_this)
{
    struct appl_context * const
        p_context =
        p_this->get_context();

    return
        appl_delete(
            appl_context_get_allocator(p_context),
            p_this);

} // s_destroy()

//
//
//
struct appl_module *
appl_file_source_module_service::s_parent(
    struct appl_file_source_module * const
        p_this)
{
    return
        p_this;

}

//
//
//
enum appl_status
appl_file_source_module_service::s_step(
    struct appl_file_source_module * const
        p_this)
{
    return
        p_this->f_step();

}

//
//
//
enum appl_status
appl_hex_convert_module_service::s_create(
    struct appl_context * const
        p_context,
    struct appl_hex_convert_module_descriptor const * const
        p_hex_convert_module_descriptor,
    struct appl_hex_convert_module * * const
        r_instance)
{
    return
        appl_hex_convert_module::s_create(
            appl_context_get_allocator(p_context),
            p_hex_convert_module_descriptor,
            r_instance);
}

enum appl_status
appl_hex_convert_module_service::s_destroy(
    struct appl_hex_convert_module * const
        p_this)
{
    struct appl_context * const
        p_context =
        p_this->get_context();

    return
        appl_delete(
            appl_context_get_allocator(p_context),
            p_this);
}

//
//
//
struct appl_module *
appl_hex_convert_module_service::s_parent(
    struct appl_hex_convert_module * const
        p_this)
{
    return
        p_this;

}

//
//
//
enum appl_status
appl_file_sink_module_service::s_create(
    struct appl_context * const
        p_context,
    struct appl_file_sink_module_descriptor const * const
        p_file_sink_module_descriptor,
    struct appl_file_sink_module * * const
        r_instance)
{
    return
        appl_file_sink_module::s_create(
            appl_context_get_allocator(p_context),
            p_file_sink_module_descriptor,
            r_instance);

}

//
//
//
enum appl_status
appl_file_sink_module_service::s_destroy(
    struct appl_file_sink_module * const
        p_this)
{
    struct appl_context * const
        p_context =
        p_this->get_context();

    return
        appl_delete(
            appl_context_get_allocator(p_context),
            p_this);
}

//
//
//
struct appl_module *
appl_file_sink_module_service::s_parent(
    struct appl_file_sink_module * const
        p_this)
{
    return
        p_this;

}

//
//
//
enum appl_status
appl_custom_module_service::s_create(
    struct appl_context * const
        p_context,
    struct appl_custom_module_descriptor const * const
        p_custom_module_descriptor,
    struct appl_custom_module * * const
        r_instance)
{
    return
        appl_custom_module::s_create(
            appl_context_get_allocator(p_context),
            p_custom_module_descriptor,
            r_instance);

}

//
//
//
struct appl_module *
appl_custom_module_service::s_parent(
    struct appl_custom_module * const
        p_custom_module)
{
    return
        p_custom_module;

}

//
//
//
enum appl_status
appl_null_module_service::s_create(
    struct appl_context * const
        p_context,
    struct appl_null_module * * const
        r_instance)
{
    return
        appl_null_module::s_create(
            appl_context_get_allocator(p_context),
            r_instance);

}

//
//
//
struct appl_module *
appl_null_module_service::s_parent(
    struct appl_null_module * const
        p_null_module)
{
    return
        p_null_module;

}

/* end-of-file: appl_module_service.h */
