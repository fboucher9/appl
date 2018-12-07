/* See LICENSE for license details */

/*

*/

#if defined APPL_OS_WINDOWS

#include <windows.h>

#include <time.h>

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <random/appl_random.h>

#include <random/appl_random_w32_crypto.h>

#include <appl_unused.h>

#include <appl_convert.h>

#include <appl_allocator_handle.h>

//
//
//
enum appl_status
appl_random_w32_crypto::s_create(
    struct appl_allocator * const
        p_allocator,
    struct appl_random * * const
        r_random)
{
    enum appl_status
        e_status;

    class appl_random_w32_crypto *
        p_random_w32_crypto;

    e_status =
        appl_new(
            p_allocator,
            &(
                p_random_w32_crypto));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_random) =
            p_random_w32_crypto;
    }

    return
        e_status;

} // s_create()

//
//
//
appl_random_w32_crypto::appl_random_w32_crypto(
    struct appl_context * const
        p_context) :
    appl_random(
        p_context)
{
}

//
//
//
appl_random_w32_crypto::~appl_random_w32_crypto()
{
}

//
//
//
appl_size_t
appl_random_w32_crypto::v_cleanup(void)
{
    return
        sizeof(class appl_random_w32_crypto);

} // v_cleanup()

//
//
//
enum appl_status
appl_random_w32_crypto::v_pick(
    unsigned long int const
        i_value_max,
    unsigned long int * const
        r_value)
{
    enum appl_status
        e_status;

    unsigned long int
        i_value;

    i_value =
        appl_convert::to_ulong(
            appl_convert::to_unsigned(
                time(NULL)));

    if (
        i_value_max)
    {
        *(
            r_value) =
            (
                i_value
                % i_value_max);
    }
    else
    {
        *(
            r_value) =
            i_value;
    }

    e_status =
        appl_status_ok;

    return
        e_status;

} // v_pick()

#endif /* #if defined APPL_OS_WINDOWS */

/* end-of-file: appl_random_w32_crypto.cpp */
