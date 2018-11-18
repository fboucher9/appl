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
#if ! defined APPL_DEBUG
#error include only from debug build
#endif /* #if ! defined APPL_DEBUG */

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
    public:

        static
        enum appl_status
            create_instance(
                struct appl_heap * const
                    p_parent,
                struct appl_heap * * const
                    r_heap);

        appl_heap_dbg();

        virtual
        ~appl_heap_dbg();

        enum appl_status
            f_init(
                struct appl_heap_dbg_descriptor const * const
                    p_descriptor);

    protected:

        struct appl_heap *
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
