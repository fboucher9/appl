/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_event_std_node_h
{
    inc_appl_event_std_node_h =
        /* Header file dependencies */
        inc_appl_event_node_h
};

struct appl_event_descriptor;

struct appl_context;

struct appl_event;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

class appl_event_std_node;

//
//
//
class appl_event_std_node : public appl_event
{
    public:

        static
        enum appl_status
            s_create(
                struct appl_allocator * const
                    p_allocator,
                struct appl_event_descriptor const * const
                    p_event_descriptor,
                struct appl_event * * const
                    r_event);

        static
        enum appl_status
            s_destroy(
                struct appl_allocator * const
                    p_allocator,
                struct appl_event * const
                    p_event);

        appl_event_std_node(
            struct appl_context * const
                p_context);

        virtual
        ~appl_event_std_node();

        enum appl_status
            f_init(
                struct appl_event_descriptor const * const
                    p_event_descriptor);

    protected:

    private:

        class appl_event_impl
            m_event_impl;

        // --

        bool
            m_event_impl_initialized;

#define PADDING (1)
#include <appl_padding.h>

        // --

        appl_event_std_node(
            class appl_event_std_node const & r);

        class appl_event_std_node &
            operator =(
                class appl_event_std_node const & r);

        virtual
        appl_size_t
            v_cleanup(void);

        virtual
        enum appl_status
            v_signal(void);

        virtual
        enum appl_status
            v_wait(
                struct appl_mutex * const
                    p_mutex,
                unsigned long int const
                    i_wait_freq,
                unsigned long int const
                    i_wait_count);

}; // class appl_event_std_node

/* end-of-file: appl_event_std_node.h */
