/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_heap_object.h>

#include <appl_pool_object.h>

#include <appl_pool.h>

//
//
//
enum appl_status
    appl_pool_object::v_destroy(void)
{
    enum appl_status
        e_status;

    struct appl_pool * const
        p_pool =
        m_pool;

    void * const
        p_placement =
        this;

    e_status =
        v_cleanup();

    if (
        appl_status_ok
        == e_status)
    {
        delete
            this;

        p_pool->v_free(
            p_placement);
    }

    return
        e_status;

} // v_destroy()

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
void
    appl_pool_object::set_pool(
        struct appl_pool * const
            p_pool)
{
    m_pool =
        p_pool;

} // set_pool()

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
