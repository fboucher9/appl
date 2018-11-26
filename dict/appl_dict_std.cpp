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

#include <allocator/appl_allocator.h>

#include <appl_buf.h>

#include <appl_crc16.h>

/*

*/
struct appl_dict_std_node
{
    struct appl_list
        o_list;

    /* -- */

    unsigned char *
        p_name_min;

    unsigned char *
        p_name_max;

    /* -- */

    void *
        p_value;

    void *
        pv_padding[1u];

}; /* struct appl_dict_std_node */

//
//
//
enum appl_status
    appl_dict_std::s_create(
        struct appl_allocator * const
            p_allocator,
        struct appl_dict_std * * const
            r_instance)
{
    return
        p_allocator->alloc_object(
            r_instance);

} // s_create()

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
enum appl_status
    appl_dict_std::v_cleanup(void)
{
    // Destroy hash table
    appl_object_destroy(
        appl_hash_parent(
            m_hash));

    return
        appl_status_ok;

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
    // Lookup else insert

    appl_unused(
        p_name_min,
        p_name_max,
        p_value);

    return
        appl_status_fail;

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
    // Lookup

    appl_unused(
        p_name_min,
        p_name_max,
        r_value);

    return
        appl_status_fail;

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
    {
        struct appl_list *
            p_list;

        struct appl_dict_std_node *
            p_dict_std_node;

    } o_node_ptr;

    o_node_ptr.p_list =
        p_node;

    i_compare_result =
        appl_buf_compare(
            o_key_ptr.pc_uchar,
            o_key_ptr.pc_uchar + i_key_len,
            o_node_ptr.p_dict_std_node->p_name_min,
            o_node_ptr.p_dict_std_node->p_name_max);

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

/* end-of-file: appl_dict_std.cpp */
