/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_pool_service_h
{
    inc_appl_pool_service_h = 1
        /* Header file dependencies */
        + inc_appl_status_h
        + inc_appl_predefines_h
};

/* Assert compiler */
#include <misc/appl_assert_cplusplus.h>

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
                struct appl_pool_descriptor const * const
                    p_pool_descriptor,
                struct appl_pool * * const
                    r_pool);

        //
        static
        enum appl_status
            s_destroy(
                struct appl_pool * const
                    p_pool);

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
