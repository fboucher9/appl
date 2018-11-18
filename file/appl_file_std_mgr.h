/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined(INC_APPL_FILE_STD_MGR_H)
#error include appl_file_std_mgr.h once
#endif /* #if defined(INC_APPL_FILE_STD_MGR_H) */

#define INC_APPL_FILE_STD_MGR_H

/* Header file dependency */
#if ! defined INC_APPL_FILE_MGR_H
#error include appl_file_mgr.h before
#endif /* #if ! defined INC_APPL_FILE_MGR_H */

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
        enum appl_status
            v_cleanup(void);

        virtual
        enum appl_status
            v_create_node(
                struct appl_file_descriptor const * const
                    p_file_descriptor,
                struct appl_file * * const
                    r_file);

}; // class appl_file_std_mgr

/* end-of-file: appl_file_std_mgr.h */
