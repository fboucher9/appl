/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined(INC_APPL_FILE_STD_MGR_H)
#error include appl_file_std_mgr.h once
#endif /* #if defined(INC_APPL_FILE_STD_MGR_H) */

#define INC_APPL_FILE_STD_MGR_H

#if !defined(__cplusplus)
#error use c++ compiler
#endif /* #if !defined(__cplusplus) */

class appl_file_std_mgr;

//
//
//
class appl_file_std_mgr : public appl_file_mgr
{
    public:

        static
        enum appl_status
            create_instance(
                struct appl_context * const
                    p_context,
                class appl_file_mgr * * const
                    r_file_mgr);

    protected:

        appl_file_std_mgr();

        virtual
        ~appl_file_std_mgr();

    private:

        appl_file_std_mgr(
            class appl_file_std_mgr const & r);

        class appl_file_std_mgr &
            operator =(
                class appl_file_std_mgr const & r);

        static
        void
            placement_new(
                void * const
                    p_placement);

        virtual
        enum appl_status
            v_create_node(
                struct appl_file_descriptor const * const
                    p_file_descriptor,
                struct appl_file * * const
                    r_file);

}; // class appl_file_std_mgr

/* end-of-file: appl_file_std_mgr.h */
