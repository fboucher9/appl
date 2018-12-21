/* See LICENSE for license details */

/*

*/

#include <appl_node_test.h>

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_node.h>

#include <appl_node_iterator.h>

#include <appl_heap_handle.h>

#include <appl_list.h>

#include <appl_unused.h>

//
//
//
class appl_letter_node : public appl_node
{
    public:

        static
        enum appl_status
            s_create(
                struct appl_context * const
                    p_context,
                char const
                    c_letter,
                class appl_letter_node * * const
                    r_instance);

        static
        enum appl_status
            s_destroy(
                class appl_letter_node * const
                    p_letter);

        appl_letter_node(
            struct appl_context * const
                p_context);

        virtual
        ~appl_letter_node();

        enum appl_status
            f_init(void);

        virtual
        appl_size_t
            v_cleanup(void);

        // --

        char
            m_letter;

#define PADDING 1
#include <appl_padding.h>

        // --

    protected:

    private:

        appl_letter_node(
            class appl_letter_node const & r);

        class appl_letter_node &
            operator =(
                class appl_letter_node const & r);

}; // class appl_letter_node

//
//
//
enum appl_status
appl_letter_node::s_create(
    struct appl_context * const
        p_context,
    char const
        c_letter,
    class appl_letter_node * * const
        r_instance)
{
    enum appl_status
        e_status;

    class appl_letter_node *
        p_letter;

    e_status =
        appl_new(
            p_context,
            &(
                p_letter));

    if (
        appl_status_ok
        == e_status)
    {
        p_letter->m_letter =
            c_letter;

        *(
            r_instance) =
            p_letter;
    }

    return
        e_status;

} // s_create()

//
//
//
enum appl_status
    appl_letter_node::s_destroy(
        class appl_letter_node * const
            p_letter)
{
    enum appl_status
        e_status;

    struct appl_context * const
        p_context =
        p_letter->get_context();

    e_status =
        appl_delete(
            p_context,
            p_letter);

    return
        e_status;

} // s_destroy()

//
//
//
appl_letter_node::appl_letter_node(
    struct appl_context * const
        p_context) :
    appl_node(
        p_context),
    m_letter()
{
}

//
//
//
appl_letter_node::~appl_letter_node()
{
}

//
//
//
enum appl_status
appl_letter_node::f_init(void)
{
    return
        appl_status_ok;

} // f_init()

//
//
//
appl_size_t
appl_letter_node::v_cleanup(void)
{
    return
        sizeof(class appl_letter_node);

} // v_cleanup()

struct appl_letter_list
{
    struct appl_list
        o_list;

    char
        m_letter;

#define PADDING 1
#include <appl_padding.h>

}; /* struct appl_letter_list */

//
//
//
void
    appl_node_test_1(
        struct appl_context * const
            p_context)
{
    {
        enum appl_status
            e_status;

        class appl_node *
            p_node_base;

        e_status =
            appl_new(
                p_context,
                &(
                    p_node_base));

        if (
            appl_status_ok
            == e_status)
        {
            appl_delete(
                p_context,
                p_node_base);
        }
    }

    {
        enum appl_status
            e_status;

        class appl_node
            o_letter_head(
                p_context);

        class appl_letter_node *
            a_letter[8u];

        unsigned int
            i;

        i =
            0u;

        while (
            i < 8u)
        {
            e_status =
                appl_letter_node::s_create(
                    p_context,
                    (char)(
                        'a' + i),
                    &(
                        a_letter[i]));

            if (
                appl_status_ok
                == e_status)
            {
                appl_node::join(
                    a_letter[i],
                    &(
                        o_letter_head));
            }

            i++;
        }

        // Forward iterator
        {
            class appl_node_iterator
                o_forward_iterator(
                    &(
                        o_letter_head));

            while (
                o_forward_iterator.next())
            {
            }
        }

        // Backward iterator
        {
            class appl_node_iterator
                o_backward_iterator(
                    &(
                        o_letter_head));

            while (
                o_backward_iterator.prev())
            {
            }
        }

        i =
            0u;

        while (
            i < 8u)
        {
            appl_letter_node::s_destroy(
                a_letter[i]);

            i++;
        }

        appl_unused(
            e_status);
    }

    {
        struct appl_list
            o_letter_head;

        struct appl_letter_list
            a_letter[8u];

        unsigned int
            i;

        appl_list_init(
            &(
                o_letter_head));

        i =
            0u;

        while (
            i < 8u)
        {
            appl_list_init(
                &(
                    a_letter[i].o_list));

            a_letter[i].m_letter =
                (('a' + i) & 0x7f);

            appl_list_join(
                &(
                    a_letter[i].o_list),
                &(
                    o_letter_head));

            i++;
        }

        // Forward iterator
        {
            struct appl_iterator
                o_forward_iterator;

            appl_iterator_init(
                &(
                    o_forward_iterator),
                &(
                    o_letter_head));

            while (
                appl_iterator_next(
                    &(
                        o_forward_iterator)))
            {
            }
        }

        // Backward iterator
        {
            struct appl_iterator
                o_backward_iterator;

            appl_iterator_init(
                &(
                    o_backward_iterator),
                &(
                    o_letter_head));

            while (
                appl_iterator_prev(
                    &(
                        o_backward_iterator)))
            {
            }
        }
    }

} // appl_node_test_1()

/* end-of-file: appl_node_test.cpp */
