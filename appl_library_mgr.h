/* See LICENSE for license details */

/*

*/

//
//
//
class appl_library_mgr : public appl_object
{
    public:

        virtual
        enum appl_status
            v_create_node(
                struct appl_library_descriptor const * const
                    p_library_descriptor,
                struct appl_library * * const
                    r_library);

    protected:

        appl_library_mgr();

        virtual
        ~appl_library_mgr();

    private:

        appl_library_mgr(
            class appl_library_mgr const & r);

        class appl_library_mgr &
            operator =(
                class appl_library_mgr const & r);

}; // class appl_library_mgr

/* end-of-file: appl_library_mgr.h */
