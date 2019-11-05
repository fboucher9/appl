/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_heap_impl_h
{
    inc_appl_heap_impl_h =
        /* Header file dependency */
        inc_appl_list_h
        | inc_appl_heap_primary_h
};

/* Assert compiler */
#include <misc/appl_assert_cplusplus.h>

#define APPL_HEAP_IMPL_COUNT (256u)

//
//
//
class appl_heap_impl
{
    public:

        appl_heap_impl();

        ~appl_heap_impl();

        enum appl_status
            f_init(
                unsigned char * const
                    p_mmap_begin,
                unsigned char * const
                    p_mmap_end);

        enum appl_status
            f_cleanup(void);

        enum appl_status
            f_alloc(
                appl_size_t const
                    i_len,
                void * * const
                    r_buf);

        enum appl_status
            f_free(
                appl_size_t const
                    i_len,
                void * const
                    p_buf);

    protected:

    private:

        class appl_heap_primary
            m_primary;

        // --

        struct appl_list
            m_free_small[APPL_HEAP_IMPL_COUNT];

        struct appl_list
            m_free_large;

        // --

        enum appl_status
            f_alloc_small(
                appl_size_t const
                    i_len,
                void * * const
                    r_buf);

        enum appl_status
            f_free_small(
                appl_size_t const
                    i_len,
                void * const
                    p_buf);

        enum appl_status
            f_alloc_large(
                appl_size_t const
                    i_len,
                void * * const
                    r_buf);

        enum appl_status
            f_free_large(
                appl_size_t const
                    i_len,
                void * const
                    p_buf);

        appl_heap_impl(
            class appl_heap_impl const & r);

        class appl_heap_impl *
            operator =(
                class appl_heap_impl const & r);

}; // class appl_heap_impl

/* end-of-file: appl_heap_impl.h */
