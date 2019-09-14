/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_buf.h>

#include <buf/appl_str_bits.h>

#include <buf/appl_bits_handle.h>

#include <appl_types.h>

#include <appl_object.h>

#include <buf/appl_bits.h>

#include <buf/appl_bits_std.h>

#include <appl_context_handle.h>

#include <appl_allocator_handle.h>

//
//
//
class appl_str_bits : public appl_bits_std
{
    public:

        appl_str_bits(
            struct appl_context * const
                p_context);

        virtual
        ~appl_str_bits();

        enum appl_status
            f_init(
                struct appl_str_bits_descriptor const * const
                    p_descriptor);

        virtual
        appl_size_t
            v_cleanup(void);

    protected:

    private:

        struct appl_buf
            m_buf_iterator;

        appl_str_bits(
            class appl_str_bits const & r);

        class appl_str_bits &
            operator =(
                class appl_str_bits const & r);

        static
        enum appl_status
            s_consume(
                void * const
                    p_callback_context,
                unsigned char * const
                    r_value);

        static
        enum appl_status
            s_produce(
                void * const
                    p_callback_context,
                unsigned char const
                    i_value);

        enum appl_status
            f_consume(
                unsigned char * const
                    r_value);

        enum appl_status
            f_produce(
                unsigned char const
                    i_value);

}; // class appl_str_bits

//
//
//
appl_str_bits::appl_str_bits(
    struct appl_context * const
        p_context) :
    appl_bits_std(
        p_context),
    m_buf_iterator()
{
}

//
//
//
appl_str_bits::~appl_str_bits()
{
}

//
//
//
enum appl_status
appl_str_bits::f_init(
    struct appl_str_bits_descriptor const * const
        p_descriptor)
{
    enum appl_status
        e_status;

    m_buf_iterator =
        p_descriptor->o_buf;

    struct appl_bits_descriptor
        o_descriptor;

    o_descriptor.p_callback_consume =
        &(
            appl_str_bits::s_consume);

    o_descriptor.p_callback_produce =
        &(
            appl_str_bits::s_produce);

    o_descriptor.p_callback_context =
        this;

    e_status =
        appl_bits_std::f_init(
            &(
                o_descriptor));

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
    appl_str_bits::v_cleanup(void)
{
    appl_bits_std::v_cleanup();

    return
        sizeof(
            class appl_str_bits);

} // v_cleanup()

//
//
//
union appl_str_bits_ptr
{
    void *
        p_callback_context;

    class appl_str_bits *
        p_this;

}; // union appl_str_bits_ptr

//
//
//
enum appl_status
    appl_str_bits::s_consume(
        void * const
            p_callback_context,
        unsigned char * const
            r_value)
{
    union appl_str_bits_ptr
        o_str_bits_ptr;

    o_str_bits_ptr.p_callback_context =
        p_callback_context;

    return
        o_str_bits_ptr.p_this->f_consume(
            r_value);

} // s_consume()

//
//
//
enum appl_status
    appl_str_bits::s_produce(
        void * const
            p_callback_context,
        unsigned char const
            i_value)
{
    union appl_str_bits_ptr
        o_str_bits_ptr;

    o_str_bits_ptr.p_callback_context =
        p_callback_context;

    return
        o_str_bits_ptr.p_this->f_produce(
            i_value);

} // s_produce()

//
//
//
enum appl_status
    appl_str_bits::f_consume(
        unsigned char * const
            r_value)
{
    enum appl_status
        e_status;

    if (
        m_buf_iterator.o_min.pc_uchar
        < m_buf_iterator.o_max.pc_uchar)
    {
        *(
            r_value) =
            *(
                m_buf_iterator.o_min.pc_uchar);

        m_buf_iterator.o_min.pc_uchar ++;

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

} // f_consume()

//
//
//
enum appl_status
    appl_str_bits::f_produce(
        unsigned char const
            i_value)
{
    enum appl_status
        e_status;

    if (
        m_buf_iterator.o_min.p_uchar
        < m_buf_iterator.o_max.p_uchar)
    {
        *(
            m_buf_iterator.o_min.p_uchar) =
            i_value;

        m_buf_iterator.o_min.p_uchar ++;

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

} // f_produce()

//
//
//
class appl_str_bits_service
{
    public:

        static
        enum appl_status
            s_create(
                struct appl_context * const
                    p_context,
                struct appl_str_bits_descriptor const * const
                    p_descriptor,
                struct appl_bits * * const
                    r_instance);

}; // class appl_str_bits_service

//
//
//
enum appl_status
    appl_str_bits_service::s_create(
        struct appl_context * const
            p_context,
        struct appl_str_bits_descriptor const * const
            p_descriptor,
        struct appl_bits * * const
            r_instance)
{
    enum appl_status
        e_status;

    struct appl_allocator * const
        p_allocator =
        appl_context_get_allocator(
            p_context);

    class appl_str_bits *
        p_str_bits;

    e_status =
        appl_new(
            p_allocator,
            p_descriptor,
            &(
                p_str_bits));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_instance) =
            p_str_bits;
    }

    return
        e_status;

} // s_create()

//
//
//
enum appl_status
    appl_str_bits_create(
        struct appl_context * const
            p_context,
        struct appl_str_bits_descriptor const * const
            p_descriptor,
        struct appl_bits * * const
            r_instance)
{
    enum appl_status
        e_status;

    e_status =
        appl_str_bits_service::s_create(
            p_context,
            p_descriptor,
            r_instance);

    return
        e_status;

} // appl_str_bits_create()

/* end-of-file: appl_str_bits.cpp */
