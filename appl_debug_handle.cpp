/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_debug_handle.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_context.h"

#include "appl_debug.h"

/*

*/
enum appl_status
appl_debug_break(
    struct appl_context_handle * const
        p_context_handle)
{
    enum appl_status
        e_status;

    class appl_context * const
        p_context =
        appl_context::convert_handle(
            p_context_handle);

    class appl_debug * const
        p_debug =
        p_context->m_debug;

    e_status =
        p_debug->break_to_debugger();

    return
        e_status;

} /* appl_debug_break() */

/* end-of-file: appl_debug_handle.cpp */
