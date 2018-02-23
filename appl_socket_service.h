/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_SOCKET_SERVICE_H
#error include appl_socket_service.h once
#endif /* #if defined INC_APPL_SOCKET_SERVICE_H */

#define INC_APPL_SOCKET_SERVICE_H

struct appl_context_handle;

struct appl_socket_descriptor;

struct appl_socket_handle;

struct appl_address_handle;

struct appl_buf;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

class appl_socket_service;

//
//
//
class appl_socket_service
{
    public:

        static
        enum appl_status
        s_create(
            struct appl_context_handle * const
                p_context_handle,
            struct appl_socket_descriptor const * const
                p_socket_descriptor,
            struct appl_socket_handle * * const
                r_socket_handle);

        static
        enum appl_status
        s_send(
            struct appl_socket_handle * const
                p_socket_handle,
            struct appl_buf * const
                p_buf);

        static
        enum appl_status
        s_recv(
            struct appl_socket_handle * const
                p_socket_handle,
            struct appl_buf * const
                p_buf);

        static
        enum appl_status
        s_sendto(
            struct appl_socket_handle * const
                p_socket_handle,
            struct appl_buf * const
                p_buf,
            struct appl_address_handle * const
                p_remote_address);

        static
        enum appl_status
        s_recvfrom(
            struct appl_socket_handle * const
                p_socket_handle,
            struct appl_buf * const
                p_buf,
            struct appl_address_handle * const
                p_remote_address);

}; // class appl_socket_service

/* end-of-file: appl_socket_service.h */
