/* See LICENSE for license details */

/*

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
//
//
struct appl_chunk_node : public appl_list
{
    unsigned char
        i_data_len;

    unsigned char
        uc_padding[7u];

    /* -- */

    unsigned char
        a_data[120u];

}; /* struct appl_chunk_node */

//
//
//
struct appl_chunk : public appl_object
{
    public:

        static
        enum appl_status
        s_create(
            struct appl_context * const
                p_context,
            struct appl_chunk * * const
                r_chunk);

        enum appl_status
        f_write(
            unsigned char const * const
                p_buf_min,
            unsigned char const * const
                p_buf_max);

        enum appl_status
        f_length(
            unsigned long int * const
                r_length) const;

        enum appl_status
        f_read(
            unsigned char * const
                p_buf_min,
            unsigned char * const
                p_buf_max) const;

    protected:

        appl_chunk();

        virtual
        ~appl_chunk();

    private:

        struct appl_list
            o_nodes;

        // --

        unsigned long int
            i_total_len;

        unsigned long int
            ul_padding[1u];

        appl_chunk(
            struct appl_chunk const & r);

        struct appl_chunk &
            operator =(
                struct appl_chunk const & r);

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

        enum appl_status
        f_append_node(
            unsigned char const
                c_value);

        enum appl_status
        f_write_char(
            unsigned char const
                c_value);

}; // struct appl_chunk

//
//
//
enum appl_status
appl_chunk::s_create(
    struct appl_context * const
        p_context,
    struct appl_chunk * * const
        r_chunk)
{
    return
        appl_object::s_create(
            p_context,
            (&
                appl_chunk::s_new),
            (&
                appl_chunk::init),
            r_chunk);

} // s_create()

//
//
//
appl_chunk::appl_chunk() :
    appl_object(),
    o_nodes(),
    i_total_len()
{
}

//
//
//
appl_chunk::~appl_chunk()
{
}

//
//
//
void
    appl_chunk::s_new(
        void * const
            p_placement)
{
    new (p_placement)
        struct appl_chunk;

} // s_new()

//
//
//
enum appl_status
appl_chunk::init(void)
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
appl_chunk::v_cleanup(void)
{
    enum appl_status
        e_status;

    // destroy all nodes
    while (
        o_nodes.o_prev.p_node != &(o_nodes))
    {
        struct appl_chunk_node * const
            p_chunk_node =
            static_cast<struct appl_chunk_node *>(
                o_nodes.o_prev.p_node);

        appl_list_join(
            p_chunk_node,
            p_chunk_node);

        m_context->m_heap->v_free(
            p_chunk_node);
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
appl_chunk::f_append_node(
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
appl_chunk::f_write_char(
    unsigned char const
        c_value)
{
    enum appl_status
        e_status;

    /* Is the list empty? */
    if (
        o_nodes.o_prev.p_node != &(o_nodes))
    {
        struct appl_chunk_node * const
            p_chunk_node =
            static_cast<struct appl_chunk_node *>(
                o_nodes.o_prev.p_node);

        /* Is there room in current chunk? */
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
appl_chunk::f_write(
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

} // f_write()

enum appl_status
appl_chunk::f_length(
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

} // f_length()

//
//
//
enum appl_status
appl_chunk::f_read(
    unsigned char * const
        p_buf_min,
    unsigned char * const
        p_buf_max) const
{
    enum appl_status
        e_status;

    unsigned char *
        p_buf_iterator;

    struct appl_list const *
        p_node_iterator;

    e_status =
        appl_status_ok;

    p_buf_iterator =
        p_buf_min;

    p_node_iterator =
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
        p_node_iterator =
            p_node_iterator->o_next.pc_node;

        if (
            p_node_iterator != &(o_nodes))
        {
            struct appl_chunk_node const * const
                p_chunk_node =
                static_cast<struct appl_chunk_node const *>(
                    p_node_iterator);

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

} // f_read()

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
        appl_chunk::s_create(
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
        p_chunk->f_write(
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
        p_chunk->f_length(
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
        p_chunk->f_read(
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
