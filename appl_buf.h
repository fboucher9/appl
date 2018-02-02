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

/* buf write iteration */
enum appl_status
appl_buf_write(
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

#if defined(__cplusplus)
} /* extern "C" */
#endif /* #if defined(__cplusplus) */

/* end-of-file: appl_buf.h */
