/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_random_mgr_h
{
    inc_appl_random_mgr_h =
        /* Header file dependencies */
        inc_appl_object_h
};

/* Assert compiler */
#include <appl_assert_cplusplus.h>

//
//
//
class appl_random_mgr : public appl_object
{
    public:

        appl_random_mgr(
            struct appl_context * const
                p_context);

        virtual
        ~appl_random_mgr();

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

    protected:

        enum appl_status
            f_create_pseudo_node(
                unsigned long int const
                    i_seed,
                struct appl_random * * const
                    r_node);

    private:

        appl_random_mgr(
            class appl_random_mgr const & r);

        class appl_random_mgr &
            operator =(
                class appl_random_mgr const & r);

}; // class appl_random_mgr

/* end-of-file: appl_random_mgr.h */
