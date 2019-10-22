/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_unique_service_h
{
    inc_appl_unique_service_h = 1
        /* Header file dependencies */
        | inc_appl_status_h
        | inc_appl_predefines_h
        /* ... */
}; /* enum guard_appl_unique_service_h */

#include <misc/appl_assert_cplusplus.h>

//
//
//
class appl_unique_service
{
    public:

        static
        enum appl_status
        s_create(
            struct appl_context * const
                p_context,
            struct appl_unique * * const
                r_unique);

        static
        enum appl_status
        s_destroy(
            struct appl_unique * const
                p_unique);

        static
        struct appl_object *
        s_parent(
            struct appl_unique * const
                p_unique);

        static
        struct appl_object const *
        s_const_parent(
            struct appl_unique const * const
                p_unique);

        static
        unsigned long int
        s_get(
            struct appl_unique const * const
                p_unique);

}; // class appl_unique_service

/* end-of-file: appl_unique_service.h */
