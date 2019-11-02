/* See LICENSE for license details */

/*

*/

#include <appl_predefines.h>

#include <unique/appl_unique_test.h>

#include <appl_status.h>

#include <unique/appl_unique_handle.h>

#include <test/appl_test.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <unique/appl_unique_mgr.h>

#include <heap/appl_heap_handle.h>

//
//
//
void
    appl_unique_test_1(
        struct appl_context * const
            p_context)
{
    unsigned long int
        i_unique;

    enum appl_status
        e_status;

    /* Basic unique handle sanity check */
    {
        e_status =
            appl_unique_pick(
                p_context,
                &(
                    i_unique));

        if (
            appl_status_ok
            == e_status)
        {
            appl_print_lu(
                i_unique);
            appl_print0(
                "\n");
        }
    }

    /* Coverage for unique_mgr */
    {
        class appl_unique_mgr *
            p_unique_mgr;

        e_status =
            appl_new(
                p_context,
                &(
                    p_unique_mgr));

        if (
            appl_status_ok
            == e_status)
        {
            e_status =
                p_unique_mgr->v_pick(
                    &(
                        i_unique));

            appl_delete(
                p_context,
                p_unique_mgr);
        }

    }

} // appl_unique_test_1()

/* end-of-file: appl_unique_test.cpp */
