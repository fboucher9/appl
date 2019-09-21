/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_bytes_handle_h
{
    inc_appl_bytes_handle_h = 1
        /* Header file dependencies */
        + inc_appl_status_h
        + inc_appl_types_h
        + inc_appl_predefines_h
        /* ... */
}; /* enum guard_appl_bytes_handle_h */

/* Predefine handle */
struct appl_bytes;

/* Predefine descriptor */
struct appl_bytes_descriptor;

#include <appl_extern_c_begin.h>

enum appl_status
    appl_bytes_create(
        struct appl_context * const
            p_context,
        struct appl_bytes_descriptor const * const
            p_descriptor,
        struct appl_bytes * * const
            r_instance);

enum appl_status
    appl_bytes_destroy(
        struct appl_bytes * const
            p_bytes);

enum appl_status
    appl_bytes_write_raw(
        struct appl_bytes * const
            p_bytes,
        struct appl_buf const * const
            p_buf);

enum appl_status
    appl_bytes_write_int(
        struct appl_bytes * const
            p_bytes,
        unsigned char const
            i_count,
        appl_ull_t const
            i_value);

enum appl_status
    appl_bytes_write_int8(
        struct appl_bytes * const
            p_bytes,
        unsigned char const
            i_value);

enum appl_status
    appl_bytes_write_int16(
        struct appl_bytes * const
            p_bytes,
        unsigned short int const
            i_value);

enum appl_status
    appl_bytes_write_int24(
        struct appl_bytes * const
            p_bytes,
        unsigned long int const
            i_value);

enum appl_status
    appl_bytes_write_int32(
        struct appl_bytes * const
            p_bytes,
        unsigned long int const
            i_value);

enum appl_status
    appl_bytes_write_int64(
        struct appl_bytes * const
            p_bytes,
        appl_ull_t const
            i_value);

enum appl_status
    appl_bytes_read_raw(
        struct appl_bytes * const
            p_bytes,
        struct appl_buf const * const
            p_buf);

enum appl_status
    appl_bytes_read_int(
        struct appl_bytes * const
            p_bytes,
        unsigned char const
            i_count,
        appl_ull_t * const
            r_value);

enum appl_status
    appl_bytes_read_int8(
        struct appl_bytes * const
            p_bytes,
        unsigned char * const
            r_value);

enum appl_status
    appl_bytes_read_int16(
        struct appl_bytes * const
            p_bytes,
        unsigned short int * const
            r_value);

enum appl_status
    appl_bytes_read_int24(
        struct appl_bytes * const
            p_bytes,
        unsigned long int * const
            r_value);

enum appl_status
    appl_bytes_read_int32(
        struct appl_bytes * const
            p_bytes,
        unsigned long int * const
            r_value);

enum appl_status
    appl_bytes_read_int64(
        struct appl_bytes * const
            p_bytes,
        appl_ull_t * const
            r_value);

#include <appl_extern_c_end.h>

/* end-of-file: appl_bytes_handle.h */
