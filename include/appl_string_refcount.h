/* See LICENSE for license details */

/* Predefine */
struct appl_refcount;

/* Predefine */
struct appl_string_refcount;

#if defined __cplusplus
extern "C" {
#endif /* #if defined __cplusplus */

enum appl_status
    appl_string_refcount_create(
        struct appl_string * const
            p_string,
        struct appl_string_refcount * * const
            r_instance);

struct appl_refcount *
    appl_string_refcount_parent(
        struct appl_string_refcount * const
            p_string_refcount);

struct appl_string *
    appl_string_refcount_get(
        struct appl_string_refcount const * const
            p_string_refcount);

#if defined __cplusplus
} /* extern "C" */
#endif /* #if defined __cplusplus */

/* end-of-file: appl_string_refcount.h */
