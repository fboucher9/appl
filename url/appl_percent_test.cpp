/* See LICENSE for license details */

/*

*/

#include <url/appl_percent_test.h>

#include <appl_status.h>

#include <appl_options_handle.h>

#include <url/appl_percent_main.h>

#include <url/appl_percent.h>

#include <appl_buf.h>

#include <appl_buf0.h>

//
//
//
class appl_percent_test_service
{
    public:

        static
        enum appl_status
            s_main(
                struct appl_context * const
                    p_context,
                char const * const
                    p_args0);

}; // class appl_percent_test_service

//
//
//
enum appl_status
    appl_percent_test_service::s_main(
        struct appl_context * const
            p_context,
        char const * const
            p_args0)
{
    enum appl_status
        e_status;

    struct appl_options *
        p_options;

    e_status =
        appl_options_create(
            p_context,
            &(
                p_options));

    if (
        appl_status_ok
        == e_status)
    {
        union appl_buf_ptr
            o_args0;

        unsigned long int
            i_count;

        char
            b_ready;

        o_args0.pc_char =
            p_args0;

        e_status =
            appl_options_write(
                p_options,
                o_args0.pc_uchar,
                o_args0.pc_uchar + appl_buf0_len(o_args0.pc_uchar),
                &(
                    i_count),
                &(
                    b_ready));

        if (
            appl_status_ok
            == e_status)
        {
            e_status =
                appl_percent_main(
                    p_context,
                    p_options,
                    0u);
        }

        appl_options_destroy(
            p_options);
    }

    return
        e_status;

} // s_main()

//
//
//
void
appl_percent_test_1(
    struct appl_context * const
        p_context)
{
    appl_percent_test_service::s_main(
        p_context,
        "test_percent dec a%21%2a%2A%gg\n");

    appl_percent_test_service::s_main(
        p_context,
        "test_percent enc a!\n");

} // appl_percent_test_1()

/* end-of-file: appl_percent_test.cpp */
