/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_predefines.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <list/appl_node.h>

#include <buf/appl_buf.h>

#include <string/appl_string_handle.h>

#include <markup/appl_markup_object.h>

#include <heap/appl_heap_handle.h>

#include <misc/appl_unused.h>

//
//
//
struct appl_markup_object : public appl_object
{
    public:

        appl_markup_object(
            struct appl_context * const
                p_context);

        virtual
        ~appl_markup_object();

        enum appl_status
            f_init(void);

        virtual
        appl_size_t
            v_cleanup(void);

        enum appl_status
            f_write(
                struct appl_markup_element const * const
                    p_element);

        enum appl_status
            f_enumerate(
                struct appl_markup_enumerate_callback const * const
                    p_callback) const;

    protected:

    private:

        // --

        appl_markup_object(
            struct appl_markup_object const & r);

        struct appl_markup_object &
            operator =(
                struct appl_markup_object const & r);

}; // struct appl_markup_object

//
//
//
appl_markup_object::appl_markup_object(
    struct appl_context * const
        p_context) :
    appl_object(
        p_context)
{
}

//
//
//
appl_markup_object::~appl_markup_object()
{
}

//
//
//
enum appl_status
    appl_markup_object::f_init(void)
{
    enum appl_status
        e_status;

    e_status =
        appl_status_ok;

    return
        e_status;

} // f_init()

//
//
//
appl_size_t
    appl_markup_object::v_cleanup(void)
{
    return
        sizeof(
            struct appl_markup_object);

} // v_cleanup()

//
//
//
enum appl_status
    appl_markup_object::f_write(
        struct appl_markup_element const * const
            p_element)
{
    appl_unused(
        p_element);

    return
        appl_raise_not_implemented();

} // f_write()

//
//
//
enum appl_status
    appl_markup_object::f_enumerate(
        struct appl_markup_enumerate_callback const * const
            p_callback) const
{
    appl_unused(
        p_callback);

    return
        appl_raise_not_implemented();

} // f_enumerate()

//
//
//
class appl_markup_object_service
{
    public:

        static
        enum appl_status
            s_create(
                struct appl_context * const
                    p_context,
                struct appl_markup_object * * const
                    r_instance);

        static
        enum appl_status
            s_destroy(
                struct appl_markup_object * const
                    p_instance);

        static
        enum appl_status
            s_write(
                struct appl_markup_object * const
                    p_instance,
                struct appl_markup_element const * const
                    p_element);

        static
        enum appl_status
            s_enumerate(
                struct appl_markup_object const * const
                    p_instance,
                struct appl_markup_enumerate_callback const * const
                    p_callback);

}; // class appl_markup_object_service

//
//
//
enum appl_status
    appl_markup_object_service::s_create(
        struct appl_context * const
            p_context,
        struct appl_markup_object * * const
            r_instance)
{
    enum appl_status
        e_status;

    e_status =
        appl_new(
            p_context,
            r_instance);

    return
        e_status;

} // s_create()

//
//
//
enum appl_status
    appl_markup_object_service::s_destroy(
        struct appl_markup_object * const
            p_instance)
{
    enum appl_status
        e_status;

    struct appl_context * const
        p_context =
        p_instance->get_context();

    e_status =
        appl_delete(
            p_context,
            p_instance);

    return
        e_status;

} // s_destroy()

//
//
//
enum appl_status
    appl_markup_object_service::s_write(
        struct appl_markup_object * const
            p_instance,
        struct appl_markup_element const * const
            p_element)
{
    enum appl_status
        e_status;

    e_status =
        p_instance->f_write(
            p_element);

    return
        e_status;

} // s_write()

//
//
//
enum appl_status
    appl_markup_object_service::s_enumerate(
        struct appl_markup_object const * const
            p_instance,
        struct appl_markup_enumerate_callback const * const
            p_callback)
{
    return
        p_instance->f_enumerate(
            p_callback);

} // s_enumerate()

//
//
//
enum appl_status
    appl_markup_object_create(
        struct appl_context * const
            p_context,
        struct appl_markup_object * * const
            r_instance)
{
    return
        appl_markup_object_service::s_create(
            p_context,
            r_instance);

} // create()

//
//
//
enum appl_status
    appl_markup_object_destroy(
        struct appl_markup_object * const
            p_instance)
{
    return
        appl_markup_object_service::s_destroy(
            p_instance);

} // destroy()

//
//
//
enum appl_status
    appl_markup_object_write(
        struct appl_markup_object * const
            p_parent,
        struct appl_markup_element const * const
            p_child)
{
    return
        appl_markup_object_service::s_write(
            p_parent,
            p_child);

} // write()

//
//
//
enum appl_status
    appl_markup_object_enumerate(
        struct appl_markup_object const * const
            p_instance,
        struct appl_markup_enumerate_callback const * const
            p_callback)
{
    return
        appl_markup_object_service::s_enumerate(
            p_instance,
            p_callback);

} // enumerate()

/* end-of-file: appl_markup_object.cpp */
