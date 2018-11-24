/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_allocator_handle_h
{
    inc_appl_allocator_handle_h =
        /* Header file dependencies */
        inc_appl_status_h
        + inc_appl_types_h
};

/* Predefine */
struct appl_object;

/* Predefine */
struct appl_allocator;

#if defined __cplusplus
extern "C" {
#endif /* #if defined __cplusplus */

struct appl_object *
    appl_allocator_parent(
        struct appl_allocator * const
            p_allocator);

enum appl_status
    appl_allocator_alloc(
        struct appl_allocator * const
            p_allocator,
        appl_size_t const
            i_buf_len,
        void * * const
            r_buf);

enum appl_status
    appl_allocator_free(
        struct appl_allocator * const
            p_allocator,
        appl_size_t const
            i_buf_len,
        void * const
            p_buf);

#if defined __cplusplus
} /* extern "C" */
#endif /* #if defined __cplusplus */

/* C++ Wrappers to avoid casts */
#if defined __cplusplus

//
//
//
template <typename T_instance>
enum appl_status
    appl_allocator_alloc_structure(
        struct appl_allocator * const
            p_allocator,
        T_instance * * const
            r_instance)
{
    union appl_allocator_alloc_structure_ptr
    {
        void * *
            r_void;

        T_instance * *
            r_instance;

    } o_structure_ptr;

    o_structure_ptr.r_instance =
        r_instance;

    return
        appl_allocator_alloc(
            p_allocator,
            sizeof(T_instance),
            o_structure_ptr.r_void);

} // appl_allocator_alloc_structure()

//
//
//
template <typename T_instance>
enum appl_status
    appl_allocator_free_structure(
        struct appl_allocator * const
            p_allocator,
        T_instance * const
            p_instance)
{
    return
        appl_allocator_free(
            p_allocator,
            sizeof(T_instance),
            p_instance);

} // appl_allocator_free_structure()

#if defined INC_APPL_OBJECT_H

//
//
//
template <typename T_instance>
enum appl_status
    appl_allocator_alloc_object(
        struct appl_context * const
            p_context,
        struct appl_allocator * const
            p_allocator,
        T_instance * * const
            r_object)
{
    enum appl_status
        e_status;

    void *
        p_placement;

    e_status =
        appl_allocator_alloc(
            p_allocator,
            sizeof(T_instance),
            &(
                p_placement));

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            appl_object::init_object(
                p_context,
                p_allocator,
                p_placement,
                sizeof(T_instance),
                r_object);

        if (
            appl_status_ok
            != e_status)
        {
            appl_allocator_free(
                p_allocator,
                sizeof(T_instance),
                p_placement);
        }
    }

    return
        e_status;

} // appl_allocator_alloc_object()

//
//
//
template <typename T_instance, typename T_descriptor>
enum appl_status
    appl_allocator_alloc_object(
        struct appl_context * const
            p_context,
        struct appl_allocator * const
            p_allocator,
        T_descriptor const * const
            p_descriptor,
        T_instance * * const
            r_object)
{
    enum appl_status
        e_status;

    void *
        p_placement;

    e_status =
        appl_allocator_alloc(
            p_allocator,
            sizeof(T_instance),
            &(
                p_placement));

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            appl_object::init_object(
                p_context,
                p_allocator,
                p_placement,
                sizeof(T_instance),
                p_descriptor,
                r_object);

        if (
            appl_status_ok
            != e_status)
        {
            appl_allocator_free(
                p_allocator,
                sizeof(T_instance),
                p_placement);
        }
    }

    return
        e_status;

} // appl_allocator_alloc_object()

#endif /* #if defined INC_APPL_OBJECT_H */

#endif /* #if defined __cplusplus */

/* end-of-file: appl_allocator_handle.h */
