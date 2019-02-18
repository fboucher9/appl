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

#include <appl_convert.h>

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
    // Free all components
    unsigned int
        i;

    union appl_url_component_ptr
        o_component_ptr;

    struct appl_context * const
        p_context =
        get_context();

    struct appl_allocator * const
        p_allocator =
        appl_context_get_allocator(
            p_context);

    for (
        i=0u;
        i<8u;
        i++)
    {
        while (
            m_components[i].o_next.p_node
            != (m_components + i))
        {
            o_component_ptr.p_list =
                m_components[i].o_next.p_node;

            appl_list_join(
                o_component_ptr.p_list,
                o_component_ptr.p_list);

            appl_size_t const
                i_buf_len =
                appl_buf_len(
                    o_component_ptr.p_component->p_buf_min,
                    o_component_ptr.p_component->p_buf_max);

            if (
                i_buf_len)
            {
                appl_heap_free(
                    p_context,
                    i_buf_len,
                    o_component_ptr.p_component->p_buf_min);
            }

            o_component_ptr.p_component->p_buf_min =
                0;

            o_component_ptr.p_component->p_buf_max =
                0;

            appl_allocator_free_structure(
                p_allocator,
                o_component_ptr.p_component);
        }
    }

    return
        sizeof(class appl_url_std);

} // v_cleanup()

//
//
//
static
enum appl_status
s_find_component(
    struct appl_buf * const
        p_iterator,
    struct appl_buf const * const
        p_filter,
    unsigned char * const
        r_sep,
    struct appl_buf * const
        r_component)
{
    enum appl_status
        e_status;

    struct appl_buf
        o_component;

    unsigned char
        c_sep;

    o_component.o_min.pc_uchar =
        p_iterator->o_min.pc_uchar;

    o_component.o_max.pc_uchar =
        p_iterator->o_min.pc_uchar;

    c_sep =
        '\000';

    bool
        b_continue;

    b_continue =
        true;

    while (
        b_continue
        && (
            p_iterator->o_min.pc_uchar
            != p_iterator->o_max.pc_uchar))
    {
        unsigned char const
            c_data =
            *(
                p_iterator->o_min.pc_uchar);

        o_component.o_max.pc_uchar =
            p_iterator->o_min.pc_uchar;

        p_iterator->o_min.pc_uchar ++;

        unsigned char const *
            p_filter_it;

        p_filter_it =
            p_filter->o_min.pc_uchar;

        while (
            b_continue
            && (
                p_filter_it
                != p_filter->o_max.pc_uchar))
        {
            if (
                c_data
                == *(
                    p_filter_it))
            {
                c_sep =
                    *(
                        p_filter_it);

                b_continue =
                    false;
            }
            else
            {
                p_filter_it ++;
            }
        }
    }

    if (
        b_continue)
    {
        o_component.o_max.pc_uchar =
            p_iterator->o_min.pc_uchar;
    }

    *(
        r_component) =
        o_component;

    *(
        r_sep) =
        c_sep;

    e_status =
        appl_status_ok;

    return
        e_status;

} // s_find_component()

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
    static unsigned char const a_scheme_filter[] =
    {
        ':',
        '/',
        '?',
        '#'
    };

    static unsigned char const a_path_filter[] =
    {
        '/',
        '?',
        '#'
    };

    static unsigned char const a_query_filter[] =
    {
        '#'
    };

    enum appl_status
        e_status;

    unsigned char
        c_sep_before;

    unsigned char
        c_sep_after;

    struct appl_buf
        o_input_iterator;

    o_input_iterator.o_min.pc_uchar =
        p_input_min;

    o_input_iterator.o_max.pc_uchar =
        p_input_max;

    c_sep_before =
        '\000';

    bool
        b_more_component;

    b_more_component =
        true;

    while (
        (
            appl_status_ok
            == e_status)
        && b_more_component)
    {
        struct appl_buf
            o_filter;

        if (
            '\000'
            == c_sep_before)
        {
            o_filter.o_min.pc_uchar =
                a_scheme_filter;

            o_filter.o_max.pc_uchar =
                a_scheme_filter + sizeof(a_scheme_filter);
        }
        else if (
            (
                ':'
                == c_sep_before)
            || (
                '/'
                == c_sep_before))
        {
            o_filter.o_min.pc_uchar =
                a_path_filter;

            o_filter.o_max.pc_uchar =
                a_path_filter + sizeof(a_path_filter);
        }
        else if (
            '?'
            == c_sep_before)
        {
            o_filter.o_min.pc_uchar =
                a_query_filter;

            o_filter.o_max.pc_uchar =
                a_query_filter + sizeof(a_query_filter);
        }
        else if (
            '#'
            == c_sep_before)
        {
            o_filter.o_min.pc_uchar =
                0;

            o_filter.o_max.pc_uchar =
                0;
        }
        else
        {
            o_filter.o_min.pc_uchar =
                0;

            o_filter.o_max.pc_uchar =
                0;
        }

        struct appl_buf
            o_component;

        c_sep_after =
            '\000';

        e_status =
            s_find_component(
                &(
                    o_input_iterator),
                &(
                    o_filter),
                &(
                    c_sep_after),
                &(
                    o_component));

        if (
            appl_status_ok
            == e_status)
        {
            if (
                (
                    '\000'
                    == c_sep_before)
                && (
                    ':'
                    == c_sep_after))
            {
                struct appl_url_component *
                    p_scheme_component;

                // Store this component as scheme
                e_status =
                    v_add_component(
                        appl_url_component_type_scheme,
                        o_component.o_min.pc_uchar,
                        o_component.o_max.pc_uchar,
                        &(
                            p_scheme_component));
            }
            else if (
                (
                    '\000'
                    == c_sep_before)
                || (
                    ':'
                    == c_sep_before)
                || (
                    '/'
                    == c_sep_before))
            {
                struct appl_url_component *
                    p_path_component;

                // Store this as path
                e_status =
                    v_add_component(
                        appl_url_component_type_path,
                        o_component.o_min.pc_uchar,
                        o_component.o_max.pc_uchar,
                        &(
                            p_path_component));
            }
            else if (
                '?'
                == c_sep_before)
            {
                struct appl_url_component *
                    p_query_component;

                // Query
                e_status =
                    v_add_component(
                        appl_url_component_type_query,
                        o_component.o_min.pc_uchar,
                        o_component.o_max.pc_uchar,
                        &(
                            p_query_component));
            }
            else if (
                '#'
                == c_sep_before)
            {
                struct appl_url_component *
                    p_fragment_component;

                // Store rest as fragment
                e_status =
                    v_add_component(
                        appl_url_component_type_fragment,
                        o_component.o_min.pc_uchar,
                        o_component.o_max.pc_uchar,
                        &(
                            p_fragment_component));
            }
            else
            {
                // What to do?
                b_more_component =
                    false;
            }

            if (
                '\000'
                != c_sep_after)
            {
                c_sep_before =
                    c_sep_after;
            }
            else
            {
                b_more_component =
                    false;
            }
        }
    }

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_input_count) =
            appl_convert::to_ulong(
                o_input_iterator.o_min.pc_uchar
                - p_input_min);
    }

    return
        e_status;

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
        struct appl_url_component * * const
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
        struct appl_url_component * const
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
        struct appl_url_component * * const
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
                p_component;

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
        struct appl_url_component * * const
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

        o_component_ptr.p_component =
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
                p_component;

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
