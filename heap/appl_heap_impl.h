/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_heap_impl_h
{
    inc_appl_heap_impl_h =
        /* Header file dependency */
        inc_appl_list_h
        + inc_appl_mutex_impl_h
};

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

#define APPL_HEAP_IMPL_COUNT (256u)

//
//
//
class appl_heap_primary
{
    public:

        appl_heap_primary();

        ~appl_heap_primary();

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

    protected:

    private:

        unsigned char *
            m_mmap_iterator;

        unsigned char *
            m_mmap_end;

        // --

        struct appl_list
            m_segments;

        // --

        appl_heap_primary(
            class appl_heap_primary const & r);

        class appl_heap_primary &
            operator =(
                class appl_heap_primary const & r);

}; // class appl_heap_primary

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

        class appl_mutex_impl
            m_lock;

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
