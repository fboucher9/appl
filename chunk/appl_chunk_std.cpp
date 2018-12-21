/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <chunk/appl_chunk.h>

#include <appl_list.h>

#include <chunk/appl_chunk_std.h>

#include <appl_allocator_handle.h>

#include <appl_heap_handle.h>

//
//  Class: appl_chunk_node
//
//  Description:
//      Single chunk of characters.  This structure is part of a linked list.
//      Maximum chunk size of 256 so that offsets may use 8-bit integer type.
//
struct appl_chunk_node : public appl_list
{
    unsigned char
        i_data_len;

#define PADDING (1)
#include <appl_padding.h>

    // --

    unsigned char
        a_data[120u];

}; // struct appl_chunk_node

//
//
//
union appl_chunk_node_ptr
{
    struct appl_list *
        p_node;

    struct appl_chunk_node *
        p_chunk_node;

}; // union appl_chunk_node_ptr

//
//
//
union appl_chunk_node_cptr
{
    struct appl_list const *
        pc_node;

    struct appl_chunk_node const *
        pc_chunk_node;

}; // union appl_chunk_node_ptr

//
//
//
enum appl_status
appl_chunk_std::s_create(
    struct appl_allocator * const
        p_allocator,
    struct appl_chunk * * const
        r_chunk)
{
    enum appl_status
        e_status;

    class appl_chunk_std *
        p_chunk_std;

    e_status =
        appl_new(
            p_allocator,
            &(
                p_chunk_std));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_chunk) =
            p_chunk_std;
    }

    return
        e_status;

} // s_create()

//
//
//
enum appl_status
appl_chunk_std::s_destroy(
    struct appl_allocator * const
        p_allocator,
    struct appl_chunk * const
        p_chunk)
{
    return
        appl_delete(
            p_allocator,
            p_chunk);

} // s_destroy()

//
//
//
appl_chunk_std::appl_chunk_std(
    struct appl_context * const
        p_context) :
    appl_chunk(
        p_context),
    o_nodes(),
    i_total_len()
{
}

//
//
//
appl_chunk_std::~appl_chunk_std()
{
}

//
//
//
enum appl_status
appl_chunk_std::f_init(void)
{
    enum appl_status
        e_status;

    appl_list_init(
        &(
            o_nodes));

    i_total_len =
        0ul;

    e_status =
        appl_status_ok;

    return
        e_status;

} // init()

void
appl_chunk_std::f_free_node_list(void)
{
    while (
        o_nodes.o_prev.p_node != &(o_nodes))
    {
        union appl_chunk_node_ptr
            o_chunk_node_ptr;

        o_chunk_node_ptr.p_node =
            o_nodes.o_prev.p_node;

        appl_list_join(
            o_chunk_node_ptr.p_chunk_node,
            o_chunk_node_ptr.p_chunk_node);

        appl_heap_free_structure(
            m_context,
            o_chunk_node_ptr.p_chunk_node);
    }
} // f_free_node_list()

//
//
//
appl_size_t
appl_chunk_std::v_cleanup(void)
{
    // destroy all nodes
    f_free_node_list();

    return
        sizeof(class appl_chunk_std);

} // v_cleanup()

//
//
//
enum appl_status
appl_chunk_std::f_append_node(
    unsigned char const
        c_value)
{
    enum appl_status
        e_status;

    struct appl_chunk_node *
        p_chunk_node;

    e_status =
        appl_heap_alloc_structure(
            m_context,
            &(
                p_chunk_node));

    if (
        appl_status_ok
        == e_status)
    {
        appl_list_init(
            p_chunk_node);

        p_chunk_node->i_data_len =
            1;

        p_chunk_node->a_data[0u] =
            c_value;

        i_total_len ++;

        appl_list_join(
            p_chunk_node,
            &(
                o_nodes));
    }

    return
        e_status;

} // f_append_node()

//
//
//
enum appl_status
appl_chunk_std::f_write_char(
    unsigned char const
        c_value)
{
    enum appl_status
        e_status;

    // Is the list empty?
    if (
        o_nodes.o_prev.p_node != &(o_nodes))
    {
        union appl_chunk_node_ptr
            o_chunk_node_ptr;

        o_chunk_node_ptr.p_node =
            o_nodes.o_prev.p_node;

        struct appl_chunk_node * const
            p_chunk_node =
            o_chunk_node_ptr.p_chunk_node;

        // Is there room in current chunk?
        if (
            p_chunk_node->i_data_len < sizeof(p_chunk_node->a_data))
        {
            p_chunk_node->a_data[p_chunk_node->i_data_len] =
                c_value;

            p_chunk_node->i_data_len ++;

            i_total_len ++;

            e_status =
                appl_status_ok;
        }
        else
        {
            e_status =
                f_append_node(
                    c_value);
        }
    }
    else
    {
        e_status =
            f_append_node(
                c_value);
    }

    return
        e_status;

} // f_write_char()

//
//
//
enum appl_status
appl_chunk_std::v_write(
    unsigned char const * const
        p_buf_min,
    unsigned char const * const
        p_buf_max)
{
    enum appl_status
        e_status;

    unsigned char const *
        p_buf_iterator;

    e_status =
        appl_status_ok;

    p_buf_iterator =
        p_buf_min;

    while (
        (
            appl_status_ok
            == e_status)
        && (
            p_buf_iterator
            < p_buf_max))
    {
        e_status =
            f_write_char(
                *(
                    p_buf_iterator));

        if (
            appl_status_ok
            == e_status)
        {
            p_buf_iterator ++;
        }
    }

    return
        e_status;

} // v_write()

enum appl_status
appl_chunk_std::v_length(
    unsigned long int * const
        r_length) const
{
    enum appl_status
        e_status;

    *(
        r_length) =
        i_total_len;

    e_status =
        appl_status_ok;

    return
        e_status;

} // v_length()

//
//
//
enum appl_status
appl_chunk_std::v_read(
    unsigned char * const
        p_buf_min,
    unsigned char * const
        p_buf_max) const
{
    enum appl_status
        e_status;

    unsigned char *
        p_buf_iterator;

    union appl_chunk_node_cptr
        o_node_iterator;

    e_status =
        appl_status_ok;

    p_buf_iterator =
        p_buf_min;

    o_node_iterator.pc_node =
        &(
            o_nodes);

    while (
        (
            appl_status_ok
            == e_status)
        && (
            p_buf_iterator
            != p_buf_max))
    {
        o_node_iterator.pc_node =
            o_node_iterator.pc_node->o_next.pc_node;

        if (
            o_node_iterator.pc_node != &(o_nodes))
        {
            struct appl_chunk_node const * const
                p_chunk_node =
                o_node_iterator.pc_chunk_node;

            unsigned char const *
                p_data_iterator;

            p_data_iterator =
                p_chunk_node->a_data;

            unsigned char const * const
                p_data_max =
                p_chunk_node->a_data + p_chunk_node->i_data_len;

            while (
                (
                    p_buf_iterator
                    != p_buf_max)
                && (
                    p_data_iterator
                    != p_data_max))
            {
                *(
                    p_buf_iterator) =
                    *(
                        p_data_iterator);

                p_buf_iterator ++;

                p_data_iterator ++;
            }
        }
        else
        {
            e_status =
                appl_status_fail;
        }
    }

    return
        e_status;

} // v_read()

//
//
//
enum appl_status
    appl_chunk_std::v_reset(void)
{
    enum appl_status
        e_status;

    // destroy all nodes
    f_free_node_list();

    i_total_len =
        0ul;

    e_status =
        appl_status_ok;

    return
        e_status;

} // v_reset()

/* end-of-file: appl_chunk_std.cpp */
