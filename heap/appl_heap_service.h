/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_heap_service_h
{
    inc_appl_heap_service_h =
        /* Header file dependency */
        inc_appl_types_h
};

/* Assert compiler */
#include <appl_assert_cplusplus.h>

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
                appl_size_t const
                    i_length,
                void * * const
                    r_buf);

        static
        enum appl_status
            s_free(
                struct appl_context const * const
                    p_context,
                appl_size_t const
                    i_length,
                void * const
                    p_buf);

}; // class appl_heap_service

/* end-of-file: appl_heap_service.h */
