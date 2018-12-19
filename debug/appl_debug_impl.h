/* See LICENSE for license details */

/*

Module: appl_debug_impl.h

Description:

    OS-specific debugging functions to be used from implementation of
    appl_debug or from other appl modules.

*/

/* Included. */
#define INC_APPL_DEBUG_IMPL_H

/* Reverse include guard */
enum guard_appl_debug_impl_h
{
    inc_appl_debug_impl_h = 1
        /* Header file dependency */
};

/* Assert configuration */
#if ! defined APPL_DEBUG
#error include only from debug build
#endif /* #if ! defined APPL_DEBUG */

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//  Class: appl_debug_impl
//
//  Description:
//      Easy to use static functions to be used from appl module
//      implementations.
//
class appl_debug_impl
{
    public:

        static
        void
            s_break(void);

        static
        void
            s_print(
                unsigned char const * const
                    p_message_min,
                unsigned char const * const
                    p_message_max);

        static
        void
            s_print0(
                char const * const
                    p_message0);

        static
        void
            s_validate(
                bool const
                    b_condition,
                char const * const
                    p_message0);

}; // class appl_debug_impl

/* end-of-file: appl_debug_impl.h */
