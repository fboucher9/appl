/* See LICENSE for license details */

/*

*/

#include "appl.h"

#include "appl_object.h"

#include "appl_client.h"

#include "appl_heap.h"

#include "appl_options.h"

//
//
//
enum appl_status
    appl_client::create_instance(
        struct appl_client_descriptor const * const
            p_client_descriptor,
        class appl_client * * const
            r_client)
{
    enum appl_status
        e_status;

    class appl_heap *
        p_heap;

    p_heap =
        p_client_descriptor->p_heap;

    struct appl_buf
        o_placement;

    e_status =
        p_heap->alloc_memory(
            &(
                o_placement),
            static_cast<unsigned long int>(
                sizeof(
                    class appl_client)));

    if (
        appl_status_ok == e_status)
    {
        class appl_object *
            p_object;

        e_status =
            appl_object::init_instance(
                static_cast<class appl_client *>(
                    0),
                o_placement.o_min.p_void,
                &(
                    appl_client::placement_new),
                static_cast<void const *>(
                    p_client_descriptor),
                &(
                    p_object));

        if (
            appl_status_ok == e_status)
        {
            class appl_client *
                p_client;

            p_client =
                reinterpret_cast<class appl_client *>(
                    p_object);

            *(
                r_client) =
                p_client;
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
appl_client::appl_client() :
    appl_object(),
    m_heap(),
    m_options()
{
}

//
//
//
appl_client::~appl_client()
{
}

void
    appl_client::placement_new(
        void * const
            p_placement)
{
    new (
        p_placement)
        class appl_client;

} // placement_new()

//
//
//
enum appl_status
    appl_client::init(
        void const * const
            p_descriptor)
{
    enum appl_status
        e_status;

    struct appl_client_descriptor const * const
        p_client_descriptor =
        static_cast<struct appl_client_descriptor const *>(
            p_descriptor);

    m_client =
        this;

    m_heap =
        p_client_descriptor->p_heap;

    e_status =
        appl_status_ok;

    return
        e_status;

} // init()

//
//
//
enum appl_status
    appl_client::cleanup(void)
{
    enum appl_status
        e_status;

    // destroy objects

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
appl_client::destroy(void)
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

/* end-of-file: appl_client.cpp */
