/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <library/appl_library_node.h>

#include <misc/appl_unused.h>

#if defined APPL_DEBUG
#include <debug/appl_debug_handle.h>
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
    return
        appl_raise_not_implemented();
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
