/* See LICENSE for license details */

/*

*/

/* Included. */
#define INC_APPL_BACKTRACE_NULL_H

/* Reverse include guard */
enum guard_appl_backtrace_null_h
{
    inc_appl_backtrace_null_h = 1
        /* Header file dependencies */
        + inc_appl_backtrace_h
};

//
//
//
class appl_backtrace_null : public appl_backtrace
{
    public:

        appl_backtrace_null(
            struct appl_context * const
                p_context);

        virtual
        ~appl_backtrace_null();

    protected:

    private:

        appl_backtrace_null(
            class appl_backtrace_null const & r);

        class appl_backtrace_null &
            operator =(
                class appl_backtrace_null const & r);

}; // appl_backtrace_null

/* end-of-file: appl_backtrace_null.h */
