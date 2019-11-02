/* See LICENSE for license details */

/*

*/

#include <pthread.h>

#include <appl_status.h>

#include <appl_predefines.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <unique/appl_unique_mgr.h>

#include <mutex/appl_mutex_impl.h>

#include <unique/appl_unique_std_mgr.h>

//
//
//
appl_unique_std_mgr::appl_unique_std_mgr(
    struct appl_context * const
        p_context) :
    appl_unique_mgr(
        p_context),
    m_lock(),
    m_counter()
{
}

//
//
//
appl_unique_std_mgr::~appl_unique_std_mgr()
{
}

//
//
//
enum appl_status
    appl_unique_std_mgr::f_init(void)
{
    m_lock.f_init();

    m_counter =
        0ul;

    return
        appl_status_ok;

} // f_init()

//
//
//
appl_size_t
    appl_unique_std_mgr::v_cleanup(void)
{
    m_lock.f_cleanup();

    return
        sizeof(
            class appl_unique_std_mgr);

} // v_cleanup()

//
//
//
enum appl_status
    appl_unique_std_mgr::v_pick(
        unsigned long int * const
            r_unique)
{
    enum appl_status
        e_status;

    e_status =
        m_lock.f_lock();

    if (
        appl_status_ok
        == e_status)
    {
        m_counter ++;

        *(
            r_unique) =
            m_counter;

        m_lock.f_unlock();
    }

    return
        e_status;

} // v_pick()

/* end-of-file: appl_unique_std_mgr.cpp */
