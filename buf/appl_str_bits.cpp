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

#include <buf/appl_bits_base.h>

#include <appl_context_handle.h>

#include <appl_allocator_handle.h>

//
//
//
class appl_str_bits : public appl_bits_base
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

        virtual
        enum appl_status
            v_consume(
                unsigned char * const
                    r_value);

        virtual
        enum appl_status
            v_produce(
                unsigned char const
                    i_value);

}; // class appl_str_bits

//
//
//
appl_str_bits::appl_str_bits(
    struct appl_context * const
        p_context) :
    appl_bits_base(
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

    e_status =
        appl_status_ok;

    return
        e_status;

} // f_init()

//
//
//
appl_size_t
    appl_str_bits::v_cleanup(void)
{
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
    appl_str_bits::v_consume(
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

} // v_consume()

//
//
//
enum appl_status
    appl_str_bits::v_produce(
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
