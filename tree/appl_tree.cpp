/* See LICENSE for license details */

/*

Module: appl_tree.cpp

Description:

    Sorted and balanced binary tree.

*/

/*

Rebalancing technique

    Use the rotation:

        Rotate

            |                |
            B                A
           / \              / \
          A   c      =>    a   B
         / \                  / \
        a   b                b   c

        -   Detach b
        -   Detach A & a
        -   Detach B & c
        -   Attach A & a as new root
        -   Attach B & c as child of A
        -   Attach b as child of B

        b = A->right
        A->right = B
        B->left = b
        return A

Note:

    -   b must be shorter than a, else another rotation is necessary.

Removal:

            x
           / \
          b   c
         / \ / \
        d  e f  g

    -   Exchange x with e or f
    -   Then remove x from new position 'e'
    -   Repeat procedure until end up with a leaf

        x           b            b         b             |
       /           /            /         /              |
      a           a            a         a               |
     / \         / \          / \       / \              |
        b    ->     x            d         d             |
       /           /            /         /              |
      c           c            c         c               |
       \           \            \         \              |
        d           d            x         e             |
       /           /            /         /              |
      e           e            e         x               |

      |
      | If both are null
      | | return null
      | Else If left is null
      | | return right
      | Else If right is null
      | | return left
      | Else
      | | a = left
      | | b = max(a)
      | | c = b->left
      | | b->left = a
      | | b->right = x->right
      | | x->left = c
      | | return b
      |


*/

#include <tree/appl_tree.h>

void
appl_tree_init(
    struct appl_tree_node * const
        p_tree_node)
{
    p_tree_node->p_child_left =
        0;

    p_tree_node->p_child_right =
        0;

    p_tree_node->i_height =
        1;

    p_tree_node->i_count =
        1;

}

static
int
appl_tree_compare(
    struct appl_tree_intf const * const
        p_tree_intf,
    struct appl_tree_node * const
        p_tree_node_a,
    struct appl_tree_node * const
        p_tree_node_b)
{
    int
        i_compare_result;

    i_compare_result =
        (*(p_tree_intf->p_compare))(
            p_tree_intf->p_context,
            p_tree_node_a,
            p_tree_node_b);

    return
        i_compare_result;

}

static
int
appl_tree_height(
    struct appl_tree_node * const
        p_tree_node)
{
    int
        i_height;

    if (
        p_tree_node)
    {
        i_height =
            p_tree_node->i_height;

    }
    else
    {
        i_height =
            0;
    }

    return
        i_height;

}

static
int
appl_tree_count(
    struct appl_tree_node * const
        p_tree_node)
{
    int
        i_count;

    if (
        p_tree_node)
    {
        i_count =
            p_tree_node->i_count;
    }
    else
    {
        i_count =
            0;
    }

    return
        i_count;

}

static
void
appl_tree_recalc(
    struct appl_tree_node * const
        p_tree_node)
{
    if (
        p_tree_node)
    {
        int
            i_height_left;

        i_height_left =
            appl_tree_height(
                p_tree_node->p_child_left);

        int
            i_height_right;

        i_height_right =
            appl_tree_height(
                p_tree_node->p_child_right);

        if (
            i_height_left > i_height_right)
        {
            p_tree_node->i_height = i_height_left + 1;
        }
        else
        {
            p_tree_node->i_height = i_height_right + 1;
        }

        int
            i_count_left;

        i_count_left =
            appl_tree_count(
                p_tree_node->p_child_left);

        int
            i_count_right;

        i_count_right =
            appl_tree_count(
                p_tree_node->p_child_right);

        p_tree_node->i_count =
            i_count_left + i_count_right + 1;
    }
}

/*

Before:

     n
    / \
   /   \
        r
       /
      x

After:

        r
       / \
      /
     n
    / \
       x

*/
static
struct appl_tree_node *
appl_tree_rotate_left(
    struct appl_tree_node * const
        p_node_n)
{
    struct appl_tree_node *
        p_node_r;

    p_node_r =
        p_node_n->p_child_right;

    if (
        p_node_r)
    {
        p_node_n->p_child_right =
            p_node_r->p_child_left;

        p_node_r->p_child_left =
            p_node_n;

        appl_tree_recalc(
            p_node_n);

        appl_tree_recalc(
            p_node_r);

        return
            p_node_r;
    }
    else
    {
        return
            p_node_n;
    }

}

/*

Before:

        n
       / \
      /
     l
    / \
       x

After:

     l
    / \
   /   \
        n
       /
      x

*/
static
struct appl_tree_node *
appl_tree_rotate_right(
    struct appl_tree_node * const
        p_node_n)
{
    struct appl_tree_node *
        p_node_l;

    p_node_l =
        p_node_n->p_child_left;

    if (
        p_node_l)
    {
        p_node_n->p_child_left =
            p_node_l->p_child_right;

        p_node_l->p_child_right =
            p_node_n;

        appl_tree_recalc(
            p_node_n);

        appl_tree_recalc(
            p_node_l);

        return
            p_node_l;
    }
    else
    {
        return
            p_node_n;
    }

}

static
struct appl_tree_node *
appl_tree_balance(
    struct appl_tree_node * const
        p_tree_node)
{
    if (
        p_tree_node)
    {
        int
            i_height_left;

        int
            i_height_right;

        appl_tree_recalc(
            p_tree_node);

        i_height_left =
            appl_tree_height(
                p_tree_node->p_child_left);

        i_height_right =
            appl_tree_height(
                p_tree_node->p_child_right);

        if (
            (i_height_right - i_height_left) >= 2)
        {
            /* right side is higher */
            /* use rotate left */

            return
                appl_tree_rotate_left(
                    p_tree_node);

        }
        else if (
            (i_height_right - i_height_left) <= -2)
        {
            /* left side is higher */
            /* use rotate right */

            return
                appl_tree_rotate_right(
                    p_tree_node);
        }
        else
        {
            /* No balance required */
        }
    }
    else
    {
        /* No balance required */
    }

    return
        p_tree_node;

}

struct appl_tree_node *
appl_tree_attach(
    struct appl_tree_intf const * const
        p_tree_intf,
    struct appl_tree_node * const
        p_tree_node_parent,
    struct appl_tree_node * const
        p_tree_node_child)
{
    if (
        p_tree_node_parent)
    {
        /* Insert left or right */
        int
            i_compare_result;

        i_compare_result =
            appl_tree_compare(
                p_tree_intf,
                p_tree_node_child,
                p_tree_node_parent);

        if (
            0 > i_compare_result)
        {
            /* attach on left side */
            p_tree_node_parent->p_child_left =
                appl_tree_attach(
                    p_tree_intf,
                    p_tree_node_parent->p_child_left,
                    p_tree_node_child);
        }
        else /* 0 <= i_compare_result */
        {
            /* attach on right side */
            p_tree_node_parent->p_child_right =
                appl_tree_attach(
                    p_tree_intf,
                    p_tree_node_parent->p_child_right,
                    p_tree_node_child);
        }

        return
            appl_tree_balance(
                p_tree_node_parent);
    }
    else
    {
        return
            p_tree_node_child;
    }
}

#if 0
static
struct appl_tree_node *
appl_tree_find_min(
    struct appl_tree_node * const
        p_tree_node)
{
    struct appl_tree_node *
        p_tree_node_iterator;

    p_tree_node_iterator =
        p_tree_node;

    while (
        p_tree_node_iterator->p_child_left)
    {
        p_tree_node_iterator =
            p_tree_node_iterator->p_child_left;
    }

    return
        p_tree_node_iterator;

}
#endif

static
struct appl_tree_node *
appl_tree_find_max(
    struct appl_tree_node * const
        p_tree_node)
{
    struct appl_tree_node *
        p_tree_node_iterator;

    p_tree_node_iterator =
        p_tree_node;

    while (
        p_tree_node_iterator->p_child_right)
    {
        p_tree_node_iterator =
            p_tree_node_iterator->p_child_right;
    }

    return
        p_tree_node_iterator;

}

#if 0
static
struct appl_tree_node *
appl_tree_find_prev(
    struct appl_tree_node * const
        p_tree_node)
{
    struct appl_tree_node *
        p_tree_node_iterator;

    p_tree_node_iterator =
        p_tree_node->p_child_left;

    if (
        p_tree_node_iterator)
    {
        p_tree_node_iterator =
            appl_tree_find_max(
                p_tree_node_iterator);
    }

    return
        p_tree_node_iterator;

}
#endif

#if 0
static
struct appl_tree_node *
appl_tree_find_next(
    struct appl_tree_node * const
        p_tree_node)
{
    struct appl_tree_node *
        p_tree_node_iterator;

    p_tree_node_iterator =
        p_tree_node->p_child_right;

    if (
        p_tree_node_iterator)
    {
        p_tree_node_iterator =
            appl_tree_find_min(
                p_tree_node_iterator);
    }

    return
        p_tree_node_iterator;

}
#endif


#if 0
static
struct appl_tree_node *
appl_tree_parent(
    struct appl_tree_intf const * const
        p_tree_intf,
    struct appl_tree_node * const
        p_tree_iterator,
    struct appl_tree_node * const
        p_tree_node)
{
    if (
        p_tree_iterator->p_child_left
        == p_tree_node)
    {
        return
            p_tree_iterator;
    }
    else if (
        p_tree_iterator->p_child_right
        == p_tree_node)
    {
        return
            p_tree_iterator;
    }
    else
    {
        int
            i_compare_result;

        i_compare_result =
            appl_tree_compare(
                p_tree_intf,
                p_tree_node,
                p_tree_iterator);

        if (
            0 > i_compare_result)
        {
            if (
                p_tree_iterator->p_child_left)
            {
                return
                    appl_tree_parent(
                        p_tree_intf,
                        p_tree_iterator->p_child_left,
                        p_tree_node);
            }
            else
            {
                return
                    0;
            }
        }
        else
        {
            if (
                p_tree_iterator->p_child_right)
            {
                return
                    appl_tree_parent(
                        p_tree_intf,
                        p_tree_iterator->p_child_right,
                        p_tree_node);
            }
            else
            {
                return
                    0;
            }
        }
    }
}
#endif

#if 0
/*
.           |
.           x
.          /
.         i
.          \
.           c
.
*/
static
struct appl_tree_node *
appl_tree_swap(
    struct appl_tree_node *
        p_node_i,
    struct appl_tree_node *
        p_node_x,
    struct appl_tree_node *
        p_node_c)
{
    if (p_node_i->p_child_right == p_node_c)
    {
        struct appl_tree_node *
            p_node_a;

        struct appl_tree_node *
            p_node_b;

        p_node_a =
            p_node_x->p_child_left;

        p_node_b =
            p_node_x->p_child_right;

        p_node_i->p_child_right =
            p_node_x;

        p_node_x->p_child_left =
            p_node_c->p_child_left;

        p_node_x->p_child_right =
            p_node_c->p_child_right;

        if (
            p_node_c != p_node_a)
        {
            p_node_c->p_child_left =
                p_node_a;
        }
        else
        {
            p_node_c->p_child_left =
                0;
        }

        p_node_c->p_child_right =
            p_node_b;

        return
            p_node_c;
    }
    else
    {
        return
            appl_tree_swap(
                p_node_i->p_child_right,
                p_node_x,
                p_node_c);
    }
}
#endif

/*

Function: appl_tree_detach()

Description:

    Detach a node from the tree.

Comments:

    -   Simple case #1
            Detach of leaf
            return NULL

    -   Simple case #2
            if (x->right is NULL)
                left->right = x->right
                return x->left
            if (x->left is NULL)
                return x->right

    -   Simple case #3
            One child on each side
            left->right = x->right
            return left

    -   Problem occurs when there are two children.  We must locate the
        inorder next or previous element and exchange.  Then repeat the
        detach.

    -   To exchange two nodes:

            |
            x
           / \
          a   b
           \
            m
           /
          y

        a = x->left
        b = x->right
        m = find_prev(x)
        y = m->left
        x->left = NULL
        x->right = NULL
        m->left = a
        m->right = b
        if (a != m)
        {
            a->max_right = y
        }
        return m
        balance from m to root

        If one of the sides has only one node:

            |
            x
           / \
          a   b

            |
            a
             \
              b

*/

static
void
appl_tree_recalc_right(
    struct appl_tree_node * const
        p_tree_node_iterator)
{
    if (
        p_tree_node_iterator->p_child_right)
    {
        appl_tree_recalc_right(
            p_tree_node_iterator->p_child_right);
    }

    appl_tree_recalc(
        p_tree_node_iterator);
}

struct appl_tree_node *
appl_tree_detach(
    struct appl_tree_intf const * const
        p_tree_intf,
    struct appl_tree_node * const
        p_tree_node_parent,
    struct appl_tree_node * const
        p_tree_node_child)
{
    struct appl_tree_node *
        p_tree_node_result;

    if (
        p_tree_node_parent == p_tree_node_child)
    {
        struct appl_tree_node *
            p_new_top;

        if (
            p_tree_node_child->p_child_left)
        {
            if (
                p_tree_node_child->p_child_right)
            {
                if (1) /* debalanced method */
                {
                    /*       |          |
                    .        x    =>    A
                    .       / \          \
                    .      A   B          B      */

                    struct appl_tree_node * const
                        p_node_max =
                        appl_tree_find_max(
                            p_tree_node_child->p_child_left);

                    p_new_top =
                        p_tree_node_child->p_child_left;

                    p_node_max->p_child_right =
                        p_tree_node_child->p_child_right;

                    p_tree_node_child->p_child_left =
                        0;

                    p_tree_node_child->p_child_right =
                        0;

                    /* Recalc all nodes from A to B */
                    appl_tree_recalc_right(
                        p_new_top);

                    p_tree_node_result =
                        appl_tree_balance(
                            p_new_top);
                }

                if ((0)) /* swap method */
                {
                    /*
                    .       |
                    .       x
                    .      / \
                    .     a   b
                    .      \
                    .       c
                    .      /
                    .     d
                    */

                    struct appl_tree_node *
                        p_node_a;

                    struct appl_tree_node *
                        p_node_b;

                    struct appl_tree_node *
                        p_node_c;

                    struct appl_tree_node *
                        p_node_d;

                    p_node_a =
                        p_tree_node_child->p_child_left;

                    p_node_b =
                        p_tree_node_child->p_child_right;

                    p_node_c =
                        appl_tree_find_max(
                            p_node_a);

                    if (
                        p_node_c != p_node_a)
                    {
                        p_node_d =
                            p_node_c->p_child_left;

                        /* Need parent of p_node_c */
                        {
                            struct appl_tree_node *
                                p_tree_node_iterator;

                            p_tree_node_iterator =
                                p_node_a;

                            while (p_tree_node_iterator->p_child_right != p_node_c)
                            {
                                p_tree_node_iterator =
                                    p_tree_node_iterator->p_child_right;
                            }

                            p_tree_node_iterator->p_child_right =
                                p_tree_node_child;
                        }

                        p_tree_node_child->p_child_right =
                            0;

                        p_tree_node_child->p_child_left =
                            p_node_d;

                        p_node_c->p_child_right =
                            p_node_b;

                        /* Recurse detach starting from a */
                        p_node_c->p_child_left =
                            appl_tree_detach(
                                p_tree_intf,
                                p_node_a,
                                p_tree_node_child);

                        p_new_top =
                            p_node_c;

                        p_tree_node_child->p_child_left =
                            0;

                        p_tree_node_child->p_child_right =
                            0;

                        p_tree_node_result =
                            appl_tree_balance(
                                p_new_top);
                    }
                    else
                    {
                        /* Simple case #3 */

                        /*
                        .           |               |
                        .           x     ->        a
                        .          / \               \
                        .         a   b               b
                        .
                        */

                        p_tree_node_child->p_child_left->p_child_right =
                            p_tree_node_child->p_child_right;

                        p_new_top =
                            p_tree_node_child->p_child_left;

                        p_tree_node_child->p_child_left =
                            0;

                        p_tree_node_child->p_child_right =
                            0;

                        p_tree_node_result =
                            appl_tree_balance(
                                p_new_top);
                    }
                }
            }
            else
            {
                /*    |           |
                .     x     =>    A
                .    /
                .   A                    */

                p_new_top =
                    p_tree_node_child->p_child_left;

                p_tree_node_child->p_child_left =
                    0;

                p_tree_node_child->p_child_right =
                    0;

                p_tree_node_result =
                    appl_tree_balance(
                        p_new_top);
            }
        }
        else
        {
            /*  |              |
            .   x      =>      B
            .    \
            .     B              */

            p_new_top =
                p_tree_node_child->p_child_right;

            p_tree_node_child->p_child_left =
                0;

            p_tree_node_child->p_child_right =
                0;

            p_tree_node_result =
                appl_tree_balance(
                    p_new_top);
        }
    }
    else
    {
        if (
            p_tree_node_child == p_tree_node_parent->p_child_left)
        {
            /* Found node and parent */
            /* Check if node must be pushed to bottom */
            p_tree_node_parent->p_child_left =
                appl_tree_detach(
                    p_tree_intf,
                    p_tree_node_parent->p_child_left,
                    p_tree_node_child);
        }
        else if (
            p_tree_node_child == p_tree_node_parent->p_child_right)
        {
            /* Found node and parent */
            /* Check if node must be pushed to bottom */
            p_tree_node_parent->p_child_right =
                appl_tree_detach(
                    p_tree_intf,
                    p_tree_node_parent->p_child_right,
                    p_tree_node_child);
        }
        else
        {
            int
                i_compare_result;

            i_compare_result =
                appl_tree_compare(
                    p_tree_intf,
                    p_tree_node_child,
                    p_tree_node_parent);

            if (
                0 > i_compare_result)
            {
                if (p_tree_node_parent->p_child_left)
                {
                    p_tree_node_parent->p_child_left =
                        appl_tree_detach(
                            p_tree_intf,
                            p_tree_node_parent->p_child_left,
                            p_tree_node_child);
                }
            }
            else
            {
                if (p_tree_node_parent->p_child_right)
                {
                    p_tree_node_parent->p_child_right =
                        appl_tree_detach(
                            p_tree_intf,
                            p_tree_node_parent->p_child_right,
                            p_tree_node_child);
                }
            }
        }

        p_tree_node_result =
            appl_tree_balance(
                p_tree_node_parent);
    }

    return
        p_tree_node_result;

} /* appl_tree_detach() */

/* end-of-file: appl_tree.cpp */
