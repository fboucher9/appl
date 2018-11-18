/* See LICENSE for license details */

/*

*/

#include <string.h>

#include <appl_status.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <appl_buf.h>

#include <string/appl_string.h>

#include <allocator/appl_allocator.h>

#include <context/appl_context.h>

#include <heap/appl_heap.h>

struct appl_string_descriptor
{
    unsigned long int
        i_alloc_len;

#define PADDING (APPL_SIZEOF_LONG)
#include <appl_padding.h>

}; /* struct appl_string_descriptor */

//
//
//
enum appl_status
    appl_string::s_create(
        struct appl_allocator * const
            p_allocator,
        unsigned long int const
            i_alloc_len,
        struct appl_string * * const
            r_string)
{
    enum appl_status
        e_status;

    struct appl_string_descriptor
        o_string_descriptor;

    o_string_descriptor.i_alloc_len =
        i_alloc_len;

    e_status =
        p_allocator->alloc_object(
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
            r_length) const
{
    *(
        r_length) =
        appl_buf_len(
            m_buf_min,
            m_buf_max);

    return
        appl_status_ok;

} // v_length()

//
//
//
enum appl_status
    appl_string::v_get(
        unsigned char * * const
            r_buf_min,
        unsigned char * * const
            r_buf_max) const
{
    enum appl_status
        e_status;

    *(
        r_buf_min) =
        m_buf_min;

    *(
        r_buf_max) =
        m_buf_max;

    e_status =
        appl_status_ok;

    return
        e_status;

} // v_get()

//
//
//
appl_string::appl_string() :
    appl_object(),
    m_buf_min(),
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
enum appl_status
    appl_string::f_init(
        struct appl_string_descriptor const * const
            p_string_descriptor)
{
    enum appl_status
        e_status;

    union appl_ptr
        o_buf_ptr;

    e_status =
        m_context->m_heap->v_alloc(
            p_string_descriptor->i_alloc_len,
            &(
                o_buf_ptr.p_void));

    if (
        appl_status_ok
        == e_status)
    {
        m_buf_min =
            o_buf_ptr.p_uchar;

        m_buf_max =
            o_buf_ptr.p_uchar + p_string_descriptor->i_alloc_len;
    }

    return
        e_status;

} // f_init()

//
//
//
enum appl_status
    appl_string::v_cleanup(void)
{
    enum appl_status
        e_status;

    union appl_ptr
        o_buf_ptr;

    o_buf_ptr.p_uchar =
        m_buf_min;

    m_context->m_heap->v_free(
        appl_buf_len(
            m_buf_min,
            m_buf_max),
        o_buf_ptr.p_void);

    e_status =
        appl_status_ok;

    return
        e_status;

} // v_cleanup()

/* end-of-file: appl_string.cpp */
