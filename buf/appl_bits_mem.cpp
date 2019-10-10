/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_predefines.h>

#include <buf/appl_buf.h>

#include <buf/appl_bits_mem.h>

#include <buf/appl_bits_handle.h>

#include <appl_types.h>

#include <appl_object.h>

#include <buf/appl_bits.h>

#include <buf/appl_bits_base.h>

#include <buf/appl_bits_descriptor.h>

#include <appl_heap_handle.h>

#include <misc/appl_unused.h>

//
//
//
struct appl_bits_mem : public appl_bits_base
{
    public:

        appl_bits_mem(
            struct appl_context * const
                p_context);

        virtual
        ~appl_bits_mem();

        enum appl_status
            f_init(
                struct appl_bits_mem_descriptor const * const
                    p_descriptor);

        virtual
        appl_size_t
            v_cleanup(void);

        virtual
        enum appl_status
            v_query(
                struct appl_buf * const
                    r_buf_used,
                struct appl_buf * const
                    r_buf_unused) const;

    protected:

    private:

        struct appl_buf
            m_buf_original;

        struct appl_buf
            m_buf_iterator;

        appl_bits_mem(
            struct appl_bits_mem const & r);

        struct appl_bits_mem &
            operator =(
                struct appl_bits_mem const & r);

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

}; // struct appl_bits_mem

//
//
//
appl_bits_mem::appl_bits_mem(
    struct appl_context * const
        p_context) :
    appl_bits_base(
        p_context),
    m_buf_original(),
    m_buf_iterator()
{
}

//
//
//
appl_bits_mem::~appl_bits_mem()
{
}

//
//
//
enum appl_status
appl_bits_mem::f_init(
    struct appl_bits_mem_descriptor const * const
        p_descriptor)
{
    enum appl_status
        e_status;

    m_buf_original =
        p_descriptor->o_buf;

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
    appl_bits_mem::v_cleanup(void)
{
    return
        sizeof(
            struct appl_bits_mem);

} // v_cleanup()

//
//
//
enum appl_status
    appl_bits_mem::v_query(
        struct appl_buf * const
            r_buf_used,
        struct appl_buf * const
            r_buf_unused) const
{
    enum appl_status
        e_status;

    r_buf_used->o_min =
        m_buf_original.o_min;

    r_buf_used->o_max =
        m_buf_iterator.o_min;

    r_buf_unused->o_min =
        m_buf_iterator.o_min;

    r_buf_unused->o_max =
        m_buf_iterator.o_max;

    e_status =
        appl_status_ok;

    return
        e_status;

} // v_query()

//
//
//
union appl_bits_mem_ptr
{
    void *
        p_callback_context;

    struct appl_bits_mem *
        p_this;

}; // union appl_bits_mem_ptr

//
//
//
enum appl_status
    appl_bits_mem::v_consume(
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
    appl_bits_mem::v_produce(
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
class appl_bits_mem_service
{
    public:

        static
        enum appl_status
            s_create(
                struct appl_context * const
                    p_context,
                struct appl_bits_mem_descriptor const * const
                    p_descriptor,
                struct appl_bits_mem * * const
                    r_instance);

        static
        struct appl_bits *
            s_parent(
                struct appl_bits_mem * const
                    p_instance);

        static
        struct appl_bits const *
            s_const_parent(
                struct appl_bits_mem const * const
                    p_instance);

        static
        enum appl_status
            s_query(
                struct appl_bits_mem const * const
                    p_instance,
                struct appl_buf * const
                    r_buf_used,
                struct appl_buf * const
                    r_buf_unused);

}; // class appl_bits_mem_service

//
//
//
enum appl_status
    appl_bits_mem_service::s_create(
        struct appl_context * const
            p_context,
        struct appl_bits_mem_descriptor const * const
            p_descriptor,
        struct appl_bits_mem * * const
            r_instance)
{
    enum appl_status
        e_status;

    struct appl_bits_mem *
        p_bits_mem;

    e_status =
        appl_new(
            p_context,
            p_descriptor,
            &(
                p_bits_mem));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_instance) =
            p_bits_mem;
    }

    return
        e_status;

} // s_create()

//
//
//
struct appl_bits *
    appl_bits_mem_service::s_parent(
        struct appl_bits_mem * const
            p_instance)
{
    return
        p_instance;

} // s_parent()

//
//
//
struct appl_bits const *
    appl_bits_mem_service::s_const_parent(
        struct appl_bits_mem const * const
            p_instance)
{
    return
        p_instance;

} // s_const_parent()

//
//
//
enum appl_status
    appl_bits_mem_service::s_query(
        struct appl_bits_mem const * const
            p_instance,
        struct appl_buf * const
            r_buf_used,
        struct appl_buf * const
            r_buf_unused)
{
    enum appl_status
        e_status;

    e_status =
        p_instance->v_query(
            r_buf_used,
            r_buf_unused);

    return
        e_status;

} // s_query()

//
//
//
enum appl_status
    appl_bits_mem_create(
        struct appl_context * const
            p_context,
        struct appl_bits_mem_descriptor const * const
            p_descriptor,
        struct appl_bits_mem * * const
            r_instance)
{
    enum appl_status
        e_status;

    e_status =
        appl_bits_mem_service::s_create(
            p_context,
            p_descriptor,
            r_instance);

    return
        e_status;

} // appl_bits_mem_create()

//
//
//
struct appl_bits *
    appl_bits_mem_parent(
        struct appl_bits_mem * const
            p_instance)
{
    return
        appl_bits_mem_service::s_parent(
            p_instance);

} // appl_bits_mem_parent()

//
//
//
struct appl_bits const *
    appl_bits_mem_const_parent(
        struct appl_bits_mem const * const
            p_instance)
{
    return
        appl_bits_mem_service::s_const_parent(
            p_instance);

} // appl_bits_mem_const_parent()

//
//
//
enum appl_status
    appl_bits_mem_query(
        struct appl_bits_mem const * const
            p_instance,
        struct appl_buf * const
            r_buf_used,
        struct appl_buf * const
            r_buf_unused)
{
    enum appl_status
        e_status;

    e_status =
        appl_bits_mem_service::s_query(
            p_instance,
            r_buf_used,
            r_buf_unused);

    return
        e_status;

} // appl_bits_mem_query()

/* end-of-file: appl_bits_mem.cpp */
