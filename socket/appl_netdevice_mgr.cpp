/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_predefines.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <socket/appl_netdevice_mgr.h>

#include <socket/appl_netdevice_handle.h>

#include <misc/appl_unused.h>

#include <buf/appl_buf.h>

//
//
//
appl_netdevice_mgr::appl_netdevice_mgr(
    struct appl_context * const
        p_context) :
    appl_object(
        p_context)
{
}

//
//
//
appl_netdevice_mgr::~appl_netdevice_mgr()
{
}

//
//
//
enum appl_status
    appl_netdevice_mgr::f_init(void)
{
    return
        appl_status_ok;

} // f_init()

//
//
//
appl_size_t
    appl_netdevice_mgr::v_cleanup(void)
{
    return
        sizeof(class appl_netdevice_mgr);

} // v_cleanup

//
//
//
enum appl_status
    appl_netdevice_mgr::v_enumerate(
        struct appl_netdevice_descriptor const * const
            p_netdevice_filter,
        void (* p_callback)(
            void * const
                p_callback_context,
            struct appl_netdevice_descriptor const * const
                p_netdevice_descriptor),
        void * p_callback_context)
{
    appl_unused(
        p_netdevice_filter,
        p_callback,
        p_callback_context);

    return
        appl_raise_not_implemented();

} // v_enumerate()

//
//
//
bool
    appl_netdevice_mgr::s_compare_filter(
        struct appl_netdevice_descriptor const * const
            p_netdevice_descriptor,
        struct appl_netdevice_descriptor const * const
            p_netdevice_filter)
{
    bool
        b_result;

    b_result =
        true;

    if (
        APPL_NETDEVICE_FLAGS_TYPE
        & p_netdevice_filter->i_flags)
    {
        if (
            APPL_NETDEVICE_FLAGS_TYPE
            & p_netdevice_descriptor->i_flags)
        {
            if (
                p_netdevice_filter->e_type
                != p_netdevice_descriptor->e_type)
            {
                b_result =
                    false;
            }
        }
        else
        {
            b_result =
                false;
        }
    }

    if (
        APPL_NETDEVICE_FLAGS_INDEX
        & p_netdevice_filter->i_flags)
    {
        if (
            APPL_NETDEVICE_FLAGS_INDEX
            & p_netdevice_descriptor->i_flags)
        {
            if (
                p_netdevice_filter->i_index
                != p_netdevice_descriptor->i_index)
            {
                b_result =
                    false;
            }
        }
        else
        {
            b_result =
                false;
        }
    }

    if (
        APPL_NETDEVICE_FLAGS_FAMILY
        & p_netdevice_filter->i_flags)
    {
        if (
            APPL_NETDEVICE_FLAGS_FAMILY
            & p_netdevice_descriptor->i_flags)
        {
            if (
                p_netdevice_filter->e_family
                != p_netdevice_descriptor->e_family)
            {
                b_result =
                    false;
            }
        }
        else
        {
            b_result =
                false;
        }
    }

    if (
        APPL_NETDEVICE_FLAGS_ADDRESS
        & p_netdevice_filter->i_flags)
    {
        if (
            APPL_NETDEVICE_FLAGS_ADDRESS
            & p_netdevice_descriptor->i_flags)
        {
            if (
                0
                == appl_buf_compare(
                    p_netdevice_filter->p_address_min,
                    p_netdevice_filter->p_address_max,
                    p_netdevice_descriptor->p_address_min,
                    p_netdevice_descriptor->p_address_max))
            {
            }
            else
            {
                b_result =
                    false;
            }
        }
        else
        {
            b_result =
                false;
        }
    }

    if (
        APPL_NETDEVICE_FLAGS_NAME
        & p_netdevice_filter->i_flags)
    {
        if (
            APPL_NETDEVICE_FLAGS_NAME
            & p_netdevice_descriptor->i_flags)
        {
            if (
                0
                == appl_buf_compare(
                    p_netdevice_filter->p_name_min,
                    p_netdevice_filter->p_name_max,
                    p_netdevice_descriptor->p_name_min,
                    p_netdevice_descriptor->p_name_max))
            {
            }
            else
            {
                b_result =
                    false;
            }
        }
        else
        {
            b_result =
                false;
        }
    }

    return
        b_result;

} // s_compare_filter()

/* end-of-file: appl_netdevice_mgr.cpp */
