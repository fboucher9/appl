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
#include <misc/appl_assert_cplusplus.h>

//
//
//
struct appl_allocator : public appl_object
{
    public:

        appl_allocator(
            struct appl_context * const
                p_context);

        virtual
        ~appl_allocator();

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

    private:

        appl_allocator(
            struct appl_allocator const & r);

        struct appl_allocator &
            operator =(
                struct appl_allocator const & r);

}; // struct appl_allocator

/* end-of-file: appl_allocator.h */
