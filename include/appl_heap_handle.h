/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_heap_handle_h
{
    inc_appl_heap_handle_h =
        /* Header file dependency */
        inc_appl_status_h
        + inc_appl_types_h
};

/* Predefine */
struct appl_context;

#if defined(__cplusplus)
extern "C" {
#endif /* #if defined(__cplusplus) */

enum appl_status
appl_heap_alloc(
    struct appl_context const * const
        p_context,
    appl_size_t const
        i_length,
    void * * const
        r_buf);

enum appl_status
appl_heap_free(
    struct appl_context const * const
        p_context,
    appl_size_t const
        i_length,
    void * const
        p_buf);

#if defined(__cplusplus)
} /* extern "C" */
#endif /* #if defined(__cplusplus) */

#if defined __cplusplus

//
//
//
template <typename T_instance>
enum appl_status
    appl_heap_alloc_structure_array(
        struct appl_context * const
            p_context,
        appl_size_t const
            i_count,
        T_instance * * const
            r_object_array)
{
    enum appl_status
        e_status;

    union object_ptr
    {
        void *
            p_placement;

        T_instance *
            p_instance;

    } o_object_ptr;

    e_status =
        appl_heap_alloc(
            p_context,
            sizeof(
                T_instance)
            * i_count,
            &(
                o_object_ptr.p_placement));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_object_array) =
            o_object_ptr.p_instance;
    }

    return
        e_status;

} // alloc_structure_array()

//
//
//
template <typename T_instance>
enum appl_status
    appl_heap_alloc_structure(
        struct appl_context * const
            p_context,
        T_instance * * const
            r_object_array)
{
    return
        appl_heap_alloc_structure_array(
            p_context,
            1,
            r_object_array);

} // alloc_structure()

//
//
//
template <typename T_instance>
enum appl_status
    appl_heap_free_structure_array(
        struct appl_context * const
            p_context,
        appl_size_t const
            i_count,
        T_instance * const
            p_object_array)
{
    enum appl_status
        e_status;

    union object_ptr
    {
        void *
            p_placement;

        T_instance *
            p_instance;

    } o_object_ptr;

    o_object_ptr.p_instance =
        p_object_array;

    e_status =
        appl_heap_free(
            p_context,
            sizeof(
                T_instance)
            * i_count,
            o_object_ptr.p_placement);

    return
        e_status;

} // free_structure_array()

template <typename T_instance>
enum appl_status
    appl_heap_free_structure(
        struct appl_context * const
            p_context,
        T_instance * const
            p_object)
{
    return
        appl_heap_free_structure_array(
            p_context,
            1,
            p_object);
}

#endif /* #if defined __cplusplus */

/* end-of-file: appl_heap_handle.h */
