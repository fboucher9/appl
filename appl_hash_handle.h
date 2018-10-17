/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_HASH_HANDLE_H
#error include appl_hash_handle.h once
#endif /* #if defined INC_APPL_HASH_HANDLE_H */

#define INC_APPL_HASH_HANDLE_H

/* Predefine */
struct appl_context;

/* Predefine */
struct appl_object;

/* Predefine */
struct appl_hash;

/*

*/
struct appl_hash_descriptor
{
    int
        (* p_compare)(
            void * const
                p_context,
            void const * const
                p_key,
            unsigned long int const
                i_key_len,
            struct appl_list * const
                p_node);

    unsigned long int
        (* p_index)(
            void * const
                p_context,
            void const * const
                p_key,
            unsigned long int const
                i_key_len);

    /* -- */

    void *
        p_context;

    void *
        pv_padding[1u];

    /* -- */

    unsigned long int
        i_max_index;

    unsigned long int
        ul_padding[1u];

}; /* struct appl_hash_descriptor */

#if defined __cplusplus
extern "C" {
#endif /* #if defined __cplusplus */

enum appl_status
appl_hash_create(
    struct appl_context * const
        p_context,
    struct appl_hash_descriptor const * const
        p_descriptor,
    struct appl_hash * * const
        r_instance);

struct appl_object *
appl_hash_parent(
    struct appl_hash * const
        p_hash);

void
appl_hash_insert(
    struct appl_hash * const
        p_hash,
    void const * const
        p_key,
    unsigned long int const
        i_key_len,
    struct appl_list * const
        p_list);

struct appl_list *
appl_hash_lookup(
    struct appl_hash * const
        p_hash,
    void const * const
        p_key,
    unsigned long int const
        i_key_len);

#if defined __cplusplus
} /* extern "C" */
#endif /* #if defined __cplusplus */

/* end-of-file: appl_hash_handle.h */
