/* See LICENSE for license details */

/*

*/

/* Included. */
#define INC_APPL_STATUS_H

/* Reverse include guard */
enum guard_appl_status_h
{
    inc_appl_status_h =
        /* Header file dependencies */
        1
};

/*

Enumeration: appl_status

Description:

    status codes for each appl function.

*/
enum appl_status
{
    /* Generic success */
    appl_status_ok = 1,

    /* Generic failure */
    appl_status_fail = 2,

    /* Out of memory (fatal error) */
    appl_status_out_of_memory = 3,

    /* Function not implemented */
    appl_status_not_implemented = 4,

    /* Timeout occured */
    appl_status_timeout = 5

}; /* enum appl_status */

/* end-of-file: appl_status.h */
