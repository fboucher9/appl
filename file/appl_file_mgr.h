/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_file_mgr_h
{
    inc_appl_file_mgr_h =
        /* Header file dependencies */
        inc_appl_object_h
};

#include <appl_assert_cplusplus.h>

//
//
//
class appl_file_mgr : public appl_object
{
    public:

        appl_file_mgr(
            struct appl_context * const
                p_context);

        virtual
        ~appl_file_mgr();

        virtual
        enum appl_status
            v_get_stdin(
                struct appl_file * * const
                    r_file_node);

        virtual
        enum appl_status
            v_get_stdout(
                struct appl_file * * const
                    r_file_node);

        virtual
        enum appl_status
            v_get_stderr(
                struct appl_file * * const
                    r_file_node);

        virtual
        enum appl_status
            v_create_node(
                struct appl_file_descriptor const * const
                    p_file_descriptor,
                struct appl_file * * const
                    r_file_node);

        virtual
        enum appl_status
            v_destroy_node(
                struct appl_file * const
                    p_file_node);

    protected:

    private:

        appl_file_mgr(
            class appl_file_mgr const & r);

        class appl_file_mgr &
            operator =(
                class appl_file_mgr const & r);

}; // class appl_file_mgr

/* end-of-file: appl_file_mgr.h */
