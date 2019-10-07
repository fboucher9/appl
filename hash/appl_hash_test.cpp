/* See LICENSE for license details */

/*

*/

#include <stdio.h>

#include <string.h>

#include <appl.h>

#include <hash/appl_hash_test.h>

#include <appl_unused.h>

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
#include <misc/appl_padding.h>

}; /* struct appl_hash_test_node */

union appl_hash_test_node_ptr
{
    struct appl_list *
        p_list;

    struct appl_hash_test_node *
        p_hash_test_node;

};

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

    union appl_hash_test_node_ptr
        o_hash_test_node_ptr;

    struct appl_hash_test_node const *
        p_hash_test_node;

    appl_unused(
        p_context,
        i_key_len);

    o_hash_test_node_ptr.p_list =
        p_list;

    p_hash_test_node =
        o_hash_test_node_ptr.p_hash_test_node;

    i_compare_result =
        strcmp(
            p_hash_test_node->p_string,
            static_cast<char const *>(
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
    appl_unused(
        p_context,
        i_key_len);

    unsigned char const * const
        p_uchar =
        static_cast<unsigned char const *>(
            p_key);

    return
        *(
            p_uchar);

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

    struct appl_hash_test_node *
        p_node;

    e_status =
        appl_heap_alloc_structure(
            p_context,
            &(
                p_node));

    if (
        appl_status_ok
        == e_status)
    {
        appl_list_init(
            &(
                p_node->o_list));

        p_node->p_string =
            p_string;

        p_node->i_string_len =
            static_cast<int>(
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

    appl_size_t
        i_placement_length;

    p_placement =
        static_cast<void *>(
            p_node);

    i_placement_length =
        sizeof(
            struct appl_hash_test_node);

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

    appl_unused(
        p_context);

    p_node =
        reinterpret_cast<struct appl_hash_test_node *>(
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
        static_cast<void *>(
            p_hash));

} /* appl_hash_test_dump() */

/*

Function: appl_hash_test()

Description:
    Test of appl_hash module.

*/
void
appl_hash_test_1(
    struct appl_context * const
        p_context)
{
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
            {
                struct appl_object *
                    p_object;

                p_object =
                    appl_hash_parent(
                        p_hash);

                appl_unused(
                    p_object);
            }

            static char const g_good_key1[] = "felix";

            static char const g_good_key2[] = "falafel";

            static char const g_bad_key[] = "bad";

            /* create some nodes */
            struct appl_hash_test_node *
                p_node1;

            e_status =
                appl_hash_test_create_node(
                    p_context,
                    g_good_key1,
                    &(
                        p_node1));

            if (
                appl_status_ok
                == e_status)
            {
                /* insert into hash table */
                appl_hash_insert(
                    p_hash,
                    static_cast<void const *>(
                        p_node1->p_string),
                    static_cast<unsigned long int>(
                        p_node1->i_string_len),
                    &(
                        p_node1->o_list));

                struct appl_hash_test_node *
                    p_node2;

                e_status =
                    appl_hash_test_create_node(
                        p_context,
                        g_good_key2,
                        &(
                            p_node2));

                if (
                    appl_status_ok
                    == e_status)
                {
                    appl_hash_insert(
                        p_hash,
                        static_cast<void const *>(
                            p_node2->p_string),
                        static_cast<unsigned long int>(
                            p_node2->i_string_len),
                        &(
                            p_node2->o_list));

                    /* Verify */
                    appl_hash_test_dump(
                        p_hash);

                    // Lookup good and bad
                    {
                        struct appl_list *
                            p_lookup_result;

                        appl_hash_lookup(
                            p_hash,
                            g_good_key1,
                            static_cast<unsigned long int>(sizeof(g_good_key1) - 1),
                            &(
                                p_lookup_result));

                        appl_hash_lookup(
                            p_hash,
                            g_good_key2,
                            static_cast<unsigned long int>(sizeof(g_good_key2) - 1),
                            &(
                                p_lookup_result));

                        appl_hash_lookup(
                            p_hash,
                            g_bad_key,
                            static_cast<unsigned long int>(sizeof(g_bad_key) - 1),
                            &(
                                p_lookup_result));
                    }

                    appl_hash_test_destroy_node(
                        p_context,
                        p_node2);
                }

                appl_hash_test_destroy_node(
                    p_context,
                    p_node1);
            }

            /* locate nodes */

            /* remove nodes */

            /* iterate */

            appl_hash_destroy(
                p_hash);
        }
    }

} /* appl_hash_test() */

/* end-of-file: appl_hash_test.c */
