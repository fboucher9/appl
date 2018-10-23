/* See LICENSE for license details */

/*

*/

#if defined(INC_APPL_THREAD_STD_MGR_H)
#error include appl_thread_std_mgr.h once
#endif /* #if defined(INC_APPL_THREAD_STD_MGR_H) */

#define INC_APPL_THREAD_STD_MGR_H

/* Predefine */
struct appl_pool;

#if !defined(__cplusplus)
#error use c++ compiler
#endif /* #if !defined(__cplusplus) */

#if !defined(INC_APPL_THREAD_MGR_H)
#error include appl_thread_mgr.h before
#endif /* #if !defined(INC_APPL_THREAD_MGR_H) */

//
//
//
class appl_thread_std_mgr :
    public appl_thread_mgr
{
    friend struct appl_heap;

    public:

        static
        enum appl_status
            s_create(
                struct appl_heap * const
                    p_heap,
                class appl_thread_mgr * * const
                    r_thread_mgr);

        enum appl_status
            f_init(void);

    protected:

        appl_thread_std_mgr();

        virtual
        ~appl_thread_std_mgr();

    private:

        // --

        struct appl_pool *
            m_pool;

        void *
            pv_padding[1u];

        // --

        bool
            m_pool_created;

        unsigned char
            uc_padding[7u];

        // --

        appl_thread_std_mgr(
            class appl_thread_std_mgr const & r);

        class appl_thread_std_mgr &
            operator =(
                class appl_thread_std_mgr const & r);

        virtual
        enum appl_status
            v_cleanup(void);

        virtual
        enum appl_status
            v_create(
                struct appl_thread_property const * const
                    p_thread_property,
                struct appl_thread * * const
                    r_thread);

}; // class appl_thread_std_mgr

/* end-of-file: appl_thread_std_mgr.h */
