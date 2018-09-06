/* See LICENSE for license details */

/*

*/

struct appl_context;

struct appl_pool;

//
//
//
class appl_pool_service
{
    public:

        static
        enum appl_status
            s_create(
                struct appl_context * const
                    p_context,
                unsigned long int const
                    i_length,
                struct appl_pool * * const
                    r_pool);

        static
        struct appl_object *
            s_parent(
                struct appl_pool * const
                    p_pool);

        static
        struct appl_object const *
            s_const_parent(
                struct appl_pool const * const
                    p_pool);

        static
        enum appl_status
            s_alloc(
                struct appl_pool * const
                    p_pool,
                void * * const
                    r_buffer);

        static
        enum appl_status
            s_free(
                struct appl_pool * const
                    p_pool,
                void * const
                    p_buffer);

}; // class appl_pool_service

/* end-of-file: appl_pool_service.h */
