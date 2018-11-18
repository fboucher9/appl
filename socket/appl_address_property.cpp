/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_address_property.h>

#include <appl_property_handle.h>

#include <appl_buf.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <appl_object_handle.h>

#include <property/appl_property_types.h>

#include <property/appl_property.h>

#include <property/appl_property_std.h>

#if defined APPL_DEBUG

#include <appl_debug_handle.h>

#endif /* #if defined APPL_DEBUG */

#include <appl_convert.h>

#include <appl_context.h>

#include <allocator/appl_allocator.h>

#define APPL_ADDRESS_PROPERTY_GUID (0xe0bfd095ul)

enum appl_address_property_id
{
    appl_address_property_id_guid = 0,

    appl_address_property_id_name_min = 1,

    appl_address_property_id_name_max = 2,

    appl_address_property_id_port = 3,

    appl_address_property_id_max = 4

}; /* enum appl_address_property_id */

//
//
//
struct appl_address_property : public appl_property_std
{
    public:

        static
        enum appl_status
        s_create(
            struct appl_context * const
                p_context,
            struct appl_address_property * * const
                r_address_property);

        appl_address_property();

        virtual
        ~appl_address_property();

        enum appl_status
            f_init(void);

    protected:

        virtual
        enum appl_status
            v_cleanup(void);

    private:

        appl_address_property(
            struct appl_address_property const & r);

        struct appl_address_property &
            operator =(
                struct appl_address_property const & r);

}; // struct appl_address_property

//
//
//
enum appl_status
appl_address_property::s_create(
    struct appl_context * const
        p_context,
    struct appl_address_property * * const
        r_address_property)
{
    return
        p_context->m_allocator->alloc_object(
            r_address_property);

} // s_create()

//
//
//
appl_address_property::appl_address_property() :
    appl_property_std()
{
}

//
//
//
appl_address_property::~appl_address_property()
{
}

//
//
//
enum appl_status
    appl_address_property::f_init(void)
{
    enum appl_status
        e_status;

    struct appl_property_std_descriptor
        o_property_std_descriptor;

    o_property_std_descriptor.i_count =
        appl_address_property_id_max;

    e_status =
        appl_property_std::f_init(
            &(
                o_property_std_descriptor));

    if (
        appl_status_ok
        == e_status)
    {
        appl_property_set_ulong(
            this,
            appl_address_property_id_guid,
            APPL_ADDRESS_PROPERTY_GUID);
    }

    return
        e_status;

} // f_init()

//
//
//
enum appl_status
    appl_address_property::v_cleanup(void)
{
    appl_property_std::v_cleanup();

    return
        appl_status_ok;

}

/*

*/
enum appl_status
appl_address_property_create(
    struct appl_context * const
        p_context,
    struct appl_address_property * * const
        r_property)
{
    return
        appl_address_property::s_create(
            p_context,
            r_property);

} /* create() */

/*

*/
enum appl_status
appl_address_property_destroy(
    struct appl_address_property * const
        p_address_property)
{
    return
        p_address_property->v_destroy();

} /* destroy() */

/*

*/
struct appl_property *
appl_address_property_parent(
    struct appl_address_property * const
        p_address_property)
{
    return
        p_address_property;

} /* parent() */

/*

*/
struct appl_property const *
appl_address_property_const_parent(
    struct appl_address_property const * const
        p_address_property)
{
    return
        p_address_property;

} /* const_parent() */

/*

*/
#if defined APPL_DEBUG
static
void
appl_address_property_assert_guid(
    struct appl_address_property const * const
        p_address_property)
{
    enum appl_status
        e_status;

    unsigned long int
        u_value;

    e_status =
        appl_property_get_ulong(
            p_address_property,
            appl_address_property_id_guid,
            &(
                u_value));

    if (
        (
            appl_status_ok
            == e_status)
        && (
            APPL_ADDRESS_PROPERTY_GUID
            == u_value))
    {
    }
    else
    {
        appl_debug_print0(
            appl_object_get_context(
                appl_address_property_const_parent(
                    p_address_property)),
            appl_convert::to_uchar_ptr(
                "invalid guid for appl_address_property object\n"));
    }
}
#endif /* #if defined APPL_DEBUG */

/*

*/
enum appl_status
appl_address_property_set_name(
    struct appl_address_property * const
        p_address_property,
    unsigned char const * const
        p_name_min,
    unsigned char const * const
        p_name_max)
{
    enum appl_status
        e_status;

#if defined APPL_DEBUG
    appl_address_property_assert_guid(
        p_address_property);
#endif /* #if defined APPL_DEBUG */

    e_status =
        appl_property_set_ptr(
            p_address_property,
            appl_address_property_id_name_min,
            p_name_min);

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            appl_property_set_ptr(
                p_address_property,
                appl_address_property_id_name_max,
                p_name_max);
    }

    return
        e_status;

} /* appl_address_property_set_name() */

/*

*/
enum appl_status
appl_address_property_set_port(
    struct appl_address_property * const
        p_address_property,
    unsigned short int const
        i_port)
{
#if defined APPL_DEBUG
    appl_address_property_assert_guid(
        p_address_property);
#endif /* #if defined APPL_DEBUG */

    return
        appl_property_set_ulong(
            p_address_property,
            appl_address_property_id_port,
            i_port);

} /* appl_address_property_set_port() */

/*

*/
enum appl_status
appl_address_property_get_name(
    struct appl_address_property const * const
        p_address_property,
    unsigned char const * * const
        r_name_min,
    unsigned char const * * const
        r_name_max)
{
    enum appl_status
        e_status;

#if defined APPL_DEBUG
    appl_address_property_assert_guid(
        p_address_property);
#endif /* #if defined APPL_DEBUG */

    union appl_ptr
        o_name_min;

    e_status =
        appl_property_get_ptr(
            p_address_property,
            appl_address_property_id_name_min,
            &(
                o_name_min.p_void));

    if (
        appl_status_ok
        == e_status)
    {
        union appl_ptr
            o_name_max;

        e_status =
            appl_property_get_ptr(
                p_address_property,
                appl_address_property_id_name_max,
                &(
                    o_name_max.p_void));

        if (
            appl_status_ok
            == e_status)
        {
            *(
                r_name_min) =
                o_name_min.pc_uchar;

            *(
                r_name_max) =
                o_name_max.pc_uchar;
        }
    }

    return
        e_status;

} /* appl_address_property_get_name() */

/*

*/
enum appl_status
appl_address_property_get_port(
    struct appl_address_property const * const
        p_address_property,
    unsigned short int * const
        r_port)
{
#if defined APPL_DEBUG
    appl_address_property_assert_guid(
        p_address_property);
#endif /* #if defined APPL_DEBUG */

    enum appl_status
        e_status;

    unsigned long int
        u_value;

    e_status =
        appl_property_get_ulong(
            p_address_property,
            appl_address_property_id_port,
            &(
                u_value));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_port) =
            appl_convert::to_ushort(
                u_value);
    }

    return
        e_status;

} /* appl_address_property_get_port() */

/* end-of-file: appl_address_property.cpp */
