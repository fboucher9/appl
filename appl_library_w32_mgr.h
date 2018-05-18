/* See LICENSE for license details */

/*

*/

struct appl_context;

class appl_library_w32_mgr;

//
//
//
class appl_library_w32_mgr : public appl_library_mgr
{
    public:

        //
        //
        //
        static
        enum appl_status
            s_create(
                struct appl_context * const
                    p_context,
                struct appl_library_mgr * * const
                    r_library_mgr);

    protected:

        //
        //
        //
        appl_library_w32_mgr();

        //
        //
        //
        virtual
        ~appl_library_w32_mgr();

    private:

        appl_library_w32_mgr(
            class appl_library_w32_mgr const & r);

        class appl_library_w32_mgr &
            operator =(
                class appl_library_w32_mgr const & r);

        //
        //
        //
        static
            void
            s_new(
                void * const
                    p_placement);

        //
        //
        //
        virtual
        enum appl_status
            v_create_node(
                struct appl_library_descriptor const * const
                    p_library_descriptor,
                struct appl_library * * const
                    r_library);

}; // class appl_library_w32_mgr

/* end-of-file: appl_library_w32_mgr.h */
