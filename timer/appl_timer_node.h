/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_timer_node_h
{
    inc_appl_timer_node_h =
        /* Header file dependency */
        inc_appl_node_h
};

struct appl_timer_descriptor;

/* Assert compiler */
#include <appl_assert_cplusplus.h>

//
//
//
struct appl_timer_node : public appl_node
{
    public:

        appl_timer_node(
            struct appl_context * const
                p_context);

        virtual
        ~appl_timer_node();

        virtual
        enum appl_status
            v_schedule(
                struct appl_timer_descriptor const * const
                    p_timer_descriptor);

    protected:

    private:

        appl_timer_node(
            struct appl_timer_node const & r);

        struct appl_timer_node &
            operator =(
                struct appl_timer_node const & r);

}; // struct appl_timer_node

/* end-of-file: appl_timer_node.h */
