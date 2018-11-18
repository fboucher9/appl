/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <options/appl_options.h>

#include <appl_list.h>

#include <options/appl_options_std.h>

#include <appl_string.h>

#include <appl_context.h>

#include <appl_allocator.h>

#include <appl_buf0.h>

#include <appl_convert.h>

#include <appl_unused.h>

#include <appl_heap.h>

#include <appl_buf.h>

#include <appl_chunk.h>

/*

*/
struct appl_options_std_node
{
    struct appl_list
        o_list;

    unsigned char *
        p_buf_min;

    unsigned char *
        p_buf_max;

}; /* struct appl_options_std_node */

union appl_options_std_node_ptr
{
    struct appl_list *
        p_list;

    struct appl_options_std_node *
        p_options_std_node;

}; /* union appl_options_std_node_ptr */

//
//
//
enum appl_status
appl_options_std::s_create(
    struct appl_allocator * const
        p_allocator,
    struct appl_options * * const
        r_options)
{
    enum appl_status
        e_status;

    class appl_options_std *
        p_options_std;

    e_status =
        p_allocator->alloc_object(
            &(
                p_options_std));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_options) =
            p_options_std;
    }

    return
        e_status;

} // create_instance()

//
//
//
appl_options_std::appl_options_std() :
    appl_options(),
    m_list(),
    m_chunk(),
    m_count(),
    m_state()
{
}

//
//
//
appl_options_std::~appl_options_std()
{
}

//
//
//
enum appl_status
appl_options_std::f_init(void)
{
    enum appl_status
        e_status;

    appl_list_init(
        &(
            m_list));

    e_status =
        appl_status_ok;

    return
        e_status;

} // f_init()

//
//
//
enum appl_status
appl_options_std::v_cleanup(void)
{
    enum appl_status
        e_status;

    // free list of nodes
    {
        while (
            m_list.o_next.p_node != &(m_list))
        {
            union appl_options_std_node_ptr
                o_options_std_node_ptr;

            o_options_std_node_ptr.p_list =
                m_list.o_next.p_node;

            appl_list_join(
                o_options_std_node_ptr.p_list,
                o_options_std_node_ptr.p_list);

            unsigned long int const
                i_buf_len =
                appl_buf_len(
                    o_options_std_node_ptr.p_options_std_node->p_buf_min,
                    o_options_std_node_ptr.p_options_std_node->p_buf_max);

            m_context->m_heap->free_structure_array(
                i_buf_len,
                o_options_std_node_ptr.p_options_std_node->p_buf_min);

            m_context->m_heap->free_structure(
                o_options_std_node_ptr.p_options_std_node);
        }
    }

    // Free the chunk
    if (
        m_chunk)
    {
        appl_chunk_destroy(
            m_chunk);

        m_chunk =
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
appl_options_std::v_count(
    unsigned long int * const
        r_count) const
{
    enum appl_status
        e_status;

    *(
        r_count) =
        m_count;

    e_status =
        appl_status_ok;

    return
        e_status;

} // v_count()

//
//
//
enum appl_status
appl_options_std::v_get(
    unsigned long int const
        i_index,
    unsigned char const * * const
        r_buf_min,
    unsigned char const * * const
        r_buf_max) const
{
    enum appl_status
        e_status;

    unsigned long int
        i_position;

    i_position =
        0u;

    union appl_options_std_node_ptr
        o_options_std_node_ptr;

    o_options_std_node_ptr.p_list =
        m_list.o_next.p_node;

    while (
        i_position < i_index)
    {
        o_options_std_node_ptr.p_list =
            o_options_std_node_ptr.p_list->o_next.p_node;

        i_position ++;
    }

    if (
        o_options_std_node_ptr.p_list != &(m_list))
    {
        *(
            r_buf_min) =
            o_options_std_node_ptr.p_options_std_node->p_buf_min;

        *(
            r_buf_max) =
            o_options_std_node_ptr.p_options_std_node->p_buf_max;

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
enum appl_status
    appl_options_std::f_flush_word(void)
{
    enum appl_status
        e_status;

    e_status =
        appl_status_ok;

    if (
        m_chunk)
    {
        unsigned long int
            i_length;

        e_status =
            appl_chunk_length(
                m_chunk,
                &(
                    i_length));

        if (
            appl_status_ok
            == e_status)
        {
            unsigned char *
                p_buf;

            e_status =
                m_context->m_heap->alloc_structure_array(
                    i_length,
                    &(
                        p_buf));

            if (
                appl_status_ok
                == e_status)
            {
                e_status =
                    appl_chunk_read(
                        m_chunk,
                        p_buf,
                        p_buf + i_length);

                if (
                    appl_status_ok
                    == e_status)
                {
                    e_status =
                        v_append_argument(
                            p_buf,
                            p_buf + i_length);
                }

                m_context->m_heap->free_structure_array(
                    i_length,
                    p_buf);
            }
        }

        appl_chunk_destroy(
            m_chunk);

        m_chunk =
            0;
    }

    return
        e_status;

} // f_flush_word()

//
//
//
enum appl_status
    appl_options_std::f_append_char(
        unsigned char const
            i_char)
{
    enum appl_status
        e_status;

    if (
        m_chunk)
    {
        e_status =
            appl_status_ok;
    }
    else
    {
        e_status =
            appl_chunk_create(
                m_context,
                &(
                    m_chunk));
    }

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            appl_chunk_write(
                m_chunk,
                &(
                    i_char),
                &(
                    i_char) + 1u);
    }

    return
        e_status;

} // f_append_char()

//
//
//
enum appl_status
    appl_options_std::f_process_char(
        unsigned char const
            i_char,
        char * const
            p_ready)
{
    enum appl_status
        e_status;

    e_status =
        appl_status_ok;

    char
        b_ready;

    b_ready =
        0;

    if (
        appl_options_std_state_space == m_state)
    {
        if (
            '\n' == i_char)
        {
            e_status =
                f_flush_word();

            m_state =
                appl_options_std_state_space;

            b_ready =
                1;
        }
        else if (
            (
                ' ' == i_char)
            || (
                '\t' == i_char)
            || (
                '\r' == i_char))
        {
            e_status =
                f_flush_word();

            m_state =
                appl_options_std_state_space;
        }
        else if (
            (
                '\'' == i_char))
        {
            m_state =
                appl_options_std_state_quote;
        }
        else if (
            (
                '\\' == i_char))
        {
            m_state =
                appl_options_std_state_escape;
        }
        else
        {
            e_status =
                f_append_char(
                    i_char);

            m_state =
                appl_options_std_state_word;
        }
    }
    else if (
        appl_options_std_state_word == m_state)
    {
        if (
            '\n' == i_char)
        {
            e_status =
                f_flush_word();

            m_state =
                appl_options_std_state_space;

            b_ready =
                1;
        }
        else if (
            (
                ' ' == i_char)
            || (
                '\t' == i_char)
            || (
                '\r' == i_char))
        {
            e_status =
                f_flush_word();

            m_state =
                appl_options_std_state_space;
        }
        else if (
            (
                '\'' == i_char))
        {
            m_state =
                appl_options_std_state_quote;
        }
        else if (
            (
                '\\' == i_char))
        {
            m_state =
                appl_options_std_state_escape;
        }
        else
        {
            e_status =
                f_append_char(
                    i_char);

            m_state =
                appl_options_std_state_word;
        }
    }
    else if (
        appl_options_std_state_quote == m_state)
    {
        if (
            (
                '\'' == i_char))
        {
            m_state =
                appl_options_std_state_word;
        }
        else
        {
            e_status =
                f_append_char(
                    i_char);

            m_state =
                appl_options_std_state_quote;
        }
    }
    else if (
        appl_options_std_state_escape == m_state)
    {
        e_status =
            f_append_char(
                i_char);

        m_state =
            appl_options_std_state_word;
    }
    else
    {
        e_status =
            appl_status_fail;
    }

    if (
        appl_status_ok
        == e_status)
    {
        *(
            p_ready) =
            b_ready;
    }

    return
        e_status;

} // f_process_char()

//
//
//
enum appl_status
    appl_options_std::v_write(
        unsigned char const * const
            p_buf_min,
        unsigned char const * const
            p_buf_max,
        unsigned long int * const
            p_count,
        char * const
            p_ready)
{
    enum appl_status
        e_status;

    e_status =
        appl_status_ok;

    unsigned long int
        i_count;

    i_count =
        0ul;

    char
        b_ready;

    b_ready =
        0;

    unsigned char const *
        p_buf_it;

    p_buf_it =
        p_buf_min;

    while (
        (
            appl_status_ok
            == e_status)
        && (
            p_buf_it
            != p_buf_max)
        && (
            !(
                b_ready)))
    {
        unsigned char const
            i_char =
            *(
                p_buf_it);

        e_status =
            f_process_char(
                i_char,
                &(
                    b_ready));

        if (
            appl_status_ok
            == e_status)
        {
            i_count ++;

            p_buf_it ++;
        }
    }

    if (
        appl_status_ok
        == e_status)
    {
        *(
            p_count) =
            i_count;

        *(
            p_ready) =
            b_ready;
    }

    return
        e_status;

} // v_write()

//
//
//
enum appl_status
    appl_options_std::v_append_argument(
        unsigned char const * const
            p_buf_min,
        unsigned char const * const
            p_buf_max)
{
    enum appl_status
        e_status;

    struct appl_options_std_node *
        p_options_std_node;

    e_status =
        m_context->m_heap->alloc_structure(
            &(
                p_options_std_node));

    if (
        appl_status_ok
        == e_status)
    {
        appl_list_init(
            &(
                p_options_std_node->o_list));

        unsigned long int const
            i_buf_len =
            appl_buf_len(
                p_buf_min,
                p_buf_max);

        e_status =
            m_context->m_heap->alloc_structure_array(
                i_buf_len,
                &(
                    p_options_std_node->p_buf_min));

        if (
            appl_status_ok
            == e_status)
        {
            p_options_std_node->p_buf_max =
                p_options_std_node->p_buf_min
                + i_buf_len;

            appl_buf_copy(
                p_options_std_node->p_buf_min,
                p_options_std_node->p_buf_max,
                p_buf_min,
                p_buf_max);

            appl_list_join(
                &(
                    p_options_std_node->o_list),
                &(
                    m_list));

            m_count ++;
        }
    }

    return
        e_status;

} // v_append_argument()

/* end-of-file: appl_options_std.cpp */
