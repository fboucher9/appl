/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_file_std_mgr_h
{
    inc_appl_file_std_mgr_h =
        /* Header file dependencies */
        inc_appl_file_mgr_h
};

/* Predefine */
struct appl_pool;

/* Assert compiler */
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
            s_create(
                struct appl_allocator * const
                    p_allocator,
                class appl_file_mgr * * const
                    r_file_mgr);

        static
        enum appl_status
            s_destroy(
                struct appl_allocator * const
                    p_allocator,
                class appl_file_mgr * const
                    p_file_mgr);

        appl_file_std_mgr();

        virtual
        ~appl_file_std_mgr();

        enum appl_status
            f_init(void);

    protected:

    private:

        // --

        struct appl_pool *
            m_pool;

#define PADDING (APPL_SIZEOF_PTR)
#include <appl_padding.h>

        // --

        appl_file_std_mgr(
            class appl_file_std_mgr const & r);

        class appl_file_std_mgr &
            operator =(
                class appl_file_std_mgr const & r);

        virtual
        appl_size_t
            v_cleanup(void);

        virtual
        enum appl_status
            v_create_node(
                struct appl_file_descriptor const * const
                    p_file_descriptor,
                struct appl_file * * const
                    r_file);

        virtual
        enum appl_status
            v_destroy_node(
                struct appl_file * const
                    p_file);

}; // class appl_file_std_mgr

/* end-of-file: appl_file_std_mgr.h */
