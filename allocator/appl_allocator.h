/* See LICENSE for license details */

/*

*/

/* Included. */
#define INC_APPL_ALLOCATOR_H

/* Reverse include guard */
enum guard_appl_allocator_h
{
    inc_appl_allocator_h =
        /* Header file dependency */
        inc_appl_object_h
};

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

// Predefine
struct appl_allocator;

//
//
//
struct appl_allocator : public appl_object
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
            struct appl_allocator const & r);

        struct appl_allocator &
            operator =(
                struct appl_allocator const & r);

}; // struct appl_allocator

/* end-of-file: appl_allocator.h */
