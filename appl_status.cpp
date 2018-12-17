/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#if defined APPL_DEBUG
#include <debug/appl_debug_impl.h>
#endif /* #if defined APPL_DEBUG */

enum appl_status
    appl_raise(
        enum appl_status const
            e_input_status)
{
    enum appl_status
        e_output_status;

    if (
        appl_status_ok
        == e_input_status)
    {
        e_output_status =
            appl_status_ok;
    }
    else
    {
        if (
            appl_status_fail
            == e_input_status)
        {
            e_output_status =
                appl_raise_fail();
        }
        else if (
            appl_status_out_of_memory
            == e_input_status)
        {
            e_output_status =
                appl_raise_out_of_memory();
        }
        else if (
            appl_status_not_implemented
            == e_input_status)
        {
            e_output_status =
                appl_raise_not_implemented();
        }
        else if (
            appl_status_timeout
            == e_input_status)
        {
            e_output_status =
                appl_raise_timeout();
        }
        else if (
            appl_status_invalid_param
            == e_input_status)
        {
            e_output_status =
                appl_raise_invalid_param();
        }
        else if (
            appl_status_fault_injection
            == e_input_status)
        {
            e_output_status =
                appl_raise_fault_injection();
        }
        else
        {
            e_output_status =
                e_input_status;
        }
    }

    return
        e_output_status;
}

enum appl_status
    appl_raise_fail(void)
{
    return
        appl_status_fail;
}

enum appl_status
    appl_raise_out_of_memory(void)
{
    return
        appl_status_out_of_memory;
}

enum appl_status
    appl_raise_not_implemented(void)
{
#if defined APPL_DEBUG
    appl_debug_impl::s_print0(
        "not implemented\n");
#endif /* #if defined APPL_DEBUG */

    return
        appl_status_not_implemented;
}

enum appl_status
    appl_raise_timeout(void)
{
    return
        appl_status_timeout;
}

enum appl_status
    appl_raise_invalid_param(void)
{
#if defined APPL_DEBUG
    appl_debug_impl::s_print0(
        "invalid param\n");
#endif /* #if defined APPL_DEBUG */

    return
        appl_status_invalid_param;
}

enum appl_status
    appl_raise_fault_injection(void)
{
    return
        appl_status_fault_injection;
}

/* end-of-file: appl_status.cpp */
