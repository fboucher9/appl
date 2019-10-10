/* See LICENSE for license details */

/*

*/

#include <appl_predefines.h>

#include <chunk/appl_chunk_test.h>

#include <appl_status.h>

#include <chunk/appl_chunk_handle.h>

#include <appl_types.h>

#include <appl_object.h>

#include <chunk/appl_chunk.h>

#include <appl_heap_handle.h>

//
//
//
void
    appl_chunk_test_1(
        struct appl_context * const
            p_context)
{
    {
        struct appl_chunk *
            p_chunk_base;

        enum appl_status
            e_status;

        e_status =
            appl_new(
                p_context,
                &(
                    p_chunk_base));

        if (
            appl_status_ok
            == e_status)
        {
            p_chunk_base->v_write(
                0,
                0);

            p_chunk_base->v_length(
                0);

            p_chunk_base->v_read(
                0,
                0);

            p_chunk_base->v_reset();

            appl_delete(
                p_context,
                p_chunk_base);
        }
    }

    {
        enum appl_status
            e_status;

        struct appl_chunk *
            p_chunk;

        e_status =
            appl_chunk_create(
                p_context,
                &(
                    p_chunk));

        if (
            appl_status_ok
            == e_status)
        {
            // length
            {
                unsigned long int
                    i_length;

                e_status =
                    appl_chunk_length(
                        p_chunk,
                        &(
                            i_length));
            }

            // read
            {
                static unsigned char a_read[8u];

                e_status =
                    appl_chunk_read(
                        p_chunk,
                        a_read,
                        a_read + sizeof(a_read));
            }

            // write
            {
                static unsigned char const a_sample[8u] =
                {
                    1,
                    2,
                    3,
                    4,
                    5,
                    6,
                    7,
                    8
                };

                unsigned long int
                    i_count;

                i_count =
                    0ul;

                while (
                    i_count < 512ul)
                {
                    e_status =
                        appl_chunk_write(
                            p_chunk,
                            a_sample,
                            a_sample + sizeof(a_sample));

                    i_count += 8ul;
                }
            }

            // length
            {
                unsigned long int
                    i_length;

                e_status =
                    appl_chunk_length(
                        p_chunk,
                        &(
                            i_length));
            }

            // read
            {
                static unsigned char a_read[8u];

                e_status =
                    appl_chunk_read(
                        p_chunk,
                        a_read,
                        a_read + sizeof(a_read));
            }

            // reset
            appl_chunk_reset(
                p_chunk);

            appl_chunk_destroy(
                p_chunk);
        }
    }

} // appl_chunk_test_1()

/* end-of-file: appl_chunk_test.cpp */
