/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_predefines.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <allocator/appl_allocator.h>

#include <heap/appl_heap.h>

#include <heap/appl_heap_locked.h>

#include <mutex/appl_mutex_handle.h>

//
//
//
appl_heap_locked::appl_heap_locked(
    struct appl_context * const
        p_context) :
    appl_heap(
        p_context),
    m_descriptor(),
    m_lock()
{
}

//
//
//
appl_heap_locked::~appl_heap_locked()
{
}

//
//
//
enum appl_status
    appl_heap_locked::f_init(
        struct appl_heap_locked_descriptor const * const
            p_descriptor)
{
    enum appl_status
        e_status;

    m_descriptor =
        *(
            p_descriptor);

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
    appl_heap_locked::v_cleanup(void)
{
    appl_mutex_destroy(
        m_lock);

    return
        sizeof(
            class appl_heap_locked);

} // v_cleanup()

//
//
//
enum appl_status
    appl_heap_locked::v_alloc(
        appl_size_t const
            i_buf_len,
        void * * const
            r_buf)
{
    enum appl_status
        e_status;

    e_status =
        m_descriptor.p_parent->v_alloc(
            i_buf_len,
            r_buf);

    return
        e_status;

} // v_alloc()

//
//
//
enum appl_status
    appl_heap_locked::v_free(
        appl_size_t const
            i_buf_len,
        void * const
            p_buf)
{
    enum appl_status
        e_status;

    e_status =
        m_descriptor.p_parent->v_free(
            i_buf_len,
            p_buf);

    return
        e_status;

} // v_free()

/* end-of-file: appl_heap_locked.cpp */
