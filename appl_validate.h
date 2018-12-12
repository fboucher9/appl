/* See LICENSE for license details */

/*

*/

/* Included. */
#define INC_APPL_VALIDATION_H

/* Reverse include guard */
enum guard_appl_validation_h
{
    inc_appl_validation_h = 1
        /* Header file dependencies */
        + inc_appl_status_h
};

#if defined __cplusplus
extern "C" {
#endif /* #if defined __cplusplus */

enum appl_status
appl_validate(
    char const
        b_condition);

#if defined __cplusplus
} /* extern "C" */
#endif /* #if defined __cplusplus */

/* end-of-file: appl_validate.h */
