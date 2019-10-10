/* See LICENSE for license details */

/*

*/

#include <appl.h>

#include <file/appl_file_test.h>

#include <file/appl_file_mgr.h>

#include <file/appl_file_node.h>

#include <misc/appl_unused.h>

//
//
//
enum appl_status
    appl_file_main(
        struct appl_context * const
            p_context,
        struct appl_options const * const
            p_options,
        unsigned long int const
            i_shift)
{
    enum appl_status
        e_status;

    appl_unused(
        p_options,
        i_shift);

    // Do cat of stdin towards stdout

    // Open stdin
    struct appl_file_descriptor *
        p_file_descriptor;

    e_status =
        appl_file_descriptor_create(
            p_context,
            &(
                p_file_descriptor));

    if (
        appl_status_ok
        == e_status)
    {
        appl_file_descriptor_set_type(
            p_file_descriptor,
            appl_file_type_stdin);

        struct appl_file *
            p_file_stdin;

        e_status =
            appl_file_create(
                p_context,
                p_file_descriptor,
                &(
                    p_file_stdin));

        if (
            appl_status_ok
            == e_status)
        {
            // Open stdout
            appl_file_descriptor_set_type(
                p_file_descriptor,
                appl_file_type_stdout);

            struct appl_file *
                p_file_stdout;

            e_status =
                appl_file_create(
                    p_context,
                    p_file_descriptor,
                    &(
                        p_file_stdout));

            if (
                appl_status_ok
                == e_status)
            {
                bool
                    b_continue;

                b_continue =
                    true;

                while (
                    b_continue)
                {
                    static unsigned char s_buf[1024u];

                    unsigned long int
                        i_count;

                    // Read from stdin
                    if (
                        appl_status_ok
                        == appl_file_read(
                            p_file_stdin,
                            s_buf,
                            s_buf + sizeof(s_buf),
                            &(
                                i_count)))
                    {
                        // Write to stdout
                        if (
                            appl_status_ok
                            == appl_file_write(
                                p_file_stdout,
                                s_buf,
                                s_buf + i_count,
                                &(
                                    i_count)))
                        {
                        }
                        else
                        {
                            b_continue =
                                false;
                        }
                    }
                    else
                    {
                        b_continue =
                            false;
                    }
                }

                appl_file_destroy(
                    p_file_stdout);
            }

            appl_file_destroy(
                p_file_stdin);
        }

        appl_file_descriptor_destroy(
            p_file_descriptor);
    }

    return
        e_status;

} // appl_file_main()

//
//
//
void
    appl_file_test_1(
        struct appl_context * const
            p_context)
{
    struct appl_file_descriptor *
        p_file_descriptor;

    appl_file_descriptor_create(
        p_context,
        &(
            p_file_descriptor));

    // open of stdin
    {
        enum appl_status
            e_status;

        struct appl_file *
            p_file;

        appl_file_descriptor_set_type(
            p_file_descriptor,
            appl_file_type_stdin);

        e_status =
            appl_file_create(
                p_context,
                p_file_descriptor,
                &(
                    p_file));

        if (
            appl_status_ok
            == e_status)
        {
            appl_file_destroy(
                p_file);
        }
    }

    // open of stdout
    // parent
    // const parent
    {
        enum appl_status
            e_status;

        struct appl_file *
            p_file;

        appl_file_descriptor_set_type(
            p_file_descriptor,
            appl_file_type_stdout);

        e_status =
            appl_file_create(
                p_context,
                p_file_descriptor,
                &(
                    p_file));

        if (
            appl_status_ok
            == e_status)
        {
            appl_file_parent(
                0);

            appl_file_parent(
                p_file);

            appl_file_const_parent(
                0);

            appl_file_const_parent(
                p_file);

            appl_file_destroy(
                p_file);
        }
    }

    // open of stderr
    {
        enum appl_status
            e_status;

        struct appl_file *
            p_file;

        appl_file_descriptor_set_type(
            p_file_descriptor,
            appl_file_type_stderr);

        e_status =
            appl_file_create(
                p_context,
                p_file_descriptor,
                &(
                    p_file));

        if (
            appl_status_ok
            == e_status)
        {
            appl_file_destroy(
                p_file);
        }
    }

    // open of invalid file type
    {
        enum appl_status
            e_status;

        struct appl_file *
            p_file;

        int
            i_invalid_file_type;

        i_invalid_file_type =
            -1;

        appl_file_descriptor_set_type(
            p_file_descriptor,
            static_cast<enum appl_file_type>(
                i_invalid_file_type));

        e_status =
            appl_file_create(
                p_context,
                p_file_descriptor,
                &(
                    p_file));

        e_status =
            (appl_status_ok == e_status)
            ? appl_file_destroy(p_file)
            : e_status;
    }

    // open of disk
    // file read
    // file read past end
    {
        static unsigned char const g_input_bin_name[] =
        {
            'i',
            'n',
            'p',
            'u',
            't',
            '.',
            'b',
            'i',
            'n'
        };

        enum appl_status
            e_status;

        struct appl_file *
            p_file;

        appl_file_descriptor_set_type(
            p_file_descriptor,
            appl_file_type_disk);

        appl_file_descriptor_set_mode(
            p_file_descriptor,
            appl_file_mode_read);

        appl_file_descriptor_set_name(
            p_file_descriptor,
            g_input_bin_name,
            g_input_bin_name + sizeof(g_input_bin_name));

        e_status =
            appl_file_create(
                p_context,
                p_file_descriptor,
                &(
                    p_file));

        if (
            appl_status_ok
            == e_status)
        {
            while (
                appl_status_ok
                == e_status)
            {
                unsigned long int
                    i_count;

                unsigned char
                    a_buf[32u];

                e_status =
                    appl_file_read(
                        p_file,
                        a_buf,
                        a_buf + sizeof(a_buf),
                        &(
                            i_count));
            }

            appl_file_destroy(
                p_file);
        }
    }

    // open of invalid file name
    {
        static unsigned char const g_invalid_file_name[] =
        {
            'i',
            'n',
            'v',
            'a',
            'l',
            'i',
            'd',
            '.',
            'b',
            'a',
            'd'
        };

        enum appl_status
            e_status;

        struct appl_file *
            p_file;

        appl_file_descriptor_set_type(
            p_file_descriptor,
            appl_file_type_disk);

        appl_file_descriptor_set_mode(
            p_file_descriptor,
            appl_file_mode_read);

        appl_file_descriptor_set_name(
            p_file_descriptor,
            g_invalid_file_name,
            g_invalid_file_name + sizeof(g_invalid_file_name));

        e_status =
            appl_file_create(
                p_context,
                p_file_descriptor,
                &(
                    p_file));

        e_status =
            (appl_status_ok == e_status)
            ? appl_file_destroy(p_file)
            : e_status;
    }

    // open using invalid file mode
    {
        static unsigned char const g_input_bin_name[] =
        {
            'i',
            'n',
            'p',
            'u',
            't',
            '.',
            'b',
            'i',
            'n'
        };

        enum appl_status
            e_status;

        struct appl_file *
            p_file;

        appl_file_descriptor_set_type(
            p_file_descriptor,
            appl_file_type_disk);

        int
            i_invalid_file_mode;

        i_invalid_file_mode =
            33;

        appl_file_descriptor_set_mode(
            p_file_descriptor,
            static_cast<enum appl_file_mode>(
                i_invalid_file_mode));

        appl_file_descriptor_set_name(
            p_file_descriptor,
            g_input_bin_name,
            g_input_bin_name + sizeof(g_input_bin_name));

        e_status =
            appl_file_create(
                p_context,
                p_file_descriptor,
                &(
                    p_file));

        e_status =
            (appl_status_ok == e_status)
            ? appl_file_destroy(p_file)
            : e_status;
    }

    // file write into read-only file
    {
        static unsigned char const g_input_bin_name[] =
        {
            'i',
            'n',
            'p',
            'u',
            't',
            '.',
            'b',
            'i',
            'n'
        };

        enum appl_status
            e_status;

        struct appl_file *
            p_file;

        appl_file_descriptor_set_type(
            p_file_descriptor,
            appl_file_type_disk);

        appl_file_descriptor_set_mode(
            p_file_descriptor,
            appl_file_mode_read);

        appl_file_descriptor_set_name(
            p_file_descriptor,
            g_input_bin_name,
            g_input_bin_name + sizeof(g_input_bin_name));

        e_status =
            appl_file_create(
                p_context,
                p_file_descriptor,
                &(
                    p_file));

        if (
            appl_status_ok
            == e_status)
        {
            static unsigned char const g_file_write_data[] =
            {
                'a',
                'b',
                'c',
                'd',
                'e',
                'f',
                'g',
                'h'
            };

            unsigned long int
                i_count;

            e_status =
                appl_file_write(
                    p_file,
                    g_file_write_data,
                    g_file_write_data + sizeof(g_file_write_data),
                    &(
                        i_count));

            appl_file_destroy(
                p_file);
        }
    }

    // file write
    {
        static unsigned char const g_out007_bin_name[] =
        {
            'o',
            'u',
            't',
            '0',
            '0',
            '7',
            '.',
            'b',
            'i',
            'n'
        };

        enum appl_status
            e_status;

        struct appl_file *
            p_file;

        appl_file_descriptor_set_type(
            p_file_descriptor,
            appl_file_type_disk);

        appl_file_descriptor_set_mode(
            p_file_descriptor,
            appl_file_mode_write);

        appl_file_descriptor_set_name(
            p_file_descriptor,
            g_out007_bin_name,
            g_out007_bin_name + sizeof(g_out007_bin_name));

        e_status =
            appl_file_create(
                p_context,
                p_file_descriptor,
                &(
                    p_file));

        if (
            appl_status_ok
            == e_status)
        {
            static unsigned char const g_file_write_data[] =
            {
                'a',
                'b',
                'c',
                'd',
                'e',
                'f',
                'g',
                'h'
            };

            unsigned long int
                i_count;

            e_status =
                appl_file_write(
                    p_file,
                    g_file_write_data,
                    g_file_write_data + sizeof(g_file_write_data),
                    &(
                        i_count));

            appl_file_destroy(
                p_file);
        }
    }

    // file append
    {
        static unsigned char const g_out007_bin_name[] =
        {
            'o',
            'u',
            't',
            '0',
            '0',
            '7',
            '.',
            'b',
            'i',
            'n'
        };

        enum appl_status
            e_status;

        struct appl_file *
            p_file;

        appl_file_descriptor_set_type(
            p_file_descriptor,
            appl_file_type_disk);

        appl_file_descriptor_set_mode(
            p_file_descriptor,
            appl_file_mode_append);

        appl_file_descriptor_set_name(
            p_file_descriptor,
            g_out007_bin_name,
            g_out007_bin_name + sizeof(g_out007_bin_name));

        e_status =
            appl_file_create(
                p_context,
                p_file_descriptor,
                &(
                    p_file));

        if (
            appl_status_ok
            == e_status)
        {
            static unsigned char const g_file_write_data[] =
            {
                'i',
                'j',
                'k',
                'l',
                'm',
                'n',
                'o',
                'p'
            };

            unsigned long int
                i_count;

            e_status =
                appl_file_write(
                    p_file,
                    g_file_write_data,
                    g_file_write_data + sizeof(g_file_write_data),
                    &(
                        i_count));

            appl_file_destroy(
                p_file);
        }
    }

    // file modify
    {
        static unsigned char const g_out007_bin_name[] =
        {
            'o',
            'u',
            't',
            '0',
            '0',
            '7',
            '.',
            'b',
            'i',
            'n'
        };

        enum appl_status
            e_status;

        struct appl_file *
            p_file;

        appl_file_descriptor_set_type(
            p_file_descriptor,
            appl_file_type_disk);

        appl_file_descriptor_set_mode(
            p_file_descriptor,
            appl_file_mode_modify);

        appl_file_descriptor_set_name(
            p_file_descriptor,
            g_out007_bin_name,
            g_out007_bin_name + sizeof(g_out007_bin_name));

        e_status =
            appl_file_create(
                p_context,
                p_file_descriptor,
                &(
                    p_file));

        if (
            appl_status_ok
            == e_status)
        {
            static unsigned char const g_file_write_data[] =
            {
                'q',
                'r',
                's',
                't',
                'u',
                'v',
                'w',
                'x'
            };

            unsigned long int
                i_count;

            e_status =
                appl_file_write(
                    p_file,
                    g_file_write_data,
                    g_file_write_data + sizeof(g_file_write_data),
                    &(
                        i_count));

            appl_file_destroy(
                p_file);
        }
    }

    // file seek ...

    // file tell ...

    // base file mgr
    {
        class appl_file_mgr *
            p_file_mgr;

        enum appl_status
            e_status;

        e_status =
            appl_new(
                p_context,
                &(
                    p_file_mgr));

        if (
            appl_status_ok
            == e_status)
        {
            p_file_mgr->v_create_node(
                0,
                0);

            p_file_mgr->v_destroy_node(
                0);

            appl_delete(
                p_context,
                p_file_mgr);
        }
    }

    // base file node
    {
        struct appl_file *
            p_file_node;

        enum appl_status
            e_status;

        e_status =
            appl_new(
                p_context,
                &(
                    p_file_node));

        if (
            appl_status_ok
            == e_status)
        {
            p_file_node->v_read(
                0,
                0,
                0);

            p_file_node->v_write(
                0,
                0,
                0);

            appl_delete(
                p_context,
                p_file_node);
        }
    }

    appl_file_descriptor_destroy(
        p_file_descriptor);

} // appl_file_test_1()

/* end-of-file: appl_file_test.cpp */
