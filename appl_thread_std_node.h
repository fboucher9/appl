/* See LICENSE for license details */

/*

Module: appl_thread_std_node.h

Description:

*/

/* Reverse include guard */
#if defined(INC_APPL_THREAD_STD_NODE_H)
#error include appl_thread_std_node.h once
#endif /* #if defined(INC_APPL_THREAD_STD_NODE_H) */

#define INC_APPL_THREAD_STD_NODE_H

struct appl_context;

struct appl_thread_property;

#if !defined(__cplusplus)
#error use C++ compiler
#endif /* #if !defined(__cplusplus) */

/* Header file dependency */
#if !defined(INC_APPL_THREAD_NODE_H)
#error include appl_thread_node.h before
#endif /* #if !defined(INC_APPL_THREAD_NODE_H) */

/* Header file dependency */
#if ! defined INC_APPL_THREAD_IMPL_H
#error include appl_thread_impl.h before
#endif /* #if ! defined INC_APPL_THREAD_IMPL_H */

/* Predefine */
class appl_thread_std_node;

//
//
//
class appl_thread_std_node : public appl_thread
{
    // friend struct appl_pool;

    public:

        static
        enum appl_status
            s_create(
                struct appl_pool * const
                    p_pool,
                struct appl_thread_property const * const
                    p_thread_property,
                struct appl_thread * * const
                    r_thread);

        appl_thread_std_node();

        virtual
        ~appl_thread_std_node();

        enum appl_status
            f_init(
                struct appl_thread_property const * const
                    p_thread_property);

    protected:

        virtual
        enum appl_status
            v_start(
                struct appl_thread_descriptor const * const
                    p_thread_descriptor);

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
        enum appl_status
            v_cleanup(void);

}; // class appl_thread_std_node

/* end-of-file: appl_thread_std_node.h */
