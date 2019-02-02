/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_address_property.h>

#include <appl_property_handle.h>

#include <appl_buf.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_object_handle.h>

#include <property/appl_property_types.h>

#include <property/appl_property.h>

#include <property/appl_property_std.h>

#if defined APPL_DEBUG

#include <debug/appl_debug_impl.h>

#endif /* #if defined APPL_DEBUG */

#include <appl_convert.h>

#include <appl_heap_handle.h>

#define APPL_ADDRESS_PROPERTY_GUID (0xe0bfd095ul)

enum appl_address_property_id
{
    appl_address_property_id_guid = 0,

    appl_address_property_id_name_min = 1,

    appl_address_property_id_name_max = 2,

    appl_address_property_id_port = 3,

    appl_address_property_id_family = 4,

    appl_address_property_id_max = 5

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

        static
        enum appl_status
        s_destroy(
            struct appl_address_property * const
                p_address_property);

        appl_address_property(
            struct appl_context * const
                p_context);

        virtual
        ~appl_address_property();

        enum appl_status
            f_init(void);

        virtual
        appl_size_t
            v_cleanup(void);

    protected:

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
        appl_new(
            p_context,
            r_address_property);

} // s_create()

//
//
//
enum appl_status
appl_address_property::s_destroy(
    struct appl_address_property * const
        p_address_property)
{
    struct appl_context * const
        p_context =
        p_address_property->get_context();

    return
        appl_delete(
            p_context,
            p_address_property);

} // s_destroy()

//
//
//
appl_address_property::appl_address_property(
    struct appl_context * const
        p_context) :
    appl_property_std(
        p_context)
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
appl_size_t
    appl_address_property::v_cleanup(void)
{
    return
        appl_property_std::v_cleanup();

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
        appl_address_property::s_destroy(
            p_address_property);

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

    appl_debug_impl::s_validate(
        (
            appl_status_ok
            == e_status)
        && (
            APPL_ADDRESS_PROPERTY_GUID
            == u_value),
        "invalid guid for appl_address_property object\n");
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
appl_address_property_set_family(
    struct appl_address_property * const
        p_address_property,
    int const
        e_family)
{
#if defined APPL_DEBUG
    appl_address_property_assert_guid(
        p_address_property);
#endif /* #if defined APPL_DEBUG */

    signed long int const
        i_value =
        e_family;

    return
        appl_property_set_long(
            p_address_property,
            appl_address_property_id_family,
            i_value);

} /* appl_address_property_set_family() */

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

    union appl_buf_ptr
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
        union appl_buf_ptr
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

/*

*/
enum appl_status
appl_address_property_get_family(
    struct appl_address_property const * const
        p_address_property,
    int * const
        r_family)
{
    enum appl_status
        e_status;

    signed long int
        i_value;

    e_status =
        appl_property_get_long(
            p_address_property,
            appl_address_property_id_family,
            &(
                i_value));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_family) =
            appl_convert::to_int(
                i_value);
    }

    return
        e_status;

} /* appl_address_property_get_family() */

/* end-of-file: appl_address_property.cpp */
