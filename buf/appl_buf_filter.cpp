/* See LICENSE for license details */

/*

*/

#include <buf/appl_buf_filter.h>

#include <buf/appl_buf.h>

#include <misc/appl_convert.h>

//
//
//
char
appl_buf_filter_test(
    struct appl_buf const * const
        p_buf_filter,
    unsigned char const
        c_data)
{
    char
        b_result;

    unsigned char const
        i_offset =
        p_buf_filter->o_min.pc_uchar[0u];

    unsigned char const
        c_index =
        appl_convert::to_uchar(
            appl_convert::to_unsigned(
                c_data
                - i_offset));

    unsigned char const
        c_byte_index =
        appl_convert::to_uchar(
            appl_convert::to_unsigned(
                c_index
                >> 3u));

    unsigned char const * const
        p_filter_byte =
        p_buf_filter->o_min.pc_uchar
        + c_byte_index
        + 1u;

    if (
        p_filter_byte
        < p_buf_filter->o_max.pc_uchar)
    {
        unsigned char const
            c_filter_byte =
            *(
                p_filter_byte);

        unsigned char const
            c_bit_index =
            (
                c_index
                & 0x07u);

        unsigned char const
            c_bit_mask =
            appl_convert::to_uchar(
                1u
                << c_bit_index);

        b_result =
               (
                   0 != (
                       c_filter_byte
                       & c_bit_mask));
    }
    else
    {
        b_result =
            0;
    }

    return
        b_result;

} // appl_buf_filter_test()

//
//
//
unsigned long int
appl_buf_filter_get_list_length(
    struct appl_buf const * const
        p_input)
{
    unsigned long int
        i_length;

    unsigned char const
        c_input_min =
        appl_buf_min_value(
            p_input->o_min.pc_uchar,
            p_input->o_max.pc_uchar);

    unsigned char const
        c_input_max =
        appl_buf_max_value(
            p_input->o_min.pc_uchar,
            p_input->o_max.pc_uchar);

    i_length =
        1ul
        + (
            (
                c_input_max
                - c_input_min
                + 8ul)
            / 8ul);

    return
        i_length;

} // appl_buf_filter_get_list_length()

static
void
appl_buf_filter_write(
    struct appl_buf * const
        p_buf_filter,
    unsigned char const
        c_data)
{
    unsigned char const
        c_index =
        appl_convert::to_uchar(
            appl_convert::to_unsigned(
                c_data
                - p_buf_filter->o_min.pc_uchar[0u]));

    unsigned char const
        c_byte_index =
        appl_convert::to_uchar(
            appl_convert::to_unsigned(
                c_index
                >> 3u));

    unsigned char * const
        p_filter_byte =
        p_buf_filter->o_min.p_uchar
        + c_byte_index
        + 1u;

    if (
        p_filter_byte
        < p_buf_filter->o_max.p_uchar)
    {
        unsigned char const
            c_bit_index =
            (
                c_index
                & 0x07u);

        unsigned char const
            c_bit_mask =
            appl_convert::to_uchar(
                1u
                << c_bit_index);

        *(
            p_filter_byte) |=
            c_bit_mask;
    }

}

//
//
//
void
appl_buf_filter_convert_list(
    struct appl_buf * const
        p_buf_filter,
    struct appl_buf const * const
        p_input)
{
    unsigned char const
        c_input_min =
        appl_buf_min_value(
            p_input->o_min.pc_uchar,
            p_input->o_max.pc_uchar);

    p_buf_filter->o_min.p_uchar[0u] =
        c_input_min;

    appl_buf_fill(
        p_buf_filter->o_min.p_uchar + 1u,
        p_buf_filter->o_max.p_uchar,
        0u);

    unsigned char const *
        p_input_iterator;

    p_input_iterator =
        p_input->o_min.pc_uchar;

    while (
        p_input_iterator
        < p_input->o_max.pc_uchar)
    {
        unsigned char const
            c_data =
            *(
                p_input_iterator);

        p_input_iterator ++;

        appl_buf_filter_write(
            p_buf_filter,
            c_data);
    }

} // appl_buf_filter_convert_list()

static
bool
    appl_buf_class_read_value(
        struct appl_buf * const
            p_buf_class,
        unsigned char * const
            r_value)
{
    bool
        b_result;

    if (
        p_buf_class->o_min.pc_uchar
        < p_buf_class->o_max.pc_uchar)
    {
        *(
            r_value) =
            p_buf_class->o_min.pc_uchar[0u];

        p_buf_class->o_min.pc_uchar ++;

        b_result =
            true;
    }
    else
    {
        b_result =
            false;
    }

    return
        b_result;

}

struct appl_buf_class_range
{
    unsigned char
        c_range_start;

    unsigned char
        c_range_end;

};

static
void
    appl_buf_class_sort_range(
        struct appl_buf_class_range * const
            p_range)
{
    if (
        p_range->c_range_start
        > p_range->c_range_end)
    {
        unsigned char
            c_range_min;

        unsigned char
            c_range_max;

        c_range_min =
            p_range->c_range_end;

        c_range_max =
            p_range->c_range_start;

        p_range->c_range_start =
            c_range_min;

        p_range->c_range_end =
            c_range_max;
    }

}

static
bool
    appl_buf_class_read_range(
        struct appl_buf * const
            p_buf_class,
        struct appl_buf_class_range * const
            p_range)
{
    bool
        b_result;

    b_result =
        appl_buf_class_read_value(
            p_buf_class,
            &(
                p_range->c_range_start));

    if (
        b_result)
    {
        if (
            (
                p_buf_class->o_min.pc_uchar
                < p_buf_class->o_max.pc_uchar)
            && (
                '-'
                == p_buf_class->o_min.pc_uchar[0u]))
        {
            p_buf_class->o_min.pc_uchar ++;

            if (
                appl_buf_class_read_value(
                    p_buf_class,
                    &(
                        p_range->c_range_end)))
            {
            }
            else
            {
                p_range->c_range_end =
                    p_range->c_range_start;
            }
        }
        else
        {
            p_range->c_range_end =
                p_range->c_range_start;
        }

        appl_buf_class_sort_range(
            p_range);
    }

    return
        b_result;

} // appl_buf_class_read_range()

//
//
//
static
void
    appl_buf_class_parser(
        struct appl_buf * const
            p_buf_class,
        void (* p_callback)(
            void * const
                p_refdata,
            struct appl_buf_class_range const * const
                p_range),
        void * const
            p_refdata)
{
    struct appl_buf_class_range
        o_buf_class_range;

    while (
        appl_buf_class_read_range(
            p_buf_class,
            &(
                o_buf_class_range)))
    {
        (*p_callback)(
            p_refdata,
            &(
                o_buf_class_range));
    }

} // appl_buf_class_parser()

union appl_buf_class_range_ptr
{
    void *
        p_refdata;

    struct appl_buf_class_range *
        p_min_max;

};

static
void
    appl_buf_class_get_min_max_worker(
        void * const
            p_refdata,
        struct appl_buf_class_range const * const
            p_range)
{
    union appl_buf_class_range_ptr
        o_range_ptr;

    o_range_ptr.p_refdata =
        p_refdata;

    struct appl_buf_class_range * const
        p_min_max =
        o_range_ptr.p_min_max;

    if (
        p_min_max->c_range_start
        > p_range->c_range_start)
    {
        p_min_max->c_range_start =
            p_range->c_range_start;
    }

    if (
        p_min_max->c_range_end
        < p_range->c_range_end)
    {
        p_min_max->c_range_end =
            p_range->c_range_end;
    }
}

//
//
//
static
bool
    appl_buf_class_get_min_max(
        struct appl_buf * const
            p_buf_class,
        struct appl_buf_class_range * const
            p_min_max)
{
    bool
        b_result;

    p_min_max->c_range_start =
        255u;

    p_min_max->c_range_end =
        0u;

    appl_buf_class_parser(
        p_buf_class,
        &(
            appl_buf_class_get_min_max_worker),
        p_min_max);

    b_result =
        (
            p_min_max->c_range_end
            >= p_min_max->c_range_start);

    return
        b_result;

} // appl_buf_class_min_value()

//
//
//
unsigned long int
    appl_buf_filter_get_class_length(
        struct appl_buf const * const
            p_input_class)
{
    unsigned long int
        i_length;

    struct appl_buf
        o_buf_class;

    o_buf_class =
        *(
            p_input_class);

    struct appl_buf_class_range
        o_min_max;

    if (
        appl_buf_class_get_min_max(
            &(
                o_buf_class),
            &(
                o_min_max)))
    {
        i_length =
            1ul
            + (
                (
                    o_min_max.c_range_end
                    - o_min_max.c_range_start
                    + 8ul)
                / 8ul);
    }
    else
    {
        i_length =
            0ul;
    }

    return
        i_length;

} // appl_buf_filter_get_class_length()

//
//
//
static
void
    appl_buf_filter_convert_class_worker(
        void * const
            p_refdata,
        struct appl_buf_class_range const * const
            p_range)
{
    union appl_buf_ptr
        o_buf_ptr;

    o_buf_ptr.p_void =
        p_refdata;

    struct appl_buf * const
        p_buf_filter =
        o_buf_ptr.p_buf;

    unsigned char
        c_range_it;

    c_range_it =
        p_range->c_range_start;

    while (
        c_range_it
        <= p_range->c_range_end)
    {
        appl_buf_filter_write(
            p_buf_filter,
            c_range_it);

        c_range_it ++;
    }

} // appl_buf_filter_convert_class_worker()

//
//
//
void
appl_buf_filter_convert_class(
    struct appl_buf * const
        p_buf_filter,
    struct appl_buf const * const
        p_input_class)
{
    struct appl_buf
        o_buf_class;

    o_buf_class =
        *(
            p_input_class);

    struct appl_buf_class_range
        o_min_max;

    if (
        appl_buf_class_get_min_max(
            &(
                o_buf_class),
            &(
                o_min_max)))
    {
        p_buf_filter->o_min.p_uchar[0u] =
            o_min_max.c_range_start;

        appl_buf_fill(
            p_buf_filter->o_min.p_uchar + 1u,
            p_buf_filter->o_max.p_uchar,
            0u);

        o_buf_class =
            *(
                p_input_class);

        appl_buf_class_parser(
            &(
                o_buf_class),
            &(
                appl_buf_filter_convert_class_worker),
            p_buf_filter);
    }

} // appl_buf_filter_convert_class()

/* end-of-file: appl_buf_filter.cpp */
