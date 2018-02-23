/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_SOCKET_NODE_H
#error include appl_socket_node.h once
#endif /* #if defined INC_APPL_SOCKET_NODE_H */

#define INC_APPL_SOCKET_NODE_H

/* Header file dependency */
#if ! defined INC_APPL_OBJECT_H
#error include appl_object.h before
#endif /* #if ! defined INC_APPL_OBJECT_H */

struct appl_buf;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

class appl_address_node;

class appl_socket_node;

//
//
//
class appl_socket_node : public appl_object
{
    public:

        virtual
        enum appl_status
        v_send(
            struct appl_buf * const
                p_buf);

        virtual
        enum appl_status
        v_recv(
            struct appl_buf * const
                p_buf);

        virtual
        enum appl_status
        v_sendto(
            struct appl_buf * const
                p_buf,
            class appl_address_node * const
                p_remote_address);

        virtual
        enum appl_status
        v_recvfrom(
            struct appl_buf * const
                p_buf,
            class appl_address_node * const
                p_remote_address);

    protected:

        appl_socket_node();

        virtual
        ~appl_socket_node();

    private:

        appl_socket_node(
            class appl_socket_node const & r);

        class appl_socket_node &
            operator =(
                class appl_socket_node const & r);

}; // class appl_socket_node

/* end-of-file: appl_socket_node.h */
