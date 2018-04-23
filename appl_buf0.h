/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_BUF0_H
#error include appl_buf0.h once
#endif /* #if defined INC_APPL_BUF0_H */

#define INC_APPL_BUF0_H

struct appl_object;

#if defined __cplusplus
extern "C" {
#endif /* #if defined __cplusplus */

enum appl_status
appl_buf0_create(
    struct appl_object const * const
        p_object,
    unsigned char const * const
        p_buf_min,
    unsigned char const * const
        p_buf_max,
    unsigned char * * const
        r_buf0);

enum appl_status
appl_buf0_destroy(
    struct appl_object const * const
        p_object,
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
