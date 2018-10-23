/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_library_node.h>

#include <appl_unused.h>

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
        appl_status_not_implemented;
}

//
//
//
appl_library::appl_library() :
    appl_object()
{
}

//
//
//
appl_library::~appl_library()
{
}

/* end-of-file: appl_library_node.cpp */
