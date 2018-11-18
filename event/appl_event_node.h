/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_event_node_h
{
    inc_appl_event_node_h =
        /* Header file dependencies */
        inc_appl_object_h
};

struct appl_event;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
struct appl_event : public appl_object
{
    public:

        virtual
        enum appl_status
            v_signal(void);

        virtual
        enum appl_status
            v_wait(
                struct appl_mutex * const
                    p_mutex_node,
                unsigned long int const
                    i_wait_freq,
                unsigned long int const
                    i_wait_count);

    protected:

        appl_event();

        virtual
        ~appl_event();

    private:

        appl_event(
            struct appl_event const & r);

        struct appl_event &
            operator =(
                struct appl_event const & r);

}; // struct appl_event

/* end-of-file: appl_event_node.h */
