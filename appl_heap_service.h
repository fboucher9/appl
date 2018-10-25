/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_HEAP_SERVICE_H
#error include appl_heap_service.h once
#endif /* #if defined INC_APPL_HEAP_SERVICE_H */

#define INC_APPL_HEAP_SERVICE_H

struct appl_context;

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
                struct appl_context const * const
                    p_context,
                unsigned long int const
                    i_length,
                void * * const
                    r_buf);

        static
        enum appl_status
            s_free(
                struct appl_context const * const
                    p_context,
                unsigned long int const
                    i_length,
                void * const
                    p_buf);

}; // class appl_heap_service

/* end-of-file: appl_heap_service.h */
