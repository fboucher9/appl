/* See LICENSE for license details */

/*

*/

struct appl_context;

struct appl_socket;

struct appl_send_socket;

struct appl_address;

struct appl_send_address;

/*

*/
struct appl_send_socket_descriptor
{
    struct appl_socket *
        p_socket;

#define PADDING (APPL_SIZEOF_PTR)
#include <appl_padding.h>

}; /* struc appl_send_socket_descriptor */

struct appl_send_address_descriptor
{
    struct appl_address *
        p_address;

#define PADDING (APPL_SIZEOF_PTR)
#include <appl_padding.h>

}; /* struct appl_send_address_descriptor */

/*

Parent is responsible for ref-count

*/
struct appl_send_packet
{
    void (* p_release)(
        void * p_release_context);

    void *
        p_release_context;

    /* -- */

    unsigned char *
        p_buf_min;

    unsigned char *
        p_buf_max;

    /* -- */

    unsigned long int
        i_duration_usec;

#define PADDING (APPL_SIZEOF_LONG)
#include <appl_padding.h>

}; /* struct appl_send_packet */

#include <appl_extern_c_begin.h>

enum appl_status
appl_send_socket_create(
    struct appl_context * const
        p_context,
    struct appl_send_socket * * const
        r_send_socket);

struct appl_object *
appl_send_socket_parent(
    struct appl_send_socket * const
        p_send_socket);

enum appl_status
appl_send_socket_add(
    struct appl_send_socket * const
        p_send_socket,
    struct appl_send_address_descriptor const * const
        p_send_address_descriptor,
    struct appl_send_address * * const
        r_send_address);

enum appl_status
appl_send_socket_remove(
    struct appl_send_socket * const
        p_send_socket,
    struct appl_send_address * const
        p_send_address);

enum appl_status
appl_send_socket_write(
    struct appl_send_socket * const
        p_send_socket,
    struct appl_send_packet * const
        p_send_packet);

/*

Notes:

    Manager has a list of nodes

        | lock mutex
        | for each node
        | | if write queue is not empty
        | | | if next packet is ready to send
        | | | | send (make sure non-blocking is set!)
        | | | | release the packet
        | | | else
        | | | | latch minimum sleep time
        | unlock mutex
        | sleep

*/

#include <appl_extern_c_end.h>

/* end-of-file: appl_send_handle.h */
