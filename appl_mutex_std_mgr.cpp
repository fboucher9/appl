/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_mutex_mgr.h>

#include <appl_mutex_std_mgr.h>

#include <appl_context.h>

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
enum appl_status
    appl_mutex_std_mgr::s_create(
        struct appl_object * const
            p_context,
        class appl_mutex_mgr * * const
            r_mutex_mgr)
{
    enum appl_status
        e_status;

    class appl_mutex_std_mgr *
        p_mutex_std_mgr;

    e_status =
        p_context->alloc_object(
            &(
                p_mutex_std_mgr));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_mutex_mgr) =
            p_mutex_std_mgr;
    }

    return
        e_status;

} // s_create()

//
//
//
appl_mutex_std_mgr::appl_mutex_std_mgr() :
    appl_mutex_mgr()
{
}

//
//
//
appl_mutex_std_mgr::~appl_mutex_std_mgr()
{
}

//
//
//
void
    appl_mutex_std_mgr::s_new(
        void * const
            p_placement)
{
    new (p_placement)
        class appl_mutex_std_mgr;

} // s_new()

enum appl_status
appl_mutex_std_node_create(
    struct appl_object * const
        p_context,
    struct appl_mutex_descriptor const * const
        p_mutex_descriptor,
    struct appl_mutex * * const
        r_mutex);

//
//
//
enum appl_status
    appl_mutex_std_mgr::v_create(
        struct appl_mutex_descriptor const * const
            p_mutex_descriptor,
        struct appl_mutex * * const
            r_mutex)
{
    enum appl_status
        e_status;

    e_status =
        appl_mutex_std_node_create(
            m_context,
            p_mutex_descriptor,
            r_mutex);

    return
        e_status;

} // v_create()

/* end-of-file: appl_mutex_std_mgr.cpp */
