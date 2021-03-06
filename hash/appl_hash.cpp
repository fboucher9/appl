/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <list/appl_list.h>

#include <hash/appl_hash_handle.h>

#include <hash/appl_hash.h>

#include <context/appl_context_handle.h>

#include <allocator/appl_allocator_handle.h>

#include <heap/appl_heap_handle.h>

//
//
//
enum appl_status
    appl_hash::f_init(
        struct appl_hash_descriptor const * const
            p_descriptor)
{
    enum appl_status
        e_status;

    e_status =
        appl_heap_alloc_structure_array(
            m_context,
            p_descriptor->i_max_index,
            &(
                m_table));

    if (
        appl_status_ok
        == e_status)
    {
        m_descriptor =
            *(
                p_descriptor);

        {
            unsigned long int
                i_index;

            i_index =
                0ul;

            while (
                i_index < m_descriptor.i_max_index)
            {
                struct appl_hash_table * const
                    p_hash_table =
                    m_table + i_index;

                appl_list_init(
                    &(
                        p_hash_table->o_list));

                i_index ++;
            }
        }

#if 0 // not used yet
        if (
            appl_status_ok
            != e_status)
        {
            appl_heap_free_structure_array(
                m_context,
                p_descriptor->i_max_index,
                m_table);
        }
#endif // not used yet
    }

    return
        e_status;

} // f_init()

//
//
//
void
    appl_hash::f_insert(
        void const * const
            p_key,
        unsigned long int const
            i_key_len,
        struct appl_list * const
            p_list)
{
    appl_size_t const
        i_index =
        (
            (*m_descriptor.p_index)(
                m_descriptor.p_context,
                p_key,
                i_key_len)
            % m_descriptor.i_max_index);

    struct appl_hash_table * const
        p_hash_table =
        m_table + i_index;

    appl_list_join(
        p_list,
        &(
            p_hash_table->o_list));

} // f_insert()

//
//
//
bool
    appl_hash::f_lookup(
        void const * const
            p_key,
        unsigned long int const
            i_key_len,
        struct appl_list * * const
            r_list)
{
    bool
        b_result;

    b_result =
        false;

    appl_size_t const
        i_index =
        (
            (*m_descriptor.p_index)(
                m_descriptor.p_context,
                p_key,
                i_key_len)
            % m_descriptor.i_max_index);

    struct appl_hash_table const * const
        p_hash_table =
        m_table + i_index;

    struct appl_list *
        p_iterator;

    p_iterator =
        p_hash_table->o_list.o_next.p_node;

    while (
        (
            !(
                b_result))
        && (
            p_iterator
            != &(p_hash_table->o_list)))
    {
        int const
            i_compare_result =
            (*m_descriptor.p_compare)(
                m_descriptor.p_context,
                p_key,
                i_key_len,
                p_iterator);

        if (
            0
            == i_compare_result)
        {
            *(
                r_list) =
                p_iterator;

            b_result =
                true;
        }
        else
        {
            p_iterator =
                p_iterator->o_next.p_node;
        }
    }

    return
        b_result;

} // f_lookup()

//
//
//
void
    appl_hash::f_iterate(
        void (
            * p_callback)(
            void * const
                p_context,
            struct appl_list * const
                p_list),
        void * const
            p_context)
{
    appl_size_t
        i_index;

    i_index =
        0u;

    while (
        i_index < m_descriptor.i_max_index)
    {
        struct appl_hash_table const * const
            p_hash_table =
            m_table + i_index;

        struct appl_list *
            p_iterator;

        p_iterator =
            p_hash_table->o_list.o_next.p_node;

        while (
            p_iterator
            != &(
                p_hash_table->o_list))
        {
            struct appl_list * const
                p_next_iterator =
                p_iterator->o_next.p_node;

            (*p_callback)(
                p_context,
                p_iterator);

            p_iterator =
                p_next_iterator;

        }

        i_index ++;
    }

} // f_iterate()

//
//
//
appl_hash::appl_hash(
    struct appl_context * const
        p_context) :
    appl_object(
        p_context),
    m_descriptor(),
    m_table()
{
}

//
//
//
appl_hash::~appl_hash()
{
}

//
//
//
appl_size_t
    appl_hash::v_cleanup(void)
{
    appl_heap_free_structure_array(
        m_context,
        m_descriptor.i_max_index,
        m_table);

    return
        sizeof(struct appl_hash);

} // v_cleanup()

/* end-of-file: appl_hash.cpp */
