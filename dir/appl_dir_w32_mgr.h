/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_dir_w32_mgr_h
{
    inc_appl_dir_w32_mgr_h = 1
        /* Header file dependencies */
        + inc_appl_dir_mgr_h
}; /* enum guard_appl_dir_w32_mgr_h */

#include <misc/appl_assert_windows.h>

#include <misc/appl_assert_cplusplus.h>

//
//
//
class appl_dir_w32_mgr : public appl_dir_mgr
{
    public:

        appl_dir_w32_mgr(
            struct appl_context * const
                p_context);

        virtual
        ~appl_dir_w32_mgr();

        enum appl_status
            f_init(void);

        virtual
        appl_size_t
            v_cleanup(void);

        virtual
        enum appl_status
            v_enumerate(
                struct appl_dir_descriptor const * const
                    p_descriptor);

    protected:

    private:

        appl_dir_w32_mgr(
            class appl_dir_w32_mgr const & r);

        class appl_dir_w32_mgr &
            operator =(
                class appl_dir_w32_mgr const & r);

}; // class appl_dir_w32_mgr

/* end-of-file: appl_dir_w32_mgr.h */
