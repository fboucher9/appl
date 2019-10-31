/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_os_h
{
    inc_appl_os_h = 1
        /* Header file dependencies */
        /* ... */
}; /* enum guard_appl_os_h */

/*

*/
enum appl_os
{
    appl_os_linux = 1,

    appl_os_windows = 2

}; /* enum appl_os */

#include <misc/appl_extern_c_begin.h>

enum appl_os
appl_os_get(void);

#include <misc/appl_extern_c_end.h>

/* end-of-file: appl_os.h */
