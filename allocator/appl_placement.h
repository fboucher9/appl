/* See LICENSE for license details */

/*

Module: appl_placement.h

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
                        m_allocator(),
                        m_child() { }
                    enum appl_status f_init(void) {
                        struct appl_placement_descriptor o_descriptor;
                        o_descriptor.p_placement = m_buffer;
                        m_allocator.f_init(m_buffer);
                        return m_allocator.alloc_object(
                            &(m_child));
                    }
                    virtual enum appl_status v_cleanup(void) {
                        m_child->v_destroy();
                        m_allocator.v_cleanup();
                        return appl_status_ok;
                    }
                private:
                    unsigned char m_buffer[
                            sizeof(class appl_demo_child)];
                    class appl_placement m_allocator;
                    class appl_demo_child * m_child;
            };

*/

/* Included. */
#define INC_APPL_PLACEMENT_H

/* Reverse include guard */
enum guard_appl_placement_h
{
    inc_appl_placement_h = 1
        /* Header file dependency */
        + inc_appl_allocator_h
        + inc_appl_types_h
};

/*

*/
struct appl_placement_descriptor
{
    void *
        p_placement;

#define PADDING (APPL_SIZEOF_PTR)
#include <appl_padding.h>

}; /* struct appl_placement_descriptor */

/* Assert compiler */
#include <appl_assert_cplusplus.h>

//
//
//
class appl_placement : public appl_allocator
{
    public:

        appl_placement(
            struct appl_context * const
                p_context);

        virtual
        ~appl_placement();

        enum appl_status
            f_init(
                struct appl_placement_descriptor const * const
                    p_descriptor);

        virtual
        appl_size_t
            v_cleanup(void);

    protected:

    private:

        struct appl_placement_descriptor
            m_descriptor;

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

        appl_placement(
            class appl_placement const & r);

        class appl_placement &
            operator =(
                class appl_placement const & r);

}; // class appl_placement

/* end-of-file: appl_placement.h */
