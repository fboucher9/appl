/* See LICENSE for license details */

/*

*/

#include <appl.h>

#include <random/appl_random_test.h>

#include <random/appl_random.h>

#include <random/appl_random_mgr.h>

#include <stdio.h>

void
appl_random_test_1(
    struct appl_context * const
        p_context)
{
    enum appl_status
        e_status;

    struct appl_random_descriptor
        o_random1_descriptor;

    struct appl_random_descriptor
        o_random2_descriptor;

    struct appl_random *
        p_random1;

    struct appl_random *
        p_random2;

    o_random1_descriptor.e_type =
        appl_random_type_crypto;

    o_random1_descriptor.i_seed =
        12345ul;

    e_status =
        appl_random_create(
            p_context,
            &(
                o_random1_descriptor),
            &(
                p_random1));

    if (
        appl_status_ok
        == e_status)
    {
        unsigned long int
            i_value;

        appl_random_parent(
            p_random1);

        appl_random_const_parent(
            p_random1);

        e_status =
            appl_random_pick(
                p_random1,
                1000ul * 1000ul * 1000ul,
                &(
                    i_value));

        if (
            appl_status_ok
            == e_status)
        {
            printf("random: seed=[%ld]\n", (signed long int)(i_value));

            o_random2_descriptor.e_type =
                appl_random_type_pseudo;

            o_random2_descriptor.i_seed =
                i_value;

            e_status =
                appl_random_create(
                    p_context,
                    &(
                        o_random2_descriptor),
                    &(
                        p_random2));

            if (
                appl_status_ok
                == e_status)
            {
                e_status =
                    appl_random_pick(
                        p_random2,
                        20,
                        &(
                            i_value));

                if (
                    appl_status_ok
                    == e_status)
                {
                    printf("random: value=[%ld/20]\n",
                        (signed long int)(i_value));

#if 1
                    /* Do a verification of randomness */
                    {
                        unsigned long int
                            i;

                        unsigned long int
                            t;

                        signed long int
                            a_count[31u];

                        for (i=0; i<31u; i++)
                        {
                            a_count[i] = 0l;
                        }

                        for (t=0; t<0x1000; t++)
                        {
                            appl_random_pick(
                                p_random2,
                                0,
                                &(
                                    i_value));

                            for (i=0; i<31u; i++)
                            {
                                if ((i_value >> i) & 1ul)
                                {
                                    a_count[i] ++;
                                }
                                else
                                {
                                    a_count[i] --;
                                }
                            }
                        }

                        for (i=0; i<31u; i++)
                        {
                            printf("random: bit count %ld = %ld\n",
                                (signed long int)(i),
                                (signed long int)(a_count[i]));
                        }
                    }
#endif

#if 1
                    /* Fairness of picks */
                    {
                        unsigned long int
                            i;

                        unsigned long int
                            t;

                        unsigned long int
                            a_count[6u];

                        for (i=0; i<6u; i++)
                        {
                            a_count[i] = 0ul;
                        }

                        for (t=0; t<0x1000; t++)
                        {
                            appl_random_pick(
                                p_random2,
                                6ul,
                                &(
                                    i_value));

                            a_count[i_value] ++;
                        }

                        for (i=0; i<6u; i++)
                        {
                            printf("random: face count %ld = %ld\n",
                                (signed long int)(i),
                                (signed long int)(a_count[i]));
                        }
                    }
#endif
                }
                else
                {
                    printf("failed appl_random_pick(2)\n");
                }

                appl_random_destroy(
                    p_random2);
            }
            else
            {
                printf("failed appl_random_create(2)\n");
            }
        }
        else
        {
            printf("failed appl_random_pick(1)\n");
        }

        appl_random_destroy(
            p_random1);
    }
    else
    {
        printf("failed appl_random_create(1)\n");
    }

    // check coverage of base manager
    {
        class appl_random_mgr *
            p_random_mgr;

        e_status =
            appl_new(
                p_context,
                &(
                    p_random_mgr));

        if (
            appl_status_ok
            == e_status)
        {
            p_random_mgr->v_create_node(
                0,
                0);

            p_random_mgr->v_destroy_node(
                0);


            appl_delete(
                p_context,
                p_random_mgr);
        }
    }

    // check coverage of base node
    {
        struct appl_random *
            p_random;

        e_status =
            appl_new(
                p_context,
                &(
                    p_random));

        if (
            appl_status_ok
            == e_status)
        {
            p_random->v_pick(
                0,
                0);

            appl_delete(
                p_context,
                p_random);
        }
    }

} /* appl_test_random() */

/* end-of-file: appl_random_test.c */
