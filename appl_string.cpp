/* See LICENSE for license details */

/*

*/

#include <string.h>

#include "appl_status.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_buf.h"

#include "appl_string.h"

struct appl_string_descriptor
{
    struct appl_buf const *
        p_ref_buf;

    unsigned long int
        i_alloc_len;

}; /* struct appl_string_descriptor */

//
//
//
enum appl_status
    appl_string::s_create(
        class appl_context * const
            p_context,
        struct appl_buf const * const
            p_ref_buf,
        unsigned long int const
            i_alloc_len,
        class appl_string * * const
            r_string)
{
    enum appl_status
        e_status;

    struct appl_string_descriptor
        o_string_descriptor;

    o_string_descriptor.p_ref_buf =
        p_ref_buf;

    o_string_descriptor.i_alloc_len =
        i_alloc_len;

    e_status =
        appl_object::s_create(
            p_context,
            sizeof(
                class appl_string)
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
    appl_string::v_length(
        unsigned long int * const
            r_buf_len) const
{
    enum appl_status
        e_status;

    *(
        r_buf_len) =
        m_data_len;

    e_status =
        appl_status_ok;

    return
        e_status;

} // v_length()

//
//
//
enum appl_status
    appl_string::v_read(
        struct appl_buf * const
            p_buf) const
{
    enum appl_status
        e_status;

    if (
        m_data_len)
    {
        unsigned long int
            i_copy_len;

        i_copy_len =
            static_cast<unsigned long int>(
                p_buf->o_max.pc_uchar
                - p_buf->o_min.pc_uchar);

        if (
            i_copy_len > m_data_len)
        {
            i_copy_len =
                m_data_len;
        }

        memcpy(
            p_buf->o_min.p_uchar,
            m_buf,
            i_copy_len);

        p_buf->o_min.p_uchar +=
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

} // v_read()

//
//
//
enum appl_status
    appl_string::v_write(
        struct appl_buf * const
            p_buf)
{
    enum appl_status
        e_status;

    if (
        m_alloc_len > m_data_len)
    {
        unsigned long int
            i_copy_len;

        i_copy_len =
            static_cast<unsigned long int>(
                p_buf->o_max.pc_uchar
                - p_buf->o_min.pc_uchar);

        if (
            (
                m_data_len
                + i_copy_len)
            > m_alloc_len)
        {
            i_copy_len =
                static_cast<unsigned long int>(
                    m_alloc_len
                    - m_data_len);
        }

        memcpy(
            m_buf + m_data_len,
            p_buf->o_min.pc_uchar,
            i_copy_len);

        p_buf->o_min.pc_uchar +=
            i_copy_len;

        m_data_len +=
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
class appl_string const *
    appl_string::convert_const_handle(
        struct appl_string_handle const * const
            p_string_handle)
{
    return
        reinterpret_cast<class appl_string const *>(
            p_string_handle);

} // convert_const_handle()

//
//
//
class appl_string *
    appl_string::convert_handle(
        struct appl_string_handle * const
            p_string_handle)
{
    return
        reinterpret_cast<class appl_string *>(
            p_string_handle);

} // convert_handle()

//
//
//
struct appl_string_handle *
    appl_string::get_handle(void)
{
    return
        reinterpret_cast<struct appl_string_handle *>(
            this);

} // get_handle()

//
//
//
struct appl_string_handle const *
    appl_string::get_const_handle(void) const
{
    return
        reinterpret_cast<struct appl_string_handle const *>(
            this);

} // get_const_handle()

//
//
//
appl_string::appl_string() :
    appl_object(),
    m_buf(),
    m_data_len(),
    m_alloc_len()
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
        class appl_string;

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
        m_alloc_len =
            p_string_descriptor->i_alloc_len;

        m_buf =
            reinterpret_cast<unsigned char *>(
                this + 1);

        m_data_len =
            static_cast<unsigned long int>(
                p_string_descriptor->p_ref_buf->o_max.pc_uchar
                - p_string_descriptor->p_ref_buf->o_min.pc_uchar);

        if (
            m_data_len > m_alloc_len)
        {
            m_data_len =
                m_alloc_len;
        }

        memcpy(
            m_buf,
            p_string_descriptor->p_ref_buf->o_min.pc_void,
            m_data_len);
    }
    else
    {
        m_buf =
            p_string_descriptor->p_ref_buf->o_min.p_uchar;

        m_data_len =
            static_cast<unsigned long int>(
                p_string_descriptor->p_ref_buf->o_max.pc_uchar
                - p_string_descriptor->p_ref_buf->o_min.pc_uchar);

        m_alloc_len =
            0;
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
