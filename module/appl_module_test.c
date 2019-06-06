/* See LICENSE for license details */

/*

*/

#include <appl.h>

#include <module/appl_module_test.h>

/*

*/
enum appl_status
appl_module_test_1(
    struct appl_context * const
        p_context)
{
    static unsigned char const g_source_file_name[] =
    {
        /* input.bin */
        'i', 'n', 'p', 'u', 't', '.', 'b', 'i', 'n'
    };

    static unsigned char const g_sink_file_name[] =
    {
        /* output.bin */
        'o', 'u', 't', 'p', 'u', 't', '.', 'b', 'i', 'n'
    };

    enum appl_status
        e_status;

    struct appl_file *
        p_sink_file;

    struct appl_file_descriptor *
        p_source_file_descriptor;

    struct appl_file_descriptor *
        p_sink_file_descriptor;

    appl_file_descriptor_create(
        p_context,
        &(
            p_source_file_descriptor));

    appl_file_descriptor_create(
        p_context,
        &(
            p_sink_file_descriptor));

    /* Create a file copy pipeline */
    /* Use push method */
    /* Create sink first */
    /* Create source last */

    appl_file_descriptor_set_name(
        p_source_file_descriptor,
        g_source_file_name,
        g_source_file_name + (sizeof g_source_file_name));

    appl_file_descriptor_set_type(
        p_source_file_descriptor,
        appl_file_type_disk);

    appl_file_descriptor_set_mode(
        p_source_file_descriptor,
        appl_file_mode_read);

    appl_file_descriptor_set_name(
        p_sink_file_descriptor,
        g_sink_file_name,
        g_sink_file_name + (sizeof g_sink_file_name));

    appl_file_descriptor_set_type(
        p_sink_file_descriptor,
        appl_file_type_disk);

    appl_file_descriptor_set_mode(
        p_sink_file_descriptor,
        appl_file_mode_write);

    e_status =
        appl_file_create(
            p_context,
            p_sink_file_descriptor,
            &(
                p_sink_file));

    if (
        appl_status_ok
        == e_status)
    {
        struct appl_file *
            p_source_file;

        e_status =
            appl_file_create(
                p_context,
                p_source_file_descriptor,
                &(
                    p_source_file));

        if (
            appl_status_ok
            == e_status)
        {
            struct appl_file_sink_module *
                p_file_sink_module;

            struct appl_file_sink_module_descriptor
                o_file_sink_module_descriptor;

            o_file_sink_module_descriptor.p_file =
                p_sink_file;

            e_status =
                appl_file_sink_module_create(
                    p_context,
                    &(
                        o_file_sink_module_descriptor),
                    &(
                        p_file_sink_module));

            if (
                appl_status_ok
                == e_status)
            {
                struct appl_hex_convert_module *
                    p_hex_convert_module;

                struct appl_hex_convert_module_descriptor
                    o_hex_convert_module_descriptor;

                o_hex_convert_module_descriptor.p_sink =
                    appl_file_sink_module_parent(
                        p_file_sink_module);

                o_hex_convert_module_descriptor.i_offset =
                    0xDEADB000ul;

                o_hex_convert_module_descriptor.i_columns =
                    8u;

                e_status =
                    appl_hex_convert_module_create(
                        p_context,
                        &(
                            o_hex_convert_module_descriptor),
                        &(
                            p_hex_convert_module));

                if (
                    appl_status_ok
                    == e_status)
                {
                    struct appl_file_source_module *
                        p_file_source_module;

                    struct appl_file_source_module_descriptor
                        o_file_source_module_descriptor;

                    o_file_source_module_descriptor.p_sink =
                        appl_hex_convert_module_parent(
                            p_hex_convert_module);

                    o_file_source_module_descriptor.p_file =
                        p_source_file;

                    /* Create source module */
                    e_status =
                        appl_file_source_module_create(
                            p_context,
                            &(
                                o_file_source_module_descriptor),
                            &(
                                p_file_source_module));

                    if (
                        appl_status_ok
                        == e_status)
                    {
                        /* Send a packet to the module */
                        e_status =
                            appl_file_source_module_step(
                                p_file_source_module);

                        appl_file_source_module_destroy(
                            p_file_source_module);
                    }

                    appl_hex_convert_module_destroy(
                        p_hex_convert_module);
                }

                appl_file_sink_module_destroy(
                    p_file_sink_module);
            }

            appl_file_destroy(
                p_source_file);
        }

        appl_file_destroy(
            p_sink_file);
    }

    appl_file_descriptor_destroy(
        p_sink_file_descriptor);

    appl_file_descriptor_destroy(
        p_source_file_descriptor);

    return
        e_status;

} /* appl_module_test_1() */

/* end-of-file: appl_module_test.c */
