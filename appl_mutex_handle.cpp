/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_object_handle.h"

#include "appl_mutex_handle.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_context.h"

#include "appl_mutex_mgr.h"

#include "appl_mutex_node.h"

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
class appl_mutex_service
{
    public:

        static
        enum appl_status
            thunk_create(
                struct appl_context_handle * const
                    p_context_handle,
                struct appl_mutex_descriptor const * const
                    p_mutex_descriptor,
                struct appl_mutex_handle * * const
                    r_mutex_handle);

        static
        enum appl_status
            thunk_lock(
                struct appl_mutex_handle * const
                    p_mutex_handle);

        static
        enum appl_status
            thunk_unlock(
                struct appl_mutex_handle * const
                    p_mutex_handle);

}; // class appl_mutex_service

//
//
//
enum appl_status
    appl_mutex_service::thunk_create(
        struct appl_context_handle * const
            p_context_handle,
        struct appl_mutex_descriptor const * const
            p_mutex_descriptor,
        struct appl_mutex_handle * * const
            r_mutex_handle)
{
    enum appl_status
        e_status;

    class appl_context * const
        p_context =
        appl_context::convert_handle(
            p_context_handle);

    class appl_mutex_mgr * const
        p_mutex_mgr =
        p_context->m_mutex_mgr;

    e_status =
        p_mutex_mgr->v_create(
            p_mutex_descriptor,
            reinterpret_cast<class appl_mutex_node * *>(
                r_mutex_handle));

    return
        e_status;

} // thunk_create()

//
//
//
enum appl_status
    appl_mutex_service::thunk_lock(
        struct appl_mutex_handle * const
            p_mutex_handle)
{
    enum appl_status
        e_status;

    class appl_mutex_node * const
        p_mutex_node =
        appl_mutex_node::convert_handle(
            p_mutex_handle);

    e_status =
        p_mutex_node->v_lock();

    return
        e_status;

} // thunk_lock()

//
//
//
enum appl_status
    appl_mutex_service::thunk_unlock(
        struct appl_mutex_handle * const
            p_mutex_handle)
{
    enum appl_status
        e_status;

    class appl_mutex_node * const
        p_mutex_node =
        appl_mutex_node::convert_handle(
            p_mutex_handle);

    e_status =
        p_mutex_node->v_unlock();

    return
        e_status;

} // thunk_unlock()

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
