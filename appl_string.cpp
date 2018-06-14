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
        appl_object::s_create(
            p_context,
            sizeof(
                struct appl_string)
            + i_alloc_len,
            (&
                appl_string::s_new),
            (&
                appl_string::init),
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
        struct appl_string_descriptor const * const
            p_string_descriptor)
{
    m_buf_min =
        reinterpret_cast<unsigned char *>(
            this + 1);

    m_buf_max =
        m_buf_min + p_string_descriptor->i_alloc_len;

    return
        appl_status_ok;

} // init()

//
//
//
enum appl_status
    appl_string::v_cleanup(void)
{
    return
        appl_status_ok;

} // v_cleanup()

/* end-of-file: appl_string.cpp */
