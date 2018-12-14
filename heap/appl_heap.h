/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_heap_h
{
    inc_appl_heap_h =
        /* Header file dependency */
        inc_appl_allocator_h
};

/* Assert compiler */
#if !defined(__cplusplus)
#error use c++ compiler
#endif /* #if !defined(__cplusplus) */

// Predefine
struct appl_heap;

//
//
//
struct appl_heap : public appl_allocator
{
    public:

        appl_heap(
            struct appl_context * const
                p_context);

        virtual
        ~appl_heap();

    protected:

    private:

        appl_heap(
            struct appl_heap const & r);

        struct appl_heap &
            operator =(
                struct appl_heap const & r);

}; // struct appl_heap

/* end-of-file: appl_heap.h */
