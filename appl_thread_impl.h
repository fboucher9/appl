/* See LICENSE for license details */

/*

Module: appl_thread_impl.h

Description:

    OS-specific implementation of thread.

*/

/* Reverse include guard */
#if defined INC_APPL_THREAD_IMPL_H
#error include appl_thread_impl.h once
#endif /* #if defined INC_APPL_THREAD_IMPL_H */

#define INC_APPL_THREAD_IMPL_H

/* Header file dependency */
#if ! defined INC_APPL_THREAD_DESCRIPTOR_H
#error include appl_thread_descriptor.h before appl_thread_impl.h
#endif /* #if ! defined INC_APPL_THREAD_DESCRIPTOR_H */

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
            f_start(
                struct appl_thread_descriptor const * const
                    p_descriptor);

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
#else /* #if defined APPL_OS_Xx */
            HANDLE
                m_thread;
#endif /* #if defined APPL_OS_Xx */

            appl_ull_t
                m_padding[
                    (sizeof(m_thread) + sizeof(appl_ull_t) - 1u)
                    / sizeof(appl_ull_t)];

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
