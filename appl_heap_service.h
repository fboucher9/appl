/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_HEAP_SERVICE_H
#error include appl_heap_service.h once
#endif /* #if defined INC_APPL_HEAP_SERVICE_H */

#define INC_APPL_HEAP_SERVICE_H

struct appl_object_handle;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

class appl_heap_service;

//
//
//
class appl_heap_service
{
    public:

        static
        enum appl_status
            s_alloc(
                struct appl_object_handle const * const
                    p_object_handle,
                unsigned long int const
                    i_length,
                void * * const
                    r_buf);

        static
        enum appl_status
            s_free(
                struct appl_object_handle const * const
                    p_object_handle,
                void * const
                    p_buf);

        static
        enum appl_status
            s_realloc(
                struct appl_object_handle const * const
                    p_object_handle,
                void * const
                    p_old_buf,
                unsigned long int const
                    i_length,
                void * * const
                    r_new_buf);

}; // class appl_heap_service

/* end-of-file: appl_heap_service.h */
