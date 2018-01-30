/* See LICENSE for license details */

/*

*/

#include <stdlib.h>

#include "appl.h"

#include "appl_object.h"

#include "appl_client.h"

#include "appl_heap.h"

#include "appl_heap_std.h"

//
//
//
enum appl_status
    appl_client::create_instance(
        struct appl_context_descriptor const * const
            p_client_descriptor,
        class appl_client * * const
            r_client)
{
    enum appl_status
        e_status;

    class appl_heap_std *
        p_heap_std;

    e_status =
        appl_heap_std::create_instance(
            &(
                p_heap_std));

    if (
        appl_status_ok
        == e_status)
    {
        class appl_heap *
            p_heap;

        p_heap =
            p_heap_std;

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

                p_client->m_heap =
                    p_heap;

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

        if (
            appl_status_ok != e_status)
        {
            p_heap_std->destroy();
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

//
//
//
enum appl_status
    appl_client::init(
        void const * const
            p_descriptor)
{
    struct appl_context_descriptor const * const
        p_client_descriptor =
        static_cast<struct appl_context_descriptor const *>(
            p_descriptor);

    static_cast<void>(
        p_client_descriptor);

    return
        appl_status_ok;

} // init()

//
//
//
enum appl_status
    appl_client::cleanup(void)
{
    return
        appl_status_ok;
} // cleanup()

/* end-of-file: appl_client.cpp */
