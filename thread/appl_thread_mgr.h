/* See LICENSE for license details */

/*

Module: appl_thread_mgr.h

Description:

*/

enum guard_appl_thread_mgr_h
{
    inc_appl_thread_mgr_h =
        /* Header file dependencies */
        inc_appl_object_h
};

#if !defined(__cplusplus)
#error use c++ compiler
#endif /* #if !defined(__cplusplus) */

struct appl_context;

struct appl_thread;

struct appl_thread_property;

//
//
//
class appl_thread_mgr : public appl_object
{
    public:

        virtual
        enum appl_status
            v_create_node(
                struct appl_thread_property const * const
                    p_thread_property,
                struct appl_thread_descriptor const * const
                    p_thread_descriptor,
                struct appl_thread * * const
                    r_thread);

        virtual
        enum appl_status
            v_destroy_node(
                struct appl_thread * const
                    p_thread);

    protected:

        appl_thread_mgr();

        virtual
        ~appl_thread_mgr();

    private:

        appl_thread_mgr(
            class appl_thread_mgr const & r);

        class appl_thread_mgr &
            operator =(
                class appl_thread_mgr const & r);

}; // class appl_thread_mgr

/* end-of-file: appl_thread_mgr.h */
