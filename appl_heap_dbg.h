/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined(INC_APPL_HEAP_DBG_H)
#error include appl_heap_dbg.h once
#endif /* #if defined(INC_APPL_HEAP_DBG_H) */

#define INC_APPL_HEAP_DBG_H

/* Assert configuration */
#if ! defined APPL_DEBUG
#error include only from debug build
#endif /* #if ! defined APPL_DEBUG */

/* Header file dependency */
#if ! defined INC_APPL_HEAP_H
#error include appl_heap.h before
#endif /* #if ! defined INC_APPL_HEAP_H */

/* Header file dependency */
#if ! defined INC_APPL_LIST_H
#error include appl_list.h before
#endif /* #if ! defined INC_APPL_LIST_H */

struct appl_heap_dbg_descriptor;

/* Assert compiler */
#if !defined(__cplusplus)
#error use c++ compiler
#endif /* #if !defined(__cplusplus) */

class appl_heap_dbg;

//
//
//
class appl_heap_dbg : public appl_heap
{
    friend struct appl_object;

    public:

        static
        enum appl_status
            create_instance(
                class appl_heap * const
                    p_parent,
                class appl_heap * * const
                    r_heap);

    protected:

        appl_heap_dbg();

        virtual
        ~appl_heap_dbg();

        class appl_heap *
            m_parent;

        struct appl_list
            m_list;

        class appl_mutex_impl
            m_lock;

        signed long int
            m_alloc_count;

        unsigned long int
            ul_padding[1u];

    private:

        appl_heap_dbg(
            class appl_heap_dbg const & r);

        class appl_heap_dbg &
            operator =(
                class appl_heap_dbg const & r);

        static
        void
            s_new(
                void * const
                    p_placement);

        enum appl_status
            f_init(
                struct appl_heap_dbg_descriptor const * const
                    p_descriptor);

        virtual
        enum appl_status
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
