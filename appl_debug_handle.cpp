/* See LICENSE for license details */

/*

*/

#if defined APPL_DEBUG

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
        p_debug->v_break();

    return
        e_status;

} /* appl_debug_break() */

/*

*/
enum appl_status
appl_debug_print(
    struct appl_context_handle * const
        p_context_handle,
    struct appl_buf const * const
        p_buf)
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
        p_debug->v_print(
            p_buf);

    return
        e_status;

} /* appl_debug_print() */

#endif /* #if defined APPL_DEBUG */

/* end-of-file: appl_debug_handle.cpp */
