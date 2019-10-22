/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_unique_std_mgr_h
{
    inc_appl_unique_std_mgr_h = 1
        /* Header file dependencies */
        | inc_appl_unique_mgr_h
        /* ... */
}; // enum guard_appl_unique_std_mgr_h

/* Assert compiler */
#include <misc/appl_assert_cplusplus.h>

//
//
//
class appl_unique_std_mgr : public appl_unique_mgr
{
    public:

        appl_unique_std_mgr(
            struct appl_context * const
                p_context);

        virtual
        ~appl_unique_std_mgr();

        enum appl_status
            f_init(void);

        virtual
        appl_size_t
            v_cleanup(void);

    protected:

    private:

        appl_unique_std_mgr(
            class appl_unique_std_mgr const & r);

        class appl_unique_std_mgr &
            operator =(
                class appl_unique_std_mgr const & r);

        virtual
        enum appl_status
            v_create(
                struct appl_unique * * const
                    r_unique);

        virtual
        enum appl_status
            v_destroy(
                struct appl_unique * const
                    p_unique);

}; // class appl_unique_std_mgr

/* end-of-file: appl_unique_std_mgr.h */
