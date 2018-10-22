/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_object_handle.h>

#include <appl_mutex_handle.h>

#include <appl_mutex_service.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_pool_object.h>

#include <appl_mutex_node.h>

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

/*

*/
enum appl_status
appl_mutex_create(
    struct appl_context * const
        p_context,
    struct appl_mutex_descriptor const * const
        p_mutex_descriptor,
    struct appl_mutex * * const
        r_mutex)
{
    enum appl_status
        e_status;

    e_status =
        appl_mutex_service::s_create(
            p_context,
            p_mutex_descriptor,
            r_mutex);

    return
        e_status;

} /* appl_mutex_create() */

struct appl_object *
appl_mutex_parent(
    struct appl_mutex * const
        p_mutex)
{
    return
        p_mutex;

}

struct appl_object const *
appl_mutex_const_parent(
    struct appl_mutex const * const
        p_mutex)
{
    return
        p_mutex;

}

/*

*/
enum appl_status
appl_mutex_lock(
    struct appl_mutex * const
        p_mutex)
{
    enum appl_status
        e_status;

    e_status =
        appl_mutex_service::s_lock(
            p_mutex);

    return
        e_status;

} /* appl_mutex_lock() */

/*

*/
enum appl_status
appl_mutex_unlock(
    struct appl_mutex * const
        p_mutex)
{
    enum appl_status
        e_status;

    e_status =
        appl_mutex_service::s_unlock(
            p_mutex);

    return
        e_status;

} /* appl_mutex_unlock() */

/* end-of-file: appl_mutex_handle.cpp */
