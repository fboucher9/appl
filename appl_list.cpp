/* See LICENSE for license details */

/*

Module: appl_list.cpp

Description:

    Linked list

*/

#include <appl_list.h>

/*

Function: appl_list_init()

Description:

    Initialize an element so that it's a list with a single element, itself.

Parameters:

    p_list
        Pointer to element to initialize

Returns: None.

Comments: None.

*/
void
appl_list_init(
    struct appl_list * const
        p_list)
{
    p_list->o_next.pc_node =
        p_list;

    p_list->o_prev.pc_node =
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
    p_list_left->o_next.p_node->o_prev.pc_node =
        p_list_right->o_prev.pc_node;

    p_list_right->o_prev.p_node->o_next.pc_node =
        p_list_left->o_next.pc_node;

    p_list_left->o_next.pc_node =
        p_list_right;

    p_list_right->o_prev.pc_node =
        p_list_left;

} /* appl_list_join() */

/*

Function: appl_iterator_init

Description:

    Initialize iterator object by pointing to beginning and end of
    a linked list.

Parameters:

    p_iterator
        Pointer to iterator object to initialize

    p_list
        Pointer to header element of linked list

Comments:

    -   Once initialized, the iterator is ready to scan a linked list in
        both directions using the appl_iterator_next and appl_iterator_prev
        functions.

    -   Application must call appl_iterator_next or appl_iterator_prev
        before using the p_cur member.

*/
void
appl_iterator_init(
    struct appl_iterator * const
        p_iterator,
    struct appl_list const * const
        p_list)
{
    p_iterator->o_cur.pc_node =
        p_list;

    p_iterator->o_end.pc_node =
        p_list;

} /* appl_iterator_init() */

/*

Function: appl_iterator_next

Description:

    Point to next element of linked list.

Parameters:

    p_iterator
        Pointer to iterator object

Return:

    1 if p_cur points to a valid element, 0 if end of list has been reached.

Comments:

    -   On first call of this function after calling appl_iterator_init, the
        iterator object will point to first element of linked list.  On
        subsequent calls, the next elements will be used.

*/
char
appl_iterator_next(
    struct appl_iterator * const
        p_iterator)
{
    char
        b_result;

    p_iterator->o_cur.pc_node =
        p_iterator->o_cur.pc_node->o_next.pc_node;

    b_result =
        (p_iterator->o_cur.pc_node != p_iterator->o_end.pc_node);

    return
        b_result;

} /* appl_iterator_next() */

/*

Function: appl_iterator_prev

Description:

    Point to previous element of linked list.

Parameters:

    p_iterator
        Pointer to iterator object

Return:

    1 if p_cur points to a valid element, 0 if end of list has been reached.

Comments:

    -   On first call of this function after calling appl_iterator_init, the
        iterator object will point to last element of linked list.  On
        subsequent calls, the previous elements will be used.

*/
char
appl_iterator_prev(
    struct appl_iterator * const
        p_iterator)
{
    char
        b_result;

    p_iterator->o_cur.pc_node =
        p_iterator->o_cur.pc_node->o_prev.pc_node;

    b_result =
        (p_iterator->o_cur.pc_node != p_iterator->o_end.pc_node);

    return
        b_result;

} /* appl_iterator_prev() */

/* end-of-file: appl_list.cpp */
