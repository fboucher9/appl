/* See LICENSE for license details */

/*

*/

#if defined APPL_OS_WINDOWS

#include <windows.h>

#include <time.h>

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_random.h>

#include <appl_random_w32_crypto.h>

#include <appl_unused.h>

//
//
//
enum appl_status
appl_random_w32_crypto::s_create(
    struct appl_context * const
        p_context,
    struct appl_random * * const
        r_random)
{
    enum appl_status
        e_status;

    class appl_random_w32_crypto *
        p_random_w32_crypto;

    e_status =
        appl_object::s_create(
            p_context,
            (&
                appl_random_w32_crypto::s_new),
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
appl_random_w32_crypto::appl_random_w32_crypto() :
    appl_random()
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
void
    appl_random_w32_crypto::s_new(
        void * const
            p_placement)
{
    new (p_placement)
        class appl_random_w32_crypto;

} // s_new()

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

    appl_unused(
        i_value_max,
        r_value);

    unsigned long int
        i_value;

    i_value =
        static_cast<unsigned long int>(
            time(NULL));

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
