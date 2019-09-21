/* See LICENSE for license details */

/*

*/

/* Predefine */
struct appl_context;

/* Predefine */
struct appl_http_decoder;

/*

*/
struct appl_http_decoder_descriptor
{
    enum appl_status
        (* p_callback_function)(
            void * const
                p_callback_context,
            int const
                i_section,
            unsigned char const * const
                p_buf_min,
            unsigned char const * const
                p_buf_max);

    void *
        p_callback_context;

}; /* struct appl_http_decoder_descriptor */

#include <appl_extern_c_begin.h>

enum appl_status
    appl_http_decoder_create(
        struct appl_context * const
            p_context,
        struct appl_http_decoder_descriptor const * const
            p_descriptor,
        struct appl_http_decoder * * const
            r_this);

enum appl_status
    appl_http_decoder_destroy(
        struct appl_http_decoder * const
            p_this);

enum appl_status
    appl_http_decoder_write(
        struct appl_http_decoder * const
            p_this,
        unsigned char const * const
            p_buf_min,
        unsigned char const * const
            p_buf_max);

#include <appl_extern_c_end.h>

/* end-of-file: appl_http_decoder.h */
