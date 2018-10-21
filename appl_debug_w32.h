/* See LICENSE for license details */

/*

*/

#if defined(INC_APPL_DEBUG_W32_H)
#error include appl_debug_w32.h once
#endif /* #if defined(INC_APPL_DEBUG_W32_H) */

#define INC_APPL_DEBUG_W32_H

/* Header file dependency */
#if !defined(INC_APPL_DEBUG_H)
#error include appl_debug.h once
#endif /* #if !defined(INC_APPL_DEBUG_H) */

/* Assert configuration */
#if ! defined APPL_DEBUG
#error include only for debug
#endif /* #if ! defined APPL_DEBUG */

/* Assert operating system */
#if ! defined APPL_OS_WINDOWS
#error include only for windows
#endif /* #if ! defined APPL_OS_WINDOWS */

/* Assert compiler */
#if !defined(__cplusplus)
#error use C++ compiler
#endif /* #if defined(__cplusplus) */

class appl_debug_w32;

//
//
//
class appl_debug_w32 : public appl_debug
{
    friend struct appl_object;

    public:

        static
        enum appl_status
            s_create(
                struct appl_heap * const
                    p_heap,
                class appl_debug * * const
                    r_debug);

    protected:

        appl_debug_w32();

        virtual
        ~appl_debug_w32();

        virtual
        enum appl_status
            v_break(void);

        virtual
        enum appl_status
            v_print(
                unsigned char const * const
                    p_msg_min,
                unsigned char const * const
                    p_msg_max);

    private:

        static
        void
            s_new(
                void * const
                    p_placement);

        appl_debug_w32(
            class appl_debug_w32 const & r);

        class appl_debug_w32 &
            operator =(
                class appl_debug_w32 const & r);

}; // class appl_debug_w32

/* end-of-file: appl_debug_w32.h */
