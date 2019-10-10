/* See LICENSE for license details */

/*

*/

/* Included. */
#define INC_APPL_NODE_H

/* Reverse include guard */
enum guard_appl_node_h
{
    inc_appl_node_h =
        /* Header file dependency */
        inc_appl_object_h
};

/* Assert compiler */
#include <misc/appl_assert_cplusplus.h>

class appl_node;

//
//
//
class appl_node : public appl_object
{
    public:

        appl_node(
            struct appl_context * const
                p_context);

        virtual
        ~appl_node();

        class appl_node *
            p_next;

        class appl_node *
            p_prev;

        static
        void
            join(
                class appl_node * const
                    p_node_left,
                class appl_node * const
                    p_node_right);

    protected:

    private:

        appl_node(
            class appl_node const & r);

        class appl_node &
            operator =(
                class appl_node const & r);

}; // class appl_node

/* end-of-file: appl_node.h */
