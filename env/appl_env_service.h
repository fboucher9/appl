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

/* Assert compiler */
#include <misc/appl_assert_cplusplus.h>

//
//
//
class appl_env_service
{
    public:

        static
        enum appl_status
        s_get(
            struct appl_context * const
                p_context,
            unsigned char const * const
                p_name_min,
            unsigned char const * const
                p_name_max,
            struct appl_string * * const
                r_string);

        static
        enum appl_status
        s_query(
            struct appl_context * const
                p_context,
            unsigned char const * const
                p_name_min,
            unsigned char const * const
                p_name_max,
            void (* p_query_callback)(
                void * const
                    p_query_context,
                unsigned char const * const
                    p_value_min,
                unsigned char const * const
                    p_value_max),
            void * const
                p_query_context);

        static
        enum appl_status
        s_set(
            struct appl_context * const
                p_context,
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
