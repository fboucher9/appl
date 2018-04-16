/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_MAIN_H
#error include appl_main.h once
#endif /* #if defined INC_APPL_MAIN_H */

#define INC_APPL_MAIN_H

/* Header file dependency */
#if ! defined INC_APPL_STATUS_H
#error include appl_status.h before
#endif /* #if ! defined INC_APPL_STATUS_H */

struct appl_context;

#if defined(__cplusplus)
extern "C" {
#endif /* #if defined(__cplusplus) */

/* extern */
enum appl_status
appl_main(
    struct appl_context * const
        p_context);

#if defined(__cplusplus)
} /* extern "C" */
#endif /* #if defined(__cplusplus) */

/* end-of-file: appl_main.h */
