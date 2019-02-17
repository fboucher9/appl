/* See LICENSE for license details */

/*

*/

struct appl_buf_filter
{
    unsigned char const *
        p_array_min;

    unsigned char const *
        p_array_max;

}; /* struct appl_buf_filter */

void
appl_buf_filter_init(
    struct appl_buf_filter * const
        p_buf_filter,
    unsigned char const * const
        p_array_min,
    unsigned char const * const
        p_array_max);

char
appl_buf_filter_test(
    struct appl_buf_filter const * const
        p_buf_filter,
    unsigned char const
        c_data);

struct appl_buf_reader
{
    unsigned char const *
        p_cur;

    unsigned char const *
        p_end;

}; /* struct appl_buf_reader */

void
appl_buf_reader_init(
    struct appl_buf_reader * const
        p_buf_reader,
    unsigned char const * const
        p_buf_min,
    unsigned char const * const
        p_buf_max);

char
appl_buf_reader_step(
    struct appl_buf_reader * const
        p_buf_reader,
    unsigned char * const
        r_data);

char
appl_buf_reader_find(
    struct appl_buf_reader * const
        p_buf_reader,
    unsigned char const
        c_data);

char
appl_buf_reader_find_n(
    struct appl_buf_reader * const
        p_buf_reader,
    unsigned char const
        c_data,
    unsigned long int const
        i_count);

char
appl_buf_reader_filter(
    struct appl_buf_reader * const
        p_buf_reader,
    unsigned char const * const
        p_filter_min,
    unsigned char const * const
        p_filter_max);

char
appl_buf_reader_filter_n(
    struct appl_buf_reader * const
        p_buf_reader,
    unsigned char const * const
        p_filter_min,
    unsigned char const * const
        p_filter_max,
    unsigned long int const
        i_count);

struct appl_buf_writer
{
    unsigned char *
        p_cur;

    unsigned char *
        p_end;

}; /* struct appl_buf_writer */

void
appl_buf_writer_init(
    struct appl_buf_writer * const
        p_buf_writer,
    unsigned char * const
        p_buf_min,
    unsigned char * const
        p_buf_max);

char
appl_buf_writer_step(
    struct appl_buf_writer * const
        p_buf_writer,
    unsigned char const
        c_data);

char
appl_buf_writer_copy(
    struct appl_buf_writer * const
        p_buf_writer,
    struct appl_buf_reader * const
        p_buf_reader);

unsigned long int
appl_buf_writer_copy_n(
    struct appl_buf_writer * const
        p_buf_writer,
    struct appl_buf_reader * const
        p_buf_reader,
    unsigned long int const
        i_count);

void
appl_buf_writer_fill(
    struct appl_buf_writer * const
        p_buf_writer,
    unsigned char const
        c_value);

unsigned long int
appl_buf_writer_fill_n(
    struct appl_buf_writer * const
        p_buf_writer,
    unsigned char const
        c_value,
    unsigned long int const
        i_count);

void
appl_buf_writer_zero(
    struct appl_buf_writer * const
        p_buf_writer);

unsigned long int
appl_buf_writer_zero_n(
    struct appl_buf_writer * const
        p_buf_writer,
    unsigned long int const
        i_count);

/* end-of-file: appl_buf1.h */
