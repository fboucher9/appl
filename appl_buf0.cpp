/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_buf0.h>

#include <appl_heap_handle.h>

#include <appl_buf.h>

#include <appl_types.h>

#include <appl_convert.h>

/*

*/
enum appl_status
appl_buf0_create(
    struct appl_object const * const
        p_object,
    unsigned char const * const
        p_buf_min,
    unsigned char const * const
        p_buf_max,
    unsigned char * * const
        r_buf0)
{
    enum appl_status
        e_status;

    union appl_ptr
        o_buf0_allocation;

    unsigned long int const
        i_buf_len =
        appl_buf_len(
            p_buf_min,
            p_buf_max);

    e_status =
        appl_heap_alloc(
            p_object,
            i_buf_len + 1,
            &(
                o_buf0_allocation.p_void));

    if (
        appl_status_ok
        == e_status)
    {
        appl_buf_copy(
            o_buf0_allocation.p_uchar,
            o_buf0_allocation.p_uchar + i_buf_len,
            p_buf_min,
            p_buf_max);

        o_buf0_allocation.p_uchar[i_buf_len] =
            0;

        *(
            r_buf0) =
            o_buf0_allocation.p_uchar;
    }

    return
        e_status;

} /* create() */

/*

*/
enum appl_status
appl_buf0_destroy(
    struct appl_object const * const
        p_object,
    unsigned char * const
        p_buf0)
{
    return
        appl_heap_free(
            p_object,
            p_buf0);

} /* destroy() */

/* buf length */
unsigned long int
appl_buf0_len(
    unsigned char const * const
        p_buf_0)
{
    unsigned char const *
        p_buf_it =
        p_buf_0;

    while (*(p_buf_it))
    {
        p_buf_it ++;
    }

    return
        appl_convert::to_ulong(
            appl_convert::to_unsigned(
                p_buf_it
                - p_buf_0));

} /* len() */

/* end-of-file: appl_buf0.cpp */
