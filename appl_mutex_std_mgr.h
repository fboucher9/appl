/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_MUTEX_STD_MGR_H
#error include appl_mutex_std_mgr.h once
#endif /* #if defined INC_APPL_MUTEX_STD_MGR_H */

#define INC_APPL_MUTEX_STD_MGR_H

/* Header file dependency */
#if ! defined INC_APPL_MUTEX_MGR_H
#error include appl_mutex_mgr.h before
#endif /* #if ! defined INC_APPL_MUTEX_MGR_H */

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

struct appl_object;

class appl_mutex_std_mgr;

//
//
//
class appl_mutex_std_mgr : public appl_mutex_mgr
{
    friend struct appl_object;
    public:

        static
        enum appl_status
            s_create(
                struct appl_heap * const
                    p_heap,
                class appl_mutex_mgr * * const
                    r_mutex_mgr);

    protected:

        appl_mutex_std_mgr();

        virtual
        ~appl_mutex_std_mgr();

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

        appl_mutex_std_mgr(
            class appl_mutex_std_mgr const & r);

        class appl_mutex_std_mgr &
            operator =(
                class appl_mutex_std_mgr const & r);

        static
        void
            s_new(
                void * const
                    p_placement);

        enum appl_status
            f_init(void);

        virtual
        enum appl_status
            v_cleanup(void);

        virtual
        enum appl_status
            v_create(
                struct appl_mutex_descriptor const * const
                    p_mutex_descriptor,
                struct appl_mutex * * const
                    r_mutex);

}; // class appl_mutex_std_mgr

/* end-of-file: appl_mutex_std_mgr.h */
