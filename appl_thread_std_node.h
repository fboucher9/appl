/* See LICENSE for license details */

/*

Module: appl_thread_std_node.h

Description:

*/

#if defined(INC_APPL_THREAD_STD_NODE_H)
#error include appl_thread_std_node.h once
#endif /* #if defined(INC_APPL_THREAD_STD_NODE_H) */

#define INC_APPL_THREAD_STD_NODE_H

#if !defined(__cplusplus)
#error use C++ compiler
#endif /* #if !defined(__cplusplus) */

#if !defined(INC_APPL_OBJECT_H)
#error include appl_object.h before
#endif /* #if !defined(INC_APPL_OBJECT_H) */

#if !defined(INC_APPL_THREAD_NODE_H)
#error include appl_thread_node.h before
#endif /* #if !defined(INC_APPL_THREAD_NODE_H) */

class appl_client;

struct appl_thread_descriptor;

//
//
//
class appl_thread_std_node : public appl_thread_node
{
    public:

        static
        enum appl_status
            create_instance(
                class appl_client * const
                    p_client,
                struct appl_thread_descriptor const * const
                    p_thread_descriptor,
                class appl_thread_node * * const
                    r_thread_node);

    protected:

        appl_thread_std_node();

        virtual
        ~appl_thread_std_node();

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

    private:

        pthread_t
            p_external_thread_handle;

        appl_thread_std_node(
            class appl_thread_std_node const & r);

        class appl_thread_std_node &
            operator =(
                class appl_thread_std_node const & r);

        static
        void
            placement_new(
                void * const
                    p_placement);

}; // class appl_thread_std_node

/* end-of-file: appl_thread_std_node.h */
