/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_poll_mgr_h
{
    inc_appl_poll_mgr_h =
        /* Header file dependency */
        inc_appl_node_h
        + inc_appl_object_h
};

struct appl_poll_table;

/* Assert compiler */
#include <misc/appl_assert_cplusplus.h>

//
//
//
class appl_poll_mgr : public appl_object
{
    public:

        static
        enum appl_status
            create_instance(
                struct appl_context * const
                    p_context,
                class appl_poll_mgr * * const
                    r_poll_mgr);

        virtual
        enum appl_status
            v_create(
                struct appl_poll_descriptor const * const
                    p_poll_descriptor,
                struct appl_poll * * const
                    r_poll);

    protected:

        appl_poll_mgr();

        virtual
        ~appl_poll_mgr();

        // --

        struct appl_thread *
            p_thread;

        struct appl_mutex *
            p_mutex;

        // --

        class appl_node
            o_nodes;

        // --

        signed long int volatile
            m_kill;

#define PADDING (APPL_SIZEOF_LONG)
#include <misc/appl_padding.h>

    private:

        appl_poll_mgr(
            class appl_poll_mgr const & r);

        class appl_poll_mgr &
            operator =(
                class appl_poll_mgr const & r);

        enum appl_status
            create_poll_table(
                struct appl_poll_table * const
                    p_poll_table);

        void
            destroy_poll_table(
                struct appl_poll_table * const
                    p_poll_table);

        void
            thread_step(void);

        void
            thread_handler(void);

        static
        void *
            thread_entry(
                void * const
                    p_thread_context);

}; // class appl_poll_mgr

/* end-of-file: appl_poll_mgr.h */
