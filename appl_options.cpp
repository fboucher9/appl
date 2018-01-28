/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_object.h"

#include "appl_options.h"

enum appl_status
    appl_options::query(
        struct appl_options_descriptor * const
            p_options_descriptor)
{
    static_cast<void>(
        p_options_descriptor);
    return
        appl_status_not_implemented;
} // query()

appl_options::appl_options() :
    appl_object()
{
}

appl_options::~appl_options()
{
}

/* end-of-file: appl_options.cpp */
