/* See LICENSE for license details */

/*

Module: appl_list.h

Description:

    Linked list

*/

/* Included. */
#define INC_APPL_LIST_H

/* Reverse include guard */
enum guard_appl_list_h
{
    inc_appl_list_h =
        /* Header file dependencies */
        1 /* None */
};

struct appl_list;

/* pointer to node */
union appl_list_ptr
{
    /* pointer to modifiable node */
    struct appl_list *
        p_node;

    /* pointer to constant node */
    struct appl_list const *
        pc_node;

}; /* union appl_list_ptr */

/* list */
struct appl_list
{
    /* pointer to next element in linked list */
    union appl_list_ptr
        o_next;

    /* pointer to previous element in linked list */
    union appl_list_ptr
        o_prev;

}; /* struct appl_list */

struct appl_iterator;

/* iterator */
struct appl_iterator
{
    /* pointer to current element in linked list */
    union appl_list_ptr
        o_cur;

    /* pointer to last element of linked list */
    union appl_list_ptr
        o_end;

}; /* struct appl_iterator */

#if defined(__cplusplus)
extern "C" {
#endif /* #if defined(__cplusplus) */

/*

Interface: appl_list

Example:

    The following sample code demonstrates basic linked list operations:

        struct T
        {
            struct appl_list
                o_list;

            int
                i_value;

        };

        struct appl_list
            o_list;

        struct T
            o_node1;

        struct T
            o_node2;

        // initialize head of linked list
        appl_list_init(
            &(
                o_list));

        // initialize first node
        appl_list_init(
            &(
                o_node1.o_list));

        o_node1.i_value =
            1;

        // initialize second node
        appl_list_init(
            &(
                o_node2.o_list));

        o_node2.i_value =
            2;

        // insert first node at end of linked list
        appl_list_join(
            &(
                o_node1.o_list),
            &(
                o_list));

        // insert second node at beginning of linked list
        appl_list_join(
            &(
                o_list),
            &(
                o_node2.o_list));

        // remove first node from linked list
        appl_list_join(
            &(
                o_node1.o_list),
            &(
                o_node1.o_list));

        if (1)
        {
            // insert first node before second
            appl_list_join(
                &(
                    o_node1.o_list),
                &(
                    o_node2.o_list));
        }
        else
        {
            // insert first node after second
            appl_list_join(
                &(
                    o_node2.o_list),
                &(
                    o_node1.o_list));
        }

*/

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

/*

Interface: appl_iterator

Example:

    The following sample code demonstrates iteration of all elements of
    a linked list:

        static
        void
        walk_forward(
            struct appl_list const * const
                p_list)
        {
            struct appl_iterator
                o_iterator;

            appl_iterator_init(
                &(
                    o_iterator),
                p_list);

            while (
                appl_iterator_next(
                    &(
                        o_iterator)))
            {
                struct T *
                    p_node;

                p_node =
                    (struct T *)(
                        o_iterator.o_cur.p_node);

                // Use node ...
            }
        }

        static
        void
        walk_backward(
            struct appl_list const * const
                p_list)
        {
            struct appl_iterator
                o_iterator;

            appl_iterator_init(
                &(
                    o_iterator),
                p_list);

            while (
                appl_iterator_prev(
                    &(
                        o_iterator)))
            {
                struct T *
                    p_node;

                p_node =
                    (struct T *)(
                        o_iterator.o_cur.p_node);

                // Use node ...
            }
        }

        static
        void
        destroy_all(
            struct appl_list * const
                p_list)
        {
            struct appl_iterator
                o_iterator;

            char
                b_more;

            // initialize the iterator object
            appl_iterator_init(
                &(
                    o_iterator),
                p_list);

            // get pointer to first node of linked list
            b_more =
                appl_iterator_next(
                    &(
                        o_iterator));

            while (
                b_more)
            {
                struct T *
                    p_node;

                // get pointer to node that will be destroyed
                p_node =
                    (struct T *)(
                        o_iterator.o_cur.p_node);

                // get pointer to next before destroying
                b_more =
                    appl_iterator_next(
                        &(
                            o_iterator));

                // remove the node from the linked list
                appl_list_join(
                    &(
                        p_node->o_list),
                    &(
                        p_node->o_list));

                // destroy this node
                free(
                    p_node);
            }
        }

*/

/* iterator methods */
void
appl_iterator_init(
    struct appl_iterator * const
        p_iterator,
    struct appl_list const * const
        p_list);

char
appl_iterator_next(
    struct appl_iterator * const
        p_iterator);

char
appl_iterator_prev(
    struct appl_iterator * const
        p_iterator);

#if defined(__cplusplus)
} /* extern "C" */
#endif /* #if defined(__cplusplus) */

/* end-of-file: appl_list.h */
