/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_predefines.h>

#include <appl_types.h>

#include <appl_object.h>

#include <buf/appl_bits.h>

#include <buf/appl_bits_base.h>

#include <appl_unused.h>

#include <appl_convert.h>

//
//
//
appl_bits_base::appl_bits_base(
    struct appl_context * const
        p_context) :
    appl_bits(
        p_context),
    i_accum(),
    m_count()
{
}

//
//
//
appl_bits_base::~appl_bits_base()
{
}

//
//
//
enum appl_status
    appl_bits_base::v_read(
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
            v_consume(
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
        appl_status_ok
        == e_status)
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
    }

    return
        e_status;

} // v_read()

//
//
//
enum appl_status
    appl_bits_base::v_write(
        unsigned char const
            i_count,
        unsigned long int const
            i_value)
{
    enum appl_status
        e_status;

    unsigned long int const
        i_mask =
        (
            (
                1ul
                << i_count)
            - 1ul);

    i_accum <<=
        i_count;

    i_accum |=
        (
            i_value
            & i_mask);

    m_count =
        appl_convert::to_uchar(
            appl_convert::to_unsigned(
                m_count
                + i_count));

    e_status =
        appl_status_ok;

    while (
        (
            appl_status_ok
            == e_status)
        && (
            8u
            <= m_count))
    {
        m_count =
            appl_convert::to_uchar(
                m_count
                - 8u);

        unsigned char const
            i_produce_value =
            (
                (
                    i_accum
                    >> m_count)
                & 0xFFu);

        e_status =
            v_produce(
                i_produce_value);
    }

    return
        e_status;

} // v_write()

//
//
//
enum appl_status
    appl_bits_base::v_consume(
        unsigned char * const
            r_value)
{
    enum appl_status
        e_status;

    appl_unused(
        r_value);

    e_status =
        appl_raise_not_implemented();

    return
        e_status;

} // v_consume()

//
//
//
enum appl_status
    appl_bits_base::v_produce(
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

} // v_produce()

/* end-of-file: appl_bits_base.cpp */
