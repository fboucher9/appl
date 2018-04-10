/* See LICENSE for license details */

/*

Module: appl_thread_w32_node.h

Description:

*/

/* Reverse include guard */
#if defined(INC_APPL_THREAD_W32_NODE_H)
#error include appl_thread_w32_node.h once
#endif /* #if defined(INC_APPL_THREAD_W32_NODE_H) */

#define INC_APPL_THREAD_W32_NODE_H

struct appl_thread_property_handle;

/* Assert compiler */
#if !defined(__cplusplus)
#error use C++ compiler
#endif /* #if !defined(__cplusplus) */

/* Header file dependency */
#if !defined(INC_APPL_THREAD_NODE_H)
#error include appl_thread_node.h before
#endif /* #if !defined(INC_APPL_THREAD_NODE_H) */

/* Assert OS */
#if ! defined APPL_OS_WINDOWS
#error include from windows build
#endif /* #if ! defined APPL_OS_WINDOWS */

class appl_context;

class appl_thread_w32_node;

//
//
//
class appl_thread_w32_node : public appl_thread_node
{
    public:

        static
        enum appl_status
            create_instance(
                class appl_context * const
                    p_context,
                struct appl_thread_property_handle const * const
                    p_thread_property_handle,
                class appl_thread_node * * const
                    r_thread_node);

    protected:

        appl_thread_w32_node();

        virtual
        ~appl_thread_w32_node();

        virtual
        enum appl_status
            v_start(void);

        virtual
        enum appl_status
            v_stop(
                unsigned long int const
                    i_wait_freq,
                unsigned long int const
                    i_wait_count,
                void * * const
                    r_result);

        virtual
        enum appl_status
            v_interrupt(void);

    private:

        HANDLE
            m_w32_thread_handle;

        appl_thread_w32_node(
            class appl_thread_w32_node const & r);

        class appl_thread_w32_node &
            operator =(
                class appl_thread_w32_node const & r);

        static
        void
            placement_new(
                void * const
                    p_placement);

        virtual
        enum appl_status
            init(
                void const * const
                    p_descriptor);

        virtual
        enum appl_status
            cleanup(void);

}; // class appl_thread_w32_node

/* end-of-file: appl_thread_w32_node.h */
