/* See LICENSE for license details */

/*

*/

#include <url/appl_url_test.h>

#include <appl_status.h>

#include <appl_url_types.h>

#include <appl_url_handle.h>

#include <appl_buf.h>

#include <appl_unused.h>

#include <stdio.h>

#define TEST_VERBOSE

//
//
//
void
    appl_url_test_1(
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

} // appl_url_test_1()

/* end-of-file: appl_url_test.cpp */
