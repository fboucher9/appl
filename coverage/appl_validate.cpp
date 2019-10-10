/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <coverage/appl_validate.h>

#if defined APPL_HAVE_COVERAGE
#include <coverage/appl_coverage.h>
#endif /* #if defined APPL_HAVE_COVERAGE */

#if defined APPL_DEBUG
#include <debug/appl_debug_impl.h>
#endif /* #if defined APPL_DEBUG */

/*

*/
enum appl_status
appl_validate(
    char const
        b_condition)
{
    enum appl_status
        e_status;

#if defined APPL_HAVE_COVERAGE
    if (appl_coverage_check())
    {
        e_status =
            appl_status_fault_injection;
    }
    else
#endif /* #if defined APPL_HAVE_COVERAGE */
    {
        if (
            b_condition)
        {
            e_status =
                appl_status_ok;
        }
        else
        {
            e_status =
                appl_raise_invalid_param();
        }
    }

    return
        e_status;

} /* appl_validate() */

/* end-of-file: appl_validate.cpp */
