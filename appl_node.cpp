/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_list.h>

#include <appl_node.h>

/* Assert compiler */
#include <misc/appl_assert_cplusplus.h>

//
//
//
void
    appl_node::join(
        class appl_node * const
            p_node_left,
        class appl_node * const
            p_node_right)
{
    /* AB(C) - (D)EF > ABCDEF */
    p_node_left->p_next->p_prev =
        p_node_right->p_prev;

    p_node_right->p_prev->p_next =
        p_node_left->p_next;

    p_node_left->p_next =
        p_node_right;

    p_node_right->p_prev =
        p_node_left;

} // join()

//
//
//
appl_node::appl_node(
    struct appl_context * const
        p_context) :
    appl_object(
        p_context),
    p_next(),
    p_prev()
{
    p_next =
        this;

    p_prev =
        this;

}

//
//
//
appl_node::~appl_node()
{
    join(
        this,
        this);
}

/* end-of-file: appl_node.cpp */
