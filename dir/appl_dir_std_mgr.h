/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_dir_std_mgr_h
{
    inc_appl_dir_std_mgr_h = 1
        /* Header file dependencies */
        + inc_appl_dir_mgr_h
}; /* enum guard_appl_dir_std_mgr_h */

#include <appl_assert_linux.h>

#include <appl_assert_cplusplus.h>

//
//
//
class appl_dir_std_mgr : public appl_dir_mgr
{
    public:

        appl_dir_std_mgr(
            struct appl_context * const
                p_context);

        virtual
        ~appl_dir_std_mgr();

        virtual
        enum appl_status
            v_enumerate(
                struct appl_dir_descriptor const * const
                    p_descriptor);

    protected:

    private:

        appl_dir_std_mgr(
            class appl_dir_std_mgr const & r);

        class appl_dir_std_mgr &
            operator =(
                class appl_dir_std_mgr const & r);

}; // class appl_dir_std_mgr

/* end-of-file: appl_dir_std_mgr.h */
