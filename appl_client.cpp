/* See LICENSE for license details */

/*

*/

#include <stdlib.h>

#include "appl.h"

#include "appl_object.h"

#include "appl_client.h"

#include "appl_heap.h"

#include "appl_heap_std.h"

#include "appl_options.h"

#include "appl_options_std.h"

struct appl_client_init_descriptor
{
    struct appl_context_descriptor
        o_context_descriptor;

    class appl_heap *
        p_heap;

};

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
            struct appl_client_init_descriptor
                o_client_init_descriptor;

            o_client_init_descriptor.o_context_descriptor =
                *(
                    p_client_descriptor);

            o_client_init_descriptor.p_heap =
                p_heap;

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
                        &(
                            o_client_init_descriptor)),
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
    enum appl_status
        e_status;

    struct appl_client_init_descriptor const * const
        p_client_init_descriptor =
        static_cast<struct appl_client_init_descriptor const *>(
            p_descriptor);

    m_heap =
        p_client_init_descriptor->p_heap;

    /* Create options */
    struct appl_options_std_descriptor
        o_options_std_descriptor;

    o_options_std_descriptor.argc =
        p_client_init_descriptor->o_context_descriptor.p_arg_max
        - p_client_init_descriptor->o_context_descriptor.p_arg_min;

    o_options_std_descriptor.argv =
        p_client_init_descriptor->o_context_descriptor.p_arg_min;

    class appl_options_std *
        p_options_std;

    e_status =
        appl_options_std::create_instance(
            this,
            &(
                o_options_std_descriptor),
            &(
                p_options_std));

    if (
        appl_status_ok == e_status)
    {
        class appl_options *
            p_options;

        p_options =
            p_options_std;

        m_options =
            p_options;
    }

    return
        e_status;

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
