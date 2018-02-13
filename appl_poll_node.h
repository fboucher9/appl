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
class appl_poll_node : public appl_object
{
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
                class appl_poll_node * * const
                    r_poll_node);

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

        appl_poll_node();

        virtual
        ~appl_poll_node();

        class appl_poll_mgr *
            m_poll_mgr;

        struct appl_poll_descriptor
            m_descriptor;

        bool
            m_busy;

        bool
            m_avail;

    private:

        appl_poll_node(
            class appl_poll_node const & r);

        class appl_poll_node &
            operator =(
                class appl_poll_node const & r);

}; // class appl_poll_node

/* end-of-file: appl_poll_node.h */
