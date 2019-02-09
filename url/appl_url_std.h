/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_url_std_h
{
    inc_appl_url_std_h = 1
        /* Header file dependencies */
        + inc_appl_url_h
}; /* enum guard_appl_url_std_h */

/* Included. */
#define INC_APPL_URL_STD_H

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

        appl_url_std(
            class appl_url_std const & r);

        class appl_url_std &
            operator =(
                class appl_url_std const & r);

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
                void * * const
                    r_handle);

        virtual
        enum appl_status
            v_remove_component(
                signed short int const
                    e_component_type,
                void * const
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
                void * * const
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
                void * * const
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

}; // class appl_url_std

/* end-of-file: appl_url_std.h */
