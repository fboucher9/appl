/* See LICENSE for license details */

/*

Installation:
    gcc -I. -Iinclude
        buf/appl_buf_filter_main.c
        buf/appl_buf_filter.cpp
        buf/appl_buf.cpp

Usage:
    ./a.out class a-c1-3
    ./a.out list abc123

*/

#include <stdio.h>

#include <string.h>

#include <buf/appl_buf_filter.h>

#include <buf/appl_buf.h>

static
void
dump_filter(
    struct appl_buf const * const
        p_filter)
{
    printf("static unsigned char const s_filter[] =\n");
    printf("{\n");
    {
        struct appl_buf
            o_filter_iterator;

        o_filter_iterator =
            *(
                p_filter);

        while (
            o_filter_iterator.o_min.pc_uchar
            < o_filter_iterator.o_max.pc_uchar)
        {
            unsigned char const
                c_data =
                *(
                    o_filter_iterator.o_min.pc_uchar);

            o_filter_iterator.o_min.pc_uchar ++;

            if (
                o_filter_iterator.o_min.pc_uchar
                < o_filter_iterator.o_max.pc_uchar)
            {
                printf(
                    "    0x%02hxu,\n",
                    (unsigned short int)(c_data & 0xFFu));
            }
            else
            {
                printf(
                    "    0x%02hxu\n",
                    (unsigned short int)(c_data & 0xFFu));
            }
        }
    }
    printf("};\n");
}

static
void
dispatch_class(
    int const
        argc,
    char const * const * const
        argv)
{
    if (
        argc > 1)
    {
        struct appl_buf
            o_class;

        unsigned long int
            i_length;

        unsigned char
            a_filter[64u];

        o_class.o_min.pc_uchar =
            (unsigned char const *)(
                argv[1u]);

        o_class.o_max.pc_uchar =
            (unsigned char const *)(
                argv[1u]
                + strlen(
                    argv[1u]));

        i_length =
            appl_buf_filter_get_class_length(
                &(
                    o_class));

        if (
            i_length <= (unsigned long int)(sizeof(a_filter)))
        {
            struct appl_buf
                o_filter;

            o_filter.o_min.p_uchar =
                a_filter;

            o_filter.o_max.p_uchar =
                a_filter + i_length;

            appl_buf_filter_convert_class(
                &(
                    o_filter),
                &(
                    o_class));

            dump_filter(
                &(
                    o_filter));
        }
    }
}

static
void
dispatch_list(
    int const
        argc,
    char const * const * const
        argv)
{
    if (
        argc > 1)
    {
        struct appl_buf
            o_list;

        unsigned long int
            i_length;

        unsigned char
            a_filter[64u];

        o_list.o_min.pc_uchar =
            (unsigned char const *)(
                argv[1u]);

        o_list.o_max.pc_uchar =
            (unsigned char const *)(
                argv[1u]
                + strlen(
                    argv[1u]));

        i_length =
            appl_buf_filter_get_list_length(
                &(
                    o_list));

        if (
            i_length <= (unsigned long int)(sizeof(a_filter)))
        {
            struct appl_buf
                o_filter;

            o_filter.o_min.p_uchar =
                a_filter;

            o_filter.o_max.p_uchar =
                a_filter + i_length;

            appl_buf_filter_convert_list(
                &(
                    o_filter),
                &(
                    o_list));

            dump_filter(
                &(
                    o_filter));
        }
    }
}


int
    main(
        int const
            argc,
        char const * const * const
            argv)
{
    if (
        argc > 1)
    {
        if (
            0
            == strcmp(
                argv[1u],
                "class"))
        {
            dispatch_class(
                argc - 1,
                argv + 1);
        }
        else if (
            0
            == strcmp(
                argv[1u],
                "list"))
        {
            dispatch_list(
                argc - 1,
                argv + 1);
        }
        else
        {
        }
    }
    else
    {
    }

    return
        0;

}

