/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_event_mgr_h
{
    inc_appl_event_mgr_h =
        /* Header file dependencies */
        inc_appl_object_h
};

struct appl_event_descriptor;

struct appl_context;

struct appl_event;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

class appl_event_mgr;

//
//
//
class appl_event_mgr : public appl_object
{
    public:

        virtual
        enum appl_status
            v_create(
                struct appl_event_descriptor const * const
                    p_event_descriptor,
                struct appl_event * * const
                    r_event);

    protected:

        appl_event_mgr();

        virtual
        ~appl_event_mgr();

    private:

        appl_event_mgr(
            class appl_event_mgr const & r);

        class appl_event_mgr &
            operator =(
                class appl_event_mgr const & r);

}; // class appl_event_mgr

/* end-of-file: appl_event_mgr.h */
