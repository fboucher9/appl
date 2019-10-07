/* See LICENSE for license details */

/*

*/

/* Included. */
#define INC_APPL_HEAP_PRIMARY_H

/* Reverse include guard */
enum guard_appl_heap_primary_h
{
    inc_appl_heap_primary_h = 1
        /* Header file dependency */
        + inc_appl_list_h
        + inc_appl_status_h
        + inc_appl_types_h
};

/* Assert compiler */
#include <misc/appl_assert_cplusplus.h>

union appl_heap_segment_ptr
{
    void *
        p_void;

    unsigned char *
        p_uchar;

    struct appl_list *
        p_list;

}; /* union appl_heap_segment_ptr */

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

        void
            f_grow(void);

}; // class appl_heap_primary

