/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_url_std_h
{
    inc_appl_url_std_h = 1
        /* Header file dependencies */
        + inc_appl_url_h
        + inc_appl_list_h
}; /* enum guard_appl_url_std_h */

/* Included. */
#define INC_APPL_URL_STD_H

/* Predefine */
struct appl_url_component;

//
//
//
class appl_url_std : public appl_url
{
    public:

        appl_url_std(
            struct appl_context * const
                p_context);

        virtual
        ~appl_url_std();

        enum appl_status
            f_init(void);

        virtual
        appl_size_t
            v_cleanup(void);

    protected:

    private:

        // --

        struct appl_list
            m_components[8u];

        // --

        unsigned long int
            m_flags;

        unsigned long int
            ul_padding[1u];

        // --

        appl_url_std(
            class appl_url_std const & r);

        class appl_url_std &
            operator =(
                class appl_url_std const & r);

        void
            f_cleanup_all_component_lists(void);

        void
            f_cleanup_component_list(
                signed short int const
                    e_component_type);

        virtual
        enum appl_status
            v_decoder(
                unsigned char const * const
                    p_input_min,
                unsigned char const * const
                    p_input_max,
                unsigned long int * const
                    r_input_count);

        virtual
        enum appl_status
            v_encoder_length(
                unsigned long int * const
                    r_output_count) const;

        virtual
        enum appl_status
            v_encoder(
                unsigned char * const
                    p_output_min,
                unsigned char * const
                    p_output_max,
                unsigned long int * const
                    r_output_count) const;

        virtual
        enum appl_status
            v_add_component(
                signed short int const
                    e_component_type,
                unsigned char const * const
                    p_buf_min,
                unsigned char const * const
                    p_buf_max,
                struct appl_url_component * * const
                    r_handle);

        virtual
        enum appl_status
            v_remove_component(
                signed short int const
                    e_component_type,
                struct appl_url_component * const
                    p_handle);

        virtual
        enum appl_status
            v_get_component(
                signed short int const
                    e_component_type,
                unsigned char const * * const
                    r_buf_min,
                unsigned char const * * const
                    r_buf_max,
                struct appl_url_component * * const
                    r_handle) const;

        virtual
        enum appl_status
            v_next_component(
                signed short int const
                    e_component_type,
                unsigned char const * * const
                    r_buf_min,
                unsigned char const * * const
                    r_buf_max,
                struct appl_url_component * * const
                    r_handle) const;

        virtual
        enum appl_status
            v_get_flags(
                unsigned long int * const
                    r_flags) const;

        virtual
        enum appl_status
            v_set_flags(
                unsigned long int const
                    i_flags);

        enum appl_status
            f_decoder_pass_1(
                struct appl_buf * const
                    p_input_iterator);

        void
            f_decoder_pass_2(void);

        void
            f_detect_absolute_prefix(void);

        void
            f_detect_authority_prefix(void);

        void
            f_detect_authority_fields(void);

        void
            f_encoder_add_component(
                struct appl_url_component const * const
                    p_component,
                bool const
                    b_apply_percent,
                void (* const p_write_callback)(
                    void * const
                        p_write_context,
                    unsigned char const
                        c_data),
                void * const
                    p_write_context) const;

        void
            f_encoder_run(
                void (* const p_write_callback)(
                    void * const
                        p_write_context,
                    unsigned char const
                        c_data),
                void * const
                    p_write_context) const;

}; // class appl_url_std

/* end-of-file: appl_url_std.h */
