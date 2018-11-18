/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_buf0_h
{
    inc_appl_buf0_h =
        /* Header file dependencies */
        inc_appl_status_h
};

struct appl_context;

#if defined __cplusplus
extern "C" {
#endif /* #if defined __cplusplus */

enum appl_status
appl_buf0_create(
    struct appl_context const * const
        p_context,
    unsigned char const * const
        p_buf_min,
    unsigned char const * const
        p_buf_max,
    unsigned char * * const
        r_buf0);

enum appl_status
appl_buf0_destroy(
    struct appl_context const * const
        p_context,
    unsigned char * const
        p_buf0);

/* buf length */
unsigned long int
appl_buf0_len(
    unsigned char const * const
        p_buf_0);

#if defined __cplusplus
} /* extern "C" */
#endif /* #if defined __cplusplus */

/* end-of-file: appl_buf0.h */
