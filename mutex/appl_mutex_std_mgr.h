/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_mutex_std_mgr_h
{
    inc_appl_mutex_std_mgr_h =
        /* Header file dependency */
        inc_appl_mutex_mgr_h
};

/* Assert compiler */
#include <misc/appl_assert_cplusplus.h>

//
//
//
class appl_mutex_std_mgr : public appl_mutex_mgr
{
    public:

        static
        enum appl_status
            s_create(
                struct appl_allocator * const
                    p_allocator,
                class appl_mutex_mgr * * const
                    r_mutex_mgr);

        static
        enum appl_status
            s_destroy(
                struct appl_allocator * const
                    p_allocator,
                class appl_mutex_mgr * const
                    p_mutex_mgr);

        appl_mutex_std_mgr(
            struct appl_context * const
                p_context);

        virtual
        ~appl_mutex_std_mgr();

        enum appl_status
            f_init(void);

    protected:

    private:

        // --

        appl_mutex_std_mgr(
            class appl_mutex_std_mgr const & r);

        class appl_mutex_std_mgr &
            operator =(
                class appl_mutex_std_mgr const & r);

        virtual
        appl_size_t
            v_cleanup(void);

        virtual
        enum appl_status
            v_create_node(
                struct appl_allocator * const
                    p_allocator,
                struct appl_mutex_descriptor const * const
                    p_mutex_descriptor,
                struct appl_mutex * * const
                    r_mutex);

        virtual
        enum appl_status
            v_destroy_node(
                struct appl_allocator * const
                    p_allocator,
                struct appl_mutex * const
                    p_mutex);

}; // class appl_mutex_std_mgr

/* end-of-file: appl_mutex_std_mgr.h */
