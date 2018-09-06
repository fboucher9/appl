/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_pool_mgr.h>

#include <appl_unused.h>

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
enum appl_status
    appl_pool_mgr::v_create_node(
        appl_size_t const
            i_buf_len,
        struct appl_pool * * const
            r_pool_node)
{
    enum appl_status
        e_status;

    appl_unused(
        i_buf_len,
        r_pool_node);

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} // v_create_node()

//
//
//
appl_pool_mgr::appl_pool_mgr()
{
}

//
//
//
appl_pool_mgr::~appl_pool_mgr()
{
}

