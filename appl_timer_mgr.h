/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_TIMER_MGR_H
#error include appl_timer_mgr.h once
#endif /* #if defined INC_APPL_TIMER_MGR_H */

#define INC_APPL_TIMER_MGR_H

/* Header file dependency */
#if ! defined INC_APPL_OBJECT_H
#error include appl_object.h before
#endif /* #if ! defined INC_APPL_OBJECT_H */

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
