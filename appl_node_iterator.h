/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_node_iterator_h
{
    inc_appl_node_iterator_h =
        /* Header file dependencies */
        1
};

/* Assert compiler */
#include <appl_assert_cplusplus.h>

class appl_node_iterator;

//
//
//
class appl_node_iterator
{
    public:

        class appl_node *
            p_cur;

        class appl_node *
            p_end;

        appl_node_iterator(
            class appl_node * const
                p_node);

        ~appl_node_iterator();

        bool
            next(void);

        bool
            prev(void);

    private:

        appl_node_iterator(
            class appl_node_iterator const & r);

        class appl_node_iterator &
            operator =(
                class appl_node_iterator const & r);

}; // class appl_node_iterator

/* end-of-file: appl_node_iterator.h */
