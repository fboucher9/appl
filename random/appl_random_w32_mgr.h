/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_random_w32_mgr_h
{
    inc_appl_random_w32_mgr_h =
        /* Header file dependencies */
        inc_appl_random_mgr_h
};

struct appl_allocator;

/* Assert compiler */
#include <appl_assert_cplusplus.h>

class appl_random_w32_mgr;

//
//
//
class appl_random_w32_mgr : public appl_random_mgr
{
    public:

        static
        enum appl_status
        s_create(
            struct appl_allocator * const
                p_allocator,
            class appl_random_mgr * * const
                r_random_mgr);

        static
        enum appl_status
        s_destroy(
            struct appl_allocator * const
                p_allocator,
            class appl_random_mgr * const
                p_random_mgr);

        appl_random_w32_mgr(
            struct appl_context * const
                p_context);

        virtual
        ~appl_random_w32_mgr();

        enum appl_status
            f_init(void);

    protected:

    private:

        appl_random_w32_mgr(
            class appl_random_w32_mgr const & r);

        class appl_random_w32_mgr &
            operator =(
                class appl_random_w32_mgr const & r);

        virtual
        appl_size_t
            v_cleanup(void);

        virtual
        enum appl_status
        v_create_node(
            struct appl_random_descriptor const * const
                p_descriptor,
            struct appl_random * * const
                r_node);

        virtual
        enum appl_status
        v_destroy_node(
            struct appl_random * const
                p_node);

}; // class appl_random_w32_mgr

/* end-of-file: appl_random_w32_mgr.h */
