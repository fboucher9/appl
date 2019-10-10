/* See LICENSE for license details */

/*

*/

#include <appl_predefines.h>

#include <buf/appl_bytes_test.h>

#include <appl_status.h>

#include <appl_types.h>

#include <buf/appl_buf.h>

#include <buf/appl_bytes_descriptor.h>

#include <buf/appl_bytes_handle.h>

#include <object/appl_object.h>

#include <buf/appl_bytes.h>

#include <buf/appl_bytes_base.h>

#include <buf/appl_mem.h>

#include <heap/appl_heap_handle.h>

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

        static unsigned char g_temp[32u];

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

            {
                static unsigned char g_check_overflow[32u];

                struct appl_buf
                    o_check_overflow;

                appl_mem_fill(
                    g_check_overflow,
                    42u,
                    sizeof(g_check_overflow));

                o_check_overflow.o_min.p_uchar =
                    g_check_overflow;

                o_check_overflow.o_max.p_uchar =
                    g_check_overflow + sizeof(g_check_overflow);

                e_status =
                    appl_bytes_write_raw(
                        p_bytes,
                        &(
                            o_check_overflow));
            }

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

        static unsigned char g_temp[32u];

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

            {
                static unsigned char g_check_overflow[32u];

                struct appl_buf
                    o_check_overflow;

                o_check_overflow.o_min.p_uchar =
                    g_check_overflow;

                o_check_overflow.o_max.p_uchar =
                    g_check_overflow + sizeof(g_check_overflow);

                e_status =
                    appl_bytes_read_raw(
                        p_bytes,
                        &(
                            o_check_overflow));
            }

            appl_bytes_destroy(
                p_bytes);
        }
    }

    {
        e_status =
            appl_new(
                p_context,
                &(
                    p_bytes));

        if (
            appl_status_ok
            == e_status)
        {
            p_bytes->v_write_raw(
                0);

            p_bytes->v_write_int(
                0,
                0);

            p_bytes->v_write_int8(
                0);

            p_bytes->v_write_int16(
                0);

            p_bytes->v_write_int24(
                0);

            p_bytes->v_write_int32(
                0);

            p_bytes->v_write_int64(
                0);

            p_bytes->v_read_raw(
                0);

            p_bytes->v_read_int(
                0,
                0);

            p_bytes->v_read_int8(
                0);

            p_bytes->v_read_int16(
                0);

            p_bytes->v_read_int24(
                0);

            p_bytes->v_read_int32(
                0);

            p_bytes->v_read_int64(
                0);

            appl_delete(
                p_context,
                p_bytes);
        }
    }

    {
        class appl_bytes_base *
            p_bytes_base;

        e_status =
            appl_new(
                p_context,
                &(
                    p_bytes_base));
        if (
            appl_status_ok
            == e_status)
        {
            unsigned char
                i_value;

            p_bytes_base->v_consume(
                &(
                    i_value));

            p_bytes_base->v_produce(
                42u);

            appl_delete(
                p_context,
                p_bytes_base);
        }
    }

    {
        appl_mem_zero(
            &(
                o_descriptor),
            sizeof(
                o_descriptor));

        appl_bytes_create(
            p_context,
            &(
                o_descriptor),
            &(
                p_bytes));
    }

} // appl_bytes_test_1()

/* end-of-file: appl_bytes_test.cpp */
