/* See LICENSE for license details */

/*

Module: appl_chunk.cpp

Description:

    See appl_chunk.h for more details.

*/

#include <appl_status.h>

#include <appl_chunk.h>

#include <appl_list.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_heap.h>

#include <appl_context.h>

#include <appl_unused.h>

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

    unsigned char
        uc_padding[7u];

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
//  Class: appl_chunk
//
//  Description:
//      Interface for serial buffer of unknown length.
//
struct appl_chunk : public appl_object
{
    public:

        virtual
        enum appl_status
        v_write(
            unsigned char const * const
                p_buf_min,
            unsigned char const * const
                p_buf_max);

        virtual
        enum appl_status
        v_length(
            unsigned long int * const
                r_length) const;

        virtual
        enum appl_status
        v_read(
            unsigned char * const
                p_buf_min,
            unsigned char * const
                p_buf_max) const;

    protected:

        appl_chunk();

        virtual
        ~appl_chunk();

    private:

        appl_chunk(
            struct appl_chunk const & r);

        struct appl_chunk &
            operator =(
                struct appl_chunk const & r);

}; // struct appl_chunk

//
//
//
enum appl_status
appl_chunk::v_write(
    unsigned char const * const
        p_buf_min,
    unsigned char const * const
        p_buf_max)
{
    appl_unused(
        p_buf_min,
        p_buf_max);

    return
        appl_status_not_implemented;

} // v_write()

//
//
//
enum appl_status
appl_chunk::v_length(
    unsigned long int * const
        r_length) const
{
    appl_unused(
        r_length);

    return
        appl_status_not_implemented;

} // v_length()

//
//
//
enum appl_status
appl_chunk::v_read(
    unsigned char * const
        p_buf_min,
    unsigned char * const
        p_buf_max) const
{
    appl_unused(
        p_buf_min,
        p_buf_max);

    return
        appl_status_not_implemented;

} // v_read()

//
//
//
appl_chunk::appl_chunk() :
    appl_object()
{
}

//
//
//
appl_chunk::~appl_chunk()
{
}

class appl_chunk_std;

//
//  Class: appl_chunk_std
//
//  Description:
//      Standard implementation for appl_chunk interface.
//
class appl_chunk_std : public appl_chunk
{
    public:

        static
        enum appl_status
        s_create(
            struct appl_context * const
                p_context,
            struct appl_chunk * * const
                r_chunk);

    protected:

        appl_chunk_std();

        virtual
        ~appl_chunk_std();

    private:

        struct appl_list
            o_nodes;

        // --

        unsigned long int
            i_total_len;

        unsigned long int
            ul_padding[1u];

        appl_chunk_std(
            class appl_chunk_std const & r);

        class appl_chunk_std &
            operator =(
                class appl_chunk_std const & r);

        static
        void
            s_new(
                void * const
                    p_placement);

        enum appl_status
            init(void);

        virtual
        enum appl_status
            v_cleanup(void);

        virtual
        enum appl_status
            v_write(
                unsigned char const * const
                    p_buf_min,
                unsigned char const * const
                    p_buf_max);

        virtual
        enum appl_status
            v_length(
                unsigned long int * const
                    r_length) const;

        virtual
        enum appl_status
            v_read(
                unsigned char * const
                    p_buf_min,
                unsigned char * const
                    p_buf_max) const;

        enum appl_status
        f_append_node(
            unsigned char const
                c_value);

        enum appl_status
        f_write_char(
            unsigned char const
                c_value);

}; // class appl_chunk_std

//
//
//
enum appl_status
appl_chunk_std::s_create(
    struct appl_context * const
        p_context,
    struct appl_chunk * * const
        r_chunk)
{
    enum appl_status
        e_status;

    class appl_chunk_std *
        p_chunk_std;

    e_status =
        appl_object::s_create(
            p_context,
            (&
                appl_chunk_std::s_new),
            (&
                appl_chunk_std::init),
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
appl_chunk_std::appl_chunk_std() :
    appl_chunk(),
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
void
    appl_chunk_std::s_new(
        void * const
            p_placement)
{
    new (p_placement)
        class appl_chunk_std;

} // s_new()

//
//
//
enum appl_status
appl_chunk_std::init(void)
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

//
//
//
enum appl_status
appl_chunk_std::v_cleanup(void)
{
    enum appl_status
        e_status;

    // destroy all nodes
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

        m_context->m_heap->v_free(
            o_chunk_node_ptr.p_chunk_node);
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
appl_chunk_std::f_append_node(
    unsigned char const
        c_value)
{
    enum appl_status
        e_status;

    struct appl_chunk_node *
        p_chunk_node;

    e_status =
        m_context->m_heap->alloc_object(
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
class appl_chunk_service
{
    public:

        static
        enum appl_status
        s_create(
            struct appl_context * const
                p_context,
            struct appl_chunk * * const
                r_chunk);

        static
        enum appl_status
        s_destroy(
            struct appl_chunk * const
                p_chunk);

        static
        enum appl_status
        s_write(
            struct appl_chunk * const
                p_chunk,
            unsigned char const * const
                p_buf_min,
            unsigned char const * const
                p_buf_max);

        static
        enum appl_status
        s_length(
            struct appl_chunk const * const
                p_chunk,
            unsigned long int * const
                r_length);

        static
        enum appl_status
        s_read(
            struct appl_chunk const * const
                p_chunk,
            unsigned char * const
                p_buf_min,
            unsigned char * const
                p_buf_max);

}; // class appl_chunk_service

//
//
//
enum appl_status
appl_chunk_service::s_create(
    struct appl_context * const
        p_context,
    struct appl_chunk * * const
        r_chunk)
{
    return
        appl_chunk_std::s_create(
            p_context,
            r_chunk);

} // s_create()

//
//
//
enum appl_status
appl_chunk_service::s_destroy(
    struct appl_chunk * const
        p_chunk)
{
    return
        p_chunk->destroy();

} // s_destroy()

//
//
//
enum appl_status
appl_chunk_service::s_write(
    struct appl_chunk * const
        p_chunk,
    unsigned char const * const
        p_buf_min,
    unsigned char const * const
        p_buf_max)
{
    return
        p_chunk->v_write(
            p_buf_min,
            p_buf_max);

} // s_write()

//
//
//
enum appl_status
appl_chunk_service::s_length(
    struct appl_chunk const * const
        p_chunk,
    unsigned long int * const
        r_length)
{
    return
        p_chunk->v_length(
            r_length);

} // s_length()

//
//
//
enum appl_status
appl_chunk_service::s_read(
    struct appl_chunk const * const
        p_chunk,
    unsigned char * const
        p_buf_min,
    unsigned char * const
        p_buf_max)
{
    return
        p_chunk->v_read(
            p_buf_min,
            p_buf_max);

} // s_read()

/*

*/
enum appl_status
appl_chunk_create(
    struct appl_context * const
        p_context,
    struct appl_chunk * * const
        r_chunk)
{
    return
        appl_chunk_service::s_create(
            p_context,
            r_chunk);

} /* appl_chunk_create() */

/*

*/
enum appl_status
appl_chunk_destroy(
    struct appl_chunk * const
        p_chunk)
{
    return
        appl_chunk_service::s_destroy(
            p_chunk);

} /* appl_chunk_destroy() */

/*

*/
enum appl_status
appl_chunk_write(
    struct appl_chunk * const
        p_chunk,
    unsigned char const * const
        p_buf_min,
    unsigned char const * const
        p_buf_max)
{
    return
        appl_chunk_service::s_write(
            p_chunk,
            p_buf_min,
            p_buf_max);

} /* appl_chunk_write() */

/*

*/
enum appl_status
appl_chunk_length(
    struct appl_chunk const * const
        p_chunk,
    unsigned long int * const
        r_length)
{
    return
        appl_chunk_service::s_length(
            p_chunk,
            r_length);

} /* appl_chunk_length() */

/*

*/
enum appl_status
appl_chunk_read(
    struct appl_chunk const * const
        p_chunk,
    unsigned char * const
        p_buf_min,
    unsigned char * const
        p_buf_max)
{
    return
        appl_chunk_service::s_read(
            p_chunk,
            p_buf_min,
            p_buf_max);

} /* appl_chunk_read() */

/* end-of-file: appl_chunk.cpp */
