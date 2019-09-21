/* See LICENSE for license details */

/*

*/

#define INC_APPL_CHUNK_SERVICE_H

enum guard_appl_chunk_service_h
{
    inc_appl_chunk_service_h = 1
        + inc_appl_status_h
        + inc_appl_predefines_h
};

struct appl_chunk;

//
//
//
class appl_chunk_service
{
    public:

        static
        enum appl_status
        s_create(
            struct appl_context * const
                p_context,
            struct appl_chunk * * const
                r_chunk);

        static
        enum appl_status
        s_destroy(
            struct appl_chunk * const
                p_chunk);

        static
        enum appl_status
        s_write(
            struct appl_chunk * const
                p_chunk,
            unsigned char const * const
                p_buf_min,
            unsigned char const * const
                p_buf_max);

        static
        enum appl_status
        s_length(
            struct appl_chunk const * const
                p_chunk,
            unsigned long int * const
                r_length);

        static
        enum appl_status
        s_read(
            struct appl_chunk const * const
                p_chunk,
            unsigned char * const
                p_buf_min,
            unsigned char * const
                p_buf_max);

        static
        enum appl_status
        s_reset(
            struct appl_chunk * const
                p_chunk);

}; // class appl_chunk_service

/* end-of-file: appl_chunk_service.h */
