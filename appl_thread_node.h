/* See LICENSE for license details */

/*

Module: appl_thread_node.h

Description:

*/

#if defined(INC_APPL_THREAD_NODE_H)
#error include appl_thread_node.h once
#endif /* #if defined(INC_APPL_THREAD_NODE_H) */

#define INC_APPL_THREAD_NODE_H

#if !defined(__cplusplus)
#error use C++ compiler
#endif /* #if !defined(__cplusplus) */

#if !defined(INC_APPL_OBJECT_H)
#error include appl_object.h before
#endif /* #if !defined(INC_APPL_OBJECT_H) */

class appl_client;

//
//
//
class appl_thread_node : public appl_object
{
    public:

        virtual
        enum appl_status
            wait_result(
                class appl_client * const
                    p_client,
                void * * const
                    r_result);

        virtual
        enum appl_status
            detach(
                class appl_client * const
                    p_client);

    protected:

        appl_thread_node();

        virtual
        ~appl_thread_node();

    private:

        appl_thread_node(
            class appl_thread_node const & r);

        class appl_thread_node &
            operator =(
                class appl_thread_node const & r);

}; // class appl_thread_node

/* end-of-file: appl_thread_node.h */
