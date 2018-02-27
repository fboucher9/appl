/* See LICENSE for license details */

/*

*/

#if ! defined APPL_DEBUG
#error include only from debug build
#endif /* #if ! defined APPL_DEBUG */

#if defined(INC_APPL_DEBUG_H)
#error include appl_debug.h once
#endif /* #if defined(INC_APPL_DEBUG_H) */

#define INC_APPL_DEBUG_H

#if !defined(INC_APPL_OBJECT_H)
#error include appl_object.h before
#endif /* #if !defined(INC_APPL_OBJECT_H) */

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
                struct appl_buf const * const
                    p_buf);

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
