/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_context.h"

#include "appl_heap.h"

//
//
//
enum appl_status
    appl_object::create_instance(
        struct appl_context * const
            p_context,
        appl_size_t const
            i_placement_length,
        void (*p_new)(
            void * const
                p_placement),
        void const * const
            p_descriptor,
        struct appl_object * * const
            r_object)
{
    enum appl_status
        e_status;

    class appl_heap *
        p_heap;

    p_heap =
        p_context->m_heap;

    void *
        p_placement;

    e_status =
        p_heap->v_alloc(
            i_placement_length,
            &(
                p_placement));

    if (
        appl_status_ok == e_status)
    {
        e_status =
            appl_object::init_instance(
                p_context,
                p_placement,
                p_new,
                p_descriptor,
                r_object);

        if (
            appl_status_ok != e_status)
        {
            p_heap->v_free(
                p_placement);
        }
    }

    return
        e_status;

} // create_instance()

//
//
//
enum appl_status
    appl_object::init_instance(
        struct appl_context * const
            p_context,
        void * const
            p_placement,
        void (*p_new)(
            void * const
                p_placement),
        void const * const
            p_descriptor,
        struct appl_object * * const
            r_object)
{
    enum appl_status
        e_status;

    struct appl_object *
        p_object;

    p_object =
        static_cast<struct appl_object *>(
            p_placement);

    (*p_new)(
        p_placement);

    p_object->m_context =
        p_context;

    e_status =
        p_object->init(
            p_descriptor);

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_object) =
            p_object;
    }

    return
        e_status;

} // init_instance()

//
//
//
enum appl_status
    appl_object::destroy(void)
{
    enum appl_status
        e_status;

    e_status =
        cleanup();

    if (
        appl_status_ok == e_status)
    {
        struct appl_context *
            p_context;

        p_context =
            m_context;

        class appl_heap *
            p_heap;

        p_heap =
            p_context->m_heap;

        void *
            p_placement;

        p_placement =
            static_cast<void *>(
                this);

        delete
            this;

        /* Free memory */
        p_heap->v_free(
            p_placement);
    }

    return
        e_status;

} // destroy()

//
//
//
appl_object::appl_object() :
    m_context()
{
}

//
//
//
appl_object::~appl_object()
{
}

void *
appl_object::operator new(
    appl_size_t const
        i_buf_len)
{
    static_cast<void>(
        i_buf_len);
    return
        reinterpret_cast<void *>(
            12345);
} // operator new

void
appl_object::operator delete(
    void *
        p_buf)
{
    static_cast<void>(
        p_buf);
} // operator delete

void *
appl_object::operator new(
    appl_size_t const
        i_buf_len,
    void * const
        p_placement)
{
    static_cast<void>(
        i_buf_len);
    return
        p_placement;
} // operator new

void
appl_object::operator delete (
    void *
        p_buf,
    void * const
        p_placement)
{
    static_cast<void>(
        p_buf);
    static_cast<void>(
        p_placement);
} // operator delete

//
//
//
enum appl_status
    appl_object::init(
        void const * const
            p_descriptor)
{
    static_cast<void>(
        p_descriptor);

    return
        appl_status_ok;

} // init()

//
//
//
enum appl_status
    appl_object::cleanup(void)
{
    return
        appl_status_ok;

} // cleanup()

//
//
//
struct appl_context *
    appl_object::get_context(void) const
{
    return
        m_context;

} // get_context()

/* end-of-file: appl_object.cpp */
