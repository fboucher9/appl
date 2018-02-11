/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined(INC_APPL_BUF_H)
#error include appl_buf.h once
#endif /* #if defined(INC_APPL_BUF_H) */

#define INC_APPL_BUF_H

/* Predefine appl_buf handle */
struct appl_buf;

/* ptr */
union appl_ptr
{
    void *
        p_void;

    void const *
        pc_void;

    unsigned char *
        p_uchar;

    unsigned char const *
        pc_uchar;

    struct appl_buf *
        p_buf;

    struct appl_buf const *
        pc_buf;

}; /* union appl_ptr */

/* buf */
struct appl_buf
{
    union appl_ptr
        o_min;

    union appl_ptr
        o_max;

}; /* struct appl_buf */

#if defined(__cplusplus)
extern "C" {
#endif /* #if defined(__cplusplus) */

/* buf read iteration */
enum appl_status
appl_buf_read(
    struct appl_buf * const
        p_buf,
    unsigned char * const
        p_value);

enum appl_status
appl_buf_read_tail(
    struct appl_buf * const
        p_buf,
    unsigned char * const
        p_value);

/* buf write iteration */
enum appl_status
appl_buf_write(
    struct appl_buf * const
        p_buf,
    unsigned char const
        c_value);

/* buf write backward iteration */
enum appl_status
appl_buf_write_tail(
    struct appl_buf * const
        p_buf,
    unsigned char const
        c_value);

/* buf repeat write */
enum appl_status
appl_buf_write_repeat(
    struct appl_buf * const
        p_buf,
    unsigned char const
        c_value,
    unsigned long int const
        i_count);

/* buf repeat write backward */
enum appl_status
appl_buf_write_tail_repeat(
    struct appl_buf * const
        p_buf,
    unsigned char const
        c_value,
    unsigned long int const
        i_count);

/* buf fill */
enum appl_status
appl_buf_fill(
    struct appl_buf * const
        p_buf,
    unsigned char const
        c_value);

/* buf copy */
enum appl_status
appl_buf_copy(
    struct appl_buf * const
        p_buf_destination,
    struct appl_buf const * const
        p_buf_source,
    unsigned long int * const
        p_count);

/* buf compare */
enum appl_status
appl_buf_compare(
    struct appl_buf const * const
        p_buf_left,
    struct appl_buf const * const
        p_buf_right,
    signed int * const
        p_result);

/* buf compare */
enum appl_status
appl_buf_case_compare(
    struct appl_buf const * const
        p_buf_left,
    struct appl_buf const * const
        p_buf_right,
    signed int * const
        p_result);

/* buf case compare */

/* fill width using spaces */
#define APPL_BUF_PRINT_PAD_SPACE 0x00000000ul

/* fill width using zeros, else use space */
#define APPL_BUF_PRINT_PAD_ZERO 0x00010000ul

/* display plus sign for positive */
#define APPL_BUF_PRINT_SIGN_PLUS 0x00020000ul

/* treat number as signed */
#define APPL_BUF_PRINT_SIGNED 0x00000000ul

/* treat number as unsigned, always positive */
#define APPL_BUF_PRINT_UNSIGNED 0x00040000ul

/* align to right (default) */
#define APPL_BUF_PRINT_ALIGN_RIGHT 0x00000000ul

/* align to left, fill with spaces */
#define APPL_BUF_PRINT_ALIGN_LEFT 0x00080000ul

/* display space for positive */
#define APPL_BUF_PRINT_SIGN_SPACE 0x00100000ul

/* base decimal (default) */
#define APPL_BUF_PRINT_DECIMAL 0x00000000ul

/* base binary */
#define APPL_BUF_PRINT_BINARY 0x00200000ul

/* base octal */
#define APPL_BUF_PRINT_OCTAL 0x00400000ul

/* base hexadecimal */
#define APPL_BUF_PRINT_HEXADECIMAL 0x00800000ul

/* width of number field in low-order bits of flags */
#define APPL_BUF_PRINT_WIDTH_MASK 0x0000FFFFul

/* buf print number using flags */
enum appl_status
appl_buf_print_number(
    struct appl_buf * const
        p_buf,
    signed long int const
        i_value,
    unsigned long int const
        i_flags);

#if defined(__cplusplus)
} /* extern "C" */
#endif /* #if defined(__cplusplus) */

/* end-of-file: appl_buf.h */
