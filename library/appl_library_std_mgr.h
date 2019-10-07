/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_library_std_mgr_h
{
    inc_appl_library_std_mgr_h =
        /* Header file dependency */
        inc_appl_library_mgr_h
};

/* Assert OS */
#include <misc/appl_assert_linux.h>

/* Assert compiler */
#include <misc/appl_assert_cplusplus.h>

//
//
//
class appl_library_std_mgr : public appl_library_mgr
{
    public:

        static
        enum appl_status
            s_create(
                struct appl_allocator * const
                    p_allocator,
                class appl_library_mgr * * const
                    r_library_mgr);

        appl_library_std_mgr(
            struct appl_context * const
                p_context);

        virtual
        ~appl_library_std_mgr();

    protected:

    private:

        appl_library_std_mgr(
            class appl_library_std_mgr const & r);

        class appl_library_std_mgr &
            operator =(
                class appl_library_std_mgr const & r);

        virtual
        appl_size_t
            v_cleanup(void);

        virtual
        enum appl_status
            v_create_node(
                struct appl_library_descriptor const * const
                    p_library_descriptor,
                struct appl_library * * const
                    r_library);

        virtual
        enum appl_status
            v_destroy_node(
                struct appl_library * const
                    p_library);

}; // class appl_library_std_mgr

/* end-of-file: appl_library_std_mgr.h */
