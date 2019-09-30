/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_predefines.h>

#include <dir/appl_dir_service.h>

#include <appl_unused.h>

//
//
//
enum appl_status
    appl_dir_service::s_enumerate(
        struct appl_context * const
            p_context,
        struct appl_dir_descriptor const * const
            p_descriptor)
{
    appl_unused(
        p_context,
        p_descriptor);

    return
        appl_raise_not_implemented();

} // s_enumerate()

/* end-of-file: appl_dir_service.cpp */
