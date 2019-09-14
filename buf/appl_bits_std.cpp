/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <buf/appl_bits.h>

#include <buf/appl_bits_handle.h>

#include <buf/appl_bits_base.h>

#include <buf/appl_bits_std.h>

#include <appl_unused.h>

#include <appl_convert.h>

//
//
//
appl_bits_std::appl_bits_std(
    struct appl_context * const
        p_context) :
    appl_bits_base(
        p_context),
    m_descriptor(),
    b_descriptor()
{
}

//
//
//
appl_bits_std::~appl_bits_std()
{
}

//
//
//
enum appl_status
appl_bits_std::f_init(
    struct appl_bits_descriptor const * const
        p_descriptor)
{
    enum appl_status
        e_status;

    m_descriptor =
        *(
            p_descriptor);

    b_descriptor =
        1;

    e_status =
        appl_status_ok;

    return
        e_status;

} // f_init()

//
//
//
appl_size_t
appl_bits_std::v_cleanup(void)
{
    b_descriptor =
        0;

    return
        sizeof(class appl_bits_std);

} // v_cleanup()

//
//
//
enum appl_status
appl_bits_std::v_consume(
    unsigned char * const
        r_value)
{
    enum appl_status
        e_status;

    // Load bytes from input buffer
    if (
        b_descriptor)
    {
        e_status =
            (*(m_descriptor.p_callback_consume))(
                m_descriptor.p_callback_context,
                r_value);
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
appl_bits_std::v_produce(
    unsigned char const
        i_value)
{
    enum appl_status
        e_status;

    appl_unused(
        i_value);

    e_status =
        appl_raise_not_implemented();

    return
        e_status;

} // v_write()

/* end-of-file: appl_bits_std.cpp */
