/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_module_handle_h
{
    inc_appl_module_handle_h =
        /* Header file dependencies */
        inc_appl_status_h
        + inc_appl_types_h
};

#include <appl_extern_c_begin.h>

struct appl_object *
appl_module_parent(
    struct appl_module * const
        p_module);

struct appl_object const *
appl_module_const_parent(
    struct appl_module const * const
        p_module);

/* Source pushes a buffer towards sink */
enum appl_status
appl_module_push(
    struct appl_module * const
        p_module,
    struct appl_packet * const
        p_packet);

/* Sink pulls a buffer from source */
enum appl_status
appl_module_pull(
    struct appl_module * const
        p_module,
    struct appl_packet * * const
        p_packet);

/* Release of buffer back to owner */
enum appl_status
appl_module_release(
    struct appl_module * const
        p_module,
    struct appl_packet * const
        p_packet);

/* -- */

/* Predefine */
struct appl_file_source_module;

/*

*/
struct appl_file_source_module_descriptor
{
    struct appl_module *
        p_sink;

    struct appl_file *
        p_file;

}; /* struct appl_file_source_module_descriptor */

enum appl_status
appl_file_source_module_create(
    struct appl_context * const
        p_context,
    struct appl_file_source_module_descriptor const * const
        p_file_source_module_descriptor,
    struct appl_file_source_module * * const
        r_instance);

enum appl_status
appl_file_source_module_destroy(
    struct appl_file_source_module * const
        p_this);

struct appl_module *
appl_file_source_module_parent(
    struct appl_file_source_module * const
        p_this);

enum appl_status
appl_file_source_module_step(
    struct appl_file_source_module * const
        p_this);

/* -- */

struct appl_hex_convert_module;

/*

*/
struct appl_hex_convert_module_descriptor
{
    struct appl_module *
        p_sink;

    unsigned long int
        i_offset;

    unsigned short int
        i_columns;

#define PADDING (APPL_SIZEOF_PTR + APPL_SIZEOF_LONG + 2)
#include <appl_padding.h>

}; /* struct appl_hex_convert_module_descriptor */

enum appl_status
appl_hex_convert_module_create(
    struct appl_context * const
        p_context,
    struct appl_hex_convert_module_descriptor const * const
        p_hex_convert_module_descriptor,
    struct appl_hex_convert_module * * const
        r_instance);

enum appl_status
appl_hex_convert_module_destroy(
    struct appl_hex_convert_module * const
        p_this);

struct appl_module *
appl_hex_convert_module_parent(
    struct appl_hex_convert_module * const
        p_this);

/* -- */

struct appl_file_sink_module;

struct appl_file_sink_module_descriptor
{
    struct appl_file *
        p_file;

#define PADDING (APPL_SIZEOF_PTR)
#include <appl_padding.h>

}; /* struct appl_file_sink_module_descriptor */

enum appl_status
appl_file_sink_module_create(
    struct appl_context * const
        p_context,
    struct appl_file_sink_module_descriptor const * const
        p_file_sink_module_descriptor,
    struct appl_file_sink_module * * const
        r_instance);

enum appl_status
appl_file_sink_module_destroy(
    struct appl_file_sink_module * const
        p_this);

struct appl_module *
appl_file_sink_module_parent(
    struct appl_file_sink_module * const
        p_this);

/* -- */

struct appl_custom_module;

/*

*/
struct appl_custom_module_descriptor
{
    enum appl_status
        (* p_push)(
            void * const
                p_custom_context,
            struct appl_packet * const
                p_packet);

    enum appl_status
        (* p_pull)(
            void * const
                p_custom_context,
            struct appl_packet * * const
                r_packet);

    /* -- */

    void *
        p_custom_context;

#define PADDING (APPL_SIZEOF_PTR)
#include <appl_padding.h>

}; /* struct appl_custom_module_descriptor */

enum appl_status
appl_custom_module_create(
    struct appl_context * const
        p_context,
    struct appl_custom_module_descriptor const * const
        p_custom_module_descriptor,
    struct appl_custom_module * * const
        r_instance);

struct appl_module *
appl_custom_module_parent(
    struct appl_custom_module * const
        p_custom_module);

/* -- */

struct appl_null_module;

enum appl_status
appl_null_module_create(
    struct appl_context * const
        p_context,
    struct appl_null_module * * const
        r_instance);

struct appl_module *
appl_null_module_parent(
    struct appl_null_module * const
        p_null_module);

#include <appl_extern_c_end.h>

/* end-of-file: appl_module_handle.h */
