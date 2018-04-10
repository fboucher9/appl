/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_ENV_SERVICE_H
#error include appl_env_service.h once
#endif /* #if defined INC_APPL_ENV_SERVICE_H */

#define INC_APPL_ENV_SERVICE_H

struct appl_object_handle;

struct appl_string_handle;

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
            struct appl_object_handle const * const
                p_object_handle,
            unsigned char const * const
                p_name_min,
            unsigned char const * const
                p_name_max,
            struct appl_string_handle * * const
                r_string_handle);

        static
        enum appl_status
        s_set(
            struct appl_object_handle const * const
                p_object_handle,
            unsigned char const * const
                p_name_min,
            unsigned char const * const
                p_name_max,
            unsigned char const * const
                p_value_min,
            unsigned char const * const
                p_value_max);

}; // class appl_env_service

