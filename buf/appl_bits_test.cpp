/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_predefines.h>

#include <buf/appl_bits_test.h>

#include <buf/appl_buf.h>

#include <buf/appl_bits_descriptor.h>

#include <buf/appl_bits_mem.h>

#include <buf/appl_bits_handle.h>

#include <appl_types.h>

#include <appl_object.h>

#include <buf/appl_bits.h>

#include <buf/appl_bits_base.h>

#include <misc/appl_unused.h>

#include <appl_heap_handle.h>

#include <buf/appl_mem.h>

#include <appl_test.h>

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
static
enum appl_status
appl_bits_test_verify_value(
    struct appl_bits * const
        p_bits,
    unsigned char const
        i_count,
    unsigned long int const
        i_expect)
{
    enum appl_status
        e_status;

    unsigned long int
        i_value;

    e_status =
        appl_bits_read(
            p_bits,
            i_count,
            &(
                i_value));

    if (
        appl_status_ok
        == e_status)
    {
        if (
            i_expect
            == i_value)
        {
        }
        else
        {
            appl_print0(
                "bits verify expect ");

            appl_print_lu(
                i_expect);

            appl_print0(
                " got ");

            appl_print_lu(
                i_value);

            appl_print0(
                "\n");

            e_status =
                appl_status_fail;
        }
    }

    return
        e_status;
}

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

        o_bits_descriptor.e_type =
            appl_bits_type_custom;

        o_bits_descriptor.u.o_custom_descriptor.p_callback_consume =
            &(
                s_consume_dummy);
        o_bits_descriptor.u.o_custom_descriptor.p_callback_produce =
            &(
                s_produce_dummy);
        o_bits_descriptor.u.o_custom_descriptor.p_callback_context =
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
        struct appl_bits_descriptor
            o_bits_descriptor;

        static unsigned char const g_bits_mem_vector[1u] =
        {
            0x5Au
        };

        o_bits_descriptor.e_type =
            appl_bits_type_mem;

        o_bits_descriptor.u.o_mem_descriptor.o_buf.o_min.pc_uchar =
            g_bits_mem_vector;

        o_bits_descriptor.u.o_mem_descriptor.o_buf.o_max.pc_uchar =
            g_bits_mem_vector + sizeof(g_bits_mem_vector);

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

            appl_bits_destroy(
                p_bits);
        }
    }

    {
        struct appl_bits_descriptor
            o_bits_descriptor;

        unsigned char g_bits_mem_vector[1u];

        o_bits_descriptor.e_type =
            appl_bits_type_mem;

        o_bits_descriptor.u.o_mem_descriptor.o_buf.o_min.pc_uchar =
            g_bits_mem_vector;

        o_bits_descriptor.u.o_mem_descriptor.o_buf.o_max.pc_uchar =
            g_bits_mem_vector + sizeof(g_bits_mem_vector);

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

            appl_bits_destroy(
                p_bits);
        }
    }

    {
        struct appl_bits_descriptor
            o_bits_descriptor;

        appl_mem_zero(
            &(
                o_bits_descriptor),
            sizeof(
                o_bits_descriptor));

        appl_bits_create(
            p_context,
            &(
                o_bits_descriptor),
            &(
                p_bits));
    }

    {
        struct appl_bits_mem_descriptor
            o_bits_mem_descriptor;

        static unsigned char const g_bits_mem_vector[1u] =
        {
            0x5Au
        };

        o_bits_mem_descriptor.o_buf.o_min.pc_uchar =
            g_bits_mem_vector;

        o_bits_mem_descriptor.o_buf.o_max.pc_uchar =
            g_bits_mem_vector + sizeof(g_bits_mem_vector);

        struct appl_bits_mem *
            p_bits_mem;

        e_status =
            appl_bits_mem_create(
                p_context,
                &(
                    o_bits_mem_descriptor),
                &(
                    p_bits_mem));

        if (
            appl_status_ok
            == e_status)
        {
            unsigned long int
                i_value;

            p_bits =
                appl_bits_mem_parent(
                    p_bits_mem);

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
        struct appl_bits_mem_descriptor
            o_bits_mem_descriptor;

        unsigned char g_bits_mem_vector[1u];

        o_bits_mem_descriptor.o_buf.o_min.p_uchar =
            g_bits_mem_vector;

        o_bits_mem_descriptor.o_buf.o_max.p_uchar =
            g_bits_mem_vector + sizeof(g_bits_mem_vector);

        struct appl_bits_mem *
            p_bits_mem;

        e_status =
            appl_bits_mem_create(
                p_context,
                &(
                    o_bits_mem_descriptor),
                &(
                    p_bits_mem));

        if (
            appl_status_ok
            == e_status)
        {
            {
                struct appl_bits const * const
                    pc_bits =
                    appl_bits_mem_const_parent(
                        p_bits_mem);

                appl_unused(
                    pc_bits);
            }

            p_bits =
                appl_bits_mem_parent(
                    p_bits_mem);

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
                appl_bits_mem_query(
                    p_bits_mem,
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

    {
        int
            e_result;

        e_result =
            1;

        // Verify normal use cases
        {
            static unsigned char g_bits_read_normal[] =
            {
                0x5au, /* 01011010 */
                0x5au, /* 01011010 */
                0x5au, /* 01011010 */
                0x5au, /* 01011010 */
                0x5au, /* 01011010 */
                0x5au, /* 01011010 */
                0x5au, /* 01011010 */
                0x5au  /* 01011010 */
            };

            struct appl_bits_descriptor
                o_bits_descriptor;

            o_bits_descriptor.e_type =
                appl_bits_type_mem;

            o_bits_descriptor.u.o_mem_descriptor.o_buf.o_min.pc_uchar =
                g_bits_read_normal;

            o_bits_descriptor.u.o_mem_descriptor.o_buf.o_max.pc_uchar =
                g_bits_read_normal + sizeof(g_bits_read_normal);

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
                if (
                    appl_status_ok
                    == appl_bits_test_verify_value(
                        p_bits,
                        2u,
                        1ul))
                {
                }
                else
                {
                    e_result =
                        0;
                }

                if (
                    appl_status_ok
                    == appl_bits_test_verify_value(
                        p_bits,
                        3u,
                        3ul))
                {
                }
                else
                {
                    e_result =
                        0;
                }

                if (
                    appl_status_ok
                    == appl_bits_test_verify_value(
                        p_bits,
                        5u,
                        9ul))
                {
                }
                else
                {
                    e_result =
                        0;
                }

                if (
                    appl_status_ok
                    == appl_bits_test_verify_value(
                        p_bits,
                        7u,
                        0x34ul))
                {
                }
                else
                {
                    e_result =
                        0;
                }

                appl_bits_destroy(
                    p_bits);
            }
            else
            {
                e_result =
                    0;
            }
        }

        // Verify limit use cases

        appl_print0(
            e_result
            ? "PASS\n"
            : "FAIL\n");
    }

} // appl_bits_test_1()

/* end-of-file: appl_bits_test.cpp */
