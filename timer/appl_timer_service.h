/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_timer_service_h
{
    inc_appl_timer_service_h =
        /* Header file dependency */
        inc_appl_status_h
};

/* Predefine */
struct appl_context;

/* Predefine */
struct appl_timer;

/* Predefine */
struct appl_timer_descriptor;

/* Assert compiler */
#include <appl_assert_cplusplus.h>

//
//
//
class appl_timer_service
{
    public:

        static
        enum appl_status
        s_create_group(
            struct appl_context * const
                p_context,
            struct appl_timer_group * * const
                r_timer_group);

        static
        enum appl_status
        s_destroy_group(
            struct appl_context * const
                p_context,
            struct appl_timer_group * const
                p_timer_group);

        static
        struct appl_object *
        s_parent_group(
            struct appl_timer_group * const
                p_timer_group);

        static
        struct appl_object const *
        s_const_parent_group(
            struct appl_timer_group const * const
                p_timer_group);

        static
        enum appl_status
        s_create_node(
            struct appl_timer_group * const
                p_timer_group,
            struct appl_timer_node * * const
                r_timer_node);

        static
        enum appl_status
        s_destroy_node(
            struct appl_timer_group * const
                p_timer_group,
            struct appl_timer_node * const
                p_timer_node);

        static
        struct appl_object *
        s_parent_node(
            struct appl_timer_node * const
                p_timer_node);

        static
        struct appl_object const *
        s_const_parent_node(
            struct appl_timer_node const * const
                p_timer_node);

        static
        enum appl_status
        s_schedule_node(
            struct appl_timer_node * const
                p_timer_node,
            struct appl_timer_descriptor const * const
                p_timer_descriptor);

}; // class appl_timer_service

/* end-of-file: appl_timer_service.h */
