/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_module_handle_h
{
    inc_appl_module_handle_h =
        /* Header file dependencies */
        inc_appl_status_h
};

/* Predefine */
struct appl_module;

/* Predefine */
struct appl_object;

/* Predefine */
struct appl_packet;

#define APPL_PACKET_TYPE_NONE (0ul)

#define APPL_PACKET_TYPE_BINARY (1ul)

#define APPL_PACKET_TYPE_TEXT (2ul)

#define APPL_PACKET_TYPE_FLUSH (3ul)

/*

*/
struct appl_packet
{
    unsigned char *
        p_buf_min;

    unsigned char *
        p_buf_max;

    /* -- */

    unsigned long int
        e_type;

    unsigned long int
        ul_padding[1u];

    /* -- */

    /* timestamps ... */

    /* extensions? */

}; /* struct appl_packet */

#if defined __cplusplus
extern "C" {
#endif /* #if defined __cplusplus */

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

    void *
        pv_padding[1u];

    /* -- */

    unsigned long int
        i_offset;

    unsigned long int
        ul_padding[1u];

    /* -- */

    unsigned short int
        i_columns;

    unsigned short int
        us_padding[3u];

}; /* struct appl_hex_convert_module_descriptor */

enum appl_status
appl_hex_convert_module_create(
    struct appl_context * const
        p_context,
    struct appl_hex_convert_module_descriptor const * const
        p_hex_convert_module_descriptor,
    struct appl_hex_convert_module * * const
        r_instance);

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

    void *
        pv_padding[1u];

}; /* struct appl_file_sink_module_descriptor */

enum appl_status
appl_file_sink_module_create(
    struct appl_context * const
        p_context,
    struct appl_file_sink_module_descriptor const * const
        p_file_sink_module_descriptor,
    struct appl_file_sink_module * * const
        r_instance);

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

    void *
        pv_padding[1u];

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

#if defined __cplusplus
} /* extern "C" */
#endif /* #if defined __cplusplus */

/* end-of-file: appl_module_handle.h */
