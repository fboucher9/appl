/* See LICENSE for license details */

/*

*/

#if defined(INC_APPL_STATUS_H)
#error include appl_status.h once
#endif /* #if defined(INC_APPL_STATUS_H) */

#define INC_APPL_STATUS_H

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
    appl_status_out_of_memory = 3

}; /* enum appl_status */

/* end-of-file: appl_status.h */
