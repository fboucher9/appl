/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_thread_std_mgr_h
{
    inc_appl_thread_std_mgr_h =
        /* Header file dependencies */
        inc_appl_thread_mgr_h
};

/* Predefine */
struct appl_allocator;

#include <appl_assert_cplusplus.h>

//
//
//
class appl_thread_std_mgr :
    public appl_thread_mgr
{
    public:

        static
        enum appl_status
            s_create(
                struct appl_allocator * const
                    p_allocator,
                class appl_thread_mgr * * const
                    r_thread_mgr);

        static
        enum appl_status
            s_destroy(
                struct appl_allocator * const
                    p_allocator,
                class appl_thread_mgr * const
                    p_thread_mgr);

        enum appl_status
            f_init(void);

        appl_thread_std_mgr(
            struct appl_context * const
                p_context);

        virtual
        ~appl_thread_std_mgr();

    protected:

    private:

        // --

        struct appl_pool *
            m_pool;

        bool
            m_pool_created;

#define PADDING (APPL_SIZEOF_PTR + 1)
#include <appl_padding.h>

        // --

        appl_thread_std_mgr(
            class appl_thread_std_mgr const & r);

        class appl_thread_std_mgr &
            operator =(
                class appl_thread_std_mgr const & r);

        virtual
        appl_size_t
            v_cleanup(void);

        virtual
        enum appl_status
            v_create_node(
                struct appl_thread_descriptor const * const
                    p_thread_descriptor,
                struct appl_thread * * const
                    r_thread);

        virtual
        enum appl_status
            v_destroy_node(
                struct appl_thread * const
                    p_thread);

}; // class appl_thread_std_mgr

/* end-of-file: appl_thread_std_mgr.h */
