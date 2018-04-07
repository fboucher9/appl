/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined(INC_APPL_HEAP_H)
#error include appl_heap.h once
#endif /* #if defined(INC_APPL_HEAP_H) */

#define INC_APPL_HEAP_H

/* Header file dependency */
#if ! defined INC_APPL_OBJECT_H
#error include appl_object.h before appl_heap.h
#endif /* #if ! defined INC_APPL_OBJECT_H */

/* Assert compiler */
#if !defined(__cplusplus)
#error use c++ compiler
#endif /* #if !defined(__cplusplus) */

class appl_heap;

//
//
//
class appl_heap : public appl_object
{
    public:

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

    protected:

        appl_heap();

        virtual
        ~appl_heap();

    private:

        appl_heap(
            class appl_heap const & r);

        class appl_heap &
            operator =(
                class appl_heap const & r);

}; // class appl_heap;

/* end-of-file: appl_heap.h */
