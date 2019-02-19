/* See LICENSE for license details */

/*

*/

#include <url/appl_url_test.h>

#include <appl_status.h>

#include <appl_url_types.h>

#include <appl_url_handle.h>

#include <appl_buf.h>

#include <appl_buf0.h>

#include <appl_convert.h>

#include <appl_unused.h>

#include <stdio.h>

#define TEST_VERBOSE

static
void
appl_url_test_1a(
    struct appl_context * const
        p_context)
{
    enum appl_status
        e_status;

    struct appl_url *
        p_url;

#if defined TEST_VERBOSE
    printf("url test enter\n");
#endif /* #if defined TEST_VERBOSE */

#if defined TEST_VERBOSE
    printf("url create:\n");
#endif /* #if defined TEST_VERBOSE */

    e_status =
        appl_url_create(
            p_context,
            &(
                p_url));

    if (
        appl_status_ok
        == e_status)
    {
        static unsigned char const g_ref_rtsp[] =
        {
            'r',
            't',
            's',
            'p'
        };

        struct appl_url_component *
            p_handle;

#if defined TEST_VERBOSE
        printf(" -> success\n");
#endif /* #if defined TEST_VERBOSE */

#if defined TEST_VERBOSE
        printf("add component: rtsp\n");
#endif /* #if defined TEST_VERBOSE */

        e_status =
            appl_url_add_component(
                p_url,
                appl_url_component_type_scheme,
                g_ref_rtsp,
                g_ref_rtsp + sizeof(g_ref_rtsp),
                &(
                    p_handle));

        if (
            appl_status_ok
            == e_status)
        {
            unsigned char const *
                p_buf_min;

            unsigned char const *
                p_buf_max;

#if defined TEST_VERBOSE
            printf(" -> success\n");
            printf(" -> handle = %p\n",
                static_cast<void *>(
                    p_handle));
            printf("get component:\n");
#endif /* #if defined TEST_VERBOSE */

            e_status =
                appl_url_get_component(
                    p_url,
                    appl_url_component_type_scheme,
                    &(
                        p_buf_min),
                    &(
                        p_buf_max),
                    &(
                        p_handle));

            if (
                appl_status_ok
                == e_status)
            {
#if defined TEST_VERBOSE
                printf(" -> success\n");
                printf(" -> handle = %p\n",
                    static_cast<void *>(
                        p_handle));
                printf(" -> buf = [%.*s]\n",
                    static_cast<int>(
                        appl_buf_len(
                            p_buf_min,
                            p_buf_max)),
                    reinterpret_cast<char const *>(
                        p_buf_min));
#endif /* #if defined TEST_VERBOSE */
            }
            else
            {
#if defined TEST_VERBOSE
                printf(" -> fail\n");
#endif /* #if defined TEST_VERBOSE */
            }
        }
        else
        {
#if defined TEST_VERBOSE
            printf(" -> fail\n");
#endif /* #if defined TEST_VERBOSE */
        }

        appl_url_destroy(
            p_url);
    }
    else
    {
#if defined TEST_VERBOSE
        printf(" -> fail\n");
#endif /* #if defined TEST_VERBOSE */
    }
} // appl_url_test_1a()


//
//
//
class appl_url_test_service
{
    public:

        static
        char const *
            s_type_to_string(
                signed short int const
                    e_component_type);

        static
        void
            s_dump_component(
                struct appl_url const * const
                    p_url,
                signed short int const
                    e_component_type);

        static
        void
            s_dump_all(
                struct appl_url const * const
                    p_url);

        static
        void
            s_decoder(
                struct appl_context * const
                    p_context,
                unsigned char const * const
                    p_text_min,
                unsigned char const * const
                    p_text_max);

        static
        void
            s_decoder0(
                struct appl_context * const
                    p_context,
                char const * const
                    p_text0);

}; // class appl_url_test_service


//
//
//
char const *
    appl_url_test_service::s_type_to_string(
        signed short int const
            e_component_type)
{
    char const *
        p_result0;

    if (
        appl_url_component_type_scheme
        == e_component_type)
    {
        p_result0 =
            "scheme";
    }
    else if (
        appl_url_component_type_path
        == e_component_type)
    {
        p_result0 =
            "path";
    }
    else if (
        appl_url_component_type_query
        == e_component_type)
    {
        p_result0 =
            "query";
    }
    else if (
        appl_url_component_type_fragment
        == e_component_type)
    {
        p_result0 =
            "fragment";
    }
    else
    {
        p_result0 =
            "unknown";
    }

    return
        p_result0;

} // s_type_to_string()


//
//
//
void
    appl_url_test_service::s_dump_component(
        struct appl_url const * const
            p_url,
        signed short int const
            e_component_type)
{
    enum appl_status
        e_status;

    unsigned char const *
        p_buf_min;

    unsigned char const *
        p_buf_max;

    struct appl_url_component *
        p_component;

    e_status =
        appl_url_get_component(
            p_url,
            e_component_type,
            &(
                p_buf_min),
            &(
                p_buf_max),
            &(
                p_component));

    while (
        appl_status_ok
        == e_status)
    {
        printf(
            "%-40s: [%.*s]\n",
            appl_url_test_service::s_type_to_string(
                e_component_type),
            static_cast<int>(
                p_buf_max
                - p_buf_min),
            reinterpret_cast<char const *>(
                p_buf_min));

        e_status =
            appl_url_next_component(
                p_url,
                e_component_type,
                &(
                    p_buf_min),
                &(
                    p_buf_max),
                &(
                    p_component));
    }

} // s_dump_component()


//
//
//
void
    appl_url_test_service::s_dump_all(
        struct appl_url const * const
            p_url)
{
    unsigned long int
        i_flags;

    if (
        appl_status_ok
        == appl_url_get_flags(
            p_url,
            &(
                i_flags)))
    {
        printf("%-40s: %lu\n",
            "flags",
            i_flags);
    }

    appl_url_test_service::s_dump_component(
        p_url,
        appl_url_component_type_scheme);

    appl_url_test_service::s_dump_component(
        p_url,
        appl_url_component_type_path);

    appl_url_test_service::s_dump_component(
        p_url,
        appl_url_component_type_query);

    appl_url_test_service::s_dump_component(
        p_url,
        appl_url_component_type_fragment);

} // s_dump_all()


//
//
//
void
    appl_url_test_service::s_decoder(
        struct appl_context * const
            p_context,
        unsigned char const * const
            p_text_min,
        unsigned char const * const
            p_text_max)
{
    enum appl_status
        e_status;

    struct appl_url *
        p_url;

    // Try decode and query
    e_status =
        appl_url_create(
            p_context,
            &(
                p_url));

    if (
        appl_status_ok
        == e_status)
    {
        unsigned long int
            i_count;

        e_status =
            appl_url_decoder(
                p_url,
                p_text_min,
                p_text_max,
                &(
                    i_count));

        if (
            appl_status_ok
            == e_status)
        {
            appl_url_test_service::s_dump_all(
                p_url);

        }

        appl_url_destroy(
            p_url);
    }
} // s_decoder()


//
//
//
void
    appl_url_test_service::s_decoder0(
        struct appl_context * const
            p_context,
        char const * const
            p_text0)
{
    unsigned char const * const
        p_text_min =
        appl_convert::to_uchar_ptr(
            p_text0);

    unsigned char const * const
        p_text_max =
        p_text_min
        + appl_buf0_len(
            p_text_min);

    printf(" *** decode of url (%s) ...\n",
        p_text0);

    appl_url_test_service::s_decoder(
        p_context,
        p_text_min,
        p_text_max);

    printf(" ... end\n");

} // s_decoder0()


//
//
//
static
void
    appl_url_test_1b(
        struct appl_context * const
            p_context)
{
    appl_url_test_service::s_decoder0(
        p_context,
        "http://google.ca/maps?q#f1");

    appl_url_test_service::s_decoder0(
        p_context,
        "/usr/bin");

    appl_url_test_service::s_decoder0(
        p_context,
        ":///?#");

    appl_url_test_service::s_decoder0(
        p_context,
        "rel/ati/vep/ath");

    appl_url_test_service::s_decoder0(
        p_context,
        "test:");

    appl_url_test_service::s_decoder0(
        p_context,
        "test:it");

} // appl_url_test_1b()

//
//
//
void
    appl_url_test_1(
        struct appl_context * const
            p_context)
{
    appl_url_test_1a(
        p_context);

    appl_url_test_1b(
        p_context);

} // appl_url_test_1()

/* end-of-file: appl_url_test.cpp */
