/* See LICENSE for license details */

/*

*/

/* Included. */
#define INC_APPL_DOWNLOAD_NODE_H

/* Reverse include guard */
enum guard_appl_download_node_h
{
    inc_appl_download_node_h = 1
        /* Header file dependency */
        + inc_appl_node_h
        + inc_appl_download_handle_h
};

//
//
//
struct appl_download : public appl_node
{
    public:

        appl_download(
            struct appl_context * const
                p_context);

        virtual
        ~appl_download();

        enum appl_status
            f_init(
                struct appl_download_descriptor const * const
                    p_descriptor);

        virtual
        appl_size_t
            v_cleanup(void);

        virtual
        enum appl_status
            v_cancel(void);

        virtual
        enum appl_status
            v_wait(
                unsigned long int const
                    i_timeout_msec,
                enum appl_download_status * const
                    r_status);

    protected:

    private:

        struct appl_download_descriptor
            m_descriptor;

        // --

        struct appl_thread *
            m_thread;

        struct appl_mutex *
            m_mutex;

        // --

        struct appl_event *
            m_event;

        enum appl_download_status
            m_status;

        bool
            m_thread_created;

        bool
            m_mutex_created;

        bool
            m_event_created;

        bool
            m_kill;

#define PADDING (APPL_SIZEOF_PTR + APPL_SIZEOF_INT + 4)
#include <appl_padding.h>

        // --

        appl_download(
            struct appl_download const & r);

        struct appl_download &
            operator =(
                struct appl_download const & r);

        static
        void
            s_thread_entry(
                void * const
                    p_thread_context);

        void
            f_thread_handler(void);

        enum appl_status
            f_cancel(void);

        enum appl_status
            f_start_thread(void);

}; // struct appl_download

/* end-of-file: appl_download_node.h */
