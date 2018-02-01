/* See LICENSE for license details */

/*

*/

#include "appl.h"

#include "appl_object.h"

#include "appl_context.h"

#include "appl_heap.h"

#include "appl_options.h"

#include "appl_thread_mgr.h"

struct appl_context_init_descriptor
{
    class appl_heap *
        p_heap;

}; /* struct appl_context_init_descriptor */

//
//
//
enum appl_status
    appl_context::create_instance(
        class appl_heap * const
            p_heap,
        class appl_context * * const
            r_context)
{
    enum appl_status
        e_status;

    struct appl_context_init_descriptor
        o_init_descriptor;

    o_init_descriptor.p_heap =
        p_heap;

    struct appl_buf
        o_placement;

    e_status =
        p_heap->alloc_memory(
            &(
                o_placement),
            static_cast<unsigned long int>(
                sizeof(
                    class appl_context)));

    if (
        appl_status_ok == e_status)
    {
        class appl_object *
            p_object;

        e_status =
            appl_object::init_instance(
                static_cast<class appl_context *>(
                    0),
                o_placement.o_min.p_void,
                &(
                    appl_context::placement_new),
                static_cast<void const *>(
                    &(
                        o_init_descriptor)),
                &(
                    p_object));

        if (
            appl_status_ok == e_status)
        {
            class appl_context *
                p_context;

            p_context =
                reinterpret_cast<class appl_context *>(
                    p_object);

            *(
                r_context) =
                p_context;
        }

        if (
            appl_status_ok != e_status)
        {
            p_heap->free_memory(
                &(
                    o_placement));
        }
    }

    return
        e_status;

} // create_instance()

//
//
//
appl_context::appl_context() :
    appl_object(),
    m_heap(),
    m_options(),
    m_thread_mgr()
{
}

//
//
//
appl_context::~appl_context()
{
}

void
    appl_context::placement_new(
        void * const
            p_placement)
{
    new (
        p_placement)
        class appl_context;

} // placement_new()

//
//
//
enum appl_status
    appl_context::init(
        void const * const
            p_descriptor)
{
    enum appl_status
        e_status;

    struct appl_context_init_descriptor const * const
        p_context_init_descriptor =
        static_cast<struct appl_context_init_descriptor const *>(
            p_descriptor);

    m_context =
        this;

    m_heap =
        p_context_init_descriptor->p_heap;

    e_status =
        appl_status_ok;

    return
        e_status;

} // init()

//
//
//
enum appl_status
    appl_context::cleanup(void)
{
    enum appl_status
        e_status;

    // destroy objects

    if (m_thread_mgr)
    {
        m_thread_mgr->destroy();

        m_thread_mgr =
            0;
    }

    if (m_options)
    {
        m_options->destroy();

        m_options =
            0;
    }

    e_status =
        appl_status_ok;

    return
        e_status;

} // cleanup()

//
//
//
enum appl_status
appl_context::destroy(void)
{
    enum appl_status
        e_status;

    class appl_heap *
        p_heap;

    p_heap =
        m_heap;

    cleanup();

    struct appl_buf
        o_placement;

    o_placement.o_min.p_void =
        this;

    o_placement.o_max.p_void =
        this + 1;

    delete
        this;

    p_heap->free_memory(
        &(
            o_placement));

    p_heap->destroy();

    e_status =
        appl_status_ok;

    return
        e_status;

} // destroy()

/* end-of-file: appl_context.cpp */
