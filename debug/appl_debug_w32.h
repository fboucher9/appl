/* See LICENSE for license details */

/*

*/

enum guard_appl_debug_w32_h
{
    inc_appl_debug_w32_h =
        /* Header file dependencies */
        inc_appl_debug_h
};

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
    public:

        static
        enum appl_status
            s_create(
                struct appl_allocator * const
                    p_allocator,
                class appl_debug * * const
                    r_debug);

        static
        enum appl_status
            s_destroy(
                struct appl_allocator * const
                    p_allocator,
                class appl_debug * const
                    p_debug);

        appl_debug_w32(
            struct appl_context * const
                p_context);

        virtual
        ~appl_debug_w32();

    protected:

        virtual
        appl_size_t
            v_cleanup(void);

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

        appl_debug_w32(
            class appl_debug_w32 const & r);

        class appl_debug_w32 &
            operator =(
                class appl_debug_w32 const & r);

}; // class appl_debug_w32

/* end-of-file: appl_debug_w32.h */
