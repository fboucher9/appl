/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_unique_handle_h
{
    inc_appl_unique_handle_h = 1
        | inc_appl_status_h
}; /* enum guard_appl_unique_handle_h */

/* Predefine */
struct appl_unique;

enum appl_status
appl_unique_create(
    struct appl_context * const
        p_context,
    struct appl_unique * * const
        r_unique);

enum appl_status
appl_unique_destroy(
    struct appl_unique * const
        p_unique);

struct appl_object *
appl_unique_parent(
    struct appl_unique * const
        p_unique);

struct appl_object const *
appl_unique_const_parent(
    struct appl_unique const * const
        p_unique);

unsigned long int
appl_unique_get(
    struct appl_unique const * const
        p_unique);

/* end-of-file: appl_unique_handle.h */
