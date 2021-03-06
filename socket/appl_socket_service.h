/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_socket_service_h
{
    inc_appl_socket_service_h =
        /* Header file dependencies */
        inc_appl_status_h
};

/* Assert compiler */
#include <misc/appl_assert_cplusplus.h>

//
//
//
class appl_socket_service
{
    public:

        static
        enum appl_status
        s_create(
            struct appl_context * const
                p_context,
            struct appl_socket_property const * const
                p_socket_descriptor,
            struct appl_socket * * const
                r_socket);

        static
        enum appl_status
        s_destroy(
            struct appl_socket * const
                p_socket);

        static
        enum appl_status
        s_accept(
            struct appl_socket * const
                p_socket,
            struct appl_socket * * const
                r_socket,
            struct appl_address * * const
                r_address);

        static
        enum appl_status
        s_send(
            struct appl_socket * const
                p_socket,
            unsigned char const * const
                p_buf_min,
            unsigned char const * const
                p_buf_max,
            unsigned long int * const
                r_count);

        static
        enum appl_status
        s_recv(
            struct appl_socket * const
                p_socket,
            unsigned char * const
                p_buf_min,
            unsigned char * const
                p_buf_max,
            unsigned long int * const
                r_count);

        static
        enum appl_status
        s_sendto(
            struct appl_socket * const
                p_socket,
            unsigned char const * const
                p_buf_min,
            unsigned char const * const
                p_buf_max,
            unsigned long int * const
                r_count,
            struct appl_address * const
                p_remote_address);

        static
        enum appl_status
        s_recvfrom(
            struct appl_socket * const
                p_socket,
            unsigned char * const
                p_buf_min,
            unsigned char * const
                p_buf_max,
            unsigned long int * const
                r_count,
            struct appl_address * const
                p_remote_address);

        static
        enum appl_status
        s_wait(
            struct appl_socket * const
                p_socket,
            enum appl_socket_wait_type const
                e_wait_type,
            unsigned long int const
                i_wait_freq,
            unsigned long int const
                i_wait_count);

        static
        enum appl_status
        s_poll(
            struct appl_context * const
                p_context,
            struct appl_poll_descriptor const * const
                p_poll_descriptor_min,
            struct appl_poll_descriptor const * const
                p_poll_descriptor_max,
            unsigned long int const
                i_wait_freq,
            unsigned long int const
                i_wait_count);

}; // class appl_socket_service

/* end-of-file: appl_socket_service.h */
