/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_heap_locked_h
{
    inc_appl_heap_locked_h = 1
        /* Header file dependencies */
        | inc_appl_heap_h
        /* ... */
}; /* enum guard_appl_heap_locked_h */

/*

*/
struct appl_heap_locked_descriptor
{
    struct appl_allocator *
        p_parent;

#define PADDING (APPL_SIZEOF_PTR)
#include <misc/appl_padding.h>

}; /* struct appl_heap_locked_descriptor */

#include <misc/appl_assert_cplusplus.h>

//
//
//
class appl_heap_locked : public appl_heap
{
    public:

        appl_heap_locked(
            struct appl_context * const
                p_context);

        virtual
        ~appl_heap_locked();

        enum appl_status
            f_init(
                struct appl_heap_locked_descriptor const * const
                    p_descriptor);

    protected:

    private:

        // --

        struct appl_heap_locked_descriptor
            m_descriptor;

        // --

        struct appl_mutex *
            m_lock;

#define PADDING (APPL_SIZEOF_PTR)
#include <misc/appl_padding.h>

        // --

        appl_heap_locked(
            class appl_heap_locked const & r);

        class appl_heap_locked &
            operator =(
                class appl_heap_locked const & r);

        virtual
        appl_size_t
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

}; // class appl_heap_locked

/* end-of-file: appl_heap_locked.h */
