/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_buf_h
{
    inc_appl_buf_h =
        1
};

/* ptr */
union appl_buf_ptr
{
    void const *
        pc_void;

    void *
        p_void;

    char const *
        pc_char;

    char *
        p_char;

    unsigned char const *
        pc_uchar;

    unsigned char *
        p_uchar;

    struct appl_buf const *
        pc_buf;

    struct appl_buf *
        p_buf;

}; /* union appl_buf_ptr */

/* buf */
struct appl_buf
{
    union appl_buf_ptr
        o_min;

    union appl_buf_ptr
        o_max;

}; /* struct appl_buf */

#include <misc/appl_extern_c_begin.h>

#if 0
/* buf read iteration */
enum appl_status
appl_buf_read(
    struct appl_buf * const
        p_buf,
    unsigned char * const
        p_value);
#endif

#if 0
enum appl_status
appl_buf_read_tail(
    struct appl_buf * const
        p_buf,
    unsigned char * const
        p_value);
#endif

/* buf length */
unsigned long int
appl_buf_len(
    unsigned char const * const
        p_buf_min,
    unsigned char const * const
        p_buf_max);

/* buf write iteration */
unsigned char *
appl_buf_write(
    unsigned char * const
        p_buf_cur,
    unsigned char * const
        p_buf_max,
    unsigned char const
        c_value);

#if 0
/* buf write backward iteration */
unsigned char *
appl_buf_write_tail(
    unsigned char * const
        p_buf_min,
    unsigned char * const
        p_buf_cur,
    unsigned char const
        c_value);
#endif

#if 0
/* buf repeat write */
unsigned char *
appl_buf_write_repeat(
    unsigned char * const
        p_buf_cur,
    unsigned char * const
        p_buf_max,
    unsigned char const
        c_value,
    unsigned long int const
        i_count);
#endif

#if 0
/* buf repeat write backward */
unsigned char *
appl_buf_write_tail_repeat(
    unsigned char * const
        p_buf_min,
    unsigned char * const
        p_buf_cur,
    unsigned char const
        c_value,
    unsigned long int const
        i_count);
#endif

#if 0
unsigned char *
appl_buf_write_array(
    unsigned char * const
        p_buf_cur,
    unsigned char * const
        p_buf_max,
    unsigned char const * const
        p_ref_min,
    unsigned char const * const
        p_ref_max);
#endif

#if 0
unsigned char *
appl_buf_write_tail_array(
    unsigned char * const
        p_buf_min,
    unsigned char * const
        p_buf_cur,
    unsigned char const * const
        p_ref_min,
    unsigned char const * const
        p_ref_max);
#endif

/* buf zero */
unsigned char *
appl_buf_zero(
    unsigned char * const
        p_buf_min,
    unsigned char * const
        p_buf_max);

/* buf fill */
unsigned char *
appl_buf_fill(
    unsigned char * const
        p_buf_min,
    unsigned char * const
        p_buf_max,
    unsigned char const
        c_value);

/* buf copy */
unsigned char *
appl_buf_copy(
    unsigned char * const
        p_dst_min,
    unsigned char * const
        p_dst_max,
    unsigned char const * const
        p_src_min,
    unsigned char const * const
        p_src_max);

/* buf compare */
signed int
appl_buf_compare(
    unsigned char const * const
        p_left_min,
    unsigned char const * const
        p_left_max,
    unsigned char const * const
        p_right_min,
    unsigned char const * const
        p_right_max);

/* find minimum value */
unsigned char
appl_buf_min_value(
    unsigned char const * const
        p_buf_min,
    unsigned char const * const
        p_buf_max);

/* find maximum value */
unsigned char
appl_buf_max_value(
    unsigned char const * const
        p_buf_min,
    unsigned char const * const
        p_buf_max);

#if 0
/* buf compare */
signed int
appl_buf_case_compare(
    struct appl_buf const * const
        p_buf_left,
    struct appl_buf const * const
        p_buf_right);
#endif

/* buf case compare */

enum appl_buf_print_flag
{
    /* fill width using zeros, else use space */
    appl_buf_print_flag_zero = 1,

    /* display plus sign for positive */
    appl_buf_print_flag_plus = 2,

    /* treat number as unsigned, always positive */
    appl_buf_print_flag_unsigned = 4,

    /* align to left, fill with spaces */
    appl_buf_print_flag_left = 8,

    /* display space for positive */
    appl_buf_print_flag_space = 16,

    /* base binary */
    appl_buf_print_flag_binary = 32,

    /* base octal */
    appl_buf_print_flag_octal = 64,

    /* base hexadecimal */
    appl_buf_print_flag_hex = 128

}; /* enum appl_buf_print_flag */

/* buf print number using flags */
unsigned char *
appl_buf_print_number(
    unsigned char * const
        p_buf_cur,
    unsigned char * const
        p_buf_max,
    signed long int const
        i_value,
    int const
        i_flags,
    unsigned int const
        i_width);

enum appl_buf_scan_flag
{
    /* treat number as unsigned, always positive */
    appl_buf_scan_flag_unsigned = 4,

    /* base binary */
    appl_buf_scan_flag_binary = 32,

    /* base octal */
    appl_buf_scan_flag_octal = 64,

    /* base hexadecimal */
    appl_buf_scan_flag_hex = 128

}; /* enum appl_buf_scan_flag */

unsigned char const *
appl_buf_scan_number(
    unsigned char const * const
        p_buf_min,
    unsigned char const * const
        p_buf_max,
    signed long int * const
        p_value,
    int const
        i_flags);

#include <misc/appl_extern_c_end.h>

/* end-of-file: appl_buf.h */
