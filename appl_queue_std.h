/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_QUEUE_STD_H
#error include appl_queue_std.h once
#endif /* #if defined INC_APPL_QUEUE_STD_H */

#define INC_APPL_QUEUE_STD_H

/* Header file dependency */
#if ! defined INC_APPL_QUEUE_H
#error include appl_queue.h before
#endif /* #if ! defined INC_APPL_QUEUE_H */

/* Header file dependency */
#if ! defined INC_APPL_QUEUE_IMPL_H
#error include appl_queue_impl.h before
#endif /* #if ! defined INC_APPL_QUEUE_IMPL_H */

/* Predefine */
struct appl_object;

/* Predefine */
struct appl_queue_descriptor;

/* Predefine */
struct appl_queue;

/* Assert compiler */
#if ! defined __cplusplus
#error use C++ compiler
#endif /* #if ! defined __cplusplus */

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

        appl_queue_std();

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
        enum appl_status
            v_cleanup(void);

}; // class appl_queue_std

/* end-of-file: appl_queue_std.h */
