/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_EVENT_STD_MGR_H
#error include appl_event_std_mgr.h once
#endif /* #if defined INC_APPL_EVENT_STD_MGR_H */

#define INC_APPL_EVENT_STD_MGR_H

/* Header file dependency */
#if ! defined INC_APPL_EVENT_MGR_H
#error include appl_event_mgr.h before
#endif /* #if ! defined INC_APPL_EVENT_MGR_H */

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

class appl_event_std_mgr;

//
//
//
class appl_event_std_mgr : public appl_event_mgr
{
    public:

        static
        enum appl_status
            s_create(
                struct appl_allocator * const
                    p_allocator,
                class appl_event_mgr * * const
                    r_event_mgr);

        appl_event_std_mgr();

        virtual
        ~appl_event_std_mgr();

        enum appl_status
            f_init(void);

    protected:

    private:

        // --

        struct appl_pool *
            m_pool;

        void *
            pv_padding[1u];

        // --

        bool
            m_pool_created;

        unsigned char
            uc_padding[7u];

        // --

        appl_event_std_mgr(
            class appl_event_std_mgr const & r);

        class appl_event_std_mgr &
            operator =(
                class appl_event_std_mgr const & r);

        virtual
        enum appl_status
            v_cleanup(void);

        virtual
        enum appl_status
            v_create(
                struct appl_event_descriptor const * const
                    p_event_descriptor,
                struct appl_event * * const
                    r_event);

}; // class appl_event_std_mgr

/* end-of-file: appl_event_std_mgr.h */