/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_heap_dbg_h
{
    inc_appl_heap_dbg_h =
        /* Header file dependency */
        inc_appl_heap_h
        + inc_appl_list_h
};

/* Assert configuration */
#include <appl_assert_debug.h>

struct appl_heap_dbg_descriptor;

/* Assert compiler */
#include <appl_assert_cplusplus.h>

//
//
//
class appl_heap_dbg : public appl_heap
{
    public:

        static
        enum appl_status
            s_create(
                struct appl_heap * const
                    p_parent,
                class appl_heap_dbg * * const
                    r_heap_dbg);

        static
        enum appl_status
            s_destroy(
                struct appl_heap * const
                    p_parent,
                class appl_heap_dbg * const
                    p_heap_dbg);

        appl_heap_dbg(
            struct appl_context * const
                p_context);

        virtual
        ~appl_heap_dbg();

        enum appl_status
            f_init(
                struct appl_heap_dbg_descriptor const * const
                    p_descriptor);

    protected:

        // --

        struct appl_heap *
            m_parent;

        signed long int
            m_alloc_count;

#define PADDING (APPL_SIZEOF_PTR + APPL_SIZEOF_LONG)
#include <appl_padding.h>

        // --

        struct appl_list
            m_list;

        // --

        class appl_mutex_impl
            m_lock;

    private:

        appl_heap_dbg(
            class appl_heap_dbg const & r);

        class appl_heap_dbg &
            operator =(
                class appl_heap_dbg const & r);

        virtual
        appl_size_t
            v_cleanup(void);

        virtual
        enum appl_status
            v_alloc(
                appl_size_t const
                    i_buf_len,
                void * * const
                    r_buf);

        virtual
        enum appl_status
            v_free(
                appl_size_t const
                    i_buf_len,
                void * const
                    p_buf);

}; // class appl_heap_dbg

/* end-of-file: appl_heap_dbg.h */
