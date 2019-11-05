/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_predefines.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <unique/appl_unique_mgr.h>

#include <mutex/appl_mutex_handle.h>

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
    enum appl_status
        e_status;

    struct appl_mutex_descriptor
        o_mutex_descriptor;

    e_status =
        appl_mutex_create(
            m_context,
            &(
                o_mutex_descriptor),
            &(
                m_lock));

    return
        e_status;

} // f_init()

//
//
//
appl_size_t
    appl_unique_std_mgr::v_cleanup(void)
{
    if (
        m_lock)
    {
        appl_mutex_destroy(
            m_lock);

        m_lock =
            0;
    }

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
        appl_mutex_lock(
            m_lock);

    if (
        appl_status_ok
        == e_status)
    {
        m_counter ++;

        *(
            r_unique) =
            m_counter;

        appl_mutex_unlock(
            m_lock);
    }

    return
        e_status;

} // v_pick()

/* end-of-file: appl_unique_std_mgr.cpp */
