/* See LICENSE for license details */

/*

*/

//
//
//
struct appl_library : public appl_object
{
    public:

        virtual
        enum appl_status
            v_query(
                unsigned char const * const
                    p_symbol_name_min,
                unsigned char const * const
                    p_symbol_name_max,
                void * * const
                    r_symbol) const;

    protected:

        appl_library();

        virtual
        ~appl_library();

    private:

        appl_library(
            struct appl_library const & r);

        struct appl_library &
            operator =(
                struct appl_library const & r);

}; // struct appl_library

/* end-of-file: appl_library_node.h */
