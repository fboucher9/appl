/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_random_service_h
{
    inc_appl_random_service_h = 1
        /* Header file dependencies */
        + inc_appl_status_h
        + inc_appl_predefines_h
};

/* Assert compiler */
#include <misc/appl_assert_cplusplus.h>

//
//
//
class appl_random_service
{
    public:

        static
        enum appl_status
        s_create(
            struct appl_context * const
                p_context,
            struct appl_random_descriptor const * const
                p_descriptor,
            struct appl_random * * const
                r_random);

        static
        enum appl_status
        s_destroy(
            struct appl_random * const
                p_random);

        static
        struct appl_object *
        s_parent(
            struct appl_random * const
                p_random);

        static
        struct appl_object const *
        s_const_parent(
            struct appl_random const * const
                p_random);

        static
        enum appl_status
        s_pick(
            struct appl_random * const
                p_random,
            unsigned long int const
                i_value_max,
            unsigned long int * const
                r_value);

}; // class appl_random_service

/* end-of-file: appl_random_service.h */
