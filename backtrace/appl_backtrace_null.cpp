/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <backtrace/appl_backtrace.h>

#include <backtrace/appl_backtrace_null.h>

//
//
//
appl_backtrace_null::appl_backtrace_null(
    struct appl_context * const
        p_context) :
    appl_backtrace(
        p_context)
{
}

//
//
//
appl_backtrace_null::~appl_backtrace_null()
{
}

/* end-of-file: appl_backtrace_null.cpp */
