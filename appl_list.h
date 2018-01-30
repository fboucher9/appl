/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined(INC_APPL_LIST_H)
#error include appl_list.h once
#endif /* #if defined(INC_APPL_LIST_H) */

#define INC_APPL_LIST_H

struct appl_list;

/* list */
struct appl_list
{
    struct appl_list *
        p_next;

    struct appl_list *
        p_prev;

}; /* struct appl_list */

#if defined(__cplusplus)
extern "C" {
#endif /* #if defined(__cplusplus) */

/* list methods */
void
appl_list_init(
    struct appl_list * const
        p_list);

void
appl_list_join(
    struct appl_list * const
        p_list_left,
    struct appl_list * const
        p_list_right);

#if defined(__cplusplus)
} /* extern "C" */
#endif /* #if defined(__cplusplus) */

/* end-of-file: appl_list.h */
