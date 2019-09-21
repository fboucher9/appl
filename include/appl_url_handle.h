/* See LICENSE for license details */

/*

*/

/* Included. */
#define INC_APPL_URL_HANDLE_H

/* Predefine */
struct appl_url;

/* Predefine */
struct appl_url_component;

#include <appl_extern_c_begin.h>

enum appl_status
    appl_url_create(
        struct appl_context * const
            p_context,
        struct appl_url * * const
            r_url);

enum appl_status
    appl_url_destroy(
        struct appl_url * const
            p_url);

enum appl_status
    appl_url_decoder(
        struct appl_url * const
            p_url,
        unsigned char const * const
            p_input_min,
        unsigned char const * const
            p_input_max,
        unsigned long int * const
            r_input_count);

enum appl_status
    appl_url_encoder_length(
        struct appl_url const * const
            p_url,
        unsigned long int * const
            r_output_count);

enum appl_status
    appl_url_encoder(
        struct appl_url const * const
            p_url,
        unsigned char * const
            p_output_min,
        unsigned char * const
            p_output_max,
        unsigned long int * const
            r_output_count);

enum appl_status
    appl_url_add_component(
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

enum appl_status
    appl_url_remove_component(
        struct appl_url * const
            p_url,
        signed short int const
            e_component_type,
        struct appl_url_component * const
            p_handle);

enum appl_status
    appl_url_get_component(
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

enum appl_status
    appl_url_next_component(
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

enum appl_status
    appl_url_get_flags(
        struct appl_url const * const
            p_url,
        unsigned long int * const
            r_flags);

enum appl_status
    appl_url_set_flags(
        struct appl_url * const
            p_url,
        unsigned long int const
            i_flags);

#include <appl_extern_c_end.h>

/* end-of-file: appl_url.h */
