/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_thread_mgr.h"

#if !defined(__cplusplus)
#error use C++ compiler
#endif /* #if !defined(__cplusplus) */

enum appl_status
    appl_thread_mgr::v_create(
        class appl_context * const
            p_context,
        struct appl_thread_descriptor const * const
            p_thread_descriptor,
        class appl_thread_node * * const
            r_thread_node)
{
    static_cast<void>(
        p_context);
    static_cast<void>(
        p_thread_descriptor);
    static_cast<void>(
        r_thread_node);
    return
        appl_status_fail;
}

appl_thread_mgr::appl_thread_mgr() :
    appl_object()
{
}

appl_thread_mgr::~appl_thread_mgr()
{
}

/* end-of-file: appl_thread_mgr.cpp */
