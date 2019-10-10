/* See LICENSE for license details */

/*

*/

#include <buf/appl_buf_iterator.h>

#include <buf/appl_buf.h>

#include <misc/appl_unused.h>

#include <string.h>

//
//
//
char
appl_buf_iterator_write(
    struct appl_buf * const
        p_buf_iterator,
    unsigned char const
        c_value)
{
    char
        b_result;

    if (
        p_buf_iterator->o_min.p_uchar
        < p_buf_iterator->o_max.p_uchar)
    {
        *(
            p_buf_iterator->o_min.p_uchar) =
            c_value;

        p_buf_iterator->o_min.p_uchar ++;

        b_result =
            1;
    }
    else
    {
        b_result =
            0;
    }

    return
        b_result;

} // appl_buf_iterator_write()

//
//
//
char
appl_buf_iterator_read(
    struct appl_buf * const
        p_buf_iterator,
    unsigned char * const
        r_value)
{
    char
        b_result;

    if (
        p_buf_iterator->o_min.p_uchar
        < p_buf_iterator->o_max.p_uchar)
    {
        *(
            r_value) =
            *(
                p_buf_iterator->o_min.p_uchar);

        p_buf_iterator->o_min.p_uchar ++;

        b_result =
            1;
    }
    else
    {
        b_result =
            0;
    }

    return
        b_result;

} // appl_buf_iterator_read()

//
//
//
char
appl_buf_iterator_copy(
    struct appl_buf * const
        p_buf_iterator,
    struct appl_buf * const
        p_buf_source)
{
    char
        b_result;

    unsigned long int
        i_copy_length;

    i_copy_length =
        appl_buf_len(
            p_buf_source->o_min.pc_uchar,
            p_buf_source->o_max.pc_uchar);

    if (
        (p_buf_iterator->o_min.p_uchar + i_copy_length)
        <= p_buf_iterator->o_max.p_uchar)
    {
        memcpy(
            p_buf_iterator->o_min.p_uchar,
            p_buf_source->o_min.pc_uchar,
            i_copy_length);

        p_buf_iterator->o_min.p_uchar +=
            i_copy_length;

        p_buf_source->o_min.p_uchar +=
            i_copy_length;

        b_result =
            1;
    }
    else
    {
        b_result =
            0;
    }

    return
        b_result;

}

char
appl_buf_iterator_copy_n(
    struct appl_buf * const
        p_buf_iterator,
    struct appl_buf * const
        p_buf_source,
    unsigned long int const
        i_count)
{
    char
        b_result;

    unsigned long int
        i_copy_length;

    i_copy_length =
        appl_buf_len(
            p_buf_source->o_min.pc_uchar,
            p_buf_source->o_max.pc_uchar);

    if (
        i_copy_length
        > i_count)
    {
        i_copy_length =
            i_count;
    }

    if (
        (p_buf_iterator->o_min.p_uchar + i_copy_length)
        <= p_buf_iterator->o_max.p_uchar)
    {
        memcpy(
            p_buf_iterator->o_min.p_uchar,
            p_buf_source->o_min.pc_uchar,
            i_copy_length);

        p_buf_iterator->o_min.p_uchar +=
            i_copy_length;

        p_buf_source->o_min.p_uchar +=
            i_copy_length;

        b_result =
            1;
    }
    else
    {
        b_result =
            0;
    }

    return
        b_result;

}

char
appl_buf_iterator_zero(
    struct appl_buf * const
        p_buf_iterator)
{
    char
        b_result;

    unsigned long int
        i_length;

    i_length =
        appl_buf_len(
            p_buf_iterator->o_min.pc_uchar,
            p_buf_iterator->o_max.pc_uchar);

    if (
        i_length)
    {
        memset(
            p_buf_iterator->o_min.p_uchar,
            0u,
            i_length);

        p_buf_iterator->o_min.p_uchar +=
            i_length;
    }

    b_result =
        1;

    return
        b_result;

}

char
appl_buf_iterator_zero_n(
    struct appl_buf * const
        p_buf_iterator,
    unsigned long int const
        i_count)
{
    char
        b_result;

    unsigned long int
        i_length;

    i_length =
        appl_buf_len(
            p_buf_iterator->o_min.pc_uchar,
            p_buf_iterator->o_max.pc_uchar);

    if (
        i_length
        > i_count)
    {
        i_length =
            i_count;
    }

    if (
        i_length)
    {
        memset(
            p_buf_iterator->o_min.p_uchar,
            0u,
            i_length);

        p_buf_iterator->o_min.p_uchar +=
            i_length;
    }

    b_result =
        1;

    return
        b_result;

}

char
appl_buf_iterator_fill(
    struct appl_buf * const
        p_buf_iterator,
    unsigned char const
        c_value)
{
    char
        b_result;

    unsigned long int
        i_length;

    i_length =
        appl_buf_len(
            p_buf_iterator->o_min.pc_uchar,
            p_buf_iterator->o_max.pc_uchar);

    if (
        i_length)
    {
        memset(
            p_buf_iterator->o_min.p_uchar,
            c_value,
            i_length);

        p_buf_iterator->o_min.p_uchar +=
            i_length;
    }

    b_result =
        1;

    return
        b_result;

}

char
appl_buf_iterator_fill_n(
    struct appl_buf * const
        p_buf_iterator,
    unsigned char const
        c_value,
    unsigned long int const
        i_count)
{
    char
        b_result;

    unsigned long int
        i_length;

    i_length =
        appl_buf_len(
            p_buf_iterator->o_min.pc_uchar,
            p_buf_iterator->o_max.pc_uchar);

    if (
        i_length
        > i_count)
    {
        i_length =
            i_count;
    }

    if (
        i_length)
    {
        memset(
            p_buf_iterator->o_min.p_uchar,
            c_value,
            i_length);

        p_buf_iterator->o_min.p_uchar +=
            i_length;
    }

    b_result =
        1;

    return
        b_result;

}

char
appl_buf_iterator_print_number(
    struct appl_buf * const
        p_buf_iterator,
    signed long int const
        i_number,
    int const
        i_flags,
    unsigned int const
        i_width)
{
    char
        b_result;

    p_buf_iterator->o_min.p_uchar =
        appl_buf_print_number(
            p_buf_iterator->o_min.p_uchar,
            p_buf_iterator->o_max.p_uchar,
            i_number,
            i_flags,
            i_width);

    b_result =
        1;

    return
        b_result;

}

char
appl_buf_iterator_scan_number(
    struct appl_buf * const
        p_buf_iterator,
    signed long int * const
        r_value,
    int const
        i_flags)
{
    char
        b_result;

    p_buf_iterator->o_min.pc_uchar =
        appl_buf_scan_number(
            p_buf_iterator->o_min.pc_uchar,
            p_buf_iterator->o_max.pc_uchar,
            r_value,
            i_flags);

    b_result =
        1;

    return
        b_result;

}

/* end-of-file: appl_buf_iterator.cpp */
