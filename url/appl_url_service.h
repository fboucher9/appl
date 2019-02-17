/* See LICENSE for license details */

/*

*/

/* Included. */
#define INC_APPL_URL_SERVICE_H

/* Predefine */
struct appl_context;

/* Predefine */
struct appl_url;

//
//
//
class appl_url_service
{
    public:

        static
        enum appl_status
            s_create(
                struct appl_context * const
                    p_context,
                struct appl_url * * const
                    r_url);

        static
        enum appl_status
            s_destroy(
                struct appl_url * const
                    p_url);

        static
        enum appl_status
            s_decoder(
                struct appl_url * const
                    p_url,
                unsigned char const * const
                    p_input_min,
                unsigned char const * const
                    p_input_max,
                unsigned long int * const
                    r_input_count);

        static
        enum appl_status
            s_encoder(
                struct appl_url const * const
                    p_url,
                unsigned char * const
                    p_output_min,
                unsigned char * const
                    p_output_max,
                unsigned long int * const
                    r_output_count);

        static
        enum appl_status
            s_add_component(
                struct appl_url * const
                    p_url,
                signed short int const
                    e_component_type,
                unsigned char const * const
                    p_buf_min,
                unsigned char const * const
                    p_buf_max,
                struct appl_url_component * * const
                    r_handle);

        static
        enum appl_status
            s_remove_component(
                struct appl_url * const
                    p_url,
                signed short int const
                    e_component_type,
                struct appl_url_component * const
                    p_handle);

        static
        enum appl_status
            s_get_component(
                struct appl_url const * const
                    p_url,
                signed short int const
                    e_component_type,
                unsigned char const * * const
                    r_buf_min,
                unsigned char const * * const
                    r_buf_max,
                struct appl_url_component * * const
                    r_handle);

        static
        enum appl_status
            s_next_component(
                struct appl_url const * const
                    p_url,
                signed short int const
                    e_component_type,
                unsigned char const * * const
                    r_buf_min,
                unsigned char const * * const
                    r_buf_max,
                struct appl_url_component * * const
                    r_handle);

        static
        enum appl_status
            s_get_flags(
                struct appl_url const * const
                    p_url,
                unsigned long int * const
                    r_flags);

        static
        enum appl_status
            s_set_flags(
                struct appl_url * const
                    p_url,
                unsigned long int const
                    i_flags);

}; // class appl_url_service

