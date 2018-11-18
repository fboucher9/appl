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

        virtual
        enum appl_status
            v_create(
                struct appl_timer * * const
                    r_timer);

    protected:

        appl_timer_mgr();

        virtual
        ~appl_timer_mgr();

    private:

        appl_timer_mgr(
            class appl_timer_mgr const & r);

        class appl_timer_mgr &
            operator =(
                class appl_timer_mgr const & r);

}; // class appl_timer_mgr

/* end-of-file: appl_timer_mgr.h */
