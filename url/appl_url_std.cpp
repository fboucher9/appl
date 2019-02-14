/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <url/appl_url.h>

#include <appl_list.h>

#include <url/appl_url_std.h>

#include <appl_url_types.h>

#include <appl_context_handle.h>

#include <appl_allocator_handle.h>

#include <appl_heap_handle.h>

#include <appl_buf.h>

#include <appl_unused.h>

//
//
//
struct appl_url_component
{
    struct appl_list
        o_list;

    unsigned char *
        p_buf_min;

    unsigned char *
        p_buf_max;

}; // struct appl_url_component

//
//
//
union appl_url_component_ptr
{
    void *
        p_void;

    struct appl_list *
        p_list;

    struct appl_url_component *
        p_component;

}; // union appl_url_component_ptr

//
//
//
appl_url_std::appl_url_std(
    struct appl_context * const
        p_context) :
    appl_url(
        p_context),
    m_flags()
{
}

//
//
//
appl_url_std::~appl_url_std()
{
}

//
//
//
enum appl_status
    appl_url_std::f_init(void)
{
    unsigned int
        i;

    for (
        i=0u;
        i<8u;
        i++)
    {
        appl_list_init(
            &(
                m_components[i]));
    }

    return
        appl_status_ok;

} // f_init()

//
//
//
appl_size_t
    appl_url_std::v_cleanup(void)
{
    return
        sizeof(class appl_url_std);

} // v_cleanup()

//
//
//
enum appl_status
    appl_url_std::v_decoder(
        unsigned char const * const
            p_input_min,
        unsigned char const * const
            p_input_max,
        unsigned long int * const
            r_input_count)
{
    appl_unused(
        p_input_min,
        p_input_max,
        r_input_count);

    return
        appl_raise_not_implemented();

} // v_decoder()

//
//
//
enum appl_status
    appl_url_std::v_encoder(
        unsigned char * const
            p_output_min,
        unsigned char * const
            p_output_max,
        unsigned long int * const
            r_output_count) const
{
    appl_unused(
        p_output_min,
        p_output_max,
        r_output_count);

    return
        appl_raise_not_implemented();

} // v_encoder()

//
//
//
enum appl_status
    appl_url_std::v_add_component(
        signed short int const
            e_component_type,
        unsigned char const * const
            p_buf_min,
        unsigned char const * const
            p_buf_max,
        void * * const
            r_handle)
{
    enum appl_status
        e_status;

    if (
        ((e_component_type + 0) > 0)
        && ((e_component_type + 0) < 8))
    {
        struct appl_context * const
            p_context =
            get_context();

        struct appl_allocator * const
            p_allocator =
            appl_context_get_allocator(
                p_context);

        struct appl_url_component *
            p_component;

        // create a new component
        e_status =
            appl_allocator_alloc_structure(
                p_allocator,
                &(
                    p_component));

        if (
            appl_status_ok
            == e_status)
        {
            appl_list_init(
                &(
                    p_component->o_list));

            p_component->p_buf_min =
                0;

            p_component->p_buf_min =
                0;

            appl_size_t const
                i_buf_len =
                appl_buf_len(
                    p_buf_min,
                    p_buf_max);

            if (
                i_buf_len)
            {
                // copy buffer
                union appl_buf_ptr
                    o_buf_ptr;

                e_status =
                    appl_heap_alloc(
                        p_context,
                        i_buf_len,
                        &(
                            o_buf_ptr.p_void));

                if (
                    appl_status_ok
                    == e_status)
                {
                    p_component->p_buf_min =
                        o_buf_ptr.p_uchar;

                    p_component->p_buf_max =
                        o_buf_ptr.p_uchar + i_buf_len;

                    appl_buf_copy(
                        p_component->p_buf_min,
                        p_component->p_buf_max,
                        p_buf_min,
                        p_buf_max);
                }
            }

            if (
                appl_status_ok
                == e_status)
            {
                // insert into linked list
                appl_list_join(
                    &(
                        p_component->o_list),
                    &(
                        m_components[e_component_type]));

                // return a handle
                *(
                    r_handle) =
                    p_component;
            }

            if (
                appl_status_ok
                != e_status)
            {
                appl_allocator_free_structure(
                    p_allocator,
                    p_component);
            }
        }
    }
    else
    {
        e_status =
            appl_raise_invalid_param();
    }

    return
        e_status;

} // v_add_component()

//
//
//
enum appl_status
    appl_url_std::v_remove_component(
        signed short int const
            e_component_type,
        void * const
            p_handle)
{
    enum appl_status
        e_status;

    if (
        ((e_component_type + 0) > 0)
        && ((e_component_type + 0) < 8))
    {
        struct appl_context * const
            p_context =
            get_context();

        struct appl_allocator * const
            p_allocator =
            appl_context_get_allocator(
                p_context);

        union appl_url_component_ptr
            o_component_ptr;

        o_component_ptr.p_void =
            p_handle;

        struct appl_url_component *
            p_component;

        p_component =
            o_component_ptr.p_component;

        appl_list_join(
            &(
                p_component->o_list),
            &(
                p_component->o_list));

        // Free buffer
        appl_size_t const
            i_buf_len =
            appl_buf_len(
                p_component->p_buf_min,
                p_component->p_buf_max);

        if (
            i_buf_len)
        {
            union appl_buf_ptr
                o_buf_ptr;

            o_buf_ptr.p_uchar =
                p_component->p_buf_min;

            appl_heap_free(
                p_context,
                i_buf_len,
                o_buf_ptr.p_void);
        }

        // Free node
        appl_allocator_free_structure(
            p_allocator,
            p_component);

        e_status =
            appl_status_ok;
    }
    else
    {
        e_status =
            appl_raise_invalid_param();
    }

    return
        e_status;

} // v_remove_component()

//
//
//
enum appl_status
    appl_url_std::v_get_component(
        signed short int const
            e_component_type,
        unsigned char const * * const
            r_buf_min,
        unsigned char const * * const
            r_buf_max,
        void * * const
            r_handle) const
{
    enum appl_status
        e_status;

    union appl_url_component_ptr
        o_component_ptr;

    if (
        ((e_component_type + 0) > 0)
        && ((e_component_type + 0) < 8))
    {
        o_component_ptr.p_list =
            m_components[e_component_type].o_next.p_node;

        if (
            o_component_ptr.p_list
            != (m_components + e_component_type))
        {
            struct appl_url_component * const
                p_component =
                o_component_ptr.p_component;

            *(
                r_buf_min) =
                p_component->p_buf_min;

            *(
                r_buf_max) =
                p_component->p_buf_max;

            *(
                r_handle) =
                o_component_ptr.p_void;

            e_status =
                appl_status_ok;
        }
        else
        {
            e_status =
                appl_status_fail;
        }
    }
    else
    {
        e_status =
            appl_raise_invalid_param();
    }

    return
        e_status;

} // v_get_component()

//
//
//
enum appl_status
    appl_url_std::v_next_component(
        signed short int const
            e_component_type,
        unsigned char const * * const
            r_buf_min,
        unsigned char const * * const
            r_buf_max,
        void * * const
            r_handle) const
{
    enum appl_status
        e_status;

    if (
        ((e_component_type + 0) > 0)
        && ((e_component_type + 0) < 8))
    {
        union appl_url_component_ptr
            o_component_ptr;

        o_component_ptr.p_void =
            *(
                r_handle);

        o_component_ptr.p_list =
            o_component_ptr.p_list->o_next.p_node;

        if (
            o_component_ptr.p_list
            != (m_components + e_component_type))
        {
            struct appl_url_component * const
                p_component =
                o_component_ptr.p_component;

            *(
                r_buf_min) =
                p_component->p_buf_min;

            *(
                r_buf_max) =
                p_component->p_buf_max;

            *(
                r_handle) =
                o_component_ptr.p_void;

            e_status =
                appl_status_ok;
        }
        else
        {
            e_status =
                appl_status_fail;
        }
    }
    else
    {
        e_status =
            appl_raise_invalid_param();
    }

    return
        e_status;

} // v_next_component()

//
//
//
enum appl_status
    appl_url_std::v_get_flags(
        unsigned long int * const
            r_flags) const
{
    enum appl_status
        e_status;

    *(
        r_flags) =
        m_flags;

    e_status =
        appl_status_ok;

    return
        e_status;

} // v_get_flags()

//
//
//
enum appl_status
    appl_url_std::v_set_flags(
        unsigned long int const
            i_flags)
{
    enum appl_status
        e_status;

    if (
        i_flags
        <= (
            APPL_URL_FLAG_AUTHORITY
            | APPL_URL_FLAG_ABSOLUTE
            | APPL_URL_FLAG_IPV6))
    {
        m_flags =
            i_flags;

        e_status =
            appl_status_ok;
    }
    else
    {
        e_status =
            appl_raise_invalid_param();
    }

    return
        e_status;

} // v_set_flags()

/* end-of-file: appl_url_std.cpp */
