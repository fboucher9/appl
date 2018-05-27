/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_random_mgr.h>

#include <appl_random_std_mgr.h>

#include <appl_unused.h>

//
//
//
enum appl_status
appl_random_std_mgr::s_create(
    struct appl_context * const
        p_context,
    class appl_random_mgr * * const
        r_random_mgr)
{
    enum appl_status
        e_status;

    class appl_random_std_mgr *
        p_random_std_mgr;

    e_status =
        appl_object::s_create(
            p_context,
            (&
                appl_random_std_mgr::s_new),
            (&
                appl_random_std_mgr::init),
            &(
                p_random_std_mgr));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_random_mgr) =
            p_random_std_mgr;
    }

    return
        e_status;

} // s_create()

//
//
//
appl_random_std_mgr::appl_random_std_mgr() :
    appl_random_mgr()
{
}

//
//
//
appl_random_std_mgr::~appl_random_std_mgr()
{
}

//
//
//
void
    appl_random_std_mgr::s_new(
        void * const
            p_placement)
{
    new (p_placement)
        class appl_random_std_mgr;

} // s_new()

//
//
//
enum appl_status
    appl_random_std_mgr::init(void)
{
    return
        appl_status_ok;

} // init()

//
//
//
enum appl_status
appl_random_std_mgr::v_generate_seed(
    unsigned long int * const
        r_seed)
{
    appl_unused(
        r_seed);
    return
        appl_status_not_implemented;
} // v_generate_seed()

//
//
//
enum appl_status
appl_random_std_mgr::v_create_node(
    unsigned long int const
        i_seed,
    struct appl_random * * const
        r_node)
{
    appl_unused(
        i_seed,
        r_node);
    return
        appl_status_not_implemented;
} // v_create_node()

/* end-of-file: appl_random_std_mgr.cpp */
