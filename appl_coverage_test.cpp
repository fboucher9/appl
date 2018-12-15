/* See LICENSE for license details */

/*

*/

#include <appl_coverage_test.h>

//
//
//
class appl_coverage_service
{
    public:

        static
        unsigned long int
            s_test(
                unsigned long int (* const p_callback)(
                    void * const
                        p_context,
                    unsigned long int const
                        i_iterator),
                void * const
                    p_context);

}; // class appl_coverage_service

//
//
//
unsigned long int
    appl_coverage_service::s_test(
        unsigned long int (* const p_callback)(
            void * const
                p_context,
            unsigned long int const
                i_iterator),
        void * const
            p_context)
{
    unsigned long int
        i_iterator;

    unsigned long int
        i_count_max;

    i_iterator =
        0ul;

    i_count_max =
        0ul;

    do
    {
        unsigned long int
            i_count;

        i_count =
            (* p_callback)(
                p_context,
                i_iterator);

        if (
            i_count_max < i_count)
        {
            i_count_max = i_count;
        }

        i_iterator ++;
    }
    while (
        i_iterator <= i_count_max)
        ;

    return
        i_count_max;

} // s_test()

/*

*/
unsigned long int
    appl_coverage_test(
        unsigned long int (* const p_callback)(
            void * const
                p_context,
            unsigned long int const
                i_iterator),
        void * const
            p_context)
{
    return
        appl_coverage_service::s_test(
            p_callback,
            p_context);

} /* appl_coverage_test() */

/* end-of-file: appl_coverage_test.cpp */
