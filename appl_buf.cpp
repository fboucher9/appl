/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_buf.h"

/*

*/
enum appl_status
appl_buf_read(
    struct appl_buf * const
        p_buf,
    unsigned char * const
        p_value)
{
    enum appl_status
        e_status;

    if (
        p_buf->o_min.pc_uchar < p_buf->o_max.pc_uchar)
    {
        *(
            p_value) =
            *(
                p_buf->o_min.pc_uchar);

        p_buf->o_min.pc_uchar ++;

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

} /* appl_buf_read() */

/*

*/
enum appl_status
appl_buf_write(
    struct appl_buf * const
        p_buf,
    unsigned char const
        c_value)
{
    enum appl_status
        e_status;

    if (
        p_buf->o_min.p_uchar < p_buf->o_max.p_uchar)
    {
        *(
            p_buf->o_min.p_uchar) =
            c_value;

        p_buf->o_min.p_uchar ++;

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

} /* appl_buf_write() */

/*

*/
enum appl_status
appl_buf_copy(
    struct appl_buf * const
        p_buf,
    struct appl_buf const * const
        p_buf_source,
    unsigned long int * const
        p_count)
{
    enum appl_status
        e_status;

    unsigned long int
        i_count;

    struct appl_buf
        o_buf_source_it;

    i_count =
        0ul;

    o_buf_source_it =
        *(
            p_buf_source);

    while (
        (
            o_buf_source_it.o_min.pc_uchar
            < o_buf_source_it.o_max.pc_uchar)
        && (
            p_buf->o_min.p_uchar
            < p_buf->o_max.p_uchar))
    {
        *(
            p_buf->o_min.p_uchar) =
            *(
                o_buf_source_it.o_min.pc_uchar);

        o_buf_source_it.o_min.pc_uchar ++;

        p_buf->o_min.p_uchar ++;

        i_count ++;
    }

    *(
        p_count) =
        i_count;

    e_status =
        appl_status_ok;

    return
        e_status;

} /* appl_buf_copy() */

/*

*/
enum appl_status
appl_buf_compare(
    struct appl_buf const * const
        p_buf_left,
    struct appl_buf const * const
        p_buf_right,
    signed int * const
        p_result)
{
    enum appl_status
        e_status;

    struct appl_buf
        o_buf_left_it;

    struct appl_buf
        o_buf_right_it;

    o_buf_left_it =
        *(
            p_buf_left);

    o_buf_right_it =
        *(
            p_buf_right);

    signed int
        i_result;

    i_result =
        0;

    while (
        (
            0
            == i_result)
        && (
            (
                o_buf_left_it.o_min.pc_uchar
                < o_buf_left_it.o_max.pc_uchar)
            || (
                o_buf_right_it.o_min.pc_uchar
                < o_buf_right_it.o_max.pc_uchar)))
    {
        unsigned char
            c_left;

        unsigned char
            c_right;

        if (
                o_buf_left_it.o_min.pc_uchar
                < o_buf_left_it.o_max.pc_uchar)
        {
            c_left =
                *(
                    o_buf_left_it.o_min.pc_uchar);

            o_buf_left_it.o_min.pc_uchar ++;
        }
        else
        {
            c_left =
                0u;
        }

        if (
            o_buf_right_it.o_min.pc_uchar
            < o_buf_right_it.o_max.pc_uchar)
        {
            c_right =
                *(
                    o_buf_right_it.o_min.pc_uchar);

            o_buf_right_it.o_min.pc_uchar ++;
        }
        else
        {
            c_right =
                0u;
        }

        i_result =
            static_cast<signed int>(
                static_cast<signed int>(
                    static_cast<unsigned int>(
                        c_left))
                - static_cast<signed int>(
                    static_cast<unsigned int>(
                        c_right)));
    }

    *(
        p_result) =
        i_result;

    e_status =
        appl_status_ok;

    return
        e_status;

} /* appl_buf_compare() */

/*

*/
#if 0
enum appl_status
appl_buf_case_compare(
    struct appl_buf const * const
        p_buf_left,
    struct appl_buf const * const
        p_buf_right,
    signed int * const
        p_result)
{
} /* appl_buf_case_compare() */
#endif

