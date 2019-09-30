/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_predefines.h>

#include <dir/appl_dir_handle.h>

#include <dir/appl_dir_service.h>

//
//
//
enum appl_status
    appl_dir_enumerate(
        struct appl_context * const
            p_context,
        struct appl_dir_descriptor const * const
            p_descriptor)
{
    return
        appl_dir_service::s_enumerate(
            p_context,
            p_descriptor);

} // appl_dir_enumerate()

/* end-of-file: appl_dir_handle.cpp */
