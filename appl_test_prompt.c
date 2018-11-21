/* See LICENSE for license details */

/*

*/

#include <appl.h>

#include <appl_test_prompt.h>

#include <options/appl_options_test.h>

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
                            appl_options_test_1(
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
