/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_percent_h
{
    inc_appl_percent_h = 1
};

/* Included. */
#define INC_APPL_PERCENT_H

#include <appl_extern_c_begin.h>

void
    appl_percent_decoder_run(
        struct appl_buf * const
            p_input_iterator,
        void (* p_write_callback)(
            void * const
                p_write_context,
            unsigned char const
                c_data),
        void * const
            p_write_context);

unsigned long int
    appl_percent_decoder_length(
        struct appl_buf const * const
            p_input);

void
    appl_percent_decoder_convert(
        struct appl_buf * const
            p_input_iterator,
        struct appl_buf * const
            p_output_iterator);

void
    appl_percent_encoder_run(
        struct appl_buf * const
            p_input_iterator,
        struct appl_buf const * const
            p_filter,
        void (* p_write_callback)(
            void * const
                p_write_context,
            unsigned char const
                c_data),
        void * const
            p_write_context);

unsigned long int
    appl_percent_encoder_length(
        struct appl_buf const * const
            p_input,
        struct appl_buf const * const
            p_filter);

void
    appl_percent_encoder_convert(
        struct appl_buf * const
            p_input_iterator,
        struct appl_buf const * const
            p_filter,
        struct appl_buf * const
            p_output_iterator);

#include <appl_extern_c_end.h>

/* end-of-file: appl_percent.h */
