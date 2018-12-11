/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_event_impl_h
{
    inc_appl_event_impl_h =
        /* Header file dependencies */
        inc_appl_status_h
};

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
            f_init(void);

        enum appl_status
            f_cleanup(void);

        enum appl_status
            f_signal(void);

        enum appl_status
            f_wait(
                class appl_mutex_impl * const
                    p_mutex_impl,
                unsigned long int const
                    i_wait_freq,
                unsigned long int const
                    i_wait_count);

    private:

        union appl_event_impl_storage
        {

#if defined APPL_OS_LINUX

            pthread_cond_t
                m_private;

            appl_ull_t
                m_padding[
                    (sizeof(pthread_cond_t) + sizeof(appl_ull_t) - 1u)
                    / sizeof(appl_ull_t)];

#else /* #if defined APPL_OS_Xx */

            CONDITION_VARIABLE
                m_private;

            appl_ull_t
                m_padding[
                    (sizeof(CONDITION_VARIABLE) + sizeof(appl_ull_t) - 1u)
                    / sizeof(appl_ull_t)];

#endif /* #if defined APPL_OS_Xx */

        } m_storage;

        appl_event_impl(
            class appl_event_impl const & r);

        class appl_event_impl &
            operator =(
                class appl_event_impl const & r);

}; // class appl_event_impl

/* end-of-file: appl_event_impl.h */
