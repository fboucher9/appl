/* See LICENSE for license details */

/*

*/

#if defined APPL_OS_LINUX

#include <pthread.h>

#else /* #if defined APPL_OS_Xx */

#include <windows.h>

#endif /* #if defined APPL_OS_Xx */

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_list.h>

#include <appl_allocator.h>

#include <pool/appl_pool.h>

#include <mutex/appl_mutex_impl.h>

#include <pool/appl_pool_std.h>

#include <appl_unused.h>

#include <appl_context.h>

struct appl_pool_std_descriptor
{
    appl_size_t
        i_buf_len;

}; /* struct appl_pool_std_descriptor */

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

union appl_pool_node_ptr
{
    void *
        p_void;

    struct appl_list *
        p_list;

};

//
//
//
enum appl_status
    appl_pool_std::s_create(
        struct appl_allocator * const
            p_allocator,
        appl_size_t const
            i_buf_len,
        class appl_pool_std * * const
            r_instance)
{
    struct appl_pool_std_descriptor
        o_pool_std_descriptor;

    o_pool_std_descriptor.i_buf_len =
        i_buf_len;

    return
        p_allocator->alloc_object(
            &(
                o_pool_std_descriptor),
            r_instance);

} // s_create()

//
//
//
appl_pool_std::appl_pool_std() :
    appl_pool(),
    m_available_items(),
    m_lock(),
    m_buf_len(),
    m_available_count()
{
}

//
//
//
appl_pool_std::~appl_pool_std()
{
}

//
//
//
enum appl_status
    appl_pool_std::f_init(
        struct appl_pool_std_descriptor const * const
            p_descriptor)
{
    enum appl_status
        e_status;

    appl_list_init(
        &(
            m_available_items));

    e_status =
        m_lock.init();

    if (
        appl_status_ok
        == e_status)
    {
        m_buf_len =
            p_descriptor->i_buf_len;

        m_available_count =
            0u;
    }

    return
        e_status;

} // f_init()

//
//
//
enum appl_status
    appl_pool_std::v_cleanup(void)
{
    enum appl_status
        e_status;

    // assert if allocated items remain

    // free all reuseable items
    while (m_available_items.o_next.p_node != &(m_available_items))
    {
        struct appl_list * const
            p_node =
            m_available_items.o_next.p_node;

        appl_list_join(
            p_node,
            p_node);

        m_context->m_allocator->v_free(
            m_buf_len,
            p_node);
    }

    m_lock.cleanup();

    e_status =
        appl_status_ok;

    return
        e_status;

} // cleanup()

//
//
//
enum appl_status
    appl_pool_std::v_alloc(
        appl_size_t const
            i_buf_len,
        void * * const
            r_buf)
{
    enum appl_status
        e_status;

    appl_unused(
        i_buf_len);

    if (
        appl_status_ok
        == m_lock.lock())
    {
        void *
            p_buf;

        bool
            b_found;

        p_buf =
            0;

        b_found =
            false;

        // Are there available items?
        if (
            m_available_items.o_next.p_node != &(m_available_items))
        {
            union appl_pool_node_ptr
                o_node_ptr;

            o_node_ptr.p_list =
                m_available_items.o_next.p_node;

            appl_list_join(
                o_node_ptr.p_list,
                o_node_ptr.p_list);

            o_node_ptr.p_list->o_next.p_node =
                0;

            o_node_ptr.p_list->o_prev.p_node =
                0;

            p_buf =
                o_node_ptr.p_void;

            b_found =
                true;
        }

        m_lock.unlock();

        if (
            !(
                b_found))
        {
            // allocate new item
            e_status =
                m_context->m_allocator->v_alloc(
                    m_buf_len,
                    &(
                        p_buf));

            if (
                appl_status_ok
                == e_status)
            {
                b_found =
                    true;
            }
        }

        if (
            b_found)
        {
            *(
                r_buf) =
                p_buf;

            e_status =
                appl_status_ok;
        }
        else
        {
            e_status =
                appl_status_out_of_memory;
        }
    }
    else
    {
        e_status =
            appl_status_fail;
    }

    return
        e_status;

} // v_alloc()

//
//
//
enum appl_status
    appl_pool_std::v_free(
        appl_size_t const
            i_buf_len,
        void * const
            p_buf)
{
    enum appl_status
        e_status;

    appl_unused(
        i_buf_len);

    if (
        appl_status_ok
        == m_lock.lock())
    {
        union appl_pool_node_ptr
            o_node_ptr;

        o_node_ptr.p_void =
            p_buf;

        // place object into linked list
        appl_list_init(
            o_node_ptr.p_list);

        appl_list_join(
            o_node_ptr.p_list,
            &(
                m_available_items));

        if (
            appl_status_ok
            == m_lock.unlock())
        {
            e_status =
                appl_status_ok;
        }
        else
        {
            e_status =
                appl_status_fail;
        }
    }
    else
    {
        e_status =
            appl_status_fail;
    }

    return
        e_status;

} // v_free()

/* end-of-file: appl_pool_std.cpp */
