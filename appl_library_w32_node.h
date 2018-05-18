/* See LICENSE for license details */

/*

*/

struct appl_context;

struct appl_library_descriptor;

//
//
//
class appl_library_w32_node : public appl_library
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
                struct appl_library_descriptor const * const
                    p_library_descriptor,
                struct appl_library * * const
                    r_library);

    protected:

        //
        //
        //
        appl_library_w32_node();

        //
        //
        //
        virtual
        ~appl_library_w32_node();

        //
        //
        //
        enum appl_status
            init(
                struct appl_library_descriptor const * const
                    p_library_descriptor);

    private:

        HMODULE
            m_library_handle;

        appl_library_w32_node(
            class appl_library_w32_node const & r);

        class appl_library_w32_node &
            operator =(
                class appl_library_w32_node const & r);

        //
        //
        //
        static
        void
        s_new(
            void * const
                p_placement);

        virtual
        enum appl_status
            v_query(
                unsigned char const * const
                    p_symbol_name_min,
                unsigned char const * const
                    p_symbol_name_max,
                void * * const
                    r_symbol) const;

}; // class appl_library_w32_node

/* end-of-file: appl_library_w32_node.h */
