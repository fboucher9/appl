/* See LICENSE for license details */

#include <misc/appl_os.h>

static
enum appl_os
const
g_appl_os =
#if defined APPL_OS_LINUX
appl_os_linux
#else /* #if defined APPL_OS_LINUX */
appl_os_windows
#endif /* #if defined APPL_OS_LINUX */
;

//
//
//
enum appl_os
appl_os_get(void)
{
    return
        g_appl_os;

} // appl_os_get()

//
//
//
char
appl_os_test(
    enum appl_os const
        e_os_value)
{
    return
        (
            g_appl_os
            == e_os_value);

} // appl_os_test()

/* end-of-file: appl_os.cpp */
