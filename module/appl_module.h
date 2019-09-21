/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_module_h
{
    inc_appl_module_h =
        /* Header file dependencies */
        inc_appl_object_h
};

/* Predefine */
struct appl_allocator;

/* Predefine */
struct appl_packet;

/* Assert compiler */
#include <appl_assert_cplusplus.h>

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

        virtual
        enum appl_status
            v_release(
                struct appl_packet * const
                    p_packet);

    protected:

        appl_module(
            struct appl_context * const
                p_context);

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

        appl_file_source_module(
            struct appl_context * const
                p_context);

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

        // --

        struct appl_file_source_module_descriptor
            m_file_source_descriptor;

        // --

        unsigned char
            m_chunk[256u];

        // --

        appl_file_source_module(
            struct appl_file_source_module const & r);

        struct appl_file_source_module &
            operator =(
                struct appl_file_source_module const & r);

        virtual
        appl_size_t
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

        appl_hex_convert_module(
            struct appl_context * const
                p_context);

        virtual
        ~appl_hex_convert_module();

        enum appl_status
            f_init(
                struct appl_hex_convert_module_descriptor const * const
                    p_hex_convert_module_descriptor);

    protected:

    private:

        // --

        struct appl_hex_convert_module_descriptor
            m_hex_convert_descriptor;

        // --

        unsigned long int
            m_offset;

        unsigned long int
            m_count;

        // --

        unsigned char
            m_columns[16u];

        // --

        unsigned char
            m_line_buffer[80u];

        // --

        appl_hex_convert_module(
            struct appl_hex_convert_module const & r);

        struct appl_hex_convert_module &
            operator =(
                struct appl_hex_convert_module const & r);

        virtual
        appl_size_t
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

        enum appl_status
            f_flush(void);

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

        appl_file_sink_module(
            struct appl_context * const
                p_context);

        virtual
        ~appl_file_sink_module();

        enum appl_status
            f_init(
                struct appl_file_sink_module_descriptor const * const
                    p_file_sink_module_descriptor);

    protected:

    private:

        // --

        struct appl_file_sink_module_descriptor
            m_file_sink_descriptor;

        // --

        appl_file_sink_module(
            struct appl_file_sink_module const & r);

        struct appl_file_sink_module &
            operator =(
                struct appl_file_sink_module const & r);

        virtual
        appl_size_t
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

        appl_custom_module(
            struct appl_context * const
                p_context);

        virtual
        ~appl_custom_module();

        enum appl_status
            f_init(
                struct appl_custom_module_descriptor const * const
                    p_custom_module_descriptor);

    protected:

    private:

        // --

        struct appl_custom_module_descriptor
            m_custom_module_descriptor;

        // --

        appl_custom_module(
            struct appl_custom_module const & r);

        struct appl_custom_module &
            operator =(
                struct appl_custom_module const & r);

        virtual
        appl_size_t
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

        appl_null_module(
            struct appl_context * const
                p_context);

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
        appl_size_t
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
