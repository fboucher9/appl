/* See LICENSE for license details */

/*

*/

#include <appl.h>

#include <log/appl_log_test.h>

#include <log/appl_log.h>

#include <appl_unused.h>

//
//
//
void
    appl_log_test_1(
        struct appl_context * const
            p_context)
{
    // normal operation
    {
        static unsigned char const s_msg[] =
        {
            'b',
            'y',
            'e'
        };

        enum appl_status
            e_status;

        e_status =
            appl_log_print(
                p_context,
                appl_log_level_info,
                s_msg,
                s_msg + sizeof(s_msg));

        appl_unused(
            e_status);
    }

    // base class
    {
        struct appl_log *
            p_log_base;

        enum appl_status
            e_status;

        e_status =
            appl_new(
                p_context,
                &(
                    p_log_base));

        if (
            appl_status_ok
            == e_status)
        {
            e_status =
                p_log_base->v_print(
                    appl_log_level_info,
                    0,
                    0);

            appl_delete(
                p_context,
                p_log_base);
        }

    }

} // appl_log_test_1()

/* end-of-file: appl_log_test.cpp */
