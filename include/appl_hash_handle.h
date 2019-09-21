/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_hash_handle_h
{
    inc_appl_hash_handle_h =
        /* Header file dependencies */
        inc_appl_status_h
        + inc_appl_types_h
};

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

    appl_size_t
        i_max_index;

}; /* struct appl_hash_descriptor */

#include <appl_extern_c_begin.h>

enum appl_status
appl_hash_create(
    struct appl_context * const
        p_context,
    struct appl_hash_descriptor const * const
        p_descriptor,
    struct appl_hash * * const
        r_instance);

enum appl_status
appl_hash_destroy(
    struct appl_hash * const
        p_instance);

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

char
appl_hash_lookup(
    struct appl_hash * const
        p_hash,
    void const * const
        p_key,
    unsigned long int const
        i_key_len,
    struct appl_list * * const
        r_list);

void
appl_hash_iterate(
    struct appl_hash * const
        p_hash,
    void (
        * p_callback)(
        void * const
            p_context,
        struct appl_list * const
            p_list),
    void * const
        p_context);

#include <appl_extern_c_end.h>

/* end-of-file: appl_hash_handle.h */
