/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_trace_std_mgr_h
{
    inc_appl_trace_std_mgr_h = 1
        /* Header file dependencies */
        | inc_appl_trace_mgr_h
        /* ... */
}; /* enum guard_appl_trace_std_mgr_h */

#include <misc/appl_assert_cplusplus.h>

//
//
//
class appl_trace_std_mgr : public appl_trace_mgr
{
    public:

        appl_trace_std_mgr(
            struct appl_context * const
                p_context);

        virtual
        ~appl_trace_std_mgr();

        enum appl_status
            f_init(void);

        virtual
        appl_size_t
            v_cleanup(void);

    protected:

    private:

        virtual
        enum appl_status
            v_message(
                struct appl_trace_message const * const
                    p_trace_message);

        appl_trace_std_mgr(
            class appl_trace_std_mgr const & r);

        class appl_trace_std_mgr &
            operator =(
                class appl_trace_std_mgr const & r);

}; // class appl_trace_std_mgr

/* end-of-file: appl_trace_std_mgr.h */
