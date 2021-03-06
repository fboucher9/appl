/* See LICENSE for license details */

/*

Module: appl_thread_std_node.h

Description:

*/

/* Reverse include guard */
enum guard_appl_thread_std_node_h
{
    inc_appl_thread_std_node_h =
        /* Header file dependencies */
        inc_appl_thread_node_h
        + inc_appl_thread_impl_h
};

#include <misc/appl_assert_cplusplus.h>

/* Predefine */
struct appl_thread_std_node_descriptor;

//
//
//
class appl_thread_std_node : public appl_thread
{
    public:

        static
        enum appl_status
            s_create(
                struct appl_allocator * const
                    p_allocator,
                struct appl_thread_descriptor const * const
                    p_thread_descriptor,
                struct appl_thread * * const
                    r_thread);

        static
        enum appl_status
            s_destroy(
                struct appl_allocator * const
                    p_allocator,
                struct appl_thread * const
                    p_thread);

        appl_thread_std_node(
            struct appl_context * const
                p_context);

        virtual
        ~appl_thread_std_node();

        enum appl_status
            f_init(
                struct appl_thread_std_node_descriptor const * const
                    p_thread_std_node_descriptor);

    protected:

        virtual
        enum appl_status
            v_interrupt(void);

    private:

        // --

        class appl_thread_impl
            m_thread_impl;

        // --

        appl_thread_std_node(
            class appl_thread_std_node const & r);

        class appl_thread_std_node &
            operator =(
                class appl_thread_std_node const & r);

        virtual
        appl_size_t
            v_cleanup(void);

}; // class appl_thread_std_node

/* end-of-file: appl_thread_std_node.h */
