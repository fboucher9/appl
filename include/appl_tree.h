/* See LICENSE for license details */

/*

Module: appl_tree.h

Description:

    Sorted and balanced binary tree.

*/

/* Predefine */
struct appl_tree_node;

/*

*/
struct appl_tree_intf
{
    int (* p_compare)(
        void * const
            p_context,
        struct appl_tree_node const * const
            p_node_1,
        struct appl_tree_node const * const
            p_node_2);

    void *
        p_context;

}; /* struct appl_tree_intf */

/*

*/
struct appl_tree_node
{
    struct appl_tree_node *
        p_child_left;

    struct appl_tree_node *
        p_child_right;

    /* -- */

    /* caches for height and count */
    int
        i_height;

    int
        i_count;

}; /* struct appl_tree_node */

#include <misc/appl_extern_c_begin.h>

/* */
void
appl_tree_init(
    struct appl_tree_node * const
        p_tree_node);

/* Insert of node into tree */
struct appl_tree_node *
appl_tree_attach(
    struct appl_tree_intf const * const
        p_tree_intf,
    struct appl_tree_node * const
        p_tree_root,
    struct appl_tree_node * const
        p_tree_node);

/* Remove of node from tree */
struct appl_tree_node *
appl_tree_detach(
    struct appl_tree_intf const * const
        p_tree_intf,
    struct appl_tree_node * const
        p_tree_root,
    struct appl_tree_node * const
        p_tree_node);

#include <misc/appl_extern_c_end.h>

/* end-of-file: appl_tree.h */
