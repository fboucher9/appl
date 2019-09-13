/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <buf/appl_bits.h>

#include <buf/appl_bits_handle.h>

#include <buf/appl_bits_std.h>

#include <appl_unused.h>

#include <appl_convert.h>

//
//
//
appl_bits_std::appl_bits_std(
    struct appl_context * const
        p_context) :
    appl_bits(
        p_context),
    m_descriptor(),
    i_accum(),
    m_count(),
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

    i_accum =
        0ul;

    m_count =
        0u;

    b_descriptor =
        1;

    e_status =
        appl_status_ok;

    return
        e_status;

} // appl_bits_init()

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
appl_bits_std::v_read(
    unsigned char const
        i_count,
    unsigned long int * const
        r_value)
{
    enum appl_status
        e_status;

    e_status =
        appl_status_ok;

    // Load bytes from input buffer until accumulator has enough bits
    while (
        (
            appl_status_ok
            == e_status)
        && (
            m_count
            < i_count))
    {
        unsigned char
            i_value;

        e_status =
            (*(m_descriptor.p_callback_consume))(
                m_descriptor.p_callback_context,
                &(
                    i_value));

        if (
            appl_status_ok
            == e_status)
        {
            i_accum <<= 8u;

            i_accum |=
                i_value;

            m_count =
                appl_convert::to_uchar(
                    m_count
                    + 8u);
        }
    }

    // Get most significant bits from accumulator
    if (
        m_count
        >= i_count)
    {
        unsigned long int const
            i_mask =
            (
                (
                    1ul
                    << i_count)
                - 1ul);

        m_count =
            appl_convert::to_uchar(
                appl_convert::to_unsigned(
                    m_count
                    - i_count));

        appl_ull_t const
            i_value =
            (
                (
                    i_accum
                    >> m_count)
                & i_mask);

        *(
            r_value) =
            appl_convert::to_ulong(
                i_value);

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
appl_bits_std::v_write(
    unsigned char const
        i_count,
    unsigned long int const
        i_value)
{
    enum appl_status
        e_status;

    appl_unused(
        i_count,
        i_value);

    e_status =
        appl_status_fail;

    return
        e_status;

} // v_write()

