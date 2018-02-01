/* See LICENSE for license details */

/*

*/

#include "appl_list.h"

/*

Function: appl_list_init()

Description:

    Initialize an element so that it's a list with a single element, itself.

Parameters:

    p_node
        Pointer to element to initialize

Returns: None.

Comments: None.

*/
void
appl_list_init(
    struct appl_list * const
        p_list)
{
    p_list->p_next =
        p_list;

    p_list->p_prev =
        p_list;

} /* appl_list_init() */

/*

Function: appl_list_join()

Description:

    Join two elements together.

Parameters:

    p_before
        Pointer to first element to join.  This element will end up before
        the p_after element.

    p_after
        Pointer to second element to join.  This element will end up after
        the p_before element.

Comments:

    If the elements are in different lists, the two lists will become one.

    If the elements are in the same list, then there will be two lists.

*/
void
appl_list_join(
    struct appl_list * const
        p_list_left,
    struct appl_list * const
        p_list_right)
{
    /* AB(C) - (D)EF > ABCDEF */
    p_list_left->p_next->p_prev =
        p_list_right->p_prev;

    p_list_right->p_prev->p_next =
        p_list_left->p_next;

    p_list_left->p_next =
        p_list_right;

    p_list_right->p_prev =
        p_list_left;

} /* appl_list_join() */

/* end-of-file: appl_list.cpp */
