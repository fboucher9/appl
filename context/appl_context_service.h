/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_context_service_h
{
    inc_appl_context_service_h =
        /* Header file dependencies */
        inc_appl_status_h
};

/* Predefine */
struct appl_context;

/* Predefine */
struct appl_object;

/* Predefine */
struct appl_allocator;

//
//
//
class appl_context_service
{
    public:

        static
        enum appl_status
        s_create(
            struct appl_context * * const
                r_context);

        static
        enum appl_status
        s_destroy(
            struct appl_context * const
                p_context);

        static
        struct appl_object *
        s_parent(
            struct appl_context * const
                p_context);

        static
        struct appl_object const *
        s_const_parent(
            struct appl_context const * const
                p_context);

        static
        struct appl_allocator *
        s_get_allocator(
            struct appl_context const * const
                p_context);

}; // class appl_context_service

/* end-of-file: appl_context_service.h */
