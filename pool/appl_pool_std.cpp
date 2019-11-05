/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <list/appl_list.h>

#include <allocator/appl_allocator.h>

#include <pool/appl_pool.h>

#include <pool/appl_pool_handle.h>

#include <pool/appl_pool_std.h>

#include <misc/appl_unused.h>

#include <allocator/appl_allocator_handle.h>

#include <heap/appl_heap_handle.h>

/* Assert compiler */
#include <misc/appl_assert_cplusplus.h>

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
        struct appl_pool_descriptor const * const
            p_pool_descriptor,
        class appl_pool_std * * const
            r_instance)
{
    return
        appl_new(
            p_allocator,
            p_pool_descriptor,
            r_instance);

} // s_create()

//
//
//
appl_pool_std::appl_pool_std(
    struct appl_context * const
        p_context) :
    appl_pool(
        p_context),
    m_available_items(),
    m_descriptor(),
    m_count_remain()
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
        struct appl_pool_descriptor const * const
            p_pool_descriptor)
{
    enum appl_status
        e_status;

    e_status =
        appl_status_ok;

    appl_list_init(
        &(
            m_available_items));

    m_descriptor =
        *(
            p_pool_descriptor);

    m_count_remain =
        m_descriptor.i_count_max;

    if (
        0u
        == m_count_remain)
    {
        m_count_remain =
            0xFFFFFFFFul;
    }

    // Pre-allocate some available items
    if (
        m_descriptor.i_count_min)
    {
        unsigned long int
            i_count;

        i_count =
            0u;

        while (
            (
                appl_status_ok
                == e_status)
            && (
                i_count
                < m_descriptor.i_count_min))
        {
            union appl_pool_node_ptr
                o_node_ptr;

            e_status =
                appl_heap_alloc(
                    m_context,
                    m_descriptor.i_length,
                    &(
                        o_node_ptr.p_void));

            if (
                appl_status_ok
                == e_status)
            {
                m_count_remain --;

                appl_list_init(
                    o_node_ptr.p_list);

                appl_list_join(
                    o_node_ptr.p_list,
                    &(
                        m_available_items));

                i_count ++;
            }
        }
    }

    return
        e_status;

} // f_init()

//
//
//
appl_size_t
    appl_pool_std::v_cleanup(void)
{
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

        appl_heap_free(
            m_context,
            m_descriptor.i_length,
            p_node);
    }

    return
        sizeof(class appl_pool_std);

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

    if (
        !(
            b_found))
    {
        if (
            m_count_remain)
        {
            // allocate new item
            e_status =
                appl_heap_alloc(
                    m_context,
                    m_descriptor.i_length,
                    &(
                        p_buf));

            if (
                appl_status_ok
                == e_status)
            {
                m_count_remain --;

                b_found =
                    true;
            }
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

    e_status =
        appl_status_ok;

    return
        e_status;

} // v_free()

/* end-of-file: appl_pool_std.cpp */
