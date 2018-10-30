/* See LICENSE for license details */

/*

*/

#include <appl.h>

void
appl_thread_cache_test(
    struct appl_context * const
        p_context);

struct test_thread_cache_data
{
    struct appl_context *
        p_context;

    struct appl_thread_cache *
        p_thread_cache;

};

/*

*/
static
void
test_thread_cache_entry(
    void * const
        p_thread_context)
{
    struct test_thread_cache_data *
        p_data;

    p_data =
        (struct test_thread_cache_data *)(
            p_thread_context);

    appl_clock_delay(
        p_data->p_context,
        1000ul,
        1000ul);

    appl_object_destroy(
        appl_thread_parent(
            appl_thread_cache_parent(
                p_data->p_thread_cache)));

} /* test_thread_cache_entry() */

/*

*/
void
appl_thread_cache_test(
    struct appl_context * const
        p_context)
{
    enum appl_status
        e_status;

    struct appl_thread_property *
        p_thread_property;

    struct appl_thread_descriptor
        o_thread_descriptor;

    static struct test_thread_cache_data
        o_test_data;

    o_test_data.p_context =
        p_context;

    o_test_data.p_thread_cache =
        0;

    o_thread_descriptor.p_entry =
        &(
            test_thread_cache_entry);

    o_thread_descriptor.p_context =
        &(
            o_test_data);

    e_status =
        appl_thread_property_create(
            p_context,
            &(
                p_thread_property));

    if (
        appl_status_ok
        == e_status)
    {
        e_status =
            appl_thread_cache_create(
                p_context,
                p_thread_property,
                &(
                    o_thread_descriptor),
                &(
                    o_test_data.p_thread_cache));

        if (
            appl_status_ok
            == e_status)
        {
        }

        appl_object_destroy(
            appl_property_parent(
                appl_thread_property_parent(
                    p_thread_property)));
    }

} /* appl_thread_cache_test() */

/* end-of-file: appl_thread_cache_test.c */
