/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_queue_std_h
{
    inc_appl_queue_std_h =
        /* Header file dependency */
        inc_appl_queue_h
        + inc_appl_queue_impl_h
};

/* Assert compiler */
#include <misc/appl_assert_cplusplus.h>

//
//
//
class appl_queue_std : public appl_queue
{
    public:

        static
        enum appl_status
            s_create(
                struct appl_allocator * const
                    p_allocator,
                struct appl_queue_descriptor const * const
                    p_descriptor,
                struct appl_queue * * const
                    r_queue);

        static
        enum appl_status
            s_destroy(
                struct appl_allocator * const
                    p_allocator,
                struct appl_queue * const
                    p_queue);

        appl_queue_std(
            struct appl_context * const
                p_context);

        virtual
        ~appl_queue_std();

        enum appl_status
            f_init(
                struct appl_queue_descriptor const * const
                    p_descriptor);

    protected:

        // --

        class appl_queue_impl
            m_queue_impl;

        // --

    private:

        appl_queue_std(
            class appl_queue_std const & r);

        class appl_queue_std &
            operator =(
                class appl_queue_std const & r);

        virtual
        enum appl_status
            v_push(
                struct appl_list * const
                    p_node,
                unsigned long int const
                    i_wait_freq,
                unsigned long int const
                    i_wait_count);

        virtual
        enum appl_status
            v_pop(
                struct appl_list * * const
                    r_node,
                unsigned long int const
                    i_wait_freq,
                unsigned long int const
                    i_wait_count);

        virtual
        enum appl_status
            v_interrupt(void);

        virtual
        appl_size_t
            v_cleanup(void);

}; // class appl_queue_std

/* end-of-file: appl_queue_std.h */
