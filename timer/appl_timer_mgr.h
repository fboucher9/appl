/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_timer_mgr_h
{
    inc_appl_timer_mgr_h =
        /* Header file dependency */
        inc_appl_object_h
};

/* Predefine */
struct appl_timer;

//
//
//
class appl_timer_mgr : public appl_object
{
    public:

        appl_timer_mgr(
            struct appl_context * const
                p_context);

        virtual
        ~appl_timer_mgr();

        virtual
        enum appl_status
            v_create_node(
                struct appl_timer * * const
                    r_timer);

        virtual
        enum appl_status
            v_destroy_node(
                struct appl_timer * const
                    p_timer);

    protected:

    private:

        appl_timer_mgr(
            class appl_timer_mgr const & r);

        class appl_timer_mgr &
            operator =(
                class appl_timer_mgr const & r);

}; // class appl_timer_mgr

/* end-of-file: appl_timer_mgr.h */
