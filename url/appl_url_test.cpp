/* See LICENSE for license details */

/*

*/

#include <url/appl_url_test.h>

#include <appl_status.h>

#include <appl_predefines.h>

#include <url/appl_url_types.h>

#include <url/appl_url_handle.h>

#include <buf/appl_buf.h>

#include <buf/appl_buf0.h>

#include <misc/appl_convert.h>

#include <misc/appl_unused.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <context/appl_context_handle.h>

#include <allocator/appl_allocator_handle.h>

#include <url/appl_url.h>

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
        printf("set flags\n");
#endif /* #if defined TEST_VERBOSE */

        e_status =
            appl_url_set_flags(
                p_url,
                APPL_URL_FLAG_ABSOLUTE);

        if (
            appl_status_ok
            == e_status)
        {
#if defined TEST_VERBOSE
            printf(" -> success\n");
#endif /* #if defined TEST_VERBOSE */
        }
        else
        {
#if defined TEST_VERBOSE
            printf(" -> fail\n");
#endif /* #if defined TEST_VERBOSE */
        }

        {
            unsigned long int
                i_flags;

#if defined TEST_VERBOSE
            printf("get flags\n");
#endif /* #if defined TEST_VERBOSE */

            e_status =
                appl_url_get_flags(
                    p_url,
                    &(
                        i_flags));

            if (
                appl_status_ok
                == e_status)
            {
#if defined TEST_VERBOSE
                printf(" -> success\n");
#endif /* #if defined TEST_VERBOSE */
            }
            else
            {
#if defined TEST_VERBOSE
                printf(" -> fail\n");
#endif /* #if defined TEST_VERBOSE */
            }
        }

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

#if defined TEST_VERBOSE
            printf("remove component:\n");
#endif /* #if defined TEST_VERBOSE */

            e_status =
                appl_url_remove_component(
                    p_url,
                    appl_url_component_type_scheme,
                    p_handle);

            if (
                appl_status_ok
                == e_status)
            {
#if defined TEST_VERBOSE
                printf(" -> success\n");
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
        appl_url_component_type_userinfo
        == e_component_type)
    {
        p_result0 =
            "userinfo";
    }
    else if (
        appl_url_component_type_host
        == e_component_type)
    {
        p_result0 =
            "host";
    }
    else if (
        appl_url_component_type_port
        == e_component_type)
    {
        p_result0 =
            "port";
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
        appl_url_component_type_userinfo);

    appl_url_test_service::s_dump_component(
        p_url,
        appl_url_component_type_host);

    appl_url_test_service::s_dump_component(
        p_url,
        appl_url_component_type_port);

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

            // Encode same url and compare
            unsigned long int
                i_length;

            e_status =
                appl_url_encoder_length(
                    p_url,
                    &(
                        i_length));

            if (
                appl_status_ok
                == e_status)
            {
                static unsigned char s_output[4096u];

                if (
                    i_length <= sizeof(s_output))
                {
                    unsigned long int
                        i_actual_length;

                    e_status =
                        appl_url_encoder(
                            p_url,
                            s_output,
                            s_output + sizeof(s_output),
                            &(
                                i_actual_length));

                    if (
                        appl_status_ok
                        == e_status)
                    {
                        printf("encode = {%.*s}\n",
                            appl_convert::to_signed(
                                appl_convert::to_uint(
                                    i_actual_length)),
                            appl_convert::to_char_ptr(
                                s_output));
                    }
                }
            }
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
        "ht%21tp://fel%21ix:bou%21cher@goo%21gle.ca:po%21rt/ma%21ps?q%21uery#f%211");

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
        "test");

    appl_url_test_service::s_decoder0(
        p_context,
        "test:");

    appl_url_test_service::s_decoder0(
        p_context,
        "test:it");

} // appl_url_test_1b()

static
void
appl_url_test_1c(
    struct appl_context * const
        p_context)
{
    struct appl_url *
        p_url_base;

    enum appl_status
        e_status;

    struct appl_allocator *
        p_allocator;

    p_allocator =
        appl_context_get_allocator(
            p_context);

    e_status =
        appl_new(
            p_allocator,
            &(
                p_url_base));

    if (
        appl_status_ok
        == e_status)
    {
        p_url_base->v_decoder(
            0,
            0,
            0);

        p_url_base->v_encoder_length(
            0);

        p_url_base->v_encoder(
            0,
            0,
            0);

        p_url_base->v_add_component(
            0,
            0,
            0,
            0);

        p_url_base->v_remove_component(
            0,
            0);

        p_url_base->v_get_component(
            0,
            0,
            0,
            0);

        p_url_base->v_next_component(
            0,
            0,
            0,
            0);

        p_url_base->v_get_flags(
            0);

        p_url_base->v_set_flags(
            0);

        appl_delete(
            p_allocator,
            p_url_base);
    }

} // appl_url_test_1c()

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

    appl_url_test_1c(
        p_context);

} // appl_url_test_1()

/* end-of-file: appl_url_test.cpp */
