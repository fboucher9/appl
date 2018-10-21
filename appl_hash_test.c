/* See LICENSE for license details */

/*

*/

#include <stdio.h>

#include <string.h>

#include <appl.h>

#include <appl_hash_test.h>

/*

*/
static
unsigned short int
appl_crc16_read(
    unsigned char const * const
        p_buf,
    unsigned long int const
        i_buf_len)
{
    static unsigned short int const a_crc16_table[256] =
    {
        0x0000, 0x1189, 0x2312, 0x329B, 0x4624, 0x57AD, 0x6536, 0x74BF,
        0x8C48, 0x9DC1, 0xAF5A, 0xBED3, 0xCA6C, 0xDBE5, 0xE97E, 0xF8F7,
        0x0919, 0x1890, 0x2A0B, 0x3B82, 0x4F3D, 0x5EB4, 0x6C2F, 0x7DA6,
        0x8551, 0x94D8, 0xA643, 0xB7CA, 0xC375, 0xD2FC, 0xE067, 0xF1EE,
        0x1232, 0x03BB, 0x3120, 0x20A9, 0x5416, 0x459F, 0x7704, 0x668D,
        0x9E7A, 0x8FF3, 0xBD68, 0xACE1, 0xD85E, 0xC9D7, 0xFB4C, 0xEAC5,
        0x1B2B, 0x0AA2, 0x3839, 0x29B0, 0x5D0F, 0x4C86, 0x7E1D, 0x6F94,
        0x9763, 0x86EA, 0xB471, 0xA5F8, 0xD147, 0xC0CE, 0xF255, 0xE3DC,
        0x2464, 0x35ED, 0x0776, 0x16FF, 0x6240, 0x73C9, 0x4152, 0x50DB,
        0xA82C, 0xB9A5, 0x8B3E, 0x9AB7, 0xEE08, 0xFF81, 0xCD1A, 0xDC93,
        0x2D7D, 0x3CF4, 0x0E6F, 0x1FE6, 0x6B59, 0x7AD0, 0x484B, 0x59C2,
        0xA135, 0xB0BC, 0x8227, 0x93AE, 0xE711, 0xF698, 0xC403, 0xD58A,
        0x3656, 0x27DF, 0x1544, 0x04CD, 0x7072, 0x61FB, 0x5360, 0x42E9,
        0xBA1E, 0xAB97, 0x990C, 0x8885, 0xFC3A, 0xEDB3, 0xDF28, 0xCEA1,
        0x3F4F, 0x2EC6, 0x1C5D, 0x0DD4, 0x796B, 0x68E2, 0x5A79, 0x4BF0,
        0xB307, 0xA28E, 0x9015, 0x819C, 0xF523, 0xE4AA, 0xD631, 0xC7B8,
        0x48C8, 0x5941, 0x6BDA, 0x7A53, 0x0EEC, 0x1F65, 0x2DFE, 0x3C77,
        0xC480, 0xD509, 0xE792, 0xF61B, 0x82A4, 0x932D, 0xA1B6, 0xB03F,
        0x41D1, 0x5058, 0x62C3, 0x734A, 0x07F5, 0x167C, 0x24E7, 0x356E,
        0xCD99, 0xDC10, 0xEE8B, 0xFF02, 0x8BBD, 0x9A34, 0xA8AF, 0xB926,
        0x5AFA, 0x4B73, 0x79E8, 0x6861, 0x1CDE, 0x0D57, 0x3FCC, 0x2E45,
        0xD6B2, 0xC73B, 0xF5A0, 0xE429, 0x9096, 0x811F, 0xB384, 0xA20D,
        0x53E3, 0x426A, 0x70F1, 0x6178, 0x15C7, 0x044E, 0x36D5, 0x275C,
        0xDFAB, 0xCE22, 0xFCB9, 0xED30, 0x998F, 0x8806, 0xBA9D, 0xAB14,
        0x6CAC, 0x7D25, 0x4FBE, 0x5E37, 0x2A88, 0x3B01, 0x099A, 0x1813,
        0xE0E4, 0xF16D, 0xC3F6, 0xD27F, 0xA6C0, 0xB749, 0x85D2, 0x945B,
        0x65B5, 0x743C, 0x46A7, 0x572E, 0x2391, 0x3218, 0x0083, 0x110A,
        0xE9FD, 0xF874, 0xCAEF, 0xDB66, 0xAFD9, 0xBE50, 0x8CCB, 0x9D42,
        0x7E9E, 0x6F17, 0x5D8C, 0x4C05, 0x38BA, 0x2933, 0x1BA8, 0x0A21,
        0xF2D6, 0xE35F, 0xD1C4, 0xC04D, 0xB4F2, 0xA57B, 0x97E0, 0x8669,
        0x7787, 0x660E, 0x5495, 0x451C, 0x31A3, 0x202A, 0x12B1, 0x0338,
        0xFBCF, 0xEA46, 0xD8DD, 0xC954, 0xBDEB, 0xAC62, 0x9EF9, 0x8F70
    };

    unsigned short int
        i_crc16;

    unsigned char const *
        p_buf_iterator;

    unsigned char const *
        p_buf_end;

    i_crc16 =
        0xFFFF;

    p_buf_iterator =
        p_buf;

    p_buf_end =
        p_buf + i_buf_len;

    while (
        p_buf_iterator != p_buf_end)
    {
        i_crc16 =
            (unsigned short int)(
                (
                    ((unsigned int)(i_crc16) << 8u)
                    ^ a_crc16_table[
                        (
                            ((unsigned int)(i_crc16) >> 8u)
                            ^ (*p_buf_iterator))
                        & 0xFFu])
                & 0xFFFFu);

        p_buf_iterator ++;
    }

    return
        i_crc16;

} /* appl_crc16_read() */

/*

*/
struct appl_hash_test_node
{
    struct appl_list
        o_list;

    /* -- */

    char const *
        p_string;

    void *
        pv_padding[1u];

    /* -- */

    int
        i_string_len;

    unsigned int
        ui_padding[3u];

}; /* struct appl_hash_test_node */

/*

*/
static
int
appl_hash_test_compare_string(
    void * const
        p_context,
    void const * const
        p_key,
    unsigned long int const
        i_key_len,
    struct appl_list * const
        p_list)
{
    int
        i_compare_result;

    struct appl_hash_test_node const *
        p_hash_test_node;

    (void)(
        p_context);
    (void)(
        i_key_len);

    p_hash_test_node =
        (struct appl_hash_test_node const *)(
            p_list);

    i_compare_result =
        strcmp(
            p_hash_test_node->p_string,
            (char const *)(
                p_key));

    return
        i_compare_result;

} /* appl_hash_test_compare_string() */

/*

*/
static
unsigned long int
appl_hash_test_index_string(
    void * const
        p_context,
    void const * const
        p_key,
    unsigned long int const
        i_key_len)
{
    (void)(
        p_context);

    return
        appl_crc16_read(
            (unsigned char const *)(
                p_key),
            i_key_len);

} /* appl_hash_test_index_string() */

/*

*/
static
enum appl_status
appl_hash_test_create_node(
    struct appl_context * const
        p_context,
    char const * const
        p_string,
    struct appl_hash_test_node * * const
        r_node)
{
    enum appl_status
        e_status;

    unsigned long int
        i_placement_length;

    void *
        p_placement;

    i_placement_length =
        (unsigned long int)(
            sizeof(
                struct appl_hash_test_node));

    e_status =
        appl_heap_alloc(
            appl_context_parent(
                p_context),
            i_placement_length,
            &(
                p_placement));

    if (
        appl_status_ok
        == e_status)
    {
        struct appl_hash_test_node *
            p_node;

        p_node =
            (struct appl_hash_test_node *)(
                p_placement);

        appl_list_init(
            &(
                p_node->o_list));

        p_node->p_string =
            p_string;

        p_node->i_string_len =
            (int)(
                strlen(
                    p_string));

        *(
            r_node) =
            p_node;
    }

    return
        e_status;

} /* appl_hash_test_create_node() */

/*

*/
static
void
appl_hash_test_destroy_node(
    struct appl_context * const
        p_context,
    struct appl_hash_test_node * const
        p_node)
{
    void *
        p_placement;

    unsigned long int
        i_placement_length;

    p_placement =
        (void *)(
            p_node);

    i_placement_length =
        (unsigned long int)(
            sizeof(
                struct appl_hash_test_node));

    appl_list_join(
        &(
            p_node->o_list),
        &(
            p_node->o_list));

    appl_heap_free(
        appl_context_parent(
            p_context),
        i_placement_length,
        p_placement);

} /* appl_hash_test_destroy_node() */

/*

*/
static
void
appl_hash_test_dump_callback(
    void * const
        p_context,
    struct appl_list * const
        p_list)
{
    struct appl_hash_test_node *
        p_node;

    (void)(
        p_context);

    p_node =
        (struct appl_hash_test_node *)(
            p_list);

    printf(
        "[%s]\n",
        p_node->p_string);

} /* appl_hash_test_dump_callback() */

/*

*/
static
void
appl_hash_test_dump(
    struct appl_hash * const
        p_hash)
{
    appl_hash_iterate(
        p_hash,
        &(
            appl_hash_test_dump_callback),
        (void *)(
            p_hash));

} /* appl_hash_test_dump() */

/*

Function: appl_hash_test()

Description:
    Test of appl_hash module.

*/
void
appl_hash_test(
    struct appl_context * const
        p_context)
{
    enum appl_status
        e_status;

    struct appl_hash *
        p_hash;

    struct appl_hash_descriptor
        o_hash_descriptor;

    o_hash_descriptor.p_compare =
        &(
            appl_hash_test_compare_string);

    o_hash_descriptor.p_index =
        &(
            appl_hash_test_index_string);

    o_hash_descriptor.i_max_index =
        16ul;

    e_status =
        appl_hash_create(
            p_context,
            &(
                o_hash_descriptor),
            &(
                p_hash));

    if (
        appl_status_ok
        == e_status)
    {
        /* create some nodes */
        struct appl_hash_test_node *
            p_node;

        e_status =
            appl_hash_test_create_node(
                p_context,
                "felix",
                &(
                    p_node));

        if (
            appl_status_ok
            == e_status)
        {
            /* insert into hash table */
            appl_hash_insert(
                p_hash,
                (void const *)(
                    p_node->p_string),
                (unsigned long int)(
                    p_node->i_string_len),
                &(
                    p_node->o_list));

            /* Verify */
            appl_hash_test_dump(
                p_hash);

            appl_hash_test_destroy_node(
                p_context,
                p_node);
        }

        /* locate nodes */

        /* remove nodes */

        /* iterate */

        appl_object_destroy(
            appl_hash_parent(
                p_hash));
    }

} /* appl_hash_test() */

/* end-of-file: appl_hash_test.c */
