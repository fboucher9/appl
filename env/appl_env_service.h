/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_env_service_h
{
    inc_appl_env_service_h =
        /* Header file dependencies */
        inc_appl_status_h
};

struct appl_object;

struct appl_string;

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
        s_get(
            struct appl_object const * const
                p_object,
            unsigned char const * const
                p_name_min,
            unsigned char const * const
                p_name_max,
            struct appl_string * * const
                r_string);

        static
        enum appl_status
        s_set(
            struct appl_object const * const
                p_object,
            unsigned char const * const
                p_name_min,
            unsigned char const * const
                p_name_max,
            unsigned char const * const
                p_value_min,
            unsigned char const * const
                p_value_max);

}; // class appl_env_service

