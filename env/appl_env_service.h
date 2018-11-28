/* See LICENSE for license details */

/*

*/

/* Included. */
#define INC_APPL_ENV_SERVICE_H

/* Reverse include guard */
enum guard_appl_env_service_h
{
    inc_appl_env_service_h =
        /* Header file dependencies */
        inc_appl_status_h
};

/* Predefine */
struct appl_context;

/* Predefine */
struct appl_string;

/* Predefine */
struct appl_env;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

class appl_env_service;

//
//
//
class appl_env_service
{
    public:

        static
        enum appl_status
        s_acquire(
            struct appl_context * const
                p_context,
            struct appl_env * * const
                r_instance);

        static
        struct appl_object *
        s_parent(
            struct appl_env * const
                p_env);

        static
        struct appl_object const *
        s_const_parent(
            struct appl_env const * const
                p_env);

        static
        enum appl_status
        s_get(
            struct appl_env const * const
                p_env,
            unsigned char const * const
                p_name_min,
            unsigned char const * const
                p_name_max,
            struct appl_string * * const
                r_string);

        static
        enum appl_status
        s_set(
            struct appl_env * const
                p_env,
            unsigned char const * const
                p_name_min,
            unsigned char const * const
                p_name_max,
            unsigned char const * const
                p_value_min,
            unsigned char const * const
                p_value_max);

}; // class appl_env_service

/* end-of-file: appl_env_service.h */
