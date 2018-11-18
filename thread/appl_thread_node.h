/* See LICENSE for license details */

/*

Module: appl_thread_node.h

Description:

*/

/* Reverse include guard */
enum guard_appl_thread_node_h
{
    inc_appl_thread_node_h =
        /* Header file dependencies */
        inc_appl_object_h
};

struct appl_thread;

struct appl_thread_descriptor;

struct appl_context;

#if !defined(__cplusplus)
#error use C++ compiler
#endif /* #if !defined(__cplusplus) */

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
