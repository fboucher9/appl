/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined(INC_APPL_HEAP_STD_H)
#error include appl_heap_std.h once
#endif /* #if defined(INC_APPL_HEAP_STD_H) */

#define INC_APPL_HEAP_STD_H

/* Header file dependency */
#if ! defined INC_APPL_HEAP_H
#error include appl_heap.h before
#endif /* #if ! defined INC_APPL_HEAP_H */

/* Assert compiler */
#if !defined(__cplusplus)
#error use c++ compiler
#endif /* #if !defined(__cplusplus) */

class appl_heap_std;

//
//
//
class appl_heap_std : public appl_heap
{
    public:

        static
        enum appl_status
            create_instance(
                class appl_heap * * const
                    r_heap);

    protected:

        appl_heap_std();

        virtual
        ~appl_heap_std();

    private:

        appl_heap_std(
            class appl_heap_std const & r);

        class appl_heap_std &
            operator =(
                class appl_heap_std const & r);

        static
        void
            placement_new(
                void * const
                    p_placement);

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
                void * const
                    p_buf);

        virtual
        enum appl_status
            v_realloc(
                void * const
                    p_old_buf,
                appl_size_t const
                    i_buf_len,
                void * * const
                    r_new_buf);

}; // class appl_heap_std

/* end-of-file: appl_heap_std.h */
