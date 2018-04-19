/* See LICENSE for license details */

/*

*/

#include <string.h>

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_buf.h>

#include <appl_string.h>

struct appl_string_descriptor
{
    unsigned char const *
        p_buf_min;

    unsigned char const *
        p_buf_cur;

    unsigned char const *
        p_buf_max;

    unsigned long int
        i_alloc_len;

    unsigned long int
        ul_padding[1u];

}; /* struct appl_string_descriptor */

//
//
//
enum appl_status
    appl_string::s_create(
        struct appl_context * const
            p_context,
        unsigned char const * const
            p_buf_min,
        unsigned char const * const
            p_buf_cur,
        unsigned char const * const
            p_buf_max,
        unsigned long int const
            i_alloc_len,
        struct appl_string * * const
            r_string)
{
    enum appl_status
        e_status;

    struct appl_string_descriptor
        o_string_descriptor;

    o_string_descriptor.p_buf_min =
        p_buf_min;

    o_string_descriptor.p_buf_cur =
        p_buf_cur;

    o_string_descriptor.p_buf_max =
        p_buf_max;

    o_string_descriptor.i_alloc_len =
        i_alloc_len;

    e_status =
        appl_object::s_create(
            p_context,
            sizeof(
                struct appl_string)
            + i_alloc_len,
            &(
                appl_string::s_new),
            &(
                o_string_descriptor),
            r_string);

    return
        e_status;

} // s_create()

//
//
//
enum appl_status
    appl_string::v_read(
        unsigned char const * * const
            r_buf_min,
        unsigned char const * * const
            r_buf_max) const
{
    enum appl_status
        e_status;

    *(
        r_buf_min) =
        m_buf_min;

    *(
        r_buf_max) =
        m_buf_cur;

    e_status =
        appl_status_ok;

    return
        e_status;

} // v_read()

//
//
//
enum appl_status
    appl_string::v_write(
        unsigned char const * const
            p_buf_min,
        unsigned char const * const
            p_buf_max)
{
    enum appl_status
        e_status;

    if (
        m_buf_max > m_buf_cur)
    {
        unsigned long int
            i_copy_len;

        i_copy_len =
            static_cast<unsigned long int>(
                p_buf_max
                - p_buf_min);

        if (
            (
                m_buf_cur
                + i_copy_len)
            > m_buf_max)
        {
            i_copy_len =
                static_cast<unsigned long int>(
                    m_buf_max
                    - m_buf_cur);
        }

        memcpy(
            m_buf_cur,
            p_buf_min,
            i_copy_len);

        m_buf_cur +=
            i_copy_len;

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

} // v_write()

//
//
//
appl_string::appl_string() :
    appl_object(),
    m_buf_min(),
    m_buf_cur(),
    m_buf_max()
{
}

//
//
//
appl_string::~appl_string()
{
}

//
//
//
void
    appl_string::s_new(
        void * const
            p_placement)
{
    new (p_placement)
        struct appl_string;

} // s_new()

//
//
//
enum appl_status
    appl_string::init(
        void const * const
            p_descriptor)
{
    struct appl_string_descriptor const * const
        p_string_descriptor =
        static_cast<struct appl_string_descriptor const *>(
            p_descriptor);

    if (
        p_string_descriptor->i_alloc_len)
    {
        m_buf_min =
        m_buf_cur =
            reinterpret_cast<unsigned char *>(
                this + 1);

        m_buf_max =
            m_buf_min + p_string_descriptor->i_alloc_len;
    }
    else
    {
        m_buf_min =
            const_cast<unsigned char *>(
                p_string_descriptor->p_buf_min);

        m_buf_cur =
            const_cast<unsigned char *>(
                p_string_descriptor->p_buf_cur);

        m_buf_max =
            const_cast<unsigned char *>(
                p_string_descriptor->p_buf_max);
    }

    return
        appl_status_ok;

} // init()

//
//
//
enum appl_status
    appl_string::cleanup(void)
{
    return
        appl_status_ok;

} // cleanup()

/* end-of-file: appl_string.cpp */
