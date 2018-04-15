/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_SOCKET_STD_NODE_H
#error include appl_socket_std_node.h once
#endif /* #if defined INC_APPL_SOCKET_STD_NODE_H */

#define INC_APPL_SOCKET_STD_NODE_H

/* Header file dependency */
#if ! defined INC_APPL_SOCKET_NODE_H
#error include appl_socket_node.h before
#endif /* #if ! defined INC_APPL_SOCKET_NODE_H */

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

class appl_socket_std_node;

//
//
//
class appl_socket_std_node : public appl_socket_node
{
    public:

        static
        enum appl_status
            s_create(
                class appl_context * const
                    p_context,
                struct appl_property_handle const * const
                    p_socket_descriptor,
                class appl_socket_node * * const
                    r_socket_node);

    protected:

        appl_socket_std_node();

        virtual
        ~appl_socket_std_node();

    private:

        int
            m_fd;

        unsigned int
            ui_padding[3u];

        appl_socket_std_node(
            class appl_socket_std_node const & r);

        class appl_socket_std_node &
            operator =(
                class appl_socket_std_node const & r);

        static
        void
            s_new(
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

        virtual
        enum appl_status
        v_send(
            unsigned char const * const
                p_buf_min,
            unsigned char const * const
                p_buf_max,
            unsigned long int * const
                r_count);

        virtual
        enum appl_status
        v_recv(
            unsigned char * const
                p_buf_min,
            unsigned char * const
                p_buf_max,
            unsigned long int * const
                r_count);

        virtual
        enum appl_status
        v_sendto(
            unsigned char const * const
                p_buf_min,
            unsigned char const * const
                p_buf_max,
            unsigned long int * const
                r_count,
            class appl_address_node * const
                p_remote_address);

        virtual
        enum appl_status
        v_recvfrom(
            unsigned char * const
                p_buf_min,
            unsigned char * const
                p_buf_max,
            unsigned long int * const
                r_count,
            class appl_address_node * const
                p_remote_address);

}; // class appl_socket_std_node

/* end-of-file: appl_socket_std_node.h */
