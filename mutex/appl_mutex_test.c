/* See LICENSE for license details */

/*

*/

#include <appl.h>

#include <mutex/appl_mutex_test.h>

#include <stdio.h>

static
enum appl_status
    appl_mutex_test_sync_callback(
        void * const
            p_sync_context)
{
    (void)(
        p_sync_context);

    printf(
        "%s\n",
        "test mutex sync callback called");

    return
        appl_status_ok;
}

/*

*/
void
    appl_mutex_test_1(
        struct appl_context * const
            p_context)
{
    enum appl_status
        e_status;

    struct appl_mutex_descriptor
        o_mutex_descriptor;

    struct appl_mutex *
        p_mutex;

    e_status =
        appl_mutex_create(
            p_context,
            &(
                o_mutex_descriptor),
            (struct appl_mutex * *)(
                0));

    if (
        appl_status_ok
        == e_status)
    {
    }
    else
    {
    }

    e_status =
        appl_mutex_create(
            p_context,
            &(
                o_mutex_descriptor),
            &(
                p_mutex));

    if (
        appl_status_ok
        == e_status)
    {
        struct appl_object *
            p_object;

        struct appl_object const *
            pc_object;

        p_object =
            appl_mutex_parent(
                (struct appl_mutex *)(
                    0));

        p_object =
            appl_mutex_parent(
                p_mutex);

        (void)(
            p_object);

        pc_object =
            appl_mutex_const_parent(
                (struct appl_mutex *)(
                    0));

        pc_object =
            appl_mutex_const_parent(
                p_mutex);

        (void)(
            pc_object);

        e_status =
            appl_mutex_lock(
                (struct appl_mutex *)(
                    0));

        if (
            appl_status_ok
            == e_status)
        {
        }
        else
        {
        }

        e_status =
            appl_mutex_lock(
                p_mutex);

        if (
            appl_status_ok
            == e_status)
        {
            e_status =
                appl_mutex_unlock(
                    (struct appl_mutex *)(
                        0));

            if (
                appl_status_ok
                == e_status)
            {
            }

            e_status =
                appl_mutex_unlock(
                    p_mutex);

            if (
                appl_status_ok
                == e_status)
            {
            }
            else
            {
            }
        }

        e_status =
            appl_mutex_sync(
                (struct appl_mutex *)(
                    0),
                &(
                    appl_mutex_test_sync_callback),
                (void *)(
                    0));

        e_status =
            appl_mutex_sync(
                p_mutex,
                &(
                    appl_mutex_test_sync_callback),
                (void *)(
                    0));

        e_status =
            appl_mutex_destroy(
                (struct appl_mutex *)(
                    0));

        if (
            appl_status_ok
            == e_status)
        {
        }
        else
        {
        }

        e_status =
            appl_mutex_destroy(
                p_mutex);

        if (
            appl_status_ok
            == e_status)
        {
        }
        else
        {
        }
    }
    else
    {
    }

} /* appl_mutex_test_1() */

/* end-of-file: appl_mutex_test.c */
