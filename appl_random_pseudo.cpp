/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_random.h>

#include <appl_random_pseudo.h>

#include <appl_unused.h>

//
//
//
enum appl_status
appl_random_pseudo::s_create(
    struct appl_context * const
        p_context,
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
        appl_object::s_create(
            p_context,
            (&
                appl_random_pseudo::s_new),
            (&
                appl_random_pseudo::init),
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
appl_random_pseudo::appl_random_pseudo() :
    appl_random(),
    m_seed()
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
void
appl_random_pseudo::s_new(
    void * const
        p_placement)
{
    new (p_placement)
        class appl_random_pseudo;

} // s_new()

//
//
//
enum appl_status
appl_random_pseudo::init(
    unsigned long int const * const
        p_seed)
{
    m_seed =
        *(
            p_seed);

    return
        appl_status_ok;

} // init()

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
    appl_unused(
        i_value_max,
        r_value);

    return
        appl_status_not_implemented;

} // v_pick()

/* end-of-file: appl_random_pseudo.cpp */
