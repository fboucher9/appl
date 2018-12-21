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
    unsigned char const * const
        p_buf_min,
    unsigned char const * const
        p_buf_max,
    char const * const
        p_name)
{
    char
        b_equal;

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

    return
        b_equal;

} /* appl_test_prompt_compare() */

static
unsigned long int
appl_test_prompt_dispatch(
    struct appl_context * const
        p_context,
    struct appl_options const * const
        p_input_options,
    unsigned long int const
        i_input_shift,
    struct appl_options * const
        p_output_options);

static
enum appl_status
appl_test_prompt_expand(
    struct appl_context * const
        p_context,
    struct appl_options const * const
        p_input_options,
    unsigned long int const
        i_input_shift,
    struct appl_options * const
        p_expand_options,
    unsigned long int * const
        r_input_consumed)
{
    enum appl_status
        e_status;

    unsigned long int
        i_input_count;

    e_status =
        appl_options_count(
            p_input_options,
            &(
                i_input_count));

    if (
        appl_status_ok
        == e_status)
    {
        unsigned long int
            i_input_iterator;

        char
            b_continue;

        i_input_iterator =
            i_input_shift;

        b_continue =
            1;

        while (
            (
                appl_status_ok
                == e_status)
            && b_continue
            && (
                i_input_iterator
                < i_input_count))
        {
            unsigned char const *
                p_buf_min;

            unsigned char const *
                p_buf_max;

            e_status =
                appl_options_get(
                    p_input_options,
                    i_input_iterator,
                    &(
                        p_buf_min),
                    &(
                        p_buf_max));

            if (
                appl_status_ok
                == e_status)
            {
                /* Detect recursive marker */
                if (appl_test_prompt_compare(
                        p_buf_min,
                        p_buf_max,
                        "["))
                {
                    i_input_iterator ++;

                    i_input_iterator +=
                        appl_test_prompt_dispatch(
                            p_context,
                            p_input_options,
                            i_input_iterator,
                            p_expand_options);
                }
                else if (appl_test_prompt_compare(
                        p_buf_min,
                        p_buf_max,
                        "]"))
                {
                    i_input_iterator ++;

                    b_continue =
                        0;
                }
                else
                {
                    e_status =
                        appl_options_append_argument(
                            p_expand_options,
                            p_buf_min,
                            p_buf_max);

                    if (
                        appl_status_ok
                        == e_status)
                    {
                        i_input_iterator ++;
                    }
                }
            }
        }

        if (
            appl_status_ok
            == e_status)
        {
            *(
                r_input_consumed) =
                (
                    i_input_iterator
                    - i_input_shift);
        }
    }

    return
        e_status;

}

static
enum appl_status
appl_test_prompt_run(
    struct appl_context * const
        p_context,
    struct appl_options const * const
        p_expand_options,
    struct appl_options * const
        p_output_options)
{
    enum appl_status
        e_status;

    unsigned long int
        i_expand_count;

    (void)(
        p_context);

    e_status =
        appl_options_count(
            p_expand_options,
            &(
                i_expand_count));

    if (
        appl_status_ok
        == e_status)
    {
        unsigned char const *
            p_cmd_min;

        unsigned char const *
            p_cmd_max;

        e_status =
            appl_options_get(
                p_expand_options,
                0u,
                &(
                    p_cmd_min),
                &(
                    p_cmd_max));

        if (
            appl_status_ok
            == e_status)
        {
            /* Detect echo */
            if (appl_test_prompt_compare(
                    p_cmd_min,
                    p_cmd_max,
                    "echo"))
            {
                /* Copy other arguments to output options */
                unsigned long int
                    i_expand_iterator;

                i_expand_iterator =
                    1;

                while (
                    (
                        appl_status_ok
                        == e_status)
                    && (
                        i_expand_iterator
                        < i_expand_count))
                {
                    unsigned char const *
                        p_arg_min;

                    unsigned char const *
                        p_arg_max;

                    e_status =
                        appl_options_get(
                            p_expand_options,
                            i_expand_iterator,
                            &(
                                p_arg_min),
                            &(
                                p_arg_max));

                    if (
                        appl_status_ok
                        == e_status)
                    {
                        e_status =
                            appl_options_append_argument(
                                p_output_options,
                                p_arg_min,
                                p_arg_max);

                        if (
                            appl_status_ok
                            == e_status)
                        {
                            i_expand_iterator ++;
                        }
                    }
                }
            }

            /* Third step, return output options */
        }
    }

    return
        e_status;

}

/*

*/
unsigned long int
appl_test_prompt_dispatch(
    struct appl_context * const
        p_context,
    struct appl_options const * const
        p_input_options,
    unsigned long int const
        i_input_shift,
    struct appl_options * const
        p_output_options)
{
    unsigned long int
        i_input_consumed;

    enum appl_status
        e_status;

    struct appl_options *
        p_expand_options;

    i_input_consumed =
        0ul;

    /* Detect if expansion is necessary */
    /* else run input directly */

    e_status =
        appl_options_create(
            p_context,
            &(
                p_expand_options));

    if (
        appl_status_ok
        == e_status)
    {
        /* First step, create expanded input options */
        e_status =
            appl_test_prompt_expand(
                p_context,
                p_input_options,
                i_input_shift,
                p_expand_options,
                &(
                    i_input_consumed));

        /* Second step, execute the expanded options */
        if (
            appl_status_ok
            == e_status)
        {
            e_status =
                appl_test_prompt_run(
                    p_context,
                    p_expand_options,
                    p_output_options);
        }

        appl_options_destroy(
            p_expand_options);
    }

    return
        i_input_consumed;

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
        p_input_options;

    struct appl_options *
        p_output_options;

    e_status =
        appl_status_ok;

    e_status =
        appl_options_create(
            p_context,
            &(
                p_output_options));

    if (
        appl_status_ok
        == e_status)
    {
        char
            b_output_options_created;

        b_output_options_created =
            1;

        e_status =
            appl_options_create(
                p_context,
                &(
                    p_input_options));

        if (
            appl_status_ok
            == e_status)
        {
            char
                b_input_options_created;

            char
                b_continue;

            b_input_options_created =
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
                                p_input_options,
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
                                    p_input_options,
                                    0,
                                    p_output_options);

                                appl_options_test_1(
                                    p_output_options);

                                appl_options_reset(
                                    p_output_options);

                                appl_options_reset(
                                    p_input_options);
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
                b_input_options_created)
            {
                appl_options_destroy(
                    p_input_options);

                b_input_options_created =
                    0;
            }
        }

        if (
            b_output_options_created)
        {
            appl_options_destroy(
                p_output_options);

            b_output_options_created =
                0;
        }
    }

    return
        e_status;

} /* appl_test_prompt() */

/* end-of-file: appl_test_prompt.c */
