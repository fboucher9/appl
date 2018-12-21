/* See LICENSE for license details */

/*

*/

/* Included. */
#define INC_APPL_DICT_HANDLE_H

/* Reverse include guard */
enum guard_appl_dict_handle_h
{
    inc_appl_dict_handle_h =
        inc_appl_status_h
};

/* Predefine */
struct appl_context;

/* Predefine */
struct appl_dict;

#if defined __cplusplus
extern "C" {
#endif /* #if defined __cplusplus */

/* Create a dictionary object */
enum appl_status
appl_dict_create(
    struct appl_context * const
        p_context,
    struct appl_dict * * const
        r_dict);

/* Destroy a dictionary object */
enum appl_status
appl_dict_destroy(
    struct appl_context * const
        p_context,
    struct appl_dict * const
        p_dict);

/* Get pointer to base class */
struct appl_object *
appl_dict_parent(
    struct appl_dict * const
        p_dict);

/* Insert value into the dictionary */
enum appl_status
appl_dict_set(
    struct appl_dict * const
        p_dict,
    unsigned char const * const
        p_name_min,
    unsigned char const * const
        p_name_max,
    void * const
        p_value);

/* Query value from dictionary */
enum appl_status
appl_dict_get(
    struct appl_dict * const
        p_dict,
    unsigned char const * const
        p_name_min,
    unsigned char const * const
        p_name_max,
    void * * const
        r_value);

#if defined __cplusplus
} /* extern "C" */
#endif /* #if defined __cplusplus */

/* In C++, a wrapper may be used to support different types: */
#if defined __cplusplus
template <typename T_instance>
enum appl_status
appl_dict_set_structure(
    struct appl_dict * const
        p_dict,
    unsigned char const * const
        p_name_min,
    unsigned char const * const
        p_name_max,
    T_instance * const
        p_object)
{
    union appl_dict_set_object_ptr
    {
        void *
            p_void;

        T_instance *
            p_object;
    } o_object_ptr;

    o_object_ptr.p_object =
        p_object;

    return
        appl_dict_set(
            p_dict,
            p_name_min,
            p_name_max,
            o_object_ptr.p_void);
}

template <typename T_instance>
enum appl_status
appl_dict_get_structure(
    struct appl_dict * const
        p_dict,
    unsigned char const * const
        p_name_min,
    unsigned char const * const
        p_name_max,
    T_instance * * const
        r_object)
{
    union appl_dict_get_object_ref
    {
        void * *
            r_void;

        T_instance * *
            r_object;

    } o_object_ref;

    o_object_ref.r_object =
        r_object;

    return
        appl_dict_get(
            p_dict,
            p_name_min,
            p_name_max,
            o_object_ref.r_void);

} /* appl_dict_get_object() */
#endif /* #if defined __cplusplus */

/* end-of-file: appl_dict_handle.h */
