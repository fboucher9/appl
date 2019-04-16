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
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

// Predefine
struct appl_download;

// Predefine
struct appl_download_descriptor;

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
