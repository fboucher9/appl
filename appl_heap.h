/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined(INC_APPL_HEAP_H)
#error include appl_heap.h once
#endif /* #if defined(INC_APPL_HEAP_H) */

#define INC_APPL_HEAP_H

struct appl_buf;

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
