/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

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
                p_ifaddrs_iterator->ifa_flags
                & (
                    IFF_UP
                    | IFF_RUNNING))
            {
                struct appl_netdevice_descriptor
                    o_descriptor;

                o_descriptor.i_flags =
                    0u;

                if (
                    IFF_LOOPBACK
                    & p_ifaddrs_iterator->ifa_flags)
                {
                    o_descriptor.e_type =
                        appl_netdevice_type_loopback;

                    o_descriptor.i_flags |=
                        APPL_NETDEVICE_FLAGS_TYPE;
                }
                else
                {
                    o_descriptor.e_type =
                        appl_netdevice_type_normal;

                    o_descriptor.i_flags |=
                        APPL_NETDEVICE_FLAGS_TYPE;
                }

                o_descriptor.p_name_min =
                    appl_convert::to_uchar_ptr(
                        p_ifaddrs_iterator->ifa_name);

                o_descriptor.p_name_max =
                    o_descriptor.p_name_min
                    + appl_buf0_len(
                        o_descriptor.p_name_min);

                o_descriptor.i_flags |=
                    APPL_NETDEVICE_FLAGS_NAME;

                unsigned char
                    a_address[64u];

                if (
                    p_ifaddrs_iterator->ifa_addr)
                {
                    struct sockaddr *
                        p_sockaddr;

                    socklen_t
                        i_sockaddr_len;

                    p_sockaddr =
                        p_ifaddrs_iterator->ifa_addr;

                    if (
                        AF_INET == p_sockaddr->sa_family)
                    {
                        i_sockaddr_len =
                            sizeof(
                                struct sockaddr_in);

                        o_descriptor.e_family =
                            appl_address_family_inet;

                        o_descriptor.i_flags |=
                            APPL_NETDEVICE_FLAGS_FAMILY;
                    }
                    else if (
                        AF_INET6 == p_sockaddr->sa_family)
                    {
                        i_sockaddr_len =
                            sizeof(
                                struct sockaddr_in6);

                        o_descriptor.e_family =
                            appl_address_family_inet6;

                        o_descriptor.i_flags |=
                            APPL_NETDEVICE_FLAGS_FAMILY;
                    }
                    else
                    {
                        i_sockaddr_len =
                            sizeof(
                                struct sockaddr_storage);
                    }

                    int
                        i_nameinfo_result;

                    i_nameinfo_result =
                        getnameinfo(
                            p_sockaddr,
                            i_sockaddr_len,
                            appl_convert::to_char_ptr(
                                a_address),
                            sizeof(a_address),
                            0,
                            0,
                            NI_NUMERICHOST);

                    if (
                        0
                        == i_nameinfo_result)
                    {
                        o_descriptor.p_address_min =
                            a_address;

                        o_descriptor.p_address_max =
                            a_address
                            + appl_buf0_len(
                                a_address);

                        o_descriptor.i_flags |=
                            APPL_NETDEVICE_FLAGS_ADDRESS;
                    }
                }

                // do filter...

                (*p_callback)(
                    p_callback_context,
                    &(
                        o_descriptor));
            }

            p_ifaddrs_iterator =
                p_ifaddrs_iterator->ifa_next;
        }

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
