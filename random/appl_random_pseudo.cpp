/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <random/appl_random.h>

#include <random/appl_random_pseudo.h>

#include <misc/appl_unused.h>

#include <appl_allocator_handle.h>

//
//
//
enum appl_status
appl_random_pseudo::s_create(
    struct appl_allocator * const
        p_allocator,
    unsigned long int const
        i_seed,
    struct appl_random * * const
        r_random)
{
    enum appl_status
        e_status;

    class appl_random_pseudo *
        p_random_pseudo;

    e_status =
        appl_new(
            p_allocator,
            &(
                i_seed),
            &(
                p_random_pseudo));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_random) =
            p_random_pseudo;
    }

    return
        e_status;

} // s_create()

//
//
//
enum appl_status
appl_random_pseudo::s_destroy(
    struct appl_allocator * const
        p_allocator,
    struct appl_random * const
        p_random)
{
    enum appl_status
        e_status;

    e_status =
        appl_delete(
            p_allocator,
            p_random);

    return
        e_status;

} // s_destroy()

//
//
//
appl_random_pseudo::appl_random_pseudo(
    struct appl_context * const
        p_context) :
    appl_random(
        p_context),
    m_seed(1)
{
}

//
//
//
appl_random_pseudo::~appl_random_pseudo()
{
}

//
//
//
enum appl_status
appl_random_pseudo::f_init(
    unsigned long int const * const
        p_seed)
{
    m_seed =
        *(
            p_seed);

    return
        appl_status_ok;

} // f_init()

//
//
//
appl_size_t
appl_random_pseudo::v_cleanup(void)
{
    return
        sizeof(class appl_random_pseudo);

} // v_cleanup()

//
//
//
enum appl_status
appl_random_pseudo::v_pick(
    unsigned long int const
        i_value_max,
    unsigned long int * const
        r_value)
{
    enum appl_status
        e_status;

    unsigned long int
        i_value;

    m_seed =
        (
            (
                m_seed
                * 1103515245ul)
            + 12345ul);

    i_value =
        ((m_seed >> 18u) & 0x000003FFul);

    m_seed =
        (
            (
                m_seed
                * 1103515245ul)
            + 12345ul);

    i_value |=
        ((m_seed >> 8u) & 0x000FFC00ul);

    m_seed =
        (
            (
                m_seed
                * 1103515245ul)
            + 12345ul);

    i_value |=
        ((m_seed << 2u) & 0xFFF00000ul);

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

/* end-of-file: appl_random_pseudo.cpp */
