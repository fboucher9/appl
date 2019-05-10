/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_timer_group_h
{
    inc_appl_timer_group_h =
        /* Header file dependency */
        inc_appl_object_h
};

/* Predefine */
struct appl_timer_node;

//
//
//
class appl_timer_group : public appl_object
{
    public:

        appl_timer_group(
            struct appl_context * const
                p_context);

        virtual
        ~appl_timer_group();

        virtual
        enum appl_status
            v_create_node(
                struct appl_timer_node * * const
                    r_timer_node);

        virtual
        enum appl_status
            v_destroy_node(
                struct appl_timer_node * const
                    p_timer_node);

    protected:

    private:

        appl_timer_group(
            class appl_timer_group const & r);

        class appl_timer_group &
            operator =(
                class appl_timer_group const & r);

}; // class appl_timer_group

/* end-of-file: appl_timer_group.h */
