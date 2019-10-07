/* See LICENSE for license details */

/*

*/

/* Included. */
#define INC_APPL_DOWNLOAD_MGR_H

/* Reverse include guard */
enum guard_appl_download_mgr_h
{
    inc_appl_download_mgr_h = 1
        /* Header file dependency */
        + inc_appl_object_h
};

/* Assert compiler */
#include <misc/appl_assert_cplusplus.h>

//
//
//
class appl_download_mgr : public appl_object
{
    public:

        appl_download_mgr(
            struct appl_context * const
                p_context);

        virtual
        ~appl_download_mgr();

        enum appl_status
            f_init(void);

        virtual
        appl_size_t
            v_cleanup(void);

        virtual
        enum appl_status
            v_create_node(
                struct appl_download_descriptor const * const
                    p_descriptor,
                struct appl_download * * const
                    r_handle);

        virtual
        enum appl_status
            v_destroy_node(
                struct appl_download * const
                    p_handle);

    protected:

    private:

        appl_download_mgr(
            class appl_download_mgr const & r);

        class appl_download_mgr &
            operator =(
                class appl_download_mgr const & r);

}; // class appl_download_mgr

/* end-of-file: appl_download_mgr.h */
