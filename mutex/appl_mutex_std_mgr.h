/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_mutex_std_mgr_h
{
    inc_appl_mutex_std_mgr_h =
        /* Header file dependency */
        inc_appl_mutex_mgr_h
};

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
    public:

        static
        enum appl_status
            s_create(
                struct appl_allocator * const
                    p_allocator,
                class appl_mutex_mgr * * const
                    r_mutex_mgr);

        appl_mutex_std_mgr();

        virtual
        ~appl_mutex_std_mgr();

        enum appl_status
            f_init(void);

    protected:

    private:

        // --

        struct appl_pool *
            m_pool;

        bool
            m_pool_created;

#define PADDING (APPL_SIZEOF_PTR + 1)
#include <appl_padding.h>

        // --

        appl_mutex_std_mgr(
            class appl_mutex_std_mgr const & r);

        class appl_mutex_std_mgr &
            operator =(
                class appl_mutex_std_mgr const & r);

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
