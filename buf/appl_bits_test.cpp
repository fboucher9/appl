/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <buf/appl_bits_test.h>

#include <appl_buf.h>

#include <buf/appl_str_bits.h>

#include <buf/appl_bits_handle.h>

#include <appl_types.h>

#include <appl_object.h>

#include <buf/appl_bits.h>

#include <buf/appl_bits_base.h>

#include <appl_unused.h>

#include <appl_heap_handle.h>

//
//
//
static
enum appl_status
    s_consume_dummy(
        void * const
            p_callback_context,
        unsigned char * const
            r_value)
{
    enum appl_status
        e_status;

    appl_unused(
        p_callback_context);

    *(
        r_value) =
        0xFFu;

    e_status =
        appl_status_ok;

    return
        e_status;

} // s_consume_dummy()

//
//
//
static
enum appl_status
    s_produce_dummy(
        void * const
            p_callback_context,
        unsigned char const
            i_value)
{
    enum appl_status
        e_status;

    appl_unused(
        p_callback_context,
        i_value);

    e_status =
        appl_status_ok;

    return
        e_status;

} // s_produce_dummy()

//
//
//
void
    appl_bits_test_1(
        struct appl_context * const
            p_context)
{
    enum appl_status
        e_status;

    struct appl_bits *
        p_bits;

    {
        struct appl_bits_descriptor
            o_bits_descriptor;

        o_bits_descriptor.p_callback_consume =
            &(
                s_consume_dummy);
        o_bits_descriptor.p_callback_produce =
            &(
                s_produce_dummy);
        o_bits_descriptor.p_callback_context =
            0;

        e_status =
            appl_bits_create(
                p_context,
                &(
                    o_bits_descriptor),
                &(
                    p_bits));

        if (
            appl_status_ok
            == e_status)
        {
            unsigned long int
                i_value;

            e_status =
                appl_bits_read(
                    p_bits,
                    1u,
                    &(
                        i_value));

            e_status =
                appl_bits_write(
                    p_bits,
                    7u,
                    i_value);

            appl_bits_destroy(
                p_bits);
        }
    }

    {
        struct appl_str_bits_descriptor
            o_str_bits_descriptor;

        static unsigned char const g_str_bits_vector[1u] =
        {
            0x5Au
        };

        o_str_bits_descriptor.o_buf.o_min.pc_uchar =
            g_str_bits_vector;

        o_str_bits_descriptor.o_buf.o_max.pc_uchar =
            g_str_bits_vector + sizeof(g_str_bits_vector);

        struct appl_str_bits *
            p_str_bits;

        e_status =
            appl_str_bits_create(
                p_context,
                &(
                    o_str_bits_descriptor),
                &(
                    p_str_bits));

        if (
            appl_status_ok
            == e_status)
        {
            unsigned long int
                i_value;

            p_bits =
                appl_str_bits_parent(
                    p_str_bits);

            e_status =
                appl_bits_read(
                    p_bits,
                    4ul,
                    &(
                        i_value));

            e_status =
                appl_bits_read(
                    p_bits,
                    5ul,
                    &(
                        i_value));

            appl_bits_destroy(
                p_bits);
        }
    }

    {
        struct appl_str_bits_descriptor
            o_str_bits_descriptor;

        unsigned char g_str_bits_vector[1u];

        o_str_bits_descriptor.o_buf.o_min.p_uchar =
            g_str_bits_vector;

        o_str_bits_descriptor.o_buf.o_max.p_uchar =
            g_str_bits_vector + sizeof(g_str_bits_vector);

        struct appl_str_bits *
            p_str_bits;

        e_status =
            appl_str_bits_create(
                p_context,
                &(
                    o_str_bits_descriptor),
                &(
                    p_str_bits));

        if (
            appl_status_ok
            == e_status)
        {
            {
                struct appl_bits const * const
                    pc_bits =
                    appl_str_bits_const_parent(
                        p_str_bits);

                appl_unused(
                    pc_bits);
            }

            p_bits =
                appl_str_bits_parent(
                    p_str_bits);

            e_status =
                appl_bits_write(
                    p_bits,
                    4ul,
                    0ul);

            e_status =
                appl_bits_write(
                    p_bits,
                    5ul,
                    0ul);

            e_status =
                appl_bits_write(
                    p_bits,
                    8ul,
                    0ul);

            struct appl_buf
                o_buf_used;

            struct appl_buf
                o_buf_unused;

            e_status =
                appl_str_bits_query(
                    p_str_bits,
                    &(
                        o_buf_used),
                    &(
                        o_buf_unused));

            appl_bits_destroy(
                p_bits);
        }
    }

    {
        struct appl_bits *
            p_bits_intf;

        e_status =
            appl_new(
                p_context,
                &(
                    p_bits_intf));

        if (
            appl_status_ok
            == e_status)
        {
            {
                unsigned long int
                    i_value;

                p_bits_intf->v_read(
                    8u,
                    &(
                        i_value));
            }

            p_bits_intf->v_write(
                8u,
                0x5A5Aul);

            appl_delete(
                p_context,
                p_bits_intf);
        }
    }

    {
        class appl_bits_base *
            p_bits_base;

        e_status =
            appl_new(
                p_context,
                &(
                    p_bits_base));

        if (
            appl_status_ok
            == e_status)
        {
            {
                unsigned char
                    i_value;

                p_bits_base->v_consume(
                    &(
                        i_value));
            }

            p_bits_base->v_produce(
                0x5Au);

            appl_delete(
                p_context,
                p_bits_base);
        }
    }

} // appl_bits_test_1()

/* end-of-file: appl_bits_test.cpp */
