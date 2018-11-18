/* See LICENSE for license details */

/*

*/

#if ! defined APPL_DEBUG
#error include only from debug build
#endif /* #if ! defined APPL_DEBUG */

enum guard_appl_debug_h
{
    inc_appl_debug_h =
        /* Header file dependencies */
        inc_appl_object_h
};

#if !defined(__cplusplus)
#error use C++ compiler
#endif /* #if !defined(__cplusplus) */

class appl_debug;

//
//
//
class appl_debug : public appl_object
{
    public:

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

    protected:

        appl_debug();

        virtual
        ~appl_debug();

    private:

        appl_debug(
            class appl_debug const & r);

        class appl_debug &
            operator =(
                class appl_debug const & r);

}; // class appl_debug

/* end-of-file: appl_debug.h */
