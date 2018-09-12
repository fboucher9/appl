/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_EVENT_IMPL_H
#error include appl_event_impl.h once
#endif /* #if defined INC_APPL_EVENT_IMPL_H */

#define INC_APPL_EVENT_IMPL_H

class appl_event_impl;

class appl_mutex_impl;

//
//
//
class appl_event_impl
{
    friend class appl_mutex_impl;

    public:

        appl_event_impl();

        ~appl_event_impl();

        enum appl_status
            init(void);

        enum appl_status
            cleanup(void);

        enum appl_status
            signal(void);

        enum appl_status
            wait(
                class appl_mutex_impl * const
                    p_mutex_impl,
                unsigned long int const
                    i_wait_freq,
                unsigned long int const
                    i_wait_count);

    private:

#if defined APPL_OS_LINUX

        pthread_cond_t
            m_private;

#else /* #if defined APPL_OS_Xx */

        CONDITION_VARIABLE
            m_private;

#endif /* #if defined APPL_OS_Xx */

        appl_event_impl(
            class appl_event_impl const & r);

        class appl_event_impl &
            operator =(
                class appl_event_impl const & r);

}; // class appl_event_impl

/* end-of-file: appl_event_impl.h */
