/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_QUEUE_H
#error include appl_queue.h once
#endif /* #if defined INC_APPL_QUEUE_H */

#define INC_APPL_QUEUE_H

/* Header file dependency */
#if ! defined INC_APPL_OBJECT_H
#error include appl_object.h before
#endif /* #if ! defined INC_APPL_OBJECT_H */

/* ... */

struct appl_context;

struct appl_queue;

struct appl_list;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
struct appl_queue : public appl_object
{
    public:

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

        appl_queue();

        virtual
        ~appl_queue();

    private:

        appl_queue(
            struct appl_queue const & r);

        struct appl_queue &
            operator =(
                struct appl_queue const & r);

}; // struct appl_queue

/* end-of-file: appl_queue.h */
