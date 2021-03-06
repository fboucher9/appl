/* See LICENSE for license details */

/*

*/

#include <stdio.h>

#include <appl_status.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <random/appl_random.h>

#include <random/appl_random_std_crypto.h>

#include <misc/appl_unused.h>

#include <allocator/appl_allocator_handle.h>

//
//
//
enum appl_status
appl_random_std_crypto::s_create(
    struct appl_allocator * const
        p_allocator,
    struct appl_random * * const
        r_random)
{
    enum appl_status
        e_status;

    class appl_random_std_crypto *
        p_random_std_crypto;

    e_status =
        appl_new(
            p_allocator,
            &(
                p_random_std_crypto));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_random) =
            p_random_std_crypto;
    }

    return
        e_status;

} // s_create()

//
//
//
#if 0
enum appl_status
appl_random_std_crypto::s_destroy(
    struct appl_allocator * const
        p_allocator,
    struct appl_random * const
        p_random)
{
    return
        appl_delete(
            p_allocator,
            p_random);

} // s_destroy()
#endif

//
//
//
appl_random_std_crypto::appl_random_std_crypto(
    struct appl_context * const
        p_context) :
    appl_random(
        p_context)
{
}

//
//
//
appl_random_std_crypto::~appl_random_std_crypto()
{
}

//
//
//
appl_size_t
appl_random_std_crypto::v_cleanup(void)
{
    return
        sizeof(class appl_random_std_crypto);

} // v_cleanup()

//
//
//
enum appl_status
appl_random_std_crypto::v_pick(
    unsigned long int const
        i_value_max,
    unsigned long int * const
        r_value)
{
    enum appl_status
        e_status;

    FILE *
        fp;

    fp =
        fopen(
            "/dev/urandom",
            "rb");

    if (
        fp)
    {
        appl_size_t
            i_read_result;

        unsigned char
            a_data[4u];

        i_read_result =
            fread(
                a_data,
                4u,
                1u,
                fp);

        if (
            1 == i_read_result)
        {
            unsigned long int
                i_value;

            i_value =
                (
                    ((a_data[0u] & 0xFFu) << 0u)
                    | ((a_data[1u] & 0xFFu) << 8u)
                    | ((a_data[2u] & 0xFFu) << 16u)
                    | ((a_data[3u] & 0xFFu) << 24u));

            if (
                i_value_max)
            {
                *(
                    r_value) =
                    i_value % i_value_max;
            }
            else
            {
                *(
                    r_value) =
                    i_value;
            }

            e_status =
                appl_status_ok;
        }
        else
        {
            e_status =
                appl_status_fail;
        }

        fclose(
            fp);
    }
    else
    {
        e_status =
            appl_status_fail;
    }

    return
        e_status;

} // v_pick()

/* end-of-file: appl_random_std_crypto.cpp */
