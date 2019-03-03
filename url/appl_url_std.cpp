/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <url/appl_url.h>

#include <appl_list.h>

#include <appl_url_types.h>

#include <url/appl_url_std.h>

#include <appl_context_handle.h>

#include <appl_allocator_handle.h>

#include <appl_heap_handle.h>

#include <appl_buf.h>

#include <appl_convert.h>

#include <appl_unused.h>

#include <url/appl_percent.h>

union write_context_ptr
{
    void *
        p_write_context;

    unsigned long int *
        p_length;

    struct appl_buf *
        p_buf;

};

//
//
//
static
void
    length_callback(
        void * const
            p_write_context,
        unsigned char const
            c_data)
{
    appl_unused(
        c_data);

    union write_context_ptr
        o_write_context_ptr;

    o_write_context_ptr.p_write_context =
        p_write_context;

    (*o_write_context_ptr.p_length) ++;

} // length_callback()

//
//
//
static
void
    convert_callback(
        void * const
            p_write_context,
        unsigned char const
            c_data)
{
    union write_context_ptr
        o_write_context_ptr;

    o_write_context_ptr.p_write_context =
        p_write_context;

    o_write_context_ptr.p_buf->o_min.p_uchar =
        appl_buf_write(
            o_write_context_ptr.p_buf->o_min.p_uchar,
            o_write_context_ptr.p_buf->o_max.p_uchar,
            c_data);

} // convert_callback()

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
    f_cleanup_all_component_lists();

    return
        sizeof(class appl_url_std);

} // v_cleanup()


//
//
//
void
    appl_url_std::f_cleanup_all_component_lists(void)
{
    signed short int
        i;

    for (
        i = appl_url_component_type_min;
        i < appl_url_component_type_max;
        i ++)
    {
        f_cleanup_component_list(
            i);
    }

} // f_cleanup_component_list()


//
//
//
void
appl_url_std::f_cleanup_component_list(
    signed short int const
        e_component_type)
{
    struct appl_list * const
        p_component_list =
        m_components + e_component_type;

    while (
        p_component_list->o_next.p_node
        != p_component_list)
    {
        union appl_url_component_ptr
            o_component_ptr;

        o_component_ptr.p_list =
            p_component_list->o_next.p_node;

        appl_url_std::v_remove_component(
            e_component_type,
            o_component_ptr.p_component);
    }

} // f_cleanup_component_list()


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

        if (
            b_continue)
        {
            o_component.o_max.pc_uchar =
                p_iterator->o_min.pc_uchar;
        }
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
    appl_url_std::f_set_component_buf(
        struct appl_url_component * const
            p_component,
        unsigned char const * const
            p_buf_min,
        unsigned char const * const
            p_buf_max)
{
    enum appl_status
        e_status;

    appl_size_t const
        i_old_len =
        appl_buf_len(
            p_component->p_buf_min,
            p_component->p_buf_max);

    appl_size_t const
        i_new_len =
        appl_buf_len(
            p_buf_min,
            p_buf_max);

    if (
        i_new_len)
    {
        union appl_buf_ptr
            o_placement;

        e_status =
            appl_heap_alloc(
                m_context,
                i_new_len,
                &(
                    o_placement.p_void));

        if (
            appl_status_ok
            == e_status)
        {
            appl_buf_copy(
                o_placement.p_uchar,
                o_placement.p_uchar + i_new_len,
                p_buf_min,
                p_buf_max);

            if (
                i_old_len)
            {
                appl_heap_free(
                    m_context,
                    i_old_len,
                    p_component->p_buf_min);

                p_component->p_buf_min =
                    0;

                p_component->p_buf_max =
                    0;
            }

            p_component->p_buf_min =
                o_placement.p_uchar;

            p_component->p_buf_max =
                o_placement.p_uchar + i_new_len;
        }
    }
    else
    {
        if (
            i_old_len)
        {
            appl_heap_free(
                m_context,
                i_old_len,
                p_component->p_buf_min);

            p_component->p_buf_min =
                0;

            p_component->p_buf_max =
                0;
        }

        e_status =
            appl_status_ok;
    }

    return
        e_status;

} // f_set_component_buf()

//
//
//
enum appl_status
    appl_url_std::f_decoder_pass_1(
        struct appl_buf * const
            p_input_iterator)
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

    c_sep_before =
        '\000';

    bool
        b_more_component;

    b_more_component =
        true;

    e_status =
        appl_status_ok;

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
                p_input_iterator,
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
                if (
                    (
                        o_component.o_min.pc_uchar
                        != o_component.o_max.pc_uchar)
                    || (
                        (
                            '/' == c_sep_before)
                        || (
                            '/' == c_sep_after)))
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

    return
        e_status;

} // f_decoder_pass_1()

//
//
//
void
    appl_url_std::f_detect_absolute_prefix(void)
{
    struct appl_url_component *
        p_component;

    unsigned char const *
        p_buf_min;

    unsigned char const *
        p_buf_max;

    if (
        (
            appl_status_ok
            == v_get_component(
                appl_url_component_type_path,
                &(
                    p_buf_min),
                &(
                    p_buf_max),
                &(
                    p_component)))
        && (
            p_buf_min
            == p_buf_max))
    {
        if (
            appl_status_ok
            == v_remove_component(
                appl_url_component_type_path,
                p_component))
        {
            m_flags |=
                APPL_URL_FLAG_ABSOLUTE;
        }
    }
}

//
//
//
void
    appl_url_std::f_detect_authority_prefix(void)
{
    if (
        APPL_URL_FLAG_ABSOLUTE
        & m_flags)
    {
        struct appl_url_component *
            p_component;

        unsigned char const *
            p_buf_min;

        unsigned char const *
            p_buf_max;

        if (
            (
                appl_status_ok
                == v_get_component(
                    appl_url_component_type_path,
                    &(
                        p_buf_min),
                    &(
                        p_buf_max),
                    &(
                        p_component)))
            && (
                p_buf_min
                == p_buf_max))
        {
            if (
                appl_status_ok
                == v_remove_component(
                    appl_url_component_type_path,
                    p_component))
            {
                m_flags |=
                    APPL_URL_FLAG_AUTHORITY;
            }
        }
    }

} // f_detect_authority_prefix()

//
//
//
void
    appl_url_std::f_detect_authority_fields(void)
{
    if (
        APPL_URL_FLAG_AUTHORITY
        & m_flags)
    {
        struct appl_url_component *
            p_component;

        unsigned char const *
            p_buf_min;

        unsigned char const *
            p_buf_max;

        // Decode of authority, to split into userinfo, host and port

        // get first path element
        if (
            appl_status_ok
            == v_get_component(
                appl_url_component_type_path,
                &(
                    p_buf_min),
                &(
                    p_buf_max),
                &(
                    p_component)))
        {
            // parse of element
            // look for @ symbol
            unsigned char const *
                p_buf_it;

            p_buf_it =
                p_buf_min;

            while (
                (
                    p_buf_it
                    < p_buf_max)
                && (
                    '@'
                    != *(p_buf_it)))
            {
                p_buf_it ++;
            }

            unsigned char const *
                p_hostinfo_min;

            unsigned char const *
                p_hostinfo_max;

            if (
                (
                    p_buf_it
                    < p_buf_max)
                && (
                    '@'
                    == *(p_buf_it)))
            {
                // Decode of userinfo
                unsigned char const *
                    p_userinfo_it;

                unsigned char const *
                    p_section_min;

                unsigned char const *
                    p_section_max;

                p_userinfo_it =
                    p_buf_min;

                p_section_min =
                    p_buf_min;

                p_section_max =
                    p_buf_min;

                while (
                    p_userinfo_it
                    < p_buf_it)
                {
                    if (
                        ':'
                        == *p_userinfo_it)
                    {
                        struct appl_url_component *
                            p_userinfo_component;

                        v_add_component(
                            appl_url_component_type_userinfo,
                            p_section_min,
                            p_section_max,
                            &(
                                p_userinfo_component));

                        p_userinfo_it ++;

                        p_section_min =
                            p_userinfo_it;

                        p_section_max =
                            p_userinfo_it;
                    }
                    else
                    {
                        p_userinfo_it ++;

                        p_section_max =
                            p_userinfo_it;
                    }
                }

                {
                    struct appl_url_component *
                        p_userinfo_component;

                    v_add_component(
                        appl_url_component_type_userinfo,
                        p_section_min,
                        p_section_max,
                        &(
                            p_userinfo_component));
                }

                // Skip '@' symbol
                p_buf_it ++;

                // Find hostinfo
                p_hostinfo_min =
                    p_buf_it;

                p_hostinfo_max =
                    p_buf_max;
            }
            else
            {
                // Find hostinfo
                p_hostinfo_min =
                    p_buf_min;

                p_hostinfo_max =
                    p_buf_max;
            }

            unsigned char const *
                p_hostinfo_it;

            p_hostinfo_it =
                p_hostinfo_min;

            while (
                (
                    p_hostinfo_it
                    < p_hostinfo_max)
                && (
                    ':'
                    != *p_hostinfo_it))
            {
                p_hostinfo_it ++;
            }

            // Add host info
            {
                struct appl_url_component *
                    p_host_component;

                v_add_component(
                    appl_url_component_type_host,
                    p_hostinfo_min,
                    p_hostinfo_it,
                    &(
                        p_host_component));
            }

            // Add port info
            if (
                (
                    p_hostinfo_it
                    < p_hostinfo_max)
                && (
                    ':'
                    == *p_hostinfo_it))
            {
                p_hostinfo_it ++;

                struct appl_url_component *
                    p_port_component;

                v_add_component(
                    appl_url_component_type_port,
                    p_hostinfo_it,
                    p_hostinfo_max,
                    &(
                        p_port_component));
            }

            // remove it
            v_remove_component(
                appl_url_component_type_path,
                p_component);
        }
    }

} // f_detect_authority_fields()

//
//
//
void
    appl_url_std::f_decoder_pass_2(void)
{
    // Post processing...
    // Detect leading empty paths
    // Clear all flags
    m_flags =
        0;

    f_detect_absolute_prefix();

    f_detect_authority_prefix();

    f_detect_authority_fields();

} // f_decoder_pass_2()

//
//
//
void
    appl_url_std::f_percent_decode_component(
        struct appl_url_component * const
            p_component)
{
    struct appl_buf
        o_input_buf;

    o_input_buf.o_min.p_uchar =
        p_component->p_buf_min;

    o_input_buf.o_max.p_uchar =
        p_component->p_buf_max;

    unsigned long int
        i_length;

    i_length =
        appl_percent_decoder_length(
            &(
                o_input_buf));

    if (
        i_length)
    {
        union appl_buf_ptr
            o_placement;

        if (
            appl_status_ok
            == appl_heap_alloc(
                m_context,
                i_length,
                &(
                    o_placement.p_void)))
        {
            struct appl_buf
                o_output_buf;

            o_output_buf.o_min.p_uchar =
                o_placement.p_uchar;

            o_output_buf.o_max.p_uchar =
                o_placement.p_uchar
                + i_length;

            appl_percent_decoder_convert(
                &(
                    o_input_buf),
                &(
                    o_output_buf));

            // Replace component buffer
            f_set_component_buf(
                p_component,
                o_placement.pc_uchar,
                o_output_buf.o_min.pc_uchar);

            appl_heap_free(
                m_context,
                i_length,
                o_placement.p_void);
        }
    }

} // f_percent_decode_component()

//
//
//
void
    appl_url_std::f_percent_decode_component_list(
        enum appl_url_component_type const
            e_component_type)
{
    struct appl_list *
        p_component_list;

    p_component_list =
        m_components + e_component_type;

    union appl_url_component_ptr
        o_url_component_ptr;

    o_url_component_ptr.p_list =
        p_component_list->o_next.p_node;

    while (
        o_url_component_ptr.p_list
        != p_component_list)
    {
        f_percent_decode_component(
            o_url_component_ptr.p_component);

        o_url_component_ptr.p_list =
            o_url_component_ptr.p_list->o_next.p_node;
    }

} // f_percent_decode_component_list()

//
//
//
void
    appl_url_std::f_decoder_pass_3(void)
{
    // Do percent decode of each segment
    f_percent_decode_component_list(
        appl_url_component_type_scheme);

    f_percent_decode_component_list(
        appl_url_component_type_userinfo);

    f_percent_decode_component_list(
        appl_url_component_type_host);

    f_percent_decode_component_list(
        appl_url_component_type_port);

    f_percent_decode_component_list(
        appl_url_component_type_path);

    // Do not decode query

    // Do not decode fragment

} // f_decoder_pass_3()

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
    enum appl_status
        e_status;

    struct appl_buf
        o_input_iterator;

    o_input_iterator.o_min.pc_uchar =
        p_input_min;

    o_input_iterator.o_max.pc_uchar =
        p_input_max;

    e_status =
        f_decoder_pass_1(
            &(
                o_input_iterator));

    if (
        appl_status_ok
        == e_status)
    {
        f_decoder_pass_2();

        f_decoder_pass_3();

        *(
            r_input_count) =
            appl_buf_len(
                p_input_min,
                o_input_iterator.o_min.pc_uchar);
    }

    return
        e_status;

} // v_decoder()

//
//
//
void
    appl_url_std::f_encoder_add_component(
        struct appl_url_component const * const
            p_component,
        bool const
            b_apply_percent,
        void (* const p_write_callback)(
            void * const
                p_write_context,
            unsigned char const
                c_data),
        void * const
            p_write_context) const
{
    unsigned char const *
        p_buf_it;

    appl_unused(
        b_apply_percent);

    p_buf_it =
        p_component->p_buf_min;

    while (
        p_buf_it
        < p_component->p_buf_max)
    {
        unsigned char const
            c_data =
            *(
                p_buf_it);

        (*p_write_callback)(
            p_write_context,
            c_data);

        p_buf_it ++;
    }

} // f_encoder_add_component()

//
//
//
void
    appl_url_std::f_encoder_run(
        void (* const p_write_callback)(
            void * const
                p_write_context,
            unsigned char const
                c_data),
        void * const
            p_write_context) const
{
    union appl_url_component_ptr
        o_url_component_ptr;

    // Do scheme
    {
        struct appl_list const * const
            p_component_list =
            m_components + appl_url_component_type_scheme;

        o_url_component_ptr.p_list =
            p_component_list->o_next.p_node;

        if (
            o_url_component_ptr.p_list
            != p_component_list)
        {
            f_encoder_add_component(
                o_url_component_ptr.p_component,
                false,
                p_write_callback,
                p_write_context);

            (*p_write_callback)(
                p_write_context,
                ':');
        }
    }

    // Path
    {
        // Authority
        if (
            APPL_URL_FLAG_AUTHORITY
            & m_flags)
        {
            (*p_write_callback)(
                p_write_context,
                '/');

            (*p_write_callback)(
                p_write_context,
                '/');
        }
        // Absolute
        else if (
            APPL_URL_FLAG_ABSOLUTE
            & m_flags)
        {
            (*p_write_callback)(
                p_write_context,
                '/');
        }

        struct appl_list const * const
            p_component_list =
            m_components + appl_url_component_type_path;

        o_url_component_ptr.p_list =
            p_component_list->o_next.p_node;

        while (
            o_url_component_ptr.p_list
            != p_component_list)
        {
            f_encoder_add_component(
                o_url_component_ptr.p_component,
                false,
                p_write_callback,
                p_write_context);

            o_url_component_ptr.p_list =
                o_url_component_ptr.p_list->o_next.p_node;

            if (
                o_url_component_ptr.p_list
                != p_component_list)
            {
                (*p_write_callback)(
                    p_write_context,
                    '/');
            }
        }
    }

    // Query
    {
        struct appl_list const * const
            p_component_list =
            m_components + appl_url_component_type_query;

        o_url_component_ptr.p_list =
            p_component_list->o_next.p_node;

        if (
            o_url_component_ptr.p_list
            != p_component_list)
        {
            (*p_write_callback)(
                p_write_context,
                '?');

            f_encoder_add_component(
                o_url_component_ptr.p_component,
                false,
                p_write_callback,
                p_write_context);
        }
    }

    // Fragment
    {
        struct appl_list const * const
            p_component_list =
            m_components + appl_url_component_type_fragment;

        o_url_component_ptr.p_list =
            p_component_list->o_next.p_node;

        if (
            o_url_component_ptr.p_list
            != p_component_list)
        {
            (*p_write_callback)(
                p_write_context,
                '#');

            f_encoder_add_component(
                o_url_component_ptr.p_component,
                false,
                p_write_callback,
                p_write_context);
        }
    }
}

//
//
//
enum appl_status
    appl_url_std::v_encoder_length(
        unsigned long int * const
            r_output_count) const
{
    enum appl_status
        e_status;

    unsigned long int
        i_length;

    i_length =
        0ul;

    f_encoder_run(
        &(
            length_callback),
        &(
            i_length));

    *(
        r_output_count) =
        i_length;

    e_status =
        appl_status_ok;

    return
        e_status;

} // v_encoder_length()

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
    struct appl_buf
        o_output_buf;

    o_output_buf.o_min.p_uchar =
        p_output_min;

    o_output_buf.o_max.p_uchar =
        p_output_max;

    f_encoder_run(
        &(
            convert_callback),
        &(
            o_output_buf));

    *(
        r_output_count) =
        appl_buf_len(
            p_output_min,
            o_output_buf.o_min.pc_uchar);

    return
        appl_status_ok;

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
        (e_component_type > appl_url_component_type_min)
        && (e_component_type < appl_url_component_type_max))
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

            p_component->p_buf_max =
                0;

            e_status =
                f_set_component_buf(
                    p_component,
                    p_buf_min,
                    p_buf_max);

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
        (e_component_type > appl_url_component_type_min)
        && (e_component_type < appl_url_component_type_max))
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
        (e_component_type > appl_url_component_type_min)
        && (e_component_type < appl_url_component_type_max))
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
        (e_component_type > appl_url_component_type_min)
        && (e_component_type < appl_url_component_type_max))
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
