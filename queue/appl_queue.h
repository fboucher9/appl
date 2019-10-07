/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_queue_h
{
    inc_appl_queue_h = 1
        /* Header file dependency */
        + inc_appl_object_h
};

/* Assert compiler */
#include <misc/appl_assert_cplusplus.h>

//
//
//
struct appl_queue : public appl_object
{
    public:

        appl_queue(
            struct appl_context * const
                p_context);

        virtual
        ~appl_queue();

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

    protected:

    private:

        appl_queue(
            struct appl_queue const & r);

        struct appl_queue &
            operator =(
                struct appl_queue const & r);

}; // struct appl_queue

/* end-of-file: appl_queue.h */
