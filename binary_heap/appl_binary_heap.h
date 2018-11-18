/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_binary_heap_h
{
    inc_appl_binary_heap_h =
        /* Header file dependencies */
        inc_appl_status_h
};

/* Predefine */
struct appl_context;

/* Predefine */
struct appl_object;

/* Predefine */
struct appl_binary_heap;

/*

*/
struct appl_binary_heap_descriptor
{
    /* p_data_1 - p_data_2 */
    int (* p_compare)(
        void * const
            p_compare_context,
        void const * const
            p_data_1,
        void const * const
            p_data_2);

    void *
        p_compare_context;

    /* -- */

    unsigned long int
        i_initial_max;

    unsigned long int
        ul_padding[1u];

}; /* struct appl_binary_heap_descriptor */

#if defined __cplusplus
extern "C" {
#endif /* #if defined __cplusplus */

enum appl_status
    appl_binary_heap_create(
        struct appl_context * const
            p_context,
        struct appl_binary_heap_descriptor const * const
            p_binary_heap_descriptor,
        struct appl_binary_heap * * const
            r_instance);

struct appl_object *
    appl_binary_heap_parent(
        struct appl_binary_heap * const
            p_binary_heap);

enum appl_status
    appl_binary_heap_insert(
        struct appl_binary_heap * const
            p_binary_heap,
        void * const
            p_data);

enum appl_status
    appl_binary_heap_remove(
        struct appl_binary_heap * const
            p_binary_heap,
        void * * const
            r_data);

#if defined __cplusplus
} /* extern "C"  */
#endif /* #if defined __cplusplus */

/* end-of-file: appl_binary_heap.h */
