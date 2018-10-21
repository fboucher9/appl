/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_pool_object.h>

#include <appl_pool.h>

//
//
//
enum appl_status
    appl_pool_object::destroy(void)
{
    enum appl_status
        e_status;

    e_status =
        v_cleanup();

    if (
        appl_status_ok
        == e_status)
    {
        struct appl_pool * const
            p_pool =
            m_pool;

        void * const
            p_placement =
            this;

        delete
            this;

        p_pool->v_free(
            p_placement);
    }

    return
        e_status;

} // destroy()

//
//
//
struct appl_pool *
    appl_pool_object::get_pool(void) const
{
    return
        m_pool;

} // get_pool()

//
//
//
enum appl_status
    appl_pool_object::f_init(
        struct appl_pool_object_descriptor const * const
            p_pool_object_descriptor)
{
    enum appl_status
        e_status;

    m_pool =
        p_pool_object_descriptor->p_pool;

    e_status =
        appl_status_ok;

    return
        e_status;

} // f_init()

//
//
//
appl_pool_object::appl_pool_object() :
    appl_object(),
    m_pool()
{
}

//
//
//
appl_pool_object::~appl_pool_object()
{
}

/* end-of-file: appl_pool_object.cpp */
