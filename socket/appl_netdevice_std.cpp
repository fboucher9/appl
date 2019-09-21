/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_predefines.h>

#include <appl_netdevice_handle.h>

#if defined APPL_OS_LINUX

#include <appl_types.h>

#include <appl_object.h>

#include <socket/appl_netdevice_mgr.h>

#include <socket/appl_netdevice_std.h>

#include <appl_unused.h>

#include <appl_convert.h>

#include <appl_buf0.h>

#include <appl_address_family.h>

#include <sys/types.h>

#include <ifaddrs.h>

#include <net/if.h>

#include <netdb.h>

//
//
//
appl_netdevice_std::appl_netdevice_std(
    struct appl_context * const
        p_context) :
    appl_netdevice_mgr(
        p_context)
{
}

//
//
//
appl_netdevice_std::~appl_netdevice_std()
{
}

//
//
//
enum appl_status
    appl_netdevice_std::f_init(void)
{
    return
        appl_status_ok;

} // f_init()

//
//
//
appl_size_t
    appl_netdevice_std::v_cleanup(void)
{
    return
        sizeof(class appl_netdevice_std);

} // v_cleanup()

//
//
//
static
enum appl_status
fill_netdevice_descriptor_type(
    struct ifaddrs const * const
        p_ifaddrs_iterator,
    struct appl_netdevice_descriptor * const
        p_netdevice_descriptor)
{
    enum appl_status
        e_status;

    if (
        IFF_LOOPBACK
        & p_ifaddrs_iterator->ifa_flags)
    {
        p_netdevice_descriptor->e_type =
            appl_netdevice_type_loopback;

        p_netdevice_descriptor->i_flags |=
            APPL_NETDEVICE_FLAGS_TYPE;

        e_status =
            appl_status_ok;
    }
    else
    {
        p_netdevice_descriptor->e_type =
            appl_netdevice_type_normal;

        p_netdevice_descriptor->i_flags |=
            APPL_NETDEVICE_FLAGS_TYPE;

        e_status =
            appl_status_ok;
    }

    return
        e_status;

} // fill_netdevice_descriptor_type()

//
//
//
static
enum appl_status
fill_netdevice_descriptor_index(
    struct ifaddrs const * const
        p_ifaddrs_iterator,
    struct appl_netdevice_descriptor * const
        p_netdevice_descriptor)
{
    enum appl_status
        e_status;

    unsigned int
        i_index;

    i_index =
        if_nametoindex(
            p_ifaddrs_iterator->ifa_name);

    if (
        0u
        != i_index)
    {
        p_netdevice_descriptor->i_index =
            i_index;

        p_netdevice_descriptor->i_flags |=
            APPL_NETDEVICE_FLAGS_INDEX;

        e_status =
            appl_status_ok;
    }
    else
    {
        e_status =
            appl_status_fail;
    }

    return
        e_status;
}

//
//
//
static
enum appl_status
fill_netdevice_descriptor_name(
    struct ifaddrs const * const
        p_ifaddrs_iterator,
    struct appl_netdevice_descriptor * const
        p_netdevice_descriptor)
{
    p_netdevice_descriptor->p_name_min =
        appl_convert::to_uchar_ptr(
            p_ifaddrs_iterator->ifa_name);

    p_netdevice_descriptor->p_name_max =
        p_netdevice_descriptor->p_name_min
        + appl_buf0_len(
            p_netdevice_descriptor->p_name_min);

    p_netdevice_descriptor->i_flags |=
        APPL_NETDEVICE_FLAGS_NAME;

    return
        appl_status_ok;

} // fill_netdevice_descriptor_name()

static
enum appl_status
fill_netdevice_descriptor_family(
    struct ifaddrs const * const
        p_ifaddrs_iterator,
    struct appl_netdevice_descriptor * const
        p_netdevice_descriptor)
{
    enum appl_status
        e_status;

    struct sockaddr * const
        p_sockaddr =
        p_ifaddrs_iterator->ifa_addr;

    if (
        AF_INET == p_sockaddr->sa_family)
    {
        p_netdevice_descriptor->e_family =
            appl_address_family_inet;

        p_netdevice_descriptor->i_flags |=
            APPL_NETDEVICE_FLAGS_FAMILY;

        e_status =
            appl_status_ok;
    }
    else if (
        AF_INET6 == p_sockaddr->sa_family)
    {
        p_netdevice_descriptor->e_family =
            appl_address_family_inet6;

        p_netdevice_descriptor->i_flags |=
            APPL_NETDEVICE_FLAGS_FAMILY;

        e_status =
            appl_status_ok;
    }
    else
    {
        e_status =
            appl_status_fail;
    }

    return
        e_status;

}

//
//
//
static
enum appl_status
fill_netdevice_descriptor_address(
    struct ifaddrs const * const
        p_ifaddrs_iterator,
    struct appl_netdevice_descriptor * const
        p_netdevice_descriptor,
    unsigned char * const
        a_address,
    appl_size_t const
        i_address_length)
{
    enum appl_status
        e_status;

    struct sockaddr * const
        p_sockaddr =
        p_ifaddrs_iterator->ifa_addr;

    socklen_t
        i_sockaddr_len;

    if (
        AF_INET == p_sockaddr->sa_family)
    {
        i_sockaddr_len =
            sizeof(
                struct sockaddr_in);
    }
    else if (
        AF_INET6 == p_sockaddr->sa_family)
    {
        i_sockaddr_len =
            sizeof(
                struct sockaddr_in6);
    }
    else
    {
        i_sockaddr_len =
            0;
    }

    if (
        i_sockaddr_len)
    {
        int
            i_nameinfo_result;

        i_nameinfo_result =
            getnameinfo(
                p_sockaddr,
                i_sockaddr_len,
                appl_convert::to_char_ptr(
                    a_address),
                i_address_length,
                0,
                0,
                NI_NUMERICHOST);

        if (
            0
            == i_nameinfo_result)
        {
            p_netdevice_descriptor->p_address_min =
                a_address;

            p_netdevice_descriptor->p_address_max =
                a_address
                + appl_buf0_len(
                    a_address);

            p_netdevice_descriptor->i_flags |=
                APPL_NETDEVICE_FLAGS_ADDRESS;

            e_status =
                appl_status_ok;
        }
        else
        {
            e_status =
                appl_status_fail;
        }
    }
    else
    {
        e_status =
            appl_status_fail;
    }

    return
        e_status;

} // fill_netdevice_descriptor_address()

//
//
//
static
enum appl_status
fill_netdevice_descriptor(
    struct ifaddrs const * const
        p_ifaddrs_iterator,
    struct appl_netdevice_descriptor * const
        p_netdevice_descriptor,
    unsigned char * const
        a_address,
    appl_size_t const
        i_address_length)
{
    enum appl_status
        e_status;

    p_netdevice_descriptor->i_flags =
        0u;

    e_status =
        fill_netdevice_descriptor_type(
            p_ifaddrs_iterator,
            p_netdevice_descriptor);

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            fill_netdevice_descriptor_index(
                p_ifaddrs_iterator,
                p_netdevice_descriptor);

        if (
            appl_status_ok
            == e_status)
        {
            e_status =
                fill_netdevice_descriptor_name(
                    p_ifaddrs_iterator,
                    p_netdevice_descriptor);

            if (
                appl_status_ok
                == e_status)
            {
                e_status =
                    fill_netdevice_descriptor_family(
                        p_ifaddrs_iterator,
                        p_netdevice_descriptor);

                if (
                    appl_status_ok
                    == e_status)
                {
                    e_status =
                        fill_netdevice_descriptor_address(
                            p_ifaddrs_iterator,
                            p_netdevice_descriptor,
                            a_address,
                            i_address_length);
                }
            }
        }
    }

    return
        e_status;

} // fill_netdevice_descriptor()

//
//
//
enum appl_status
    appl_netdevice_std::v_enumerate(
        struct appl_netdevice_descriptor const * const
            p_netdevice_filter,
        void (* p_callback)(
            void * const
                p_callback_context,
            struct appl_netdevice_descriptor const * const
                p_netdevice_descriptor),
        void * p_callback_context)
{
    enum appl_status
        e_status;

    struct ifaddrs *
        p_ifaddrs_list;

    struct ifaddrs *
        p_ifaddrs_iterator;

    int
        i_ifaddrs_result;

    appl_unused(
        p_netdevice_filter);

    i_ifaddrs_result =
        getifaddrs(
            &(
                p_ifaddrs_list));

    if (
        0
        == i_ifaddrs_result)
    {
        p_ifaddrs_iterator =
            p_ifaddrs_list;

        while (
            p_ifaddrs_iterator)
        {
            if (
                (
                    (
                        IFF_UP
                        | IFF_RUNNING)
                    == (
                        p_ifaddrs_iterator->ifa_flags
                        & (
                            IFF_UP
                            | IFF_RUNNING)))
                && p_ifaddrs_iterator->ifa_addr)
            {
                struct appl_netdevice_descriptor
                    o_descriptor;

                unsigned char
                    a_address[64u];

                if (
                    appl_status_ok
                    == fill_netdevice_descriptor(
                        p_ifaddrs_iterator,
                        &(
                            o_descriptor),
                        a_address,
                        sizeof(
                            a_address)))
                {
                    // do filter...
                    if (
                        appl_netdevice_mgr::s_compare_filter(
                            &(
                                o_descriptor),
                            p_netdevice_filter))
                    {
                        (*p_callback)(
                            p_callback_context,
                            &(
                                o_descriptor));
                    }
                }
            }

            p_ifaddrs_iterator =
                p_ifaddrs_iterator->ifa_next;
        }

        e_status =
            appl_status_ok;

        freeifaddrs(
            p_ifaddrs_list);
    }
    else
    {
        e_status =
            appl_status_fail;
    }

    return
        e_status;

} // v_enumerate()

#endif /* #if defined APPL_OS_LINUX */

/* end-of-file: appl_netdevice_std.h */
