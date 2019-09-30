/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_dir_mgr_h
{
    inc_appl_dir_mgr_h = 1
        /* Header file dependencies */
        + inc_appl_object_h
}; /* enum guard_appl_dir_mgr_h */

/* Predefine descriptor */
struct appl_dir_descriptor;

#include <appl_assert_cplusplus.h>

//
//
//
class appl_dir_mgr : public appl_object
{
    public:

        appl_dir_mgr(
            struct appl_context * const
                p_context);

        virtual
        ~appl_dir_mgr();

        virtual
        enum appl_status
            v_enumerate(
                struct appl_dir_descriptor const * const
                    p_descriptor);

    protected:

    private:

        appl_dir_mgr(
            class appl_dir_mgr const & r);

        class appl_dir_mgr &
            operator =(
                class appl_dir_mgr const & r);

}; // class appl_dir_mgr

/* end-of-file: appl_dir_mgr.h */
