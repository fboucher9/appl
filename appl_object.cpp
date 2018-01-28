/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_object.h"

#include "appl_client.h"

#include "appl_heap.h"

//
//
//
enum appl_status
    appl_object::create_instance(
        class appl_client * const
            p_client,
        unsigned long int const
            i_placement_length,
        void (*p_new)(
            void * const
                p_placement),
        void const * const
            p_descriptor,
        class appl_object * * const
            r_object)
{
    enum appl_status
        e_status;

    unsigned char *
        p_placement;

    p_placement =
        new unsigned char [i_placement_length];

    if (
        p_placement)
    {
        e_status =
            appl_object::init_instance(
                p_client,
                p_placement,
                p_new,
                p_descriptor,
                r_object);

        if (
            appl_status_ok != e_status)
        {
            delete []
                p_placement;
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

enum appl_status
    appl_object::init_instance(
        class appl_client * const
            p_client,
        void * const
            p_placement,
        void (*p_new)(
            void * const
                p_placement),
        void const * const
            p_descriptor,
        class appl_object * * const
            r_object)
{
    enum appl_status
        e_status;

    class appl_object *
        p_object;

    p_object =
        static_cast<class appl_object *>(
            p_placement);

    (*p_new)(
        p_placement);

    p_object->m_client =
        p_client;

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
        delete
            this;
    }

    return
        e_status;

} // destroy()

//
//
//
appl_object::appl_object() :
    m_client()
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
    unsigned long int const
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
    void * const
        p_buf)
{
    static_cast<void>(
        p_buf);
} // operator delete

void *
appl_object::operator new(
    unsigned long int const
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
    void * const
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

/* end-of-file: appl_object.cpp */
