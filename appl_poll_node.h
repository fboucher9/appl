/* See LICENSE for license details */

/*

*/

#if !defined(__cplusplus)
#error use c++ compiler
#endif /* #if !defined(__cplusplus) */

class appl_poll_node;

class appl_poll_mgr;

class appl_context;

struct appl_poll_descriptor;

//
//
//
struct appl_poll : public appl_node
{
    friend class appl_poll_mgr;

    public:

        static
        enum appl_status
            create_instance(
                class appl_context * const
                    p_context,
                class appl_poll_mgr * const
                    p_poll_mgr,
                struct appl_poll_descriptor const * const
                    p_poll_descriptor,
                struct appl_poll * * const
                    r_poll);

        virtual
        enum appl_status
            dispatch_event(
                unsigned int const
                    i_poll_flags);

        bool
            is_busy(void) const;

        bool
            is_avail(void) const;

    protected:

        appl_poll();

        virtual
        ~appl_poll();

        class appl_poll_mgr *
            m_poll_mgr;

        struct appl_poll_descriptor
            m_descriptor;

        int
            m_fd;

        unsigned int
            ui_padding[3u];

        bool
            m_busy;

        bool
            m_avail;

        unsigned char
            uc_padding[6u];

    private:

        appl_poll(
            class appl_poll const & r);

        class appl_poll &
            operator =(
                class appl_poll const & r);

}; // struct appl_poll

/* end-of-file: appl_poll_node.h */
