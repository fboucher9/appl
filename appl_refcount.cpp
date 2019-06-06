/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_refcount.h>

#include <appl_object_handle.h>

#include <appl_mutex_handle.h>

//
//
//
appl_refcount::appl_refcount(
    struct appl_context * const
        p_context) :
    appl_object(
        p_context),
    m_mutex(),
    m_refcount(1)
{
}

//
//
//
appl_refcount::~appl_refcount()
{
}

//
//
//
enum appl_status
appl_refcount::f_init(void)
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
                m_mutex));

    return
        e_status;

} // f_init()

//
//
//
enum appl_status
    appl_refcount::v_acquire(void)
{
    appl_mutex_lock(
        m_mutex);

    m_refcount ++;

    appl_mutex_unlock(
        m_mutex);

    return
        appl_status_ok;

} // v_acquire()

//
//
//
enum appl_status
    appl_refcount::v_release(void)
{
    enum appl_status
        e_status;

    bool
        b_destroy;

    appl_mutex_lock(
        m_mutex);

    if (
        m_refcount)
    {
        m_refcount --;

        if (
            0
            == m_refcount)
        {
            b_destroy =
                true;
        }
        else
        {
            b_destroy =
                false;
        }
    }
    else
    {
        b_destroy =
            false;
    }

    appl_mutex_unlock(
        m_mutex);

    if (
        b_destroy)
    {
    }

    e_status =
        appl_status_ok;

    return
        e_status;

} // v_release()

//
//
//
appl_size_t
    appl_refcount::v_cleanup(void)
{
    appl_mutex_destroy(
        m_mutex);

    return
        sizeof(class appl_refcount);

} // v_cleanup()

/* end-of-file: appl_refcount.cpp */
