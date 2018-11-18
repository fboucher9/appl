/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_POOL_SERVICE_H
#error include appl_pool_service.h once
#endif /* #if defined INC_APPL_POOL_SERVICE_H */

#define INC_APPL_POOL_SERVICE_H

/* Header file dependencies */
#if ! defined INC_APPL_STATUS_H
#error include appl_status.h before
#endif /* #if ! defined INC_APPL_STATUS_H */

/* Predefine */
struct appl_context;

/* Predefine */
struct appl_allocator;

/* Predefine */
struct appl_pool;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
class appl_pool_service
{
    public:

        //
        static
        enum appl_status
            s_create(
                struct appl_context * const
                    p_context,
                unsigned long int const
                    i_length,
                struct appl_pool * * const
                    r_pool);

        //
        static
        struct appl_allocator *
            s_parent(
                struct appl_pool * const
                    p_pool);

        //
        static
        struct appl_allocator const *
            s_const_parent(
                struct appl_pool const * const
                    p_pool);

        //
        static
        enum appl_status
            s_alloc(
                struct appl_pool * const
                    p_pool,
                void * * const
                    r_buffer);

        //
        static
        enum appl_status
            s_free(
                struct appl_pool * const
                    p_pool,
                void * const
                    p_buffer);

}; // class appl_pool_service

/* end-of-file: appl_pool_service.h */
