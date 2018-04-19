/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined(INC_APPL_THREAD_W32_MGR_H)
#error include appl_thread_w32_mgr.h once
#endif /* #if defined(INC_APPL_THREAD_W32_MGR_H) */

#define INC_APPL_THREAD_W32_MGR_H

struct appl_thread_property_handle;

/* Assert compiler */
#if !defined(__cplusplus)
#error use c++ compiler
#endif /* #if !defined(__cplusplus) */

/* Assert OS */
#if ! defined APPL_OS_WINDOWS
#error include from windows build
#endif /* #if ! defined APPL_OS_WINDOWS */

/* Header file dependency */
#if !defined(INC_APPL_THREAD_MGR_H)
#error include appl_thread_mgr.h before
#endif /* #if !defined(INC_APPL_THREAD_MGR_H) */

class appl_thread_w32_mgr;

//
//
//
class appl_thread_w32_mgr :
    public appl_thread_mgr
{
    public:

        static
        enum appl_status
            create_instance(
                struct appl_context * const
                    p_context,
                class appl_thread_mgr * * const
                    r_thread_mgr);

    protected:

        appl_thread_w32_mgr();

        virtual
        ~appl_thread_w32_mgr();

    private:

        appl_thread_w32_mgr(
            class appl_thread_w32_mgr const & r);

        class appl_thread_w32_mgr &
            operator =(
                class appl_thread_w32_mgr const & r);

        static
        void
            placement_new(
                void * const
                    p_placement);

        virtual
        enum appl_status
            v_create(
                struct appl_context * const
                    p_context,
                struct appl_thread_property const * const
                    p_thread_property,
                struct appl_thread * * const
                    r_thread);

}; // class appl_thread_w32_mgr

/* end-of-file: appl_thread_w32_mgr.h */
