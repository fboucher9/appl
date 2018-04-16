/* See LICENSE for license details */

/*

*/

#if defined APPL_DEBUG

#include "appl_status.h"

#include "appl_debug_handle.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_context.h"

#include "appl_debug.h"

#include "appl_object_handle.h"

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

    class appl_debug * const
        p_debug =
        p_context->m_debug;

    e_status =
        p_debug->v_break();

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

    class appl_debug * const
        p_debug =
        p_context->m_debug;

    e_status =
        p_debug->v_print(
            p_msg_min,
            p_msg_max);

    return
        e_status;

} // s_print()

/*

*/
enum appl_status
appl_debug_break(
    struct appl_object const * const
        p_object)
{
    enum appl_status
        e_status;

    struct appl_context * const
        p_context =
        appl_object_get_context(
            p_object);

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
    struct appl_object const * const
        p_object,
    unsigned char const * const
        p_msg_min,
    unsigned char const * const
        p_msg_max)
{
    enum appl_status
        e_status;

    struct appl_context * const
        p_context =
        appl_object_get_context(
            p_object);

    e_status =
        appl_debug_service::s_print(
            p_context,
            p_msg_min,
            p_msg_max);

    return
        e_status;

} /* appl_debug_print() */

#endif /* #if defined APPL_DEBUG */

/* end-of-file: appl_debug_handle.cpp */
