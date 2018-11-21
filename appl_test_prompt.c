/* See LICENSE for license details */

/*

*/

#include <appl.h>

#include <appl_test_prompt.h>

#include <options/appl_options_test.h>

#include <string.h>

static
char
appl_test_prompt_compare(
    struct appl_options const * const
        p_options,
    char const * const
        p_name)
{
    char
        b_equal;

    unsigned char const *
        p_buf_min;

    unsigned char const *
        p_buf_max;

    enum appl_status
        e_status;

    e_status =
        appl_options_get(
            p_options,
            0ul,
            &(
                p_buf_min),
            &(
                p_buf_max));

    if (
        appl_status_ok
        == e_status)
    {
        unsigned long int
            i_buf_len;

        unsigned long int
            i_name_len;

        i_buf_len =
            appl_buf_len(
                p_buf_min,
                p_buf_max);

        i_name_len =
            appl_buf0_len(
                (unsigned char const *)(
                    p_name));

        if (
            i_buf_len
            == i_name_len)
        {
            if (
                0 == memcmp(
                    p_buf_min,
                    p_name,
                    i_name_len))
            {
                b_equal =
                    1;
            }
            else
            {
                b_equal =
                    0;
            }
        }
        else
        {
            b_equal =
                0;
        }
    }
    else
    {
        b_equal =
            0;
    }

    return
        b_equal;

} /* appl_test_prompt_compare() */

/*

*/
static
void
appl_test_prompt_dispatch(
    struct appl_context * const
        p_context,
    struct appl_options const * const
        p_options)
{
    /* Detect echo */

    if (appl_test_prompt_compare(
            p_options,
            "echo"))
    {
        appl_options_test_1(
            p_context,
            p_options);
    }
    else
    {
    }

} /* appl_test_prompt_dispatch() */

/*


*/
enum appl_status
appl_test_prompt(
    struct appl_context * const
        p_context,
    struct appl_file * const
        p_file)
{
    enum appl_status
        e_status;

    struct appl_options *
        p_options;

    e_status =
        appl_status_ok;

    e_status =
        appl_options_create(
            p_context,
            &(
                p_options));

    if (
        appl_status_ok
        == e_status)
    {
        char
            b_options_created;

        char
            b_continue;

        b_options_created =
            1;

        b_continue =
            1;

        while (
            (
                appl_status_ok
                == e_status)
            && b_continue)
        {
            unsigned char
                a_buf[32u];

            unsigned long int
                i_read_count;

            e_status =
                appl_file_read(
                    p_file,
                    a_buf,
                    a_buf + sizeof(a_buf),
                    &(
                        i_read_count));

            if (
                appl_status_ok
                == e_status)
            {
                /* Copy data to options */
                unsigned long int
                    i_read_offset;

                i_read_offset =
                    0ul;

                while (
                    (
                        appl_status_ok
                        == e_status)
                    && b_continue
                    && (
                        i_read_offset
                        < i_read_count))
                {
                    unsigned long int
                        i_write_count;

                    char
                        b_ready;

                    e_status =
                        appl_options_write(
                            p_options,
                            a_buf + i_read_offset,
                            a_buf + i_read_count,
                            &(
                                i_write_count),
                            &(
                                b_ready));

                    if (
                        appl_status_ok
                        == e_status)
                    {
                        if (
                            b_ready)
                        {
                            appl_test_prompt_dispatch(
                                p_context,
                                p_options);

                            appl_options_reset(
                                p_options);
                        }

                        if (
                            i_write_count)
                        {
                            i_read_offset +=
                                i_write_count;
                        }
                        else
                        {
                            b_continue =
                                0;
                        }
                    }
                }
            }
        }

        if (
            b_options_created)
        {
            appl_object_destroy(
                appl_options_parent(
                    p_options));

            b_options_created =
                0;
        }
    }

    return
        e_status;

} /* appl_test_prompt() */

/* end-of-file: appl_test_prompt.c */
