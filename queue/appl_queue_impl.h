/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_queue_impl_h
{
    inc_appl_queue_impl_h =
        /* Header file dependency */
        inc_appl_queue_handle_h
        + inc_appl_list_h
};

/* Predefine */
struct appl_context;

/* Predefine */
struct appl_mutex;

/* Predefine */
struct appl_event;

/* Assert compiler */
#if ! defined __cplusplus
#error use C++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
class appl_queue_impl
{
    public:

        appl_queue_impl();

        ~appl_queue_impl();

        enum appl_status
            f_init(
                struct appl_context * const
                    p_context,
                struct appl_queue_descriptor const * const
                    p_descriptor);

        enum appl_status
            f_cleanup(void);

        enum appl_status
            f_push(
                struct appl_list * const
                    p_node,
                unsigned long int const
                    i_wait_freq,
                unsigned long int const
                    i_wait_count);

        enum appl_status
            f_pop(
                struct appl_list * * const
                    r_node,
                unsigned long int const
                    i_wait_freq,
                unsigned long int const
                    i_wait_count);

        enum appl_status
            f_interrupt(void);

    protected:

    private:

        // --

        struct appl_mutex *
            m_lock;

        struct appl_event *
            m_event;

        // --

        struct appl_list
            m_list;

        // --

        struct appl_queue_descriptor
            m_descriptor;

        // --

        unsigned long int
            m_count;

#define PADDING (APPL_SIZEOF_LONG)
#include <appl_padding.h>

        // --

        appl_queue_impl(
            class appl_queue_impl const & r);

        class appl_queue_impl &
            operator =(
                class appl_queue_impl const & r);

}; // class appl_queue_impl

/* end-of-file: appl_queue_impl.h */
