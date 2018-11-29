/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_mutex_impl_h
{
    inc_appl_mutex_impl_h =
        /* Header file dependencies */
        inc_appl_status_h
};

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

class appl_mutex_impl;

class appl_event_impl;

//
//
//
class appl_mutex_impl
{
    friend class appl_event_impl;

    public:

        appl_mutex_impl();

        ~appl_mutex_impl();

        enum appl_status
            f_init(void);

        enum appl_status
            f_cleanup(void);

        enum appl_status
            f_lock(void);

        enum appl_status
            f_unlock(void);

        enum appl_status
            f_sync(
                enum appl_status (*
                    p_sync_callback)(
                    void * const
                        p_sync_context),
                void * const
                    p_sync_context);

    private:

        union appl_mutex_impl_storage
        {
#if defined APPL_OS_LINUX

            pthread_mutex_t
                m_private;

            appl_ull_t
                m_padding[
                    (sizeof(pthread_mutex_t) + sizeof(appl_ull_t) - 1u)
                    / sizeof(appl_ull_t)];

#else /* #if defined APPL_OS_Xx */

            CRITICAL_SECTION
                m_private;

            appl_ull_t
                m_padding[
                    (sizeof(CRITICAL_SECTION) + sizeof(appl_ull_t) - 1u)
                    / sizeof(appl_ull_t)];

#endif /* #if defined APPL_OS_Xx */

        } m_storage;

        appl_mutex_impl(
            class appl_mutex_impl const & r);

        class appl_mutex_impl &
            operator =(
                class appl_mutex_impl const & r);

}; // class appl_mutex_impl

/* end-of-file: appl_mutex_impl.h */
