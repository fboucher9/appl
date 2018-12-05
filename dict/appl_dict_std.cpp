/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <dict/appl_dict.h>

#include <appl_list.h>

#include <dict/appl_dict_std.h>

#include <appl_hash_handle.h>

#include <appl_object_handle.h>

#include <appl_unused.h>

#include <appl_allocator_handle.h>

#include <appl_buf.h>

#include <appl_crc16.h>

#include <appl_string_handle.h>

#include <context/appl_context.h>

/*

*/
struct appl_dict_std_node
{
    struct appl_list
        o_list;

    /* -- */

    struct appl_string *
        p_name;

    void *
        p_value;

}; /* struct appl_dict_std_node */

union appl_dict_std_node_ptr
{
    struct appl_list *
        p_list;

    struct appl_dict_std_node *
        p_dict_std_node;

};

//
//
//
enum appl_status
    appl_dict_std::s_create(
        struct appl_allocator * const
            p_allocator,
        class appl_dict_std * * const
            r_instance)
{
    return
        appl_new(
            p_allocator,
            r_instance);

} // s_create()

//
//
//
enum appl_status
    appl_dict_std::s_destroy(
        struct appl_allocator * const
            p_allocator,
        class appl_dict_std * const
            p_instance)
{
    return
        appl_delete(
            p_allocator,
            p_instance);

} // s_destroy()

//
//
//
appl_dict_std::appl_dict_std() :
    appl_dict(),
    m_hash()
{
}

//
//
//
appl_dict_std::~appl_dict_std()
{
}

//
//
//
enum appl_status
    appl_dict_std::f_init(void)
{
    enum appl_status
        e_status;

    // Create hash table
    struct appl_hash_descriptor
        o_hash_descriptor;

    o_hash_descriptor.p_compare =
        &(
            appl_dict_std::s_compare);

    o_hash_descriptor.p_index =
        &(
            appl_dict_std::s_index);

    o_hash_descriptor.p_context =
        this;

    o_hash_descriptor.i_max_index =
        256u;

    e_status =
        appl_hash_create(
            m_context,
            &(
                o_hash_descriptor),
            &(
                m_hash));

    if (
        appl_status_ok
        == e_status)
    {
    }

    return
        e_status;

} // f_init()

//
//
//
appl_size_t
    appl_dict_std::v_cleanup(void)
{
    // Destroy hash table
    appl_hash_destroy(
        m_hash);

    return
        sizeof(class appl_dict_std);

} // v_cleanup()

//
//
//
enum appl_status
    appl_dict_std::v_set(
        unsigned char const * const
            p_name_min,
        unsigned char const * const
            p_name_max,
        void * const
            p_value)
{
    enum appl_status
        e_status;

    union appl_dict_std_node_ptr
        o_node_ptr;

    // Lookup else insert
    if (
        appl_hash_lookup(
            m_hash,
            p_name_min,
            appl_buf_len(
                p_name_min,
                p_name_max),
            &(
                o_node_ptr.p_list)))
    {
        o_node_ptr.p_dict_std_node->p_value =
            p_value;

        e_status =
            appl_status_ok;
    }
    else
    {
        // Reuse an old node
        // Create a new node
        e_status =
            f_alloc_node(
                p_name_min,
                p_name_max,
                p_value,
                &(
                    o_node_ptr.p_dict_std_node));

        if (
            appl_status_ok
            == e_status)
        {
            appl_hash_insert(
                m_hash,
                p_name_min,
                appl_buf_len(
                    p_name_min,
                    p_name_max),
                &(
                    o_node_ptr.p_dict_std_node->o_list));
        }
    }

    return
        e_status;

} // v_set()

//
//
//
enum appl_status
    appl_dict_std::v_get(
        unsigned char const * const
            p_name_min,
        unsigned char const * const
            p_name_max,
        void * * const
            r_value)
{
    enum appl_status
        e_status;

    // Lookup
    union appl_dict_std_node_ptr
        o_node_ptr;

    // Lookup else fail
    if (
        appl_hash_lookup(
            m_hash,
            p_name_min,
            appl_buf_len(
                p_name_min,
                p_name_max),
            &(
                o_node_ptr.p_list)))
    {
        *(
            r_value) =
            o_node_ptr.p_dict_std_node->p_value;

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

} // v_get()

//
//
//
int
    appl_dict_std::s_compare(
        void * const
            p_context,
        void const * const
            p_key,
        unsigned long int const
            i_key_len,
        struct appl_list * const
            p_node)
{
    int
        i_compare_result;

    union appl_buf_ptr
        o_key_ptr;

    appl_unused(
        p_context);

    o_key_ptr.pc_void =
        p_key;

    union appl_dict_std_node_ptr
        o_node_ptr;

    o_node_ptr.p_list =
        p_node;

    struct appl_string *
        p_name;

    unsigned char *
        p_name_min;

    unsigned char *
        p_name_max;

    p_name =
        o_node_ptr.p_dict_std_node->p_name;

    appl_string_get(
        p_name,
        &(
            p_name_min),
        &(
            p_name_max));

    i_compare_result =
        appl_buf_compare(
            o_key_ptr.pc_uchar,
            o_key_ptr.pc_uchar + i_key_len,
            p_name_min,
            p_name_max);

    return
        i_compare_result;

} // s_compare()

//
//
//
unsigned long int
    appl_dict_std::s_index(
        void * const
            p_context,
        void const * const
            p_key,
        unsigned long int const
            i_key_len)
{
    union appl_buf_ptr
        o_key_ptr;

    appl_unused(
        p_context);

    o_key_ptr.pc_void =
        p_key;

    return
        appl_crc16(
            o_key_ptr.pc_uchar,
            i_key_len);

} // s_index()

//
//
//
enum appl_status
    appl_dict_std::f_alloc_node(
        unsigned char const * const
            p_name_min,
        unsigned char const * const
            p_name_max,
        void * const
            p_value,
        struct appl_dict_std_node * * const
            r_node)
{
    enum appl_status
        e_status;

    struct appl_dict_std_node *
        p_dict_std_node;

    e_status =
        appl_allocator_alloc_structure(
            m_context->m_allocator,
            &(
                p_dict_std_node));

    if (
        appl_status_ok
        == e_status)
    {
        appl_list_init(
            &(
                p_dict_std_node->o_list));

        e_status =
            appl_string_create_dup_buffer(
                this,
                p_name_min,
                p_name_max,
                &(
                    p_dict_std_node->p_name));

        if (
            appl_status_ok
            == e_status)
        {
            p_dict_std_node->p_value =
                p_value;

            *(
                r_node) =
                p_dict_std_node;
        }
        else
        {
            appl_allocator_free_structure(
                m_context->m_allocator,
                p_dict_std_node);
        }
    }

    return
        e_status;

} // f_alloc_node()

/* end-of-file: appl_dict_std.cpp */
