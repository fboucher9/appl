/* See LICENSE for license details */

/*

*/

#include <stdlib.h>

#include "appl.h"

#include "appl_object.h"

#include "appl_client.h"

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

    void *
        p_placement;

    p_placement =
        malloc(
            sizeof(
                class appl_client));

    if (p_placement)
    {
        class appl_object *
            p_object;

        e_status =
            appl_object::init_instance(
                static_cast<class appl_client *>(
                    0),
                p_placement,
                &(
                    appl_client::placement_new),
                static_cast<void const *>(
                    p_client_descriptor),
                &(
                    p_object));

        if (
            appl_status_ok == e_status)
        {
            *(
                r_client) =
                    reinterpret_cast<class appl_client *>(
                        p_object);
        }

        if (
            appl_status_ok != e_status)
        {
            free(
                p_placement);
        }
    }
    else
    {
        e_status =
            appl_status_out_of_memory;
    }

    return
        e_status;

} // create_instance()

//
//
//
appl_client::appl_client() :
    appl_object()
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
