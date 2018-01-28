/* See LICENSE for license details */

/*

*/

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

    class appl_client *
        p_client;

    p_client =
        new
            class appl_client;

    if (
        p_client)
    {
        e_status =
            p_client->init(
                p_client_descriptor);

        if (
            appl_status_ok == e_status)
        {
            *(
                r_client) =
                    p_client;
        }

        if (
            appl_status_ok != e_status)
        {
            delete
                p_client;
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
        struct appl_context_descriptor const * const
            p_client_descriptor)
{
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
