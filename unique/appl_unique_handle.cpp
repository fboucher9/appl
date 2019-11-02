/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_predefines.h>

#include <unique/appl_unique_handle.h>

#include <unique/appl_unique_service.h>

//
//
//
enum appl_status
appl_unique_pick(
    struct appl_context * const
        p_context,
    unsigned long int * const
        r_unique)
{
    return
        appl_unique_service::s_pick(
            p_context,
            r_unique);

} // appl_unique_pick()

/* end-of-file: appl_unique_handle.cpp */
