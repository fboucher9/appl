/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_library_std_node_h
{
    inc_appl_library_std_node_h =
        /* Header file dependency */
        inc_appl_library_node_h
};

struct appl_allocator;

struct appl_library_descriptor;

struct appl_library;

/* Assert OS */
#if ! defined APPL_OS_LINUX
#error include only from linux build
#endif /* #if ! defined APPL_OS_LINUX */

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

class appl_library_std_node;

//
//
//
class appl_library_std_node : public appl_library
{
    public:

        static
        enum appl_status
            s_create(
                struct appl_allocator * const
                    p_allocator,
                struct appl_library_descriptor const * const
                    p_library_descriptor,
                struct appl_library * * const
                    r_library);

        static
        enum appl_status
            s_destroy(
                struct appl_allocator * const
                    p_allocator,
                struct appl_library * const
                    p_library);

        appl_library_std_node();

        virtual
        ~appl_library_std_node();

        enum appl_status
            f_init(
                struct appl_library_descriptor const * const
                    p_library_descriptor);

    protected:

    private:

        // --

        void *
            m_library_handle;

        bool
            b_library_handle_initialized;

#define PADDING (APPL_SIZEOF_PTR + 1)
#include <appl_padding.h>

        // --

        appl_library_std_node(
            class appl_library_std_node const & r);

        class appl_library_std_node &
            operator =(
                class appl_library_std_node const & r);

        virtual
        appl_size_t
            v_cleanup(void);

        virtual
        enum appl_status
            v_query(
                unsigned char const * const
                    p_symbol_name_min,
                unsigned char const * const
                    p_symbol_name_max,
                void * * const
                    r_symbol) const;

}; // class appl_library_std_node

/* end-of-file: appl_library_std_node.h */
