/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_module_service_h
{
    inc_appl_module_service_h =
        /* Header file dependencies */
        inc_appl_status_h
};

/* Predefine */
struct appl_context;

/* Predefine */
struct appl_packet;

/* Predefine */
struct appl_module;

/* Predefine */
struct appl_object;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
class appl_module_service
{
    public:

        static
        struct appl_object *
        s_parent(
            struct appl_module * const
                p_module);

        static
        struct appl_object const *
        s_const_parent(
            struct appl_module const * const
                p_module);

        static
        enum appl_status
        s_push(
            struct appl_module * const
                p_module,
            struct appl_packet * const
                p_packet);

        static
        enum appl_status
        s_pull(
            struct appl_module * const
                p_module,
            struct appl_packet * * const
                r_packet);

}; // class appl_module_service

/* -- */

/* Predefine */
struct appl_file_source_module;

/* Predefine */
struct appl_file_source_module_descriptor;

//
//
//
class appl_file_source_module_service
{
    public:

        static
        enum appl_status
        s_create(
            struct appl_context * const
                p_context,
            struct appl_file_source_module_descriptor const * const
                p_file_source_module_descriptor,
            struct appl_file_source_module * * const
                r_instance);

        static
        enum appl_status
        s_destroy(
            struct appl_file_source_module * const
                p_this);

        static
        struct appl_module *
        s_parent(
            struct appl_file_source_module * const
                p_this);

        static
        enum appl_status
        s_step(
            struct appl_file_source_module * const
                p_this);

}; // class appl_file_source_module_service

/* -- */

/* Predefine */
struct appl_hex_convert_module;

/* Predefine */
struct appl_hex_convert_module_descriptor;

//
//
//
class appl_hex_convert_module_service
{
    public:

        static
        enum appl_status
        s_create(
            struct appl_context * const
                p_context,
            struct appl_hex_convert_module_descriptor const * const
                p_hex_convert_module_descriptor,
            struct appl_hex_convert_module * * const
                r_instance);

        static
        enum appl_status
        s_destroy(
            struct appl_hex_convert_module * const
                p_this);

        static
        struct appl_module *
        s_parent(
            struct appl_hex_convert_module * const
                p_this);

}; // class appl_hex_convert_module_service

/* -- */

/* Predefine */
struct appl_file_sink_module;

/* Predefine */
struct appl_file_sink_module_descriptor;

//
//
//
class appl_file_sink_module_service
{
    public:

        static
        enum appl_status
        s_create(
            struct appl_context * const
                p_context,
            struct appl_file_sink_module_descriptor const * const
                p_file_sink_module_descriptor,
            struct appl_file_sink_module * * const
                r_instance);

        static
        enum appl_status
        s_destroy(
            struct appl_file_sink_module * const
                p_this);

        static
        struct appl_module *
        s_parent(
            struct appl_file_sink_module * const
                p_this);

}; // class appl_file_sink_module_service

/* -- */

/* Predefine */
struct appl_custom_module;

/* Predefine */
struct appl_custom_module_descriptor;

//
//
//
class appl_custom_module_service
{
    public:

        static
        enum appl_status
        s_create(
            struct appl_context * const
                p_context,
            struct appl_custom_module_descriptor const * const
                p_custom_module_descriptor,
            struct appl_custom_module * * const
                r_instance);

        static
        struct appl_module *
        s_parent(
            struct appl_custom_module * const
                p_custom_module);

}; // class appl_custom_module_service

/* -- */

/* Predefine */
struct appl_null_module;

//
//
//
class appl_null_module_service
{
    public:

        static
        enum appl_status
        s_create(
            struct appl_context * const
                p_context,
            struct appl_null_module * * const
                r_instance);

        static
        struct appl_module *
        s_parent(
            struct appl_null_module * const
                p_null_module);

}; // class appl_null_module_service

/* end-of-file: appl_module_service.h */
