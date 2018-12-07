/* See LICENSE for license details */

/*

Module: appl_allocator_placement.h

Description:

    Allocator for placement of object at fixed address.

Comments:

    -   Use this class from a parent, to initialize objects into pre-allocated
        memory.  The following code shows how to initialize a appl_demo_child
        object into a buffer that is statically allocated by appl_demo_parent
        object:

            class appl_demo_child : appl_object { ...  };

            class appl_demo_parent : appl_object {
                public:
                    appl_demo_parent() :
                        m_allocator(m_buffer),
                        m_child() { }
                    enum appl_status f_init(void) {
                        return m_allocator.alloc_object(
                            &(m_child));
                    }
                    virtual enum appl_status v_cleanup(void) {
                        m_child->v_destroy();
                        return appl_status_ok;
                    }
                private:
                    unsigned char m_buffer[
                            sizeof(class appl_demo_child)];
                    class appl_allocator_placement m_allocator;
                    class appl_demo_child * m_child;
            };

*/

/* Included. */
#define INC_APPL_ALLOCATOR_PLACEMENT_H

/* Reverse include guard */
enum guard_appl_allocator_placement_h
{
    inc_appl_allocator_placement_h = 1
        /* Header file dependency */
        + inc_appl_allocator_h
        + inc_appl_types_h
};

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
class appl_allocator_placement : public appl_allocator
{
    public:

        appl_allocator_placement(
            struct appl_context * const
                p_context,
            void * const
                p_placement);

        virtual
        ~appl_allocator_placement();

    protected:

    private:

        void *
            m_placement;

#define PADDING (APPL_SIZEOF_PTR)
#include <appl_padding.h>

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

        appl_allocator_placement(
            class appl_allocator_placement const & r);

        class appl_allocator_placement &
            operator =(
                class appl_allocator_placement const & r);

}; // class appl_allocator_placement

/* end-of-file: appl_allocator_placement.h */
