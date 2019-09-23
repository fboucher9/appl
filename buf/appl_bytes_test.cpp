/* See LICENSE for license details */

/*

*/

#include <appl_predefines.h>

#include <buf/appl_bytes_test.h>

#include <appl_status.h>

#include <appl_types.h>

#include <appl_buf.h>

#include <buf/appl_bytes_descriptor.h>

#include <buf/appl_bytes_handle.h>

#include <appl_mem.h>

//
//
//
void
    appl_bytes_test_1(
        struct appl_context * const
            p_context)
{
    enum appl_status
        e_status;

    struct appl_bytes *
        p_bytes;

    struct appl_bytes_descriptor
        o_descriptor;

    appl_bytes_descriptor_init(
        &(
            o_descriptor));

    e_status =
        appl_bytes_create(
            p_context,
            &(
                o_descriptor),
            &(
                p_bytes));

    if (
        appl_status_ok
        == e_status)
    {
        {
            unsigned char
                uc_value;

            e_status =
                appl_bytes_read_int8(
                    p_bytes,
                    &(
                        uc_value));
        }

        e_status =
            appl_bytes_write_int8(
                p_bytes,
                42u);

        appl_bytes_destroy(
            p_bytes);
    }

    {
        appl_bytes_descriptor_init(
            &(
                o_descriptor));

        o_descriptor.e_type =
            appl_bytes_type_mem;

        static unsigned char g_temp[256u];

        o_descriptor.u.o_mem_descriptor.o_buf.o_min.p_uchar =
            g_temp;

        o_descriptor.u.o_mem_descriptor.o_buf.o_max.p_uchar =
            g_temp + sizeof(g_temp);

        e_status =
            appl_bytes_create(
                p_context,
                &(
                    o_descriptor),
                &(
                    p_bytes));

        if (
            appl_status_ok
            == e_status)
        {
            static unsigned char const g_raw_data[2u] =
            {
                42u,
                42u
            };

            struct appl_buf
                o_raw_data;

            o_raw_data.o_min.pc_uchar =
                g_raw_data;

            o_raw_data.o_max.pc_uchar =
                g_raw_data + sizeof(g_raw_data);

            e_status =
                appl_bytes_write_raw(
                    p_bytes,
                    &(
                        o_raw_data));

            e_status =
                appl_bytes_write_int(
                    p_bytes,
                    2u,
                    1234ul);

            e_status =
                appl_bytes_write_int8(
                    p_bytes,
                    42u);

            e_status =
                appl_bytes_write_int16(
                    p_bytes,
                    1234u);

            e_status =
                appl_bytes_write_int24(
                    p_bytes,
                    123456u);

            e_status =
                appl_bytes_write_int32(
                    p_bytes,
                    123456789ul);

            e_status =
                appl_bytes_write_int64(
                    p_bytes,
                    123456789ul);

            appl_bytes_destroy(
                p_bytes);
        }
    }

    {
        appl_bytes_descriptor_init(
            &(
                o_descriptor));

        o_descriptor.e_type =
            appl_bytes_type_mem;

        static unsigned char g_temp[256u];

        appl_mem_fill(
            g_temp,
            42u,
            sizeof(g_temp));

        o_descriptor.u.o_mem_descriptor.o_buf.o_min.p_uchar =
            g_temp;

        o_descriptor.u.o_mem_descriptor.o_buf.o_max.p_uchar =
            g_temp + sizeof(g_temp);

        e_status =
            appl_bytes_create(
                p_context,
                &(
                    o_descriptor),
                &(
                    p_bytes));

        if (
            appl_status_ok
            == e_status)
        {
            static unsigned char g_raw_data[2u];

            struct appl_buf
                o_raw_data;

            o_raw_data.o_min.pc_uchar =
                g_raw_data;

            o_raw_data.o_max.pc_uchar =
                g_raw_data + sizeof(g_raw_data);

            e_status =
                appl_bytes_read_raw(
                    p_bytes,
                    &(
                        o_raw_data));

            {
                appl_ull_t
                    ll_value;

                e_status =
                    appl_bytes_read_int(
                        p_bytes,
                        2u,
                        &(
                            ll_value));
            }

            {
                unsigned char
                    uc_value;

                e_status =
                    appl_bytes_read_int8(
                        p_bytes,
                        &(
                            uc_value));
            }

            {
                unsigned short int
                    us_value;

                e_status =
                    appl_bytes_read_int16(
                        p_bytes,
                        &(
                            us_value));
            }

            {
                unsigned long int
                    ul_value;

                e_status =
                    appl_bytes_read_int24(
                        p_bytes,
                        &(
                            ul_value));
            }

            {
                unsigned long int
                    ul_value;

                e_status =
                    appl_bytes_read_int32(
                        p_bytes,
                        &(
                            ul_value));
            }

            {
                appl_ull_t
                    ll_value;

                e_status =
                    appl_bytes_read_int64(
                        p_bytes,
                        &(
                            ll_value));
            }

            appl_bytes_destroy(
                p_bytes);
        }
    }

} // appl_bytes_test_1()

/* end-of-file: appl_bytes_test.cpp */
