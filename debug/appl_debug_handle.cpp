/* See LICENSE for license details */

/*

*/

#if defined APPL_DEBUG

#include <appl_status.h>

#include <appl_debug_handle.h>

#include <appl_types.h>

#include <appl_object.h>

#include <context/appl_context.h>

#include <debug/appl_debug.h>

#include <appl_buf.h>

#include <appl_buf0.h>

#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
class appl_debug_service
{
    public:

        static
        enum appl_status
        s_break(
            struct appl_context * const
                p_context);

        static
        enum appl_status
        s_print(
            struct appl_context * const
                p_context,
            unsigned char const * const
                p_msg_min,
            unsigned char const * const
                p_msg_max);

}; // class appl_debug_service

//
//
//
enum appl_status
    appl_debug_service::s_break(
        struct appl_context * const
            p_context)
{
    enum appl_status
        e_status;

    class appl_debug *
        p_debug;

    e_status =
        p_context->v_debug(
            &(
                p_debug));

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            p_debug->v_break();
    }

    return
        e_status;

} // s_break()

//
//
//
enum appl_status
    appl_debug_service::s_print(
        struct appl_context * const
            p_context,
        unsigned char const * const
            p_msg_min,
        unsigned char const * const
            p_msg_max)
{
    enum appl_status
        e_status;

    class appl_debug *
        p_debug;

    e_status =
        p_context->v_debug(
            &(
                p_debug));

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            p_debug->v_print(
                p_msg_min,
                p_msg_max);
    }

    return
        e_status;

} // s_print()

/*

*/
enum appl_status
appl_debug_break(
    struct appl_context * const
        p_context)
{
    enum appl_status
        e_status;

    e_status =
        appl_debug_service::s_break(
            p_context);

    return
        e_status;

} /* appl_debug_break() */

/*

*/
enum appl_status
appl_debug_print(
    struct appl_context * const
        p_context,
    unsigned char const * const
        p_msg_min,
    unsigned char const * const
        p_msg_max)
{
    enum appl_status
        e_status;

    e_status =
        appl_debug_service::s_print(
            p_context,
            p_msg_min,
            p_msg_max);

    return
        e_status;

} /* appl_debug_print() */

/*

*/
enum appl_status
appl_debug_print0(
    struct appl_context * const
        p_context,
    unsigned char const * const
        p_msg_0)
{
    return
        appl_debug_print(
            p_context,
            p_msg_0,
            p_msg_0 + appl_buf0_len(p_msg_0));

} /* appl_debug_print0() */

/*

*/
enum appl_status
appl_debug_print_number(
    struct appl_context * const
        p_context,
    signed long int const
        i_value,
    int const
        e_flags,
    unsigned int const
        i_width)
{
    unsigned char
        a_buf[80u];

    return
        appl_debug_print(
            p_context,
            a_buf,
            appl_buf_print_number(
                a_buf,
                a_buf + sizeof a_buf,
                i_value,
                e_flags,
                i_width));

} /* appl_debug_print_number() */

#endif /* #if defined APPL_DEBUG */

/* end-of-file: appl_debug_handle.cpp */
