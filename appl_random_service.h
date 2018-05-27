/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_RANDOM_SERVICE_H
#error include appl_random_service.h once
#endif /* #if defined INC_APPL_RANDOM_SERVICE_H */

#define INC_APPL_RANDOM_SERVICE_H

struct appl_context;

struct appl_object;

struct appl_random;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
class appl_random_service
{
    public:

        static
        enum appl_status
        s_generate_seed(
            struct appl_context * const
                p_context,
            unsigned long int * const
                r_seed);

        static
        enum appl_status
        s_create(
            struct appl_context * const
                p_context,
            unsigned long int const
                i_seed,
            struct appl_random * * const
                r_random);

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
