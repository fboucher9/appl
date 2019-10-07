/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_predefines.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_node.h>

#include <appl_buf.h>

#include <appl_string_handle.h>

#include <markup/appl_markup_value.h>

#include <appl_heap_handle.h>

//
//
//
struct appl_markup_value : public appl_node
{
    public:

        appl_markup_value(
            struct appl_context * const
                p_context);

        virtual
        ~appl_markup_value();

        enum appl_status
            f_init(void);

        virtual
        appl_size_t
            v_cleanup(void);

        enum appl_status
            f_set_type(
                enum appl_markup_value_type const
                    e_type);

        enum appl_markup_value_type
            f_get_type(void) const;

        enum appl_status
            f_set_data(
                struct appl_buf const * const
                    p_data);

        enum appl_status
            f_get_data(
                struct appl_buf * const
                    r_buf) const;

        enum appl_status
            f_join(
                struct appl_markup_value * const
                    p_child);

        struct appl_markup_value *
            f_get_first(void) const;

        struct appl_markup_value *
            f_get_next(void) const;

        struct appl_markup_value *
            f_get_parent(void) const;

        enum appl_status
            f_enumerate(
                enum appl_status (* const p_callback)(
                    void * const
                        p_void,
                    struct appl_markup_value * const
                        p_instance),
                void * const
                    p_void) const;

    protected:

    private:

        // --

        enum appl_markup_value_type
            m_type;

#define PADDING (APPL_SIZEOF_INT)
#include <appl_padding.h>

        // --

        struct appl_string *
            m_data;

        struct appl_markup_value *
            m_parent;

        // --

        class appl_node
            m_values;

        // --

        appl_markup_value(
            struct appl_markup_value const & r);

        struct appl_markup_value &
            operator =(
                struct appl_markup_value const & r);

        void
            f_cleanup_data(void);

}; // struct appl_markup_value

//
//
//
appl_markup_value::appl_markup_value(
    struct appl_context * const
        p_context) :
    appl_node(
        p_context),
    m_type(),
    m_data(),
    m_parent(),
    m_values(
        p_context)
{
}

//
//
//
appl_markup_value::~appl_markup_value()
{
}

//
//
//
enum appl_status
    appl_markup_value::f_init(void)
{
    enum appl_status
        e_status;

    e_status =
        appl_status_ok;

    return
        e_status;

} // f_init()

//
//
//
appl_size_t
    appl_markup_value::v_cleanup(void)
{
    f_cleanup_data();

    return
        sizeof(
            struct appl_markup_value);

} // v_cleanup()

//
//
//
enum appl_status
    appl_markup_value::f_set_type(
        enum appl_markup_value_type const
            e_type)
{
    m_type =
        e_type;

    return
        appl_status_ok;

} // f_set_type()

//
//
//
enum appl_markup_value_type
    appl_markup_value::f_get_type(void) const
{
    return
        m_type;

} // f_get_type()

//
//
//
enum appl_status
    appl_markup_value::f_set_data(
        struct appl_buf const * const
            p_data)
{
    enum appl_status
        e_status;

    f_cleanup_data();

    e_status =
        appl_string_create_dup_buffer(
            m_context,
            p_data->o_min.pc_uchar,
            p_data->o_max.pc_uchar,
            &(
                m_data));

    return
        e_status;

} // f_set_data()

//
//
//
enum appl_status
    appl_markup_value::f_get_data(
        struct appl_buf * const
            r_buf) const
{
    enum appl_status
        e_status;

    e_status =
        appl_string_get(
            m_data,
            &(
                r_buf->o_min.p_uchar),
            &(
                r_buf->o_max.p_uchar));

    return
        e_status;

} // f_get_data()

//
//
//
enum appl_status
    appl_markup_value::f_join(
        struct appl_markup_value * const
            p_child)
{
    enum appl_status
        e_status;

    appl_node::join(
        p_child,
        &(
            m_values));

    p_child->m_parent =
        this;

    e_status =
        appl_status_ok;

    return
        e_status;

} // f_join()

//
//
//
union appl_markup_value_ptr
{
    struct appl_markup_value *
        p_markup_value;

    struct appl_markup_value const *
        pc_markup_value;

    class appl_node *
        p_node;

    class appl_node const *
        pc_node;

};

//
//
//
struct appl_markup_value *
    appl_markup_value::f_get_first(void) const
{
    struct appl_markup_value *
        p_first_markup_value;

    if (
        m_values.p_next
        != &(
            m_values))
    {
        union appl_markup_value_ptr
            o_markup_value_ptr;

        o_markup_value_ptr.p_node =
            m_values.p_next;

        p_first_markup_value =
            o_markup_value_ptr.p_markup_value;
    }
    else
    {
        p_first_markup_value =
            0;
    }

    return
        p_first_markup_value;

} // f_get_first()

//
//
//
struct appl_markup_value *
    appl_markup_value::f_get_next(void) const
{
    struct appl_markup_value *
        p_next_markup_value;

    if (
        m_parent)
    {
        if (
            p_next
            != &(
                m_parent->m_values))
        {
            union appl_markup_value_ptr
                o_markup_value_ptr;

            o_markup_value_ptr.p_node =
                p_next;

            p_next_markup_value =
                o_markup_value_ptr.p_markup_value;
        }
        else
        {
            p_next_markup_value =
                0;
        }
    }
    else
    {
        p_next_markup_value =
            0;
    }

    return
        p_next_markup_value;

} // f_get_next()

//
//
//
struct appl_markup_value *
    appl_markup_value::f_get_parent(void) const
{
    return
        m_parent;

} // f_get_parent()

//
//
//
enum appl_status
    appl_markup_value::f_enumerate(
        enum appl_status (* const p_callback)(
            void * const
                p_void,
            struct appl_markup_value * const
                p_instance),
        void * const
            p_void) const
{
    enum appl_status
        e_status;

    union appl_markup_value_ptr
        o_iterator;

    o_iterator.p_node =
        m_values.p_next;

    e_status =
        appl_status_ok;

    while (
        (
            appl_status_ok
            == e_status)
        && (
            o_iterator.p_node
            != &(
                m_values)))
    {
        e_status =
            (* p_callback)(
                p_void,
                o_iterator.p_markup_value);

        if (
            appl_status_ok
            == e_status)
        {
            o_iterator.p_node =
                o_iterator.p_node->p_next;
        }
    }

    return
        e_status;

} // f_enumerate()

//
//
//
void
    appl_markup_value::f_cleanup_data(void)
{
    if (
        m_data)
    {
        appl_string_destroy(
            m_data);

        m_data =
            0;
    }

} // f_cleanup_data()

//
//
//
class appl_markup_value_service
{
    public:

        static
        enum appl_status
            s_create(
                struct appl_context * const
                    p_context,
                struct appl_markup_value * * const
                    r_instance);

        static
        enum appl_status
            s_destroy(
                struct appl_markup_value * const
                    p_instance);

        static
        enum appl_status
            s_join(
                struct appl_markup_value * const
                    p_parent,
                struct appl_markup_value * const
                    p_child);

        static
        enum appl_status
            s_set_type(
                struct appl_markup_value * const
                    p_instance,
                enum appl_markup_value_type const
                    e_type);

        static
        enum appl_status
            s_set_data(
                struct appl_markup_value * const
                    p_instance,
                struct appl_buf const * const
                    p_data);

        static
        enum appl_markup_value_type
            s_get_type(
                struct appl_markup_value const * const
                    p_instance);

        static
        enum appl_status
            s_get_data(
                struct appl_markup_value const * const
                    p_instance,
                struct appl_buf * const
                    r_buf);

        static
        struct appl_markup_value *
            s_get_first(
                struct appl_markup_value const * const
                    p_instance);

        static
        struct appl_markup_value *
            s_get_next(
                struct appl_markup_value const * const
                    p_instance);

        static
        struct appl_markup_value *
            s_get_parent(
                struct appl_markup_value const * const
                    p_instance);

        static
        enum appl_status
            s_enumerate(
                struct appl_markup_value const * const
                    p_instance,
                enum appl_status (* const p_callback)(
                    void * const
                        p_void,
                    struct appl_markup_value * const
                        p_instance),
                void * const
                    p_void);

}; // class appl_markup_value_service

//
//
//
enum appl_status
    appl_markup_value_service::s_create(
        struct appl_context * const
            p_context,
        struct appl_markup_value * * const
            r_instance)
{
    enum appl_status
        e_status;

    e_status =
        appl_new(
            p_context,
            r_instance);

    return
        e_status;

} // s_create()

//
//
//
enum appl_status
    appl_markup_value_service::s_destroy(
        struct appl_markup_value * const
            p_instance)
{
    enum appl_status
        e_status;

    struct appl_context * const
        p_context =
        p_instance->get_context();

    e_status =
        appl_delete(
            p_context,
            p_instance);

    return
        e_status;

} // s_destroy()

//
//
//
enum appl_status
    appl_markup_value_service::s_join(
        struct appl_markup_value * const
            p_parent,
        struct appl_markup_value * const
            p_child)
{
    enum appl_status
        e_status;

    e_status =
        p_parent->f_join(
            p_child);

    return
        e_status;

} // s_join()

//
//
//
enum appl_status
    appl_markup_value_service::s_set_type(
        struct appl_markup_value * const
            p_instance,
        enum appl_markup_value_type const
            e_type)
{
    enum appl_status
        e_status;

    e_status =
        p_instance->f_set_type(
            e_type);

    return
        e_status;

} // s_set_type()

//
//
//
enum appl_status
    appl_markup_value_service::s_set_data(
        struct appl_markup_value * const
            p_instance,
        struct appl_buf const * const
            p_data)
{
    enum appl_status
        e_status;

    e_status =
        p_instance->f_set_data(
            p_data);

    return
        e_status;

} // s_set_data()

//
//
//
enum appl_markup_value_type
    appl_markup_value_service::s_get_type(
        struct appl_markup_value const * const
            p_instance)
{
    return
        p_instance->f_get_type();

} // s_get_type()

//
//
//
enum appl_status
    appl_markup_value_service::s_get_data(
        struct appl_markup_value const * const
            p_instance,
        struct appl_buf * const
            r_buf)
{
    enum appl_status
        e_status;

    e_status =
        p_instance->f_get_data(
            r_buf);

    return
        e_status;

} // s_get_data()

//
//
//
struct appl_markup_value *
    appl_markup_value_service::s_get_first(
        struct appl_markup_value const * const
            p_instance)
{
    return
        p_instance->f_get_first();

} // s_get_first()

//
//
//
struct appl_markup_value *
    appl_markup_value_service::s_get_next(
        struct appl_markup_value const * const
            p_instance)
{
    return
        p_instance->f_get_next();

} // s_get_next()

//
//
//
struct appl_markup_value *
    appl_markup_value_service::s_get_parent(
        struct appl_markup_value const * const
            p_instance)
{
    return
        p_instance->f_get_parent();

} // s_get_parent()

//
//
//
enum appl_status
    appl_markup_value_service::s_enumerate(
        struct appl_markup_value const * const
            p_instance,
        enum appl_status (* const p_callback)(
            void * const
                p_void,
            struct appl_markup_value * const
                p_instance),
        void * const
            p_void)
{
    return
        p_instance->f_enumerate(
            p_callback,
            p_void);

} // s_enumerate()

//
//
//
enum appl_status
    appl_markup_value_create(
        struct appl_context * const
            p_context,
        struct appl_markup_value * * const
            r_instance)
{
    return
        appl_markup_value_service::s_create(
            p_context,
            r_instance);

} // create()

//
//
//
enum appl_status
    appl_markup_value_destroy(
        struct appl_markup_value * const
            p_instance)
{
    return
        appl_markup_value_service::s_destroy(
            p_instance);

} // destroy()

//
//
//
enum appl_status
    appl_markup_value_join(
        struct appl_markup_value * const
            p_parent,
        struct appl_markup_value * const
            p_child)
{
    return
        appl_markup_value_service::s_join(
            p_parent,
            p_child);

} // join()

//
//
//
enum appl_status
    appl_markup_value_set_type(
        struct appl_markup_value * const
            p_instance,
        enum appl_markup_value_type const
            e_type)
{
    return
        appl_markup_value_service::s_set_type(
            p_instance,
            e_type);

} // set_type()

//
//
//
enum appl_status
    appl_markup_value_set_data(
        struct appl_markup_value * const
            p_instance,
        struct appl_buf const * const
            p_data)
{
    return
        appl_markup_value_service::s_set_data(
            p_instance,
            p_data);

} // set_data()

//
//
//
enum appl_markup_value_type
    appl_markup_value_get_type(
        struct appl_markup_value const * const
            p_instance)
{
    return
        appl_markup_value_service::s_get_type(
            p_instance);

} // get_type()

//
//
//
enum appl_status
    appl_markup_value_get_data(
        struct appl_markup_value const * const
            p_instance,
        struct appl_buf * const
            r_buf)
{
    return
        appl_markup_value_service::s_get_data(
            p_instance,
            r_buf);

} // get_data()

//
//
//
struct appl_markup_value *
    appl_markup_value_get_first(
        struct appl_markup_value const * const
            p_instance)
{
    return
        appl_markup_value_service::s_get_first(
            p_instance);

} // get_first()

//
//
//
struct appl_markup_value *
    appl_markup_value_get_next(
        struct appl_markup_value const * const
            p_instance)
{
    return
        appl_markup_value_service::s_get_next(
            p_instance);

} // get_next()

//
//
//
struct appl_markup_value *
    appl_markup_value_get_parent(
        struct appl_markup_value const * const
            p_instance)
{
    return
        appl_markup_value_service::s_get_parent(
            p_instance);

} // get_parent()

//
//
//
enum appl_status
    appl_markup_value_enumerate(
        struct appl_markup_value const * const
            p_instance,
        enum appl_status (* const p_callback)(
            void * const
                p_void,
            struct appl_markup_value * const
                p_instance),
        void * const
            p_void)
{
    return
        appl_markup_value_service::s_enumerate(
            p_instance,
            p_callback,
            p_void);

} // enumerate()

/* end-of-file: appl_markup_value.cpp */
