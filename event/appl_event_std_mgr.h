/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_event_std_mgr_h
{
    inc_appl_event_std_mgr_h =
        /* Header file dependencies */
        inc_appl_event_mgr_h
};

/* Assert compiler */
#include <misc/appl_assert_cplusplus.h>

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

        static
        enum appl_status
            s_destroy(
                struct appl_allocator * const
                    p_allocator,
                class appl_event_mgr * const
                    p_event_mgr);

        appl_event_std_mgr(
            struct appl_context * const
                p_context);

        virtual
        ~appl_event_std_mgr();

        enum appl_status
            f_init(void);

    protected:

    private:

        // --

        struct appl_pool *
            m_pool;

        bool
            m_pool_created;

#define PADDING (APPL_SIZEOF_PTR + 1)
#include <misc/appl_padding.h>

        // --

        appl_event_std_mgr(
            class appl_event_std_mgr const & r);

        class appl_event_std_mgr &
            operator =(
                class appl_event_std_mgr const & r);

        virtual
        appl_size_t
            v_cleanup(void);

        virtual
        enum appl_status
            v_create_node(
                struct appl_event_descriptor const * const
                    p_event_descriptor,
                struct appl_event * * const
                    r_event);

        virtual
        enum appl_status
            v_destroy_node(
                struct appl_event * const
                    p_event);

}; // class appl_event_std_mgr

/* end-of-file: appl_event_std_mgr.h */
