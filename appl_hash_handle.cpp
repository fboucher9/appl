/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_hash_handle.h>

#include <appl_heap_handle.h>

#include <appl_list.h>

#include <appl_convert.h>

/*

*/
struct appl_hash_table
{
    struct appl_list
        o_list;

}; /* struct appl_hash_table */

/*

Structure: appl_hash

Description:

    Instance of appl_hash object.

*/
struct appl_hash
{
    struct appl_hash_descriptor
        m_descriptor;

    /* -- */

    struct appl_hash_table *
        m_table;

    void *
        pv_padding[1u];

}; /* struct appl_hash */

/*

*/
union appl_hash_ptr
{
    void *
        p_void;

    struct appl_hash *
        p_hash;

}; /* union appl_hash_ptr */

/*

*/
union appl_hash_table_ptr
{
    void *
        p_void;

    struct appl_hash_table *
        p_table;

}; /* union appl_hash_table_ptr */

/*

*/
enum appl_status
appl_hash_create(
    struct appl_object * const
        p_context,
    struct appl_hash_descriptor const * const
        p_descriptor,
    struct appl_hash * * const
        r_instance)
{
    enum appl_status
        e_status;

    union appl_hash_ptr
        o_hash_ptr;

    unsigned long int const
        i_object_length =
        appl_convert::to_ulong(
            sizeof(
                struct appl_hash));

    e_status =
        appl_heap_alloc(
            p_context,
            i_object_length,
            &(
                o_hash_ptr.p_void));

    if (
        appl_status_ok
        == e_status)
    {
        unsigned long int const
            i_table_length =
            appl_convert::to_ulong(
                p_descriptor->i_max_index
                * sizeof(
                    struct appl_hash_table));

        union appl_hash_table_ptr
            o_table_ptr;

        e_status =
            appl_heap_alloc(
                p_context,
                i_table_length,
                &(
                    o_table_ptr.p_void));

        if (
            appl_status_ok
            == e_status)
        {
            o_hash_ptr.p_hash->m_descriptor =
                *(
                    p_descriptor);

            o_hash_ptr.p_hash->m_table =
                o_table_ptr.p_table;

            *(
                r_instance) =
                o_hash_ptr.p_hash;

            if (
                appl_status_ok
                != e_status)
            {
                appl_heap_free(
                    p_context,
                    i_table_length,
                    o_table_ptr.p_void);
            }
        }

        if (
            appl_status_ok
            != e_status)
        {
            appl_heap_free(
                p_context,
                i_object_length,
                o_hash_ptr.p_void);
        }
    }

    return
        e_status;

} /* appl_hash_create() */

/*

*/
enum appl_status
appl_hash_destroy(
    struct appl_object * const
        p_context,
    struct appl_hash * const
        p_hash)
{
    enum appl_status
        e_status;

    unsigned long int const
        i_object_length =
        appl_convert::to_ulong(
            sizeof(
                struct appl_hash));

    unsigned long int const
        i_table_length =
        appl_convert::to_ulong(
            p_hash->m_descriptor.i_max_index
            * sizeof(
                struct appl_hash_table));

    appl_heap_free(
        p_context,
        i_table_length,
        p_hash->m_table);

    appl_heap_free(
        p_context,
        i_object_length,
        p_hash);

    e_status =
        appl_status_ok;

    return
        e_status;

} /* appl_hash_destroy() */

/*

*/
void
appl_hash_insert(
    struct appl_hash * const
        p_hash,
    void const * const
        p_key,
    unsigned long int const
        i_key_len,
    struct appl_list * const
        p_list)
{
    unsigned long int const
        i_index =
        (
            (*p_hash->m_descriptor.p_index)(
                p_hash->m_descriptor.p_context,
                p_key,
                i_key_len)
            % p_hash->m_descriptor.i_max_index);

    struct appl_hash_table * const
        p_item =
        p_hash->m_table + i_index;

    appl_list_join(
        p_list,
        &(
            p_item->o_list));

} /* appl_hash_insert() */

/*

*/
struct appl_list *
appl_hash_lookup(
    struct appl_hash * const
        p_hash,
    void const * const
        p_key,
    unsigned long int const
        i_key_len)
{
    struct appl_list *
        p_list;

    p_list =
        0;

    unsigned long int const
        i_index =
        (
            (*p_hash->m_descriptor.p_index)(
                p_hash->m_descriptor.p_context,
                p_key,
                i_key_len)
            % p_hash->m_descriptor.i_max_index);

    struct appl_hash_table const * const
        p_item =
        p_hash->m_table + i_index;

    struct appl_list *
        p_iterator;

    p_iterator =
        p_item->o_list.o_next.p_node;

    while (
        (
            !(
                p_list))
        && (
            p_iterator
            != &(p_item->o_list)))
    {
        int const
            i_compare_result =
            (*p_hash->m_descriptor.p_compare)(
                p_hash->m_descriptor.p_context,
                p_key,
                i_key_len,
                p_iterator);

        if (
            0
            == i_compare_result)
        {
            p_list =
                p_iterator;
        }
        else
        {
            p_iterator =
                p_iterator->o_next.p_node;
        }
    }

    return
        p_list;

} /* appl_hash_lookup() */

/* end-of-file: appl_hash_handle.cpp */
