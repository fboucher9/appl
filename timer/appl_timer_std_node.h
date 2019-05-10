/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_timer_std_node_h
{
    inc_appl_timer_std_node_h =
        /* Header file dependency */
        inc_appl_timer_node_h
};

/* Predefine */
struct appl_timer_descriptor;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
class appl_timer_std_node : public appl_timer_node
{
    friend class appl_timer_std_group;

    public:

        static
        enum appl_status
            s_create(
                struct appl_allocator * const
                    p_allocator,
                class appl_timer_std_group * const
                    p_timer_std_group,
                struct appl_timer_node * * const
                    r_timer_node);

        static
        enum appl_status
            s_destroy(
                struct appl_allocator * const
                    p_allocator,
                struct appl_timer_node * const
                    p_timer_node);

        appl_timer_std_node(
            struct appl_context * const
                p_context);

        virtual
        ~appl_timer_std_node();

        enum appl_status
            f_init(void);

    protected:

    private:

        class appl_timer_std_group *
            m_timer_group;

        appl_timer_std_node(
            class appl_timer_std_node const & r);

        class appl_timer_std_node &
            operator =(
                class appl_timer_std_node const & r);

        virtual
        appl_size_t
            v_cleanup(void);

        virtual
        enum appl_status
            v_schedule(
                struct appl_timer_descriptor const * const
                    p_timer_descriptor);

}; // class appl_timer_std_node

/* end-of-file: appl_timer_std_node.h */
