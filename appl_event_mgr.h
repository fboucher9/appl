/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_EVENT_MGR_H
#error include appl_event_mgr.h once
#endif /* #if defined INC_APPL_EVENT_MGR_H */

#define INC_APPL_EVENT_MGR_H

struct appl_event_descriptor;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

class appl_context;

class appl_event_node;

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
                class appl_context * const
                    p_context,
                struct appl_event_descriptor const * const
                    p_event_descriptor,
                class appl_event_node * * const
                    r_event_node);

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
