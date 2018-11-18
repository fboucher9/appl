/* See LICENSE for license details */

/*

*/

#include <stdio.h>

#include <string.h>

#include <appl.h>

#include <hash/appl_hash_test.h>

#include <appl_crc16.h>

/*

*/
struct appl_hash_test_node
{
    struct appl_list
        o_list;

    /* -- */

    char const *
        p_string;

    int
        i_string_len;

#define PADDING (APPL_SIZEOF_PTR + APPL_SIZEOF_INT)
#include <appl_padding.h>

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
        appl_crc16(
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
            p_context,
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
        p_context,
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
