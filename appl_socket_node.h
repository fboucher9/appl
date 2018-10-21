/* See LICENSE for license details */

/*

Module: appl_socket_node.h

Description:

    Public interface of a socket instance, created via the socket manager.

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

/* Header file dependency */
#if ! defined INC_APPL_SOCKET_DESCRIPTOR_H
#error include appl_socket_descriptor.h before
#endif /* #if ! defined INC_APPL_SOCKET_DESCRIPTOR_H */

struct appl_address;

struct appl_socket;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
struct appl_socket : public appl_heap_object
{
    public:

        virtual
        enum appl_status
        v_accept(
            struct appl_socket * * const
                r_socket,
            struct appl_address * * const
                r_address);

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
            struct appl_address * const
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
            struct appl_address * const
                p_remote_address);

        virtual
        enum appl_status
        v_wait(
            enum appl_socket_wait_type const
                e_wait_type,
            unsigned long int const
                i_wait_freq,
            unsigned long int const
                i_wait_count);

    protected:

        appl_socket();

        virtual
        ~appl_socket();

    private:

        appl_socket(
            struct appl_socket const & r);

        struct appl_socket &
            operator =(
                struct appl_socket const & r);

}; // struct appl_socket

/* end-of-file: appl_socket_node.h */
