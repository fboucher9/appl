/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_object_handle.h"

#include "appl_mutex_handle.h"

#include "appl_mutex_service.h"

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

/*

*/
enum appl_status
appl_mutex_create(
    struct appl_context_handle * const
        p_context_handle,
    struct appl_mutex_descriptor const * const
        p_mutex_descriptor,
    struct appl_mutex_handle * * const
        r_mutex_handle)
{
    enum appl_status
        e_status;

    e_status =
        appl_mutex_service::thunk_create(
            p_context_handle,
            p_mutex_descriptor,
            r_mutex_handle);

    return
        e_status;

} /* appl_mutex_create() */

/*

*/
enum appl_status
appl_mutex_lock(
    struct appl_mutex_handle * const
        p_mutex_handle)
{
    enum appl_status
        e_status;

    e_status =
        appl_mutex_service::thunk_lock(
            p_mutex_handle);

    return
        e_status;

} /* appl_mutex_lock() */

/*

*/
enum appl_status
appl_mutex_unlock(
    struct appl_mutex_handle * const
        p_mutex_handle)
{
    enum appl_status
        e_status;

    e_status =
        appl_mutex_service::thunk_unlock(
            p_mutex_handle);

    return
        e_status;

} /* appl_mutex_unlock() */

/* end-of-file: appl_mutex_handle.cpp */
