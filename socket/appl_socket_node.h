/* See LICENSE for license details */

/*

Module: appl_socket_node.h

Description:

    Public interface of a socket instance, created via the socket manager.

*/

/* Reverse include guard */
enum guard_appl_socket_node_h
{
    inc_appl_socket_node_h =
        /* Header file dependency */
        inc_appl_object_h
        + inc_appl_socket_descriptor_h
};

/* Assert compiler */
#include <misc/appl_assert_cplusplus.h>

//
//
//
struct appl_socket : public appl_object
{
    public:

        appl_socket(
            struct appl_context * const
                p_context);

        virtual
        ~appl_socket();

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

    private:

        appl_socket(
            struct appl_socket const & r);

        struct appl_socket &
            operator =(
                struct appl_socket const & r);

}; // struct appl_socket

/* end-of-file: appl_socket_node.h */
