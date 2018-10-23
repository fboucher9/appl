/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined(INC_APPL_ALLOCATOR_H)
#error include appl_heap.h once
#endif /* #if defined(INC_APPL_ALLOCATOR_H) */

#define INC_APPL_ALLOCATOR_H

/* Header file dependency */
#if ! defined INC_APPL_OBJECT_H
#error include appl_object.h before
#endif /* #if ! defined INC_APPL_OBJECT_H */

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

// Predefine
class appl_allocator;

//
//
//
class appl_allocator : public appl_object
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
                appl_size_t const
                    i_buf_len,
                void * const
                    p_buf);

    protected:

        appl_allocator();

        virtual
        ~appl_allocator();

    private:

        appl_allocator(
            class appl_allocator const & r);

        class appl_allocator &
            operator =(
                class appl_allocator const & r);

}; // class appl_allocator

/* end-of-file: appl_allocator.h */
