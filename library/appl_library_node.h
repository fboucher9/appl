/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_library_node_h
{
    inc_appl_library_node_h =
        /* Header file dependency */
        inc_appl_object_h
};

struct appl_library;

/* Assert compiler */
#include <misc/appl_assert_cplusplus.h>

//
//
//
struct appl_library : public appl_object
{
    public:

        appl_library(
            struct appl_context * const
                p_context);

        virtual
        ~appl_library();

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

    private:

        appl_library(
            struct appl_library const & r);

        struct appl_library &
            operator =(
                struct appl_library const & r);

}; // struct appl_library

/* end-of-file: appl_library_node.h */
