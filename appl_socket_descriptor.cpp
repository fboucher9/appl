/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_socket_descriptor.h>

#include <appl_property_handle.h>

#include <appl_object_handle.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_property_types.h>

#include <appl_property.h>

#if defined APPL_DEBUG

#include <appl_debug_handle.h>

#endif /* #if defined APPL_DEBUG */

#include <appl_unused.h>

#include <appl_convert.h>

/* Unique identifier for appl_socket_property structure */
static unsigned long int const APPL_SOCKET_PROPERTY_GUID = 0x77ca3c76ul;

/* Socket option unique identifiers */
enum appl_socket_option_id
{
    /* First option is unique id of structure */
    appl_socket_option_id_guid = 0,

    /* Select 0 for TCP with SOCK_STREAM,
              1 for UDP with SOCK_DGRAM */
    /* Default is to select TCP type with SOCK_STREAM option */
    appl_socket_option_id_protocol = 1,

    /* Provide an address for call to bind() */
    /* Default is an unbound socket, kernel will select interface and port */
    appl_socket_option_id_bind_address = 2,

    /* Provide an address for call to connect() */
    appl_socket_option_id_connect_address = 3,

    /* Provide number for call to listen() */
    appl_socket_option_id_listen_count = 4,

    /* Set timeout for call to accept() */
    appl_socket_option_id_accept_timeout = 5,

    /* Set recv timeout socket option */
    appl_socket_option_id_recv_timeout = 6,

    /* Set send timeout socket option */
    appl_socket_option_id_send_timeout = 7,

    /* Provide an address for add membership */
    appl_socket_option_id_join_address = 8,

    /* Provide an interface for add membership */
    appl_socket_option_id_join_interface = 9,

    /* Provide recv buffer size option */
    appl_socket_option_id_recv_buffer = 10,

    /* Provide send buffer size option */
    appl_socket_option_id_send_buffer = 11,

    /* Set timeout for call to connect() */
    appl_socket_option_id_connect_timeout = 12,

    /* Maximum number of options */
    appl_socket_option_id_max

}; /* enum appl_socket_option_id */

union appl_address_ptr
{
    void *
        p_value;

    struct appl_address const *
        p_address;

};

struct appl_socket_property : public appl_property
{
};

union appl_socket_property_ptr
{
    struct appl_property *
        p_property;

    struct appl_socket_property *
        p_socket_property;

}; /* union appl_socket_property_ptr */

enum appl_status
appl_socket_property_create(
    struct appl_context * const
        p_context,
    struct appl_socket_property * * const
        r_socket_property)
{
    enum appl_status
        e_status;

    struct appl_property *
        p_property;

    e_status =
        appl_property_create(
            p_context,
            appl_socket_option_id_max,
            &(
                p_property));

    if (
        appl_status_ok
        == e_status)
    {
        appl_property_set_ulong(
            p_property,
            appl_socket_option_id_guid,
            APPL_SOCKET_PROPERTY_GUID);

        union appl_socket_property_ptr
            o_socket_property_ptr;

        o_socket_property_ptr.p_property =
            p_property;

        *(
            r_socket_property) =
            o_socket_property_ptr.p_socket_property;
    }

    return
        e_status;

} /* create() */

/*

*/
enum appl_status
appl_socket_property_destroy(
    struct appl_socket_property * const
        p_socket_property)
{
    return
        p_socket_property->v_destroy();

} /* destroy() */

/*

*/
struct appl_property *
appl_socket_property_parent(
    struct appl_socket_property * const
        p_socket_property)
{
    return
        p_socket_property;

} /* parent() */

/*

*/
struct appl_property const *
appl_socket_property_const_parent(
    struct appl_socket_property const * const
        p_socket_property)
{
    return
        p_socket_property;

} /* const_parent() */

#if defined APPL_DEBUG
static
void
appl_socket_property_assert_guid(
    struct appl_socket_property const * const
        p_socket_property)
{
    enum appl_status
        e_status;

    unsigned long int
        u_value;

    e_status =
        appl_property_get_ulong(
            p_socket_property,
            appl_socket_option_id_guid,
            &(
                u_value));

    if (
        (
            appl_status_ok
            == e_status)
        && (
            APPL_SOCKET_PROPERTY_GUID
            == u_value))
    {
    }
    else
    {
        /* break to debugger ... */
        appl_debug_break(
            appl_object_get_context(
                appl_socket_property_const_parent(
                    p_socket_property)));
    }
} /* assert_guid() */
#endif /* #if defined APPL_DEBUG */

enum appl_status
appl_socket_property_set_protocol(
    struct appl_socket_property * const
        p_socket_property,
    enum appl_socket_protocol const
        e_socket_protocol)
{
    enum appl_status
        e_status;

#if defined APPL_DEBUG
    appl_socket_property_assert_guid(
        p_socket_property);
#endif /* #if defined APPL_DEBUG */

    unsigned long int
        u_value;

    u_value =
        e_socket_protocol;

    e_status =
        appl_property_set_ulong(
            p_socket_property,
            appl_socket_option_id_protocol,
            u_value);

    return
        e_status;

} /* set_protocol() */

enum appl_status
appl_socket_property_set_bind_address(
    struct appl_socket_property * const
        p_socket_property,
    struct appl_address const * const
        p_bind_address)
{
    enum appl_status
        e_status;

#if defined APPL_DEBUG
    appl_socket_property_assert_guid(
        p_socket_property);
#endif /* #if defined APPL_DEBUG */

    union appl_address_ptr
        o_bind_address;

    o_bind_address.p_address =
        p_bind_address;

    e_status =
        appl_property_set_ptr(
            p_socket_property,
            appl_socket_option_id_bind_address,
            o_bind_address.p_value);

    return
        e_status;

} /* set_bind_address() */

enum appl_status
appl_socket_property_set_connect_address(
    struct appl_socket_property * const
        p_socket_property,
    struct appl_address const * const
        p_connect_address)
{
    enum appl_status
        e_status;

#if defined APPL_DEBUG
    appl_socket_property_assert_guid(
        p_socket_property);
#endif /* #if defined APPL_DEBUG */

    union appl_address_ptr
        o_connect_address;

    o_connect_address.p_address =
        p_connect_address;

    e_status =
        appl_property_set_ptr(
            p_socket_property,
            appl_socket_option_id_connect_address,
            o_connect_address.p_value);

    return
        e_status;

} /* set_connect_address() */

enum appl_status
appl_socket_property_set_listen_count(
    struct appl_socket_property * const
        p_socket_property,
    unsigned long int const
        i_listen_count)
{
    enum appl_status
        e_status;

#if defined APPL_DEBUG
    appl_socket_property_assert_guid(
        p_socket_property);
#endif /* #if defined APPL_DEBUG */

    e_status =
        appl_property_set_ulong(
            p_socket_property,
            appl_socket_option_id_listen_count,
            i_listen_count);

    return
        e_status;

} /* set_listen_count() */

enum appl_status
appl_socket_property_set_recv_timeout(
    struct appl_socket_property * const
        p_socket_property,
    unsigned long int const
        i_recv_timeout)
{
    enum appl_status
        e_status;

#if defined APPL_DEBUG
    appl_socket_property_assert_guid(
        p_socket_property);
#endif /* #if defined APPL_DEBUG */

    e_status =
        appl_property_set_ulong(
            p_socket_property,
            appl_socket_option_id_recv_timeout,
            i_recv_timeout);

    return
        e_status;

} /* set_recv_timeout() */

enum appl_status
appl_socket_property_set_send_timeout(
    struct appl_socket_property * const
        p_socket_property,
    unsigned long int const
        i_send_timeout)
{
    enum appl_status
        e_status;

#if defined APPL_DEBUG
    appl_socket_property_assert_guid(
        p_socket_property);
#endif /* #if defined APPL_DEBUG */

    e_status =
        appl_property_set_ulong(
            p_socket_property,
            appl_socket_option_id_send_timeout,
            i_send_timeout);

    return
        e_status;

} /* set_send_timeout() */

enum appl_status
appl_socket_property_set_recv_buffer(
    struct appl_socket_property * const
        p_socket_property,
    unsigned long int const
        i_recv_buffer)
{
    enum appl_status
        e_status;

#if defined APPL_DEBUG
    appl_socket_property_assert_guid(
        p_socket_property);
#endif /* #if defined APPL_DEBUG */

    e_status =
        appl_property_set_ulong(
            p_socket_property,
            appl_socket_option_id_recv_buffer,
            i_recv_buffer);

    return
        e_status;

} /* set_recv_buffer() */

enum appl_status
appl_socket_property_set_send_buffer(
    struct appl_socket_property * const
        p_socket_property,
    unsigned long int const
        i_send_buffer)
{
    enum appl_status
        e_status;

#if defined APPL_DEBUG
    appl_socket_property_assert_guid(
        p_socket_property);
#endif /* #if defined APPL_DEBUG */

    e_status =
        appl_property_set_ulong(
            p_socket_property,
            appl_socket_option_id_send_buffer,
            i_send_buffer);

    return
        e_status;

} /* set_send_buffer() */

enum appl_status
appl_socket_property_set_connect_timeout(
    struct appl_socket_property * const
        p_socket_property,
    unsigned long int const
        i_connect_timeout)
{
    enum appl_status
        e_status;

#if defined APPL_DEBUG
    appl_socket_property_assert_guid(
        p_socket_property);
#endif /* #if defined APPL_DEBUG */

    e_status =
        appl_property_set_ulong(
            p_socket_property,
            appl_socket_option_id_connect_timeout,
            i_connect_timeout);

    return
        e_status;

} /* set_connect_timeout() */

enum appl_status
appl_socket_property_set_accept_timeout(
    struct appl_socket_property * const
        p_socket_property,
    unsigned long int const
        i_accept_timeout)
{
    enum appl_status
        e_status;

#if defined APPL_DEBUG
    appl_socket_property_assert_guid(
        p_socket_property);
#endif /* #if defined APPL_DEBUG */

    e_status =
        appl_property_set_ulong(
            p_socket_property,
            appl_socket_option_id_accept_timeout,
            i_accept_timeout);

    return
        e_status;

} /* set_accept_timeout() */

enum appl_status
appl_socket_property_set_join_address(
    struct appl_socket_property * const
        p_socket_property,
    struct appl_address const * const
        p_join_address)
{
    enum appl_status
        e_status;

#if defined APPL_DEBUG
    appl_socket_property_assert_guid(
        p_socket_property);
#endif /* #if defined APPL_DEBUG */

    union appl_socket_ptr
    {
        void *
            p_value;

        struct appl_address const *
            p_address;

    } o_join_address;

    o_join_address.p_address =
        p_join_address;

    e_status =
        appl_property_set_ptr(
            p_socket_property,
            appl_socket_option_id_join_address,
            o_join_address.p_value);

    return
        e_status;

} /* set_join_address() */

enum appl_status
appl_socket_property_set_join_interface(
    struct appl_socket_property * const
        p_socket_property,
    struct appl_address const * const
        p_interface_address)
{
    enum appl_status
        e_status;

#if defined APPL_DEBUG
    appl_socket_property_assert_guid(
        p_socket_property);
#endif /* #if defined APPL_DEBUG */

    union appl_address_ptr
        o_interface_address;

    o_interface_address.p_address =
        p_interface_address;

    e_status =
        appl_property_set_ptr(
            p_socket_property,
            appl_socket_option_id_join_interface,
            o_interface_address.p_value);

    return
        e_status;

} /* set_join_interface() */

enum appl_status
appl_socket_property_get_protocol(
    struct appl_socket_property const * const
        p_socket_property,
    enum appl_socket_protocol * const
        r_socket_protocol)
{
    enum appl_status
        e_status;

    unsigned long int
        u_value;

#if defined APPL_DEBUG
    appl_socket_property_assert_guid(
        p_socket_property);
#endif /* #if defined APPL_DEBUG */

    e_status =
        appl_property_get_ulong(
            p_socket_property,
            appl_socket_option_id_protocol,
            &(
                u_value));

    if (
        appl_status_ok
        == e_status)
    {
        if (sizeof(enum appl_socket_protocol) == sizeof(unsigned int))
        {
            union appl_socket_protocol_int
            {
                enum appl_socket_protocol
                    e_socket_protocol;

                unsigned int
                    i_value;

            } o_socket_protocol;

            o_socket_protocol.i_value =
                appl_convert::to_uint(
                    u_value);

            *(
                r_socket_protocol) =
                o_socket_protocol.e_socket_protocol;
        }
        else
        {
            e_status =
                appl_status_fail;
        }
    }

    return
        e_status;

} /* get_protocol() */

enum appl_status
appl_socket_property_get_bind_address(
    struct appl_socket_property const * const
        p_socket_property,
    struct appl_address const * * const
        r_bind_address)
{
    enum appl_status
        e_status;

#if defined APPL_DEBUG
    appl_socket_property_assert_guid(
        p_socket_property);
#endif /* #if defined APPL_DEBUG */

    union appl_address_ptr
        o_bind_address;

    e_status =
        appl_property_get_ptr(
            p_socket_property,
            appl_socket_option_id_bind_address,
            &(
                o_bind_address.p_value));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_bind_address) =
            o_bind_address.p_address;
    }

    return
        e_status;

} /* get_bind_address() */

enum appl_status
appl_socket_property_get_connect_address(
    struct appl_socket_property const * const
        p_socket_property,
    struct appl_address const * * const
        r_connect_address)
{
    enum appl_status
        e_status;

#if defined APPL_DEBUG
    appl_socket_property_assert_guid(
        p_socket_property);
#endif /* #if defined APPL_DEBUG */

    union appl_address_ptr
        o_address_ptr;

    e_status =
        appl_property_get_ptr(
            p_socket_property,
            appl_socket_option_id_connect_address,
            &(
                o_address_ptr.p_value));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_connect_address) =
            o_address_ptr.p_address;
    }

    return
        e_status;

} /* get_connect_address() */

enum appl_status
appl_socket_property_get_listen_count(
    struct appl_socket_property const * const
        p_socket_property,
    unsigned long int * const
        r_listen_count)
{
    enum appl_status
        e_status;

#if defined APPL_DEBUG
    appl_socket_property_assert_guid(
        p_socket_property);
#endif /* #if defined APPL_DEBUG */

    e_status =
        appl_property_get_ulong(
            p_socket_property,
            appl_socket_option_id_listen_count,
            r_listen_count);

    return
        e_status;

} /* get_listen_count() */

enum appl_status
appl_socket_property_get_recv_timeout(
    struct appl_socket_property const * const
        p_socket_property,
    unsigned long int * const
        r_recv_timeout)
{
    enum appl_status
        e_status;

#if defined APPL_DEBUG
    appl_socket_property_assert_guid(
        p_socket_property);
#endif /* #if defined APPL_DEBUG */

    e_status =
        appl_property_get_ulong(
            p_socket_property,
            appl_socket_option_id_recv_timeout,
            r_recv_timeout);

    return
        e_status;

} /* get_recv_timeout() */

enum appl_status
appl_socket_property_get_send_timeout(
    struct appl_socket_property const * const
        p_socket_property,
    unsigned long int * const
        r_send_timeout)
{
    enum appl_status
        e_status;

#if defined APPL_DEBUG
    appl_socket_property_assert_guid(
        p_socket_property);
#endif /* #if defined APPL_DEBUG */

    e_status =
        appl_property_get_ulong(
            p_socket_property,
            appl_socket_option_id_send_timeout,
            r_send_timeout);

    return
        e_status;

} /* get_send_timeout() */

enum appl_status
appl_socket_property_get_recv_buffer(
    struct appl_socket_property const * const
        p_socket_property,
    unsigned long int * const
        r_recv_buffer)
{
    enum appl_status
        e_status;

#if defined APPL_DEBUG
    appl_socket_property_assert_guid(
        p_socket_property);
#endif /* #if defined APPL_DEBUG */

    appl_unused(
        p_socket_property,
        r_recv_buffer);

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} /* get_recv_buffer() */

enum appl_status
appl_socket_property_get_send_buffer(
    struct appl_socket_property const * const
        p_socket_property,
    unsigned long int * const
        r_send_buffer)
{
    enum appl_status
        e_status;

#if defined APPL_DEBUG
    appl_socket_property_assert_guid(
        p_socket_property);
#endif /* #if defined APPL_DEBUG */

    appl_unused(
        p_socket_property,
        r_send_buffer);

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} /* get_send_buffer() */

enum appl_status
appl_socket_property_get_connect_timeout(
    struct appl_socket_property const * const
        p_socket_property,
    unsigned long int * const
        r_connect_timeout)
{
    enum appl_status
        e_status;

#if defined APPL_DEBUG
    appl_socket_property_assert_guid(
        p_socket_property);
#endif /* #if defined APPL_DEBUG */

    e_status =
        appl_property_get_ulong(
            p_socket_property,
            appl_socket_option_id_connect_timeout,
            r_connect_timeout);

    return
        e_status;

} /* get_connect_timeout() */

enum appl_status
appl_socket_property_get_accept_timeout(
    struct appl_socket_property const * const
        p_socket_property,
    unsigned long int * const
        r_accept_timeout)
{
    enum appl_status
        e_status;

#if defined APPL_DEBUG
    appl_socket_property_assert_guid(
        p_socket_property);
#endif /* #if defined APPL_DEBUG */

    appl_unused(
        p_socket_property,
        r_accept_timeout);

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} /* get_accept_timeout() */

enum appl_status
appl_socket_property_get_join_address(
    struct appl_socket_property const * const
        p_socket_property,
    struct appl_address const * * const
        r_join_address)
{
    enum appl_status
        e_status;

#if defined APPL_DEBUG
    appl_socket_property_assert_guid(
        p_socket_property);
#endif /* #if defined APPL_DEBUG */

    appl_unused(
        p_socket_property,
        r_join_address);

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} /* get_join_address() */

enum appl_status
appl_socket_property_get_join_interface(
    struct appl_socket_property const * const
        p_socket_property,
    struct appl_address const * * const
        r_interface_address)
{
    enum appl_status
        e_status;

#if defined APPL_DEBUG
    appl_socket_property_assert_guid(
        p_socket_property);
#endif /* #if defined APPL_DEBUG */

    appl_unused(
        p_socket_property,
        r_interface_address);

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} /* get_join_interface() */

/* end-of-file: appl_socket_descriptor.cpp */
