/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <appl_node.h>

#include <appl_node_iterator.h>

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
appl_node_iterator::appl_node_iterator(
    class appl_node * const
        p_node) :
    p_cur(
        p_node),
    p_end(
        p_node)
{
}

//
//
//
appl_node_iterator::~appl_node_iterator()
{
}

//
//
//
bool
    appl_node_iterator::next(void)
{
    bool
        b_result;

    p_cur =
        p_cur->p_next;

    b_result =
        (p_cur != p_end);

    return
        b_result;

} // next()

//
//
//
bool
    appl_node_iterator::prev(void)
{
    bool
        b_result;

    p_cur =
        p_cur->p_prev;

    b_result =
        (p_cur != p_end);

    return
        b_result;

} // prev()

/* end-of-file: appl_node_iterator.cpp */
