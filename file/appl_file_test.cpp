/* See LICENSE for license details */

/*

*/

#include <appl.h>

#include <file/appl_file_test.h>

#include <file/appl_file_mgr.h>

#include <file/appl_file_node.h>

//
//
//
void
    appl_file_test_1(
        struct appl_context * const
            p_context)
{
    // open of stdin
    {
        enum appl_status
            e_status;

        struct appl_file_descriptor
            o_file_descriptor;

        struct appl_file *
            p_file;

        o_file_descriptor.e_type =
            appl_file_type_stdin;

        e_status =
            appl_file_create(
                p_context,
                &(
                    o_file_descriptor),
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

        struct appl_file_descriptor
            o_file_descriptor;

        struct appl_file *
            p_file;

        o_file_descriptor.e_type =
            appl_file_type_stdout;

        e_status =
            appl_file_create(
                p_context,
                &(
                    o_file_descriptor),
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

        struct appl_file_descriptor
            o_file_descriptor;

        struct appl_file *
            p_file;

        o_file_descriptor.e_type =
            appl_file_type_stderr;

        e_status =
            appl_file_create(
                p_context,
                &(
                    o_file_descriptor),
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

        struct appl_file_descriptor
            o_file_descriptor;

        struct appl_file *
            p_file;

        int
            i_invalid_file_type;

        i_invalid_file_type =
            -1;

        o_file_descriptor.e_type =
            static_cast<enum appl_file_type>(
                i_invalid_file_type);

        e_status =
            appl_file_create(
                p_context,
                &(
                    o_file_descriptor),
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

        struct appl_file_descriptor
            o_file_descriptor;

        o_file_descriptor.e_type =
            appl_file_type_disk;

        o_file_descriptor.e_mode =
            appl_file_mode_read;

        o_file_descriptor.p_name_min =
            g_input_bin_name;

        o_file_descriptor.p_name_max =
            g_input_bin_name + sizeof(g_input_bin_name);

        e_status =
            appl_file_create(
                p_context,
                &(
                    o_file_descriptor),
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

        struct appl_file_descriptor
            o_file_descriptor;

        o_file_descriptor.e_type =
            appl_file_type_disk;

        o_file_descriptor.e_mode =
            appl_file_mode_read;

        o_file_descriptor.p_name_min =
            g_invalid_file_name;

        o_file_descriptor.p_name_max =
            g_invalid_file_name + sizeof(g_invalid_file_name);

        e_status =
            appl_file_create(
                p_context,
                &(
                    o_file_descriptor),
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

        struct appl_file_descriptor
            o_file_descriptor;

        o_file_descriptor.e_type =
            appl_file_type_disk;

        int
            i_invalid_file_mode;

        i_invalid_file_mode =
            33;

        o_file_descriptor.e_mode =
            static_cast<enum appl_file_mode>(
                i_invalid_file_mode);

        o_file_descriptor.p_name_min =
            g_input_bin_name;

        o_file_descriptor.p_name_max =
            g_input_bin_name + sizeof(g_input_bin_name);

        e_status =
            appl_file_create(
                p_context,
                &(
                    o_file_descriptor),
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

        struct appl_file_descriptor
            o_file_descriptor;

        o_file_descriptor.e_type =
            appl_file_type_disk;

        o_file_descriptor.e_mode =
            appl_file_mode_read;

        o_file_descriptor.p_name_min =
            g_input_bin_name;

        o_file_descriptor.p_name_max =
            g_input_bin_name + sizeof(g_input_bin_name);

        e_status =
            appl_file_create(
                p_context,
                &(
                    o_file_descriptor),
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

        struct appl_file_descriptor
            o_file_descriptor;

        o_file_descriptor.e_type =
            appl_file_type_disk;

        o_file_descriptor.e_mode =
            appl_file_mode_write;

        o_file_descriptor.p_name_min =
            g_out007_bin_name;

        o_file_descriptor.p_name_max =
            g_out007_bin_name + sizeof(g_out007_bin_name);

        e_status =
            appl_file_create(
                p_context,
                &(
                    o_file_descriptor),
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

        struct appl_file_descriptor
            o_file_descriptor;

        o_file_descriptor.e_type =
            appl_file_type_disk;

        o_file_descriptor.e_mode =
            appl_file_mode_append;

        o_file_descriptor.p_name_min =
            g_out007_bin_name;

        o_file_descriptor.p_name_max =
            g_out007_bin_name + sizeof(g_out007_bin_name);

        e_status =
            appl_file_create(
                p_context,
                &(
                    o_file_descriptor),
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

        struct appl_file_descriptor
            o_file_descriptor;

        o_file_descriptor.e_type =
            appl_file_type_disk;

        o_file_descriptor.e_mode =
            appl_file_mode_modify;

        o_file_descriptor.p_name_min =
            g_out007_bin_name;

        o_file_descriptor.p_name_max =
            g_out007_bin_name + sizeof(g_out007_bin_name);

        e_status =
            appl_file_create(
                p_context,
                &(
                    o_file_descriptor),
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

} // appl_file_test_1()

/* end-of-file: appl_file_test.cpp */
