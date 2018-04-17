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

class appl_context;

class appl_mutex_std_mgr;

//
//
//
class appl_mutex_std_mgr : public appl_mutex_mgr
{
    public:

        static
        enum appl_status
            create_instance(
                class appl_context * const
                    p_context,
                class appl_mutex_mgr * * const
                    r_mutex_mgr);

    protected:

        appl_mutex_std_mgr();

        virtual
        ~appl_mutex_std_mgr();

    private:

        appl_mutex_std_mgr(
            class appl_mutex_std_mgr const & r);

        class appl_mutex_std_mgr &
            operator =(
                class appl_mutex_std_mgr const & r);

        static
        void
            placement_new(
                void * const
                    p_placement);

        virtual
        enum appl_status
            v_create(
                struct appl_mutex_descriptor const * const
                    p_mutex_descriptor,
                struct appl_mutex * * const
                    r_mutex);

}; // class appl_mutex_std_mgr

/* end-of-file: appl_mutex_std_mgr.h */
