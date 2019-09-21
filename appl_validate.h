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

#include <appl_extern_c_begin.h>

enum appl_status
appl_validate(
    char const
        b_condition);

#include <appl_extern_c_end.h>

/* end-of-file: appl_validate.h */
