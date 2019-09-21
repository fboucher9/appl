/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_timer_std_group_h
{
    inc_appl_timer_std_group_h =
        /* Header file dependency */
        inc_appl_timer_group_h
};

/* Predefine */
struct appl_allocator;

/* Predefine */
struct appl_timer_node;

/* Assert compiler */
#include <appl_assert_cplusplus.h>

// Predefine
class appl_timer_std_node;

//
//
//
class appl_timer_std_group : public appl_timer_group
{
    friend class appl_timer_std_node;

    public:

        static
        enum appl_status
            s_create(
                struct appl_allocator * const
                    p_allocator,
                struct appl_timer_group * * const
                    r_timer_group);

        static
        enum appl_status
            s_destroy(
                struct appl_allocator * const
                    p_allocator,
                struct appl_timer_group * const
                    p_timer_group);

        appl_timer_std_group(
            struct appl_context * const
                p_context);

        virtual
        ~appl_timer_std_group();

        enum appl_status
            f_init(void);

    protected:

    private:

        appl_timer_std_group(
            class appl_timer_std_group const & r);

        class appl_timer_std_group &
            operator =(
                class appl_timer_std_group const & r);

        virtual
        appl_size_t
            v_cleanup(void);

        virtual
        enum appl_status
            v_create_node(
                struct appl_timer_node * * const
                    r_timer_node);

        virtual
        enum appl_status
            v_destroy_node(
                struct appl_timer_node * const
                    p_timer_node);

}; // class appl_timer_std_group

/* end-of-file: appl_timer_std_group.h */

