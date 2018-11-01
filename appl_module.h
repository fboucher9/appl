/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_MODULE_H
#error include appl_module.h once
#endif /* #if defined INC_APPL_MODULE_H */

#define INC_APPL_MODULE_H

/* Header file dependencies */
#if ! defined INC_APPL_OBJECT_H
#error include appl_object.h before
#endif /* #if ! defined INC_APPL_OBJECT_H */

/* Predefine */
struct appl_allocator;

/* Predefine */
struct appl_packet;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
struct appl_module : public appl_object
{
    public:

        virtual
        enum appl_status
            v_push(
                struct appl_packet * const
                    p_packet);

        virtual
        enum appl_status
            v_pull(
                struct appl_packet * * const
                    r_packet);

    protected:

        appl_module();

        virtual
        ~appl_module();

    private:

        appl_module(
            struct appl_module const & r);

        struct appl_module &
            operator =(
                struct appl_module const & r);

}; // struct appl_module

/* -- */

/* Predefine */
struct appl_file_source_module_descriptor;

//
//
//
struct appl_file_source_module : public appl_module
{
    public:

        static
        enum appl_status
            s_create(
                struct appl_allocator * const
                    p_allocator,
                struct appl_file_source_module_descriptor const * const
                    p_file_source_module_descriptor,
                struct appl_file_source_module * * const
                    r_instance);

        appl_file_source_module();

        virtual
        ~appl_file_source_module();

        enum appl_status
            f_init(
                struct appl_file_source_module_descriptor const * const
                    p_file_source_module_descriptor);

        enum appl_status
            f_step(void);

    protected:

    private:

        struct appl_file_source_module_descriptor
            m_file_source_descriptor;

        unsigned char
            m_chunk[256u];

        appl_file_source_module(
            struct appl_file_source_module const & r);

        struct appl_file_source_module &
            operator =(
                struct appl_file_source_module const & r);

        virtual
        enum appl_status
            v_cleanup(void);

        virtual
        enum appl_status
            v_push(
                struct appl_packet * const
                    p_packet);

        virtual
        enum appl_status
            v_pull(
                struct appl_packet * * const
                    r_packet);

}; // struct appl_file_source_module

/* -- */

/* Predefine */
struct appl_hex_convert_module_descriptor;

//
//
//
struct appl_hex_convert_module : public appl_module
{
    public:

        static
        enum appl_status
            s_create(
                struct appl_allocator * const
                    p_allocator,
                struct appl_hex_convert_module_descriptor const * const
                    p_hex_convert_module_descriptor,
                struct appl_hex_convert_module * * const
                    r_instance);

        appl_hex_convert_module();

        virtual
        ~appl_hex_convert_module();

        enum appl_status
            f_init(
                struct appl_hex_convert_module_descriptor const * const
                    p_hex_convert_module_descriptor);

    protected:

    private:

        appl_hex_convert_module(
            struct appl_hex_convert_module const & r);

        struct appl_hex_convert_module &
            operator =(
                struct appl_hex_convert_module const & r);

        virtual
        enum appl_status
            v_cleanup(void);

        virtual
        enum appl_status
            v_push(
                struct appl_packet * const
                    p_packet);

        virtual
        enum appl_status
            v_pull(
                struct appl_packet * * const
                    r_packet);

}; // struct appl_hex_convert_module

/* -- */

/* Predefine */
struct appl_file_sink_module_descriptor;

//
//
//
struct appl_file_sink_module : public appl_module
{
    public:

        static
        enum appl_status
            s_create(
                struct appl_allocator * const
                    p_allocator,
                struct appl_file_sink_module_descriptor const * const
                    p_file_sink_module_descriptor,
                struct appl_file_sink_module * * const
                    r_instance);

        appl_file_sink_module();

        virtual
        ~appl_file_sink_module();

        enum appl_status
            f_init(
                struct appl_file_sink_module_descriptor const * const
                    p_file_sink_module_descriptor);

    protected:

    private:

        struct appl_file_sink_module_descriptor
            m_file_sink_descriptor;

        appl_file_sink_module(
            struct appl_file_sink_module const & r);

        struct appl_file_sink_module &
            operator =(
                struct appl_file_sink_module const & r);

        virtual
        enum appl_status
            v_cleanup(void);

        virtual
        enum appl_status
            v_push(
                struct appl_packet * const
                    p_packet);

        virtual
        enum appl_status
            v_pull(
                struct appl_packet * * const
                    r_packet);

}; // struct appl_file_sink_module

/* -- */

/* Predefine */
struct appl_custom_module_descriptor;

//
//
//
struct appl_custom_module : public appl_module
{
    public:

        static
        enum appl_status
            s_create(
                struct appl_allocator * const
                    p_allocator,
                struct appl_custom_module_descriptor const * const
                    p_custom_module_descriptor,
                struct appl_custom_module * * const
                    r_instance);

        appl_custom_module();

        virtual
        ~appl_custom_module();

        enum appl_status
            f_init(
                struct appl_custom_module_descriptor const * const
                    p_custom_module_descriptor);

    protected:

    private:

        struct appl_custom_module_descriptor
            m_custom_module_descriptor;

        appl_custom_module(
            struct appl_custom_module const & r);

        struct appl_custom_module &
            operator =(
                struct appl_custom_module const & r);

        virtual
        enum appl_status
            v_cleanup(void);

        virtual
        enum appl_status
            v_push(
                struct appl_packet * const
                    p_packet);

        virtual
        enum appl_status
            v_pull(
                struct appl_packet * * const
                    r_packet);

}; // struct appl_custom_module

/* -- */

//
//
//
struct appl_null_module : public appl_module
{
    public:

        static
        enum appl_status
            s_create(
                struct appl_allocator * const
                    p_allocator,
                struct appl_null_module * * const
                    r_instance);

        appl_null_module();

        virtual
        ~appl_null_module();

        enum appl_status
            f_init(void);

    protected:

    private:

        appl_null_module(
            struct appl_null_module const & r);

        struct appl_null_module &
            operator =(
                struct appl_null_module const & r);

        virtual
        enum appl_status
            v_cleanup(void);

        virtual
        enum appl_status
            v_push(
                struct appl_packet * const
                    p_packet);

        virtual
        enum appl_status
            v_pull(
                struct appl_packet * * const
                    r_packet);

}; // struct appl_null_module

/* end-of-file: appl_module.h */
