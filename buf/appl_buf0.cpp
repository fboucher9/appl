/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_predefines.h>

#include <buf/appl_buf0.h>

#include <appl_types.h>

#include <heap/appl_heap_handle.h>

#include <buf/appl_buf.h>

#include <misc/appl_convert.h>

#include <object/appl_object.h>

/*

*/
struct appl_buf0_descriptor
{
    struct appl_buf
        o_reference_buffer;

}; /* struct appl_buf0_descriptor */

//
//
//
struct appl_buf0 : public appl_object
{
    public:

        appl_buf0(
            struct appl_context * const
                p_context);

        virtual
        ~appl_buf0();

        enum appl_status
            f_init(
                struct appl_buf0_descriptor const * const
                    p_descriptor);

        virtual
        appl_size_t
            v_cleanup(void);

        unsigned char const *
            f_get(void) const;

    protected:

        struct appl_buf
            m_buf;

        // --

        bool
            m_allocated;

#define PADDING (1)
#include <misc/appl_padding.h>

    private:

        appl_buf0(
            struct appl_buf0 const & r);

        struct appl_buf0 &
            operator =(
                struct appl_buf0 const & r);

}; // struct appl_buf0

//
//
//
appl_buf0::appl_buf0(
    struct appl_context * const
        p_context) :
    appl_object(
        p_context),
    m_buf(),
    m_allocated(false)
{
}

//
//
//
appl_buf0::~appl_buf0()
{
}

//
//
//
enum appl_status
    appl_buf0::f_init(
        struct appl_buf0_descriptor const * const
            p_descriptor)
{
    enum appl_status
        e_status;

    unsigned long int const
        i_buf_len =
        appl_buf_len(
            p_descriptor->o_reference_buffer.o_min.pc_uchar,
            p_descriptor->o_reference_buffer.o_max.pc_uchar);

    e_status =
        appl_heap_alloc(
            m_context,
            i_buf_len + 1u,
            &(
                m_buf.o_min.p_void));

    if (
        appl_status_ok
        == e_status)
    {
        m_buf.o_max.pc_uchar =
            m_buf.o_min.pc_uchar
            + i_buf_len
            + 1u;

        appl_buf_copy(
            m_buf.o_min.p_uchar,
            m_buf.o_max.p_uchar,
            p_descriptor->o_reference_buffer.o_min.pc_uchar,
            p_descriptor->o_reference_buffer.o_max.pc_uchar);

        m_buf.o_min.p_uchar[i_buf_len] =
            0;

        m_allocated =
            true;
    }

    return
        e_status;

} // f_init()

//
//
//
appl_size_t
    appl_buf0::v_cleanup(void)
{
    if (
        m_allocated)
    {
        appl_heap_free(
            m_context,
            appl_buf_len(
                m_buf.o_min.pc_uchar,
                m_buf.o_max.pc_uchar),
            m_buf.o_min.p_void);

        m_allocated =
            false;
    }

    return
        sizeof(
            struct appl_buf0);

} // v_cleanup()

//
//
//
unsigned char const *
    appl_buf0::f_get(void) const
{
    return
        m_buf.o_min.pc_uchar;

} // f_get()

//
//
//
class appl_buf0_service
{
    public:

        static
        enum appl_status
            s_create(
                struct appl_context * const
                    p_context,
                struct appl_buf0_descriptor const * const
                    p_descriptor,
                struct appl_buf0 * * const
                    r_instance);

        static
        enum appl_status
            s_destroy(
                struct appl_buf0 * const
                    p_instance);

        static
        unsigned char const *
            s_get(
                struct appl_buf0 const * const
                    p_instance);

}; // class appl_buf0_service

//
//
//
enum appl_status
    appl_buf0_service::s_create(
        struct appl_context * const
            p_context,
        struct appl_buf0_descriptor const * const
            p_descriptor,
        struct appl_buf0 * * const
            r_instance)
{
    enum appl_status
        e_status;

    e_status =
        appl_new(
            p_context,
            p_descriptor,
            r_instance);

    return
        e_status;

} // s_create()

//
//
//
enum appl_status
    appl_buf0_service::s_destroy(
        struct appl_buf0 * const
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
unsigned char const *
    appl_buf0_service::s_get(
        struct appl_buf0 const * const
            p_instance)
{
    return
        p_instance->f_get();

} // s_get()

/*

*/
enum appl_status
appl_buf0_create(
    struct appl_context * const
        p_context,
    unsigned char const * const
        p_buf_min,
    unsigned char const * const
        p_buf_max,
    struct appl_buf0 * * const
        r_buf0)
{
    struct appl_buf0_descriptor
        o_descriptor;

    o_descriptor.o_reference_buffer.o_min.pc_uchar =
        p_buf_min;

    o_descriptor.o_reference_buffer.o_max.pc_uchar =
        p_buf_max;

    return
        appl_buf0_service::s_create(
            p_context,
            &(
                o_descriptor),
            r_buf0);

} /* create() */

/*

*/
enum appl_status
appl_buf0_destroy(
    struct appl_buf0 * const
        p_instance)
{
    return
        appl_buf0_service::s_destroy(
            p_instance);

} /* destroy() */

/*

*/
unsigned char const *
appl_buf0_get(
    struct appl_buf0 const * const
        p_instance)
{
    return
        appl_buf0_service::s_get(
            p_instance);

} /* get() */

/* buf length */
unsigned long int
appl_buf0_len(
    unsigned char const * const
        p_buf_0)
{
    unsigned char const *
        p_buf_it =
        p_buf_0;

    while (*(p_buf_it))
    {
        p_buf_it ++;
    }

    return
        appl_convert::to_ulong(
            appl_convert::to_unsigned(
                p_buf_it
                - p_buf_0));

} /* len() */

/* end-of-file: appl_buf0.cpp */
