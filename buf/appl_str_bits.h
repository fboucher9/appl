/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_str_bits_h
{
    inc_appl_str_bits_h = 1
        /* Header file dependencies */
        + inc_appl_status_h
        + inc_appl_buf_h
        /* ... */

}; /* enum guard_appl_str_bits_h */

/*

*/
struct appl_str_bits_descriptor
{
    struct appl_buf
        o_buf;

}; /* struct appl_str_bits_descriptor */

#if defined __cplusplus
extern "C" {
#endif /* #if defined __cplusplus */

enum appl_status
    appl_str_bits_create(
        struct appl_context * const
            p_context,
        struct appl_str_bits_descriptor const * const
            p_descriptor,
        struct appl_bits * * const
            r_instance);

#if defined __cplusplus
} /* extern "C" */
#endif /* #if defined __cplusplus */

/* end-of-file: appl_str_bits.h */
