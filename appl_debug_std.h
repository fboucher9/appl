/* See LICENSE for license details */

/*

*/

#if defined(INC_APPL_DEBUG_STD_H)
#error include appl_debug_std.h once
#endif /* #if defined(INC_APPL_DEBUG_STD_H) */

#define INC_APPL_DEBUG_STD_H

#if !defined(INC_APPL_DEBUG_H)
#error include appl_debug.h once
#endif /* #if !defined(INC_APPL_DEBUG_H) */

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
            create_instance(
                class appl_context * const
                    p_context,
                class appl_debug * * const
                    r_debug);

    protected:

        appl_debug_std();

        virtual
        ~appl_debug_std();

        virtual
        enum appl_status
            break_to_debugger(void);

    private:

        static
        void
            placement_new(
                void * const
                    p_placement);

        appl_debug_std(
            class appl_debug_std const & r);

        class appl_debug_std &
            operator =(
                class appl_debug_std const & r);

}; // class appl_debug_std

/* end-of-file: appl_debug_std.h */
