/* See LICENSE for license details */

/*

Module: appl.c

Description:

    Dispatch of Application Library entry-points.

*/

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include "appl.h"

#include "appl_object.h"

#include "appl_client.h"

/*

*/
enum appl_status
appl_object_destroy(
    struct appl_object_handle * const
        p_object_handle)
{
    class appl_object *
        p_object;

    p_object =
        reinterpret_cast<class appl_object *>(
            p_object_handle);

    return
        p_object->destroy();

} /* appl_object_destroy() */

enum appl_status
appl_context_create(
    struct appl_context_descriptor const * const
        p_client_descriptor,
    struct appl_context_handle * * const
        r_context_handle)
{
    enum appl_status
        e_status;

    class appl_client *
        p_client;

    e_status =
        appl_client::create_instance(
            p_client_descriptor,
            &(
                p_client));

    if (
        appl_status_ok == e_status)
    {
        *(
            r_context_handle) =
            reinterpret_cast<struct appl_context_handle *>(
                p_client);
    }

    return
        e_status;

} /* appl_context_create() */

class appl_options;

//
//
//
class appl_options : public appl_object
{
    public:

        virtual
        enum appl_status
            read(
                struct appl_buf * const
                    p_buf);

    protected:

        appl_options();

        virtual
        ~appl_options();

    private:

        appl_options(
            class appl_options const & r);

        class appl_options &
            operator =(
                class appl_options const & r);

}; // class appl_options

class appl_options_impl;

//
//
//
class appl_options_impl : public appl_options
{
    public:

        static
        enum appl_status
        create_instance(
            class appl_client * const
                p_client,
            struct appl_options_descriptor const * const
                p_options_descriptor,
            class appl_options_impl * * const
                r_options_impl);

    protected:

        appl_options_impl();

        virtual
        ~appl_options_impl();

    private:

        struct appl_buf *
            m_buf_min;

        struct appl_buf *
            m_buf_max;

        appl_options_impl(
            class appl_options_impl const & r);

        class appl_options_impl &
            operator =(
                class appl_options_impl const & r);

}; // class appl_options_impl

//
//
//
enum appl_status
appl_options_impl::create_instance(
    class appl_client * const
        p_client,
    struct appl_options_descriptor const * const
        p_options_descriptor,
    class appl_options_impl * * const
        r_options_impl)
{
    class appl_options_impl *
        p_options_impl;

    unsigned long int
        i_placement_length;

    void *
        p_placement;

    i_placement_length =
        (unsigned long int)(
            sizeof(
                struct appl_options_impl));

    if (
        p_options_descriptor)
    {
        unsigned long int
            i_count;

        i_count =
            (unsigned long int)(
                p_options_descriptor->p_buf_max
                - p_options_descriptor->p_buf_min);

        i_placement_length +=
            (unsigned long int)(
                i_count
                * sizeof(
                    struct feed_buf));

        struct feed_buf *
            p_buf_iterator;

        p_buf_iterator =
            p_options_descriptor->p_buf_min;

        while (
            p_buf_iterator < p_options_descriptor->p_buf_max)
        {
        }
    }

    p_options_impl =
        (struct appl_options_impl *)(
            malloc(
                sizeof(
                    struct appl_options_impl)));

    if (
        p_options_impl)
    {
        e_status =
            appl_options_init(
                p_context,
                p_options_descriptor,
                p_options_impl);

        if (
            appl_status_ok
            == e_status)
        {
            *(
                r_options_impl) =
                p_options_impl;
        }
        else
        {
            free(
                (void *)(
                    p_options_impl));
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
appl_options_impl::appl_options_impl() :
    appl_options(),
    m_buf_min(),
    m_buf_max()
{
}

//
//
//
appl_options_impl::~appl_options_impl()
{
}

/*

*/
enum appl_status
appl_options_create(
    struct appl_context_handle * const
        p_context,
    struct appl_options_descriptor const * const
        p_options_descriptor,
    struct appl_options_handle * * const
        r_options_handle)
{
    enum appl_status
        e_status;

    class appl_client *
        p_client;

    class appl_options_impl *
        p_options_impl;

    p_client =
        reinterpret_cast<class appl_client *>(
            p_context);

    e_status =
        appl_options_impl::create_instance(
            p_client,
            p_options_descriptor,
            &(
                p_options_impl));

    if (
        appl_status_ok == e_status)
    {
        *(
            r_options_handle) =
            p_options_impl;
    }

    return
        e_status;

} /* appl_options_create() */

enum appl_status
appl_options_read(
    struct appl_options * const
        p_options,
    struct appl_buf * const
        p_buf)
{
    enum appl_status
        e_status;

    (void)(
        p_options);
    (void)(
        p_buf);

    e_status =
        appl_status_fail;

    return
        e_status;

}

int
main(
    int argc,
    char * * argv)
{
    int
        i_exit_code;

    struct appl_context_handle *
        p_context;

    enum appl_status
        e_status;

    struct appl_context_descriptor
        o_context_descriptor;

    /* Create context */
    e_status =
        appl_context_create(
            &(
                o_context_descriptor),
            &(
                p_context));

    if (
        appl_status_ok
        == e_status)
    {
        /* Create options */
        struct appl_options *
            p_options;

        struct appl_options_descriptor
            o_options_descriptor;

        if (argc)
        {
            /* Create array of buffer */
            o_options_descriptor.p_buf_min =
                (struct appl_buf *)(
                    malloc(
                        argc * sizeof(
                            struct appl_buf)));

            if (
                o_options_descriptor.p_buf_min)
            {
                int argi;

                o_options_descriptor.p_buf_max =
                    o_options_descriptor.p_buf_min + argc;

                for (argi = 0; argi < argc; argi ++)
                {
                    o_options_descriptor.p_buf_min[argi].o_min.p_void =
                        (void *)(
                            argv[argi]);

                    o_options_descriptor.p_buf_min[argi].o_max.p_void =
                        (void *)(
                            argv[argi] + strlen(argv[argi]));
                }
            }
        }
        else
        {
            o_options_descriptor.p_buf_min =
                0;

            o_options_descriptor.p_buf_max =
                0;

        }

        e_status =
            appl_options_create(
                p_context,
                &(
                    o_options_descriptor),
                &(
                    p_options));

        if (
            appl_status_ok
            == e_status)
        {
            /* Dispatch */
            i_exit_code =
                1;

            e_status =
                appl_main(
                    p_context,
                    p_options,
                    &(
                        i_exit_code));
        }
        else
        {
            i_exit_code =
                1;
        }
    }
    else
    {
        i_exit_code =
            1;
    }


    return
        i_exit_code;

}
