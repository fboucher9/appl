/* See LICENSE for license details */

/*

*/

enum guard_appl_debug_std_h
{
    inc_appl_debug_std_h =
        /* Header file dependencies */
        inc_appl_debug_h
};

#if !defined(__cplusplus)
#error use C++ compiler
#endif /* #if defined(__cplusplus) */

class appl_debug_std;

//
//
//
class appl_debug_std : public appl_debug
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

        appl_debug_std();

        virtual
        ~appl_debug_std();

    protected:

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

        appl_debug_std(
            class appl_debug_std const & r);

        class appl_debug_std &
            operator =(
                class appl_debug_std const & r);

        virtual
        appl_size_t
            v_cleanup(void);

}; // class appl_debug_std

/* end-of-file: appl_debug_std.h */
