/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_OBJECT_SERVICE_H
#error include appl_object_service.h once
#endif /* #if defined INC_APPL_OBJECT_SERVICE_H */

#define INC_APPL_OBJECT_SERVICE_H

/* Predefine */
struct appl_object;

/* Predefine */
struct appl_context;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
class appl_object_service
{
    public:

        static
        enum appl_status
        s_destroy(
            struct appl_object * const
                p_object);

        static
        struct appl_context *
        s_get_context(
            struct appl_object const * const
                p_object);

}; // class appl_object_service

/* end-of-file: appl_object_service.h */
