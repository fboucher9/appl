/* See LICENSE for license details */

/*

Module: appl_thread_node.h

Description:

*/

#if defined(INC_APPL_THREAD_NODE_H)
#error include appl_thread_node.h once
#endif /* #if defined(INC_APPL_THREAD_NODE_H) */

#define INC_APPL_THREAD_NODE_H

struct appl_thread;

struct appl_thread_descriptor;

struct appl_context;

#if !defined(__cplusplus)
#error use C++ compiler
#endif /* #if !defined(__cplusplus) */

#if !defined(INC_APPL_OBJECT_H)
#error include appl_object.h before
#endif /* #if !defined(INC_APPL_OBJECT_H) */

//
//
//
struct appl_thread : public appl_object
{
    public:

        virtual
        enum appl_status
            v_interrupt(void);

    protected:

        appl_thread();

        virtual
        ~appl_thread();

    private:

        appl_thread(
            struct appl_thread const & r);

        struct appl_thread &
            operator =(
                struct appl_thread const & r);

}; // struct appl_thread

/* end-of-file: appl_thread_node.h */
