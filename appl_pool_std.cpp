/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_list.h>

#include <appl_pool.h>

#include <pthread.h>

#include <appl_pool_std.h>

#include <appl_unused.h>

struct appl_pool_std_descriptor
{
    appl_size_t
        i_buf_len;

}; /* struct appl_pool_std_descriptor */

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
enum appl_status
    appl_pool_std::s_create(
        struct appl_context * const
            p_context,
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
        appl_object::s_create(
            p_context,
            (&
                appl_pool_std::s_new),
            (&
                appl_pool_std::init),
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
void
    appl_pool_std::s_new(
        void * const
            p_placement)
{
    new (
        p_placement)
        class appl_pool_std;

} // s_new()

//
//
//
enum appl_status
    appl_pool_std::init(
        struct appl_pool_std_descriptor const * const
            p_descriptor)
{
    enum appl_status
        e_status;

    appl_list_init(
        &(
            m_available_items));

    int
        i_pthread_mutex_result;

    i_pthread_mutex_result =
        pthread_mutex_init(
            &(
                m_lock),
            0);

    if (
        0 == i_pthread_mutex_result)
    {
        m_buf_len =
            p_descriptor->i_buf_len;

        m_available_count =
            0u;

        e_status =
            appl_status_ok;
    }
    else
    {
        e_status =
            appl_status_fail;
    }

    return
        e_status;

} // init()

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
        void * * const
            r_buf)
{
    enum appl_status
        e_status;

    appl_unused(
        r_buf);

    int
        i_pthread_mutex_result;

    i_pthread_mutex_result =
        pthread_mutex_lock(
            &(
                m_lock));

    if (
        0 == i_pthread_mutex_result)
    {
        // Are there available items?
        if (
            m_available_items.o_next.p_node != &(m_available_items))
        {
            struct appl_list *
                p_node;

            p_node =
                m_available_items.o_next.p_node;

            appl_list_join(
                p_node,
                p_node);
        }
        else
        {
            // allocate new item
            // allocate group of free items
        }

        e_status =
            appl_status_ok;

        pthread_mutex_unlock(
            &(
                m_lock));
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
        void * const
            p_buf)
{
    enum appl_status
        e_status;

    // place object into linked list

    appl_unused(
        p_buf);

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} // v_free()

/* end-of-file: appl_pool_std.cpp */
