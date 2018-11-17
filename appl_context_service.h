/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_CONTEXT_SERVICE_H
#error include appl_context_service.h once
#endif /* #if defined INC_APPL_CONTEXT_SERVICE_H */

#define INC_APPL_CONTEXT_SERVICE_H

/* Predefine */
struct appl_context;

/* Predefine */
struct appl_object;

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
        struct appl_object *
        s_parent(
            struct appl_context * const
                p_context);

        static
        struct appl_object const *
        s_const_parent(
            struct appl_context const * const
                p_context);

}; // class appl_context_service

/* end-of-file: appl_context_service.h */
