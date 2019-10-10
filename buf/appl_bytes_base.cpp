/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_predefines.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <buf/appl_bytes.h>

#include <buf/appl_bytes_base.h>

#include <misc/appl_unused.h>

#include <buf/appl_buf.h>

#include <misc/appl_convert.h>

//
//
//
appl_bytes_base::appl_bytes_base(
    struct appl_context * const
        p_context) :
    appl_bytes(
        p_context)
{
}

//
//
//
appl_bytes_base::~appl_bytes_base()
{
}

//
//
//
enum appl_status
    appl_bytes_base::v_consume(
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
    appl_bytes_base::v_produce(
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

//
//
//
enum appl_status
    appl_bytes_base::v_write_raw(
        struct appl_buf const * const
            p_buf)
{
    enum appl_status
        e_status;

    struct appl_buf
        o_buf_iterator;

    e_status =
        appl_status_ok;

    o_buf_iterator =
        *(
            p_buf);

    while (
        (
            appl_status_ok
            == e_status)
        && (
            o_buf_iterator.o_min.pc_uchar
            < o_buf_iterator.o_max.pc_uchar))
    {
        unsigned char const
            i_value =
            *(
                o_buf_iterator.o_min.pc_uchar);

        o_buf_iterator.o_min.pc_uchar ++;

        e_status =
            v_produce(
                i_value);

    }

    return
        e_status;

} // v_write_raw()

//
//
//
enum appl_status
    appl_bytes_base::v_write_int(
        unsigned char const
            i_count,
        appl_ull_t const
            i_value)
{
    enum appl_status
        e_status;

    unsigned char
        i_iterator;

    i_iterator =
        i_count;

    e_status =
        appl_status_ok;

    while (
        (
            appl_status_ok
            == e_status)
        && i_iterator)
    {
        i_iterator --;

        unsigned char const
            i_digit =
            (
                (
                    i_value
                    >> (
                        i_iterator
                        * 8u))
                & 0xFFu);

        e_status =
            v_produce(
                i_digit);
    }

    return
        e_status;

} // v_write_int()

//
//
//
enum appl_status
    appl_bytes_base::v_write_int8(
        unsigned char const
            i_value)
{
    enum appl_status
        e_status;

    e_status =
        v_produce(
            i_value);

    return
        e_status;

} // v_write_int8()

//
//
//
enum appl_status
    appl_bytes_base::v_write_int16(
        unsigned short int const
            i_value)
{
    enum appl_status
        e_status;

    unsigned char const
        i_digit_high =
        appl_convert::to_uchar(
            (i_value >> 8u) & 0xFFu);

    e_status =
        v_produce(
            i_digit_high);

    if (
        appl_status_ok
        == e_status)
    {
        unsigned char const
            i_digit_low =
            appl_convert::to_uchar(
                (i_value >> 0u) & 0xFFu);

        e_status =
            v_produce(
                i_digit_low);
    }

    return
        e_status;

} // v_write_int16()

//
//
//
enum appl_status
    appl_bytes_base::v_write_int24(
        unsigned long int const
            i_value)
{
    enum appl_status
        e_status;

    unsigned char const
        i_digit_high =
        appl_convert::to_uchar(
            (i_value >> 16u) & 0xFFu);

    e_status =
        v_produce(
            i_digit_high);

    if (
        appl_status_ok
        == e_status)
    {
        unsigned char const
            i_digit_mid =
            appl_convert::to_uchar(
                (i_value >> 8u) & 0xFFu);

        e_status =
            v_produce(
                i_digit_mid);

        if (
            appl_status_ok
            == e_status)
        {
            unsigned char const
                i_digit_low =
                appl_convert::to_uchar(
                    (i_value >> 0u) & 0xFFu);

            e_status =
                v_produce(
                    i_digit_low);
        }
    }

    return
        e_status;

} // v_write_int24()

//
//
//
enum appl_status
    appl_bytes_base::v_write_int32(
        unsigned long int const
            i_value)
{
    enum appl_status
        e_status;

    unsigned char const
        i_digit_a =
        appl_convert::to_uchar(
            (i_value >> 24u) & 0xFFu);

    e_status =
        v_produce(
            i_digit_a);

    if (
        appl_status_ok
        == e_status)
    {
        unsigned char const
            i_digit_b =
            appl_convert::to_uchar(
                (i_value >> 16u) & 0xFFu);

        e_status =
            v_produce(
                i_digit_b);

        if (
            appl_status_ok
            == e_status)
        {
            unsigned char const
                i_digit_c =
                appl_convert::to_uchar(
                    (i_value >> 8u) & 0xFFu);

            e_status =
                v_produce(
                    i_digit_c);

            if (
                appl_status_ok
                == e_status)
            {
                unsigned char const
                    i_digit_d =
                    appl_convert::to_uchar(
                        (i_value >> 0u) & 0xFFu);

                e_status =
                    v_produce(
                        i_digit_d);
            }
        }
    }

    return
        e_status;

} // v_write_int32()

//
//
//
enum appl_status
    appl_bytes_base::v_write_int64(
        appl_ull_t const
            i_value)
{
    enum appl_status
        e_status;

    e_status =
        appl_bytes_base::v_write_int(
            8u,
            i_value);

#if 0
    unsigned long int const
        i_value_high =
        appl_convert::to_ulong(
            (i_value >> 32u) & 0xFFFFFFFFul);

    e_status =
        appl_bytes_base::v_write_int32(
            i_value_high);

    if (
        appl_status_ok
        == e_status)
    {
        unsigned long int const
            i_value_low =
            appl_convert::to_ulong(
                (i_value >> 0u) & 0xFFFFFFFFul);

        e_status =
            appl_bytes_base::v_write_int32(
                i_value_low);
    }
#endif

    return
        e_status;

} // v_write_int64()

//
//
//
enum appl_status
    appl_bytes_base::v_read_raw(
        struct appl_buf const * const
            p_buf)
{
    enum appl_status
        e_status;

    struct appl_buf
        o_buf_iterator;

    e_status =
        appl_status_ok;

    o_buf_iterator =
        *(
            p_buf);

    while (
        (
            appl_status_ok
            == e_status)
        && (
            o_buf_iterator.o_min.pc_uchar
            < o_buf_iterator.o_max.pc_uchar))
    {
        unsigned char
            i_digit;

        e_status =
            v_consume(
                &(
                    i_digit));

        if (
            appl_status_ok
            == e_status)
        {
            *(
                o_buf_iterator.o_min.p_uchar) =
                i_digit;

            o_buf_iterator.o_min.p_uchar ++;
        }
    }

    return
        e_status;

} // v_read_raw()

//
//
//
enum appl_status
    appl_bytes_base::v_read_int(
        unsigned char const
            i_count,
        appl_ull_t * const
            r_value)
{
    enum appl_status
        e_status;

    unsigned char
        i_iterator;

    appl_ull_t
        i_value;

    i_value =
        0u;

    i_iterator =
        i_count;

    e_status =
        appl_status_ok;

    while (
        (
            appl_status_ok
            == e_status)
        && i_iterator)
    {
        unsigned char
            i_digit;

        e_status =
            v_consume(
                &(
                    i_digit));

        if (
            appl_status_ok
            == e_status)
        {
            i_value =
                (
                    (
                        i_value
                        << 8u)
                    | i_digit);

            i_iterator --;
        }
    }

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_value) =
            i_value;
    }

    return
        e_status;

} // v_read_int()

//
//
//
enum appl_status
    appl_bytes_base::v_read_int8(
        unsigned char * const
            r_value)
{
    enum appl_status
        e_status;

    e_status =
        v_consume(
            r_value);

    return
        e_status;

} // v_read_int8()

//
//
//
enum appl_status
    appl_bytes_base::v_read_int16(
        unsigned short int * const
            r_value)
{
    enum appl_status
        e_status;

    unsigned char
        i_digit_high;

    e_status =
        v_consume(
            &(
                i_digit_high));

    if (
        appl_status_ok
        == e_status)
    {
        unsigned char
            i_digit_low;

        e_status =
            v_consume(
                &(
                    i_digit_low));

        if (
            appl_status_ok
            == e_status)
        {
            *(
                r_value) =
                appl_convert::to_ushort(
                    (
                        appl_convert::to_ushort(
                            i_digit_high)
                        << 8u)
                    | i_digit_low);
        }
    }

    return
        e_status;

} // v_read_int16()

//
//
//
enum appl_status
    appl_bytes_base::v_read_int24(
        unsigned long int * const
            r_value)
{
    enum appl_status
        e_status;

    unsigned char
        i_digit_high;

    e_status =
        v_consume(
            &(
                i_digit_high));

    if (
        appl_status_ok
        == e_status)
    {
        unsigned char
            i_digit_mid;

        e_status =
            v_consume(
                &(
                    i_digit_mid));

        if (
            appl_status_ok
            == e_status)
        {
            unsigned char
                i_digit_low;

            e_status =
                v_consume(
                    &(
                        i_digit_low));

            if (
                appl_status_ok
                == e_status)
            {
                *(
                    r_value) =
                    appl_convert::to_ulong(
                        (
                            appl_convert::to_ulong(
                                i_digit_high)
                            << 16u)
                        | (
                            appl_convert::to_ulong(
                                i_digit_mid)
                            << 8u)
                        | i_digit_low);
            }
        }
    }

    return
        e_status;

} // v_read_int24()

//
//
//
enum appl_status
    appl_bytes_base::v_read_int32(
        unsigned long int * const
            r_value)
{
    enum appl_status
        e_status;

    unsigned char
        i_digit_a;

    e_status =
        v_consume(
            &(
                i_digit_a));

    if (
        appl_status_ok
        == e_status)
    {
        unsigned char
            i_digit_b;

        e_status =
            v_consume(
                &(
                    i_digit_b));

        if (
            appl_status_ok
            == e_status)
        {
            unsigned char
                i_digit_c;

            e_status =
                v_consume(
                    &(
                        i_digit_c));

            if (
                appl_status_ok
                == e_status)
            {
                unsigned char
                    i_digit_d;

                e_status =
                    v_consume(
                        &(
                            i_digit_d));

                if (
                    appl_status_ok
                    == e_status)
                {
                *(
                    r_value) =
                    appl_convert::to_ulong(
                        (
                            appl_convert::to_ulong(
                                i_digit_a)
                            << 24u)
                        | (
                            appl_convert::to_ulong(
                                i_digit_b)
                            << 16u)
                        | (
                            appl_convert::to_ulong(
                                i_digit_c)
                            << 8u)
                        | i_digit_d);
                }
            }
        }
    }

    return
        e_status;

} // v_read_int32()

//
//
//
enum appl_status
    appl_bytes_base::v_read_int64(
        appl_ull_t * const
            r_value)
{
    enum appl_status
        e_status;

    e_status =
        appl_bytes_base::v_read_int(
            8u,
            r_value);

    return
        e_status;

} // v_read_int64()

/* end-of-file: appl_bytes_base.cpp */
