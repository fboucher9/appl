/* See LICENSE for license details */

/*

Module: appl_thread_impl.h

Description:

    OS-specific implementation of thread.

*/

/* Reverse include guard */
enum guard_appl_thread_impl_h
{
    inc_appl_thread_impl_h =
        /* Header file dependencies */
        inc_appl_thread_descriptor_h
};

/* Assert compiler */
#if ! defined __cplusplus
#error use C++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
class appl_thread_impl
{
    public:

        appl_thread_impl();

        ~appl_thread_impl();

        enum appl_status
            f_init(
                struct appl_thread_descriptor const * const
                    p_thread_descriptor);

        enum appl_status
            f_cleanup(void);

        enum appl_status
            f_interrupt(void);

    private:

        struct appl_thread_descriptor
            m_descriptor;

        // --

        union appl_thread_std_node_storage
        {
#if defined APPL_OS_LINUX
            pthread_t
                m_thread;

            appl_ull_t
                m_padding[
                    (sizeof(pthread_t) + sizeof(appl_ull_t) - 1u)
                    / sizeof(appl_ull_t)];

#else /* #if defined APPL_OS_Xx */
            HANDLE
                m_thread;

            appl_ull_t
                m_padding[
                    (sizeof(HANDLE) + sizeof(appl_ull_t) - 1u)
                    / sizeof(appl_ull_t)];

#endif /* #if defined APPL_OS_Xx */

        } m_storage;

        // --

        appl_thread_impl(
            class appl_thread_impl const & r);

        class appl_thread_impl &
            operator =(
                class appl_thread_impl const & r);

#if defined APPL_OS_LINUX

        void *
            thread_linux_handler(void);

        static
        void *
            thread_linux_entry(
                void *
                    p_thread_context);

#else /* #if defined APPL_OS_Xx */

        DWORD
            thread_windows_handler(void);

        static
        DWORD
        CALLBACK
            thread_windows_entry(
                void * const
                    p_thread_context);

#endif /* #if defined APPL_OS_Xx */

}; // class appl_thread_impl

/* end-of-file: appl_thread_impl.h */
