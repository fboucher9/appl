/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_binary_heap.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_context.h>

#include <appl_allocator.h>

#include <appl_heap.h>

#include <string.h>

//
//
//
struct appl_binary_heap : public appl_object
{
    public:

        appl_binary_heap();

        virtual
        ~appl_binary_heap();

        enum appl_status
            f_init(
                struct appl_binary_heap_descriptor const * const
                    p_binary_heap_descriptor);

        virtual
        enum appl_status
            v_insert(
                void * const
                    p_data);

        virtual
        enum appl_status
            v_remove(
                void * * const
                    r_data);

    protected:

    private:

        // --

        void * *
            m_table;

        void *
            pv_padding[1u];

        // --

        unsigned long int
            m_count;

        unsigned long int
            m_count_max;

        // --

        struct appl_binary_heap_descriptor
            m_descriptor;

        // --

        appl_binary_heap(
            struct appl_binary_heap const & r);

        struct appl_binary_heap &
            operator =(
                struct appl_binary_heap const & r);

        virtual
        enum appl_status
            v_cleanup(void);

}; // struct appl_binary_heap

//
//
//
appl_binary_heap::appl_binary_heap() :
    appl_object(),
    m_table(),
    m_count(),
    m_count_max(),
    m_descriptor()
{
}

//
//
//
appl_binary_heap::~appl_binary_heap()
{
}

//
//
//
enum appl_status
    appl_binary_heap::f_init(
        struct appl_binary_heap_descriptor const * const
            p_binary_heap_descriptor)
{
    enum appl_status
        e_status;

    e_status =
        m_context->m_heap->alloc_structure_array(
            p_binary_heap_descriptor->i_initial_max,
            &(
                m_table));

    if (
        appl_status_ok
        == e_status)
    {
        m_count =
            0ul;

        m_count_max =
            p_binary_heap_descriptor->i_initial_max;
    }

    return
        e_status;

} // f_init()

//
//
//
enum appl_status
    appl_binary_heap::v_cleanup(void)
{
    enum appl_status
        e_status;

    if (
        m_table)
    {
        m_context->m_heap->free_structure_array(
            m_count_max,
            m_table);

        m_count =
            0;

        m_count_max =
            0;

        m_table =
            0;
    }

    e_status =
        appl_status_ok;

    return
        e_status;

} // v_cleanup()

//
//
//
enum appl_status
    appl_binary_heap::v_insert(
        void * const
            p_data)
{
    enum appl_status
        e_status;

    unsigned long int
        i_pos =
        m_count + 1ul;

    if (
        i_pos >= m_count_max)
    {
        void * *
            p_new_table;

        unsigned long int const
            i_new_count_max =
            m_count_max * 2;

        e_status =
            m_context->m_heap->alloc_structure_array(
                i_new_count_max,
                &(
                    p_new_table));

        if (
            appl_status_ok
            == e_status)
        {
            memcpy(
                p_new_table,
                m_table,
                m_count_max * sizeof(void *));

            m_count_max =
                i_new_count_max;

            m_table =
                p_new_table;
        }
    }
    else
    {
        e_status =
            appl_status_ok;
    }

    if (
        appl_status_ok
        == e_status)
    {
        m_count =
            i_pos;

        while (
            (i_pos > 1)
            && ((m_descriptor.p_compare)(
                    m_descriptor.p_compare_context,
                    p_data,
                    m_table[i_pos / 2]) < 0))
        {
            m_table[i_pos] =
                m_table[i_pos / 2];

            i_pos = i_pos / 2;
        }

        m_table[i_pos] = p_data;
    }

    return
        e_status;

} // v_insert()

//
//
//
enum appl_status
    appl_binary_heap::v_remove(
        void * * const
            r_data)
{
    enum appl_status
        e_status;

    if (
        0 != m_count)
    {
        *(
            r_data) =
            m_table[1u];

        m_table[1u] =
            m_table[m_count];

        m_count --;

        void *
            p_tmp;

        unsigned long int
            i_iterator;

        i_iterator =
            1u;

        p_tmp = m_table[i_iterator];

        while (2*i_iterator <= m_count)
        {
            unsigned long int
                i_child;

            i_child =
                2*i_iterator;

            if (i_child != m_count)
            {
                if ((*(m_descriptor.p_compare))(
                        m_descriptor.p_compare_context,
                        m_table[i_child],
                        m_table[i_child + 1]))
                {
                    i_child ++;
                }
            }

            if ((*(m_descriptor.p_compare))(
                    m_descriptor.p_compare_context,
                    p_tmp,
                    m_table[i_child]) > 0)
            {
                m_table[i_iterator] = m_table[i_child];
            }
            else
            {
                break;
            }

            i_iterator = i_child;
        }

        m_table[i_iterator] = p_tmp;

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

} // v_remove()

//
//
//
class appl_binary_heap_service
{
    public:

        static
        enum appl_status
            s_create(
                struct appl_context * const
                    p_context,
                struct appl_binary_heap_descriptor const * const
                    p_binary_heap_descriptor,
                struct appl_binary_heap * * const
                    r_instance);

        static
        struct appl_object *
            s_parent(
                struct appl_binary_heap * const
                    p_binary_heap);

        static
        enum appl_status
            s_insert(
                struct appl_binary_heap * const
                    p_binary_heap,
                void * const
                    p_data);

        static
        enum appl_status
            s_remove(
                struct appl_binary_heap * const
                    p_binary_heap,
                void * * const
                    r_data);

}; // class appl_binary_heap_service

//
//
//
enum appl_status
    appl_binary_heap_service::s_create(
        struct appl_context * const
            p_context,
        struct appl_binary_heap_descriptor const * const
            p_binary_heap_descriptor,
        struct appl_binary_heap * * const
            r_instance)
{
    return
        p_context->m_allocator->alloc_object(
            p_binary_heap_descriptor,
            r_instance);

} // s_create()

//
//
//
struct appl_object *
    appl_binary_heap_service::s_parent(
        struct appl_binary_heap * const
            p_binary_heap)
{
    return
        p_binary_heap;

} // s_parent()

//
//
//
enum appl_status
    appl_binary_heap_service::s_insert(
        struct appl_binary_heap * const
            p_binary_heap,
        void * const
            p_data)
{
    return
        p_binary_heap->v_insert(
            p_data);

} // s_insert()

//
//
//
enum appl_status
    appl_binary_heap_service::s_remove(
        struct appl_binary_heap * const
            p_binary_heap,
        void * * const
            r_data)
{
    return
        p_binary_heap->v_remove(
            r_data);

} // s_remove()


/*

*/
enum appl_status
    appl_binary_heap_create(
        struct appl_context * const
            p_context,
        struct appl_binary_heap_descriptor const * const
            p_binary_heap_descriptor,
        struct appl_binary_heap * * const
            r_instance)
{
    return
        appl_binary_heap_service::s_create(
            p_context,
            p_binary_heap_descriptor,
            r_instance);

} /* _create() */

/*

*/
struct appl_object *
    appl_binary_heap_parent(
        struct appl_binary_heap * const
            p_binary_heap)
{
    return
        appl_binary_heap_service::s_parent(
            p_binary_heap);

} /* _parent() */

/*

*/
enum appl_status
    appl_binary_heap_insert(
        struct appl_binary_heap * const
            p_binary_heap,
        void * const
            p_data)
{
    return
        appl_binary_heap_service::s_insert(
            p_binary_heap,
            p_data);

} /* _insert() */

/*

*/
enum appl_status
    appl_binary_heap_remove(
        struct appl_binary_heap * const
            p_binary_heap,
        void * * const
            r_data)
{
    return
        appl_binary_heap_service::s_remove(
            p_binary_heap,
            r_data);

} /* _remove() */

/* end-of-file: appl_binary_heap.cpp */
