/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_MUTEX_IMPL_H
#error include appl_mutex_impl.h once
#endif /* #if defined INC_APPL_MUTEX_IMPL_H */

#define INC_APPL_MUTEX_IMPL_H

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
            init(void);

        enum appl_status
            cleanup(void);

        enum appl_status
            lock(void);

        enum appl_status
            unlock(void);

    private:

        union appl_mutex_impl_storage
        {
#if defined APPL_OS_LINUX

            pthread_mutex_t
                m_private;

#else /* #if defined APPL_OS_Xx */

            CRITICAL_SECTION
                m_private;

#endif /* #if defined APPL_OS_Xx */

            unsigned char
                m_padding[((sizeof(m_private) + 7u) / 8u) * 8u];

        } m_storage;

        appl_mutex_impl(
            class appl_mutex_impl const & r);

        class appl_mutex_impl &
            operator =(
                class appl_mutex_impl const & r);

}; // class appl_mutex_impl

/* end-of-file: appl_mutex_impl.h */
