/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_unique_mgr_h
{
    inc_appl_unique_mgr_h = 1
        /* Header file dependencies */
        | inc_appl_object_h
        /* ... */
}; // enum guard_appl_unique_mgr_h

/* Assert compiler */
#include <misc/appl_assert_cplusplus.h>

//
//
//
class appl_unique_mgr : public appl_object
{
    public:

        appl_unique_mgr(
            struct appl_context * const
                p_context);

        virtual
        ~appl_unique_mgr();

        enum appl_status
            f_init(void);

        virtual
        appl_size_t
            v_cleanup(void);

        virtual
        enum appl_status
            v_pick(
                unsigned long int * const
                    r_unique);

    protected:

    private:

        appl_unique_mgr(
            class appl_unique_mgr const & r);

        class appl_unique_mgr &
            operator =(
                class appl_unique_mgr const & r);

}; // class appl_unique_mgr

/* end-of-file: appl_unique_mgr.h */
