/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_library_mgr_h
{
    inc_appl_library_mgr_h =
        /* Header file dependency */
        inc_appl_object_h
};

/* Assert compiler */
#include <appl_assert_cplusplus.h>

//
//
//
class appl_library_mgr : public appl_object
{
    public:

        appl_library_mgr(
            struct appl_context * const
                p_context);

        virtual
        ~appl_library_mgr();

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

    protected:

    private:

        appl_library_mgr(
            class appl_library_mgr const & r);

        class appl_library_mgr &
            operator =(
                class appl_library_mgr const & r);

}; // class appl_library_mgr

/* end-of-file: appl_library_mgr.h */
