/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <library/appl_library_node.h>

#include <appl_unused.h>

#if defined APPL_DEBUG
#include <appl_debug_handle.h>
#endif /* #if defined APPL_DEBUG */

//
//
//
enum appl_status
    appl_library::v_query(
        unsigned char const * const
            p_symbol_name_min,
        unsigned char const * const
            p_symbol_name_max,
        void * * const
            r_symbol) const
{
    appl_unused(
        p_symbol_name_min,
        p_symbol_name_max,
        r_symbol);
#if defined APPL_DEBUG
    {
        static unsigned char const s_msg[] =
            "library query not implemented\n";
        appl_debug_print0(
            m_context,
            s_msg);
    }
#endif /* #if defined APPL_DEBUG */

    return
        appl_status_not_implemented;
}

//
//
//
appl_library::appl_library(
    struct appl_context * const
        p_context) :
    appl_object(
        p_context)
{
}

//
//
//
appl_library::~appl_library()
{
}

/* end-of-file: appl_library_node.cpp */
