/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_allocator_service_h
{
    inc_appl_allocator_service_h =
        /* Header file dependency */
        inc_appl_status_h
        + inc_appl_types_h
};

/* Predefine */
struct appl_object;

/* Predefine */
struct appl_allocator;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

// Predefine
class appl_allocator_service;

//
//
//
class appl_allocator_service
{
    public:

        static
        struct appl_object *
            s_parent(
                struct appl_allocator * const
                    p_allocator);

        static
        enum appl_status
            s_alloc(
                struct appl_allocator * const
                    p_allocator,
                appl_size_t const
                    i_buf_len,
                void * * const
                    r_buf);

        static
        enum appl_status
            s_free(
                struct appl_allocator * const
                    p_allocator,
                appl_size_t const
                    i_buf_len,
                void * const
                    p_buf);

}; // class appl_allocator_service

/* end-of-file: appl_allocator_service.h */
