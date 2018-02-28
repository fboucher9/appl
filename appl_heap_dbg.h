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

#if defined APPL_DEBUG

/* Header file dependency */
#if ! defined INC_APPL_LIST_H
#error include appl_list.h before
#endif /* #if ! defined INC_APPL_LIST_H */

#endif /* #if defined APPL_DEBUG */

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

        pthread_mutex_t
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
            placement_new(
                void * const
                    p_placement);

        virtual
        enum appl_status
            destroy(void);

        virtual
        enum appl_status
            init(
                void const * const
                    p_descriptor);

        virtual
        enum appl_status
            cleanup(void);

        virtual
        enum appl_status
            v_alloc(
                struct appl_buf * const
                    p_buf,
                appl_size_t const
                    i_buf_len);

        virtual
        enum appl_status
            v_free(
                struct appl_buf * const
                    p_buf);

        virtual
        enum appl_status
            v_realloc(
                struct appl_buf * const
                    p_buf,
                appl_size_t const
                    i_buf_len);

}; // class appl_heap_dbg

/* end-of-file: appl_heap_dbg.h */
