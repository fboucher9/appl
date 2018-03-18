/* See LICENSE for license details */

/*

Module: appl_thread_mgr.h

Description:

*/

#if defined(INC_APPL_THREAD_MGR_H)
#error include appl_thread_mgr.h once
#endif

#define INC_APPL_THREAD_MGR_H

#if !defined(__cplusplus)
#error use c++ compiler
#endif /* #if !defined(__cplusplus) */

#if !defined(INC_APPL_OBJECT_H)
#error include appl_object.h before
#endif /* #if !defined(INC_APPL_OBJECT_H) */

class appl_context;

class appl_thread_node;

struct appl_thread_descriptor;

//
//
//
class appl_thread_mgr : public appl_object
{
    public:

        virtual
        enum appl_status
            v_create(
                class appl_context * const
                    p_context,
                struct appl_thread_descriptor const * const
                    p_thread_descriptor,
                class appl_thread_node * * const
                    r_thread_node);

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
