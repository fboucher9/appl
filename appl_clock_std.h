/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_CLOCK_STD_H
#error include appl_clock_std.h once
#endif /* #if defined INC_APPL_CLOCK_STD_H */

#define INC_APPL_CLOCK_STD_H

/* Header file dependency */
#if ! defined INC_APPL_CLOCK_H
#error include appl_clock.h before
#endif /* #if ! defined INC_APPL_CLOCK_H */

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

/* Assert OS */
#if ! defined APPL_OS_LINUX
#error must define APPL_OS_LINUX
#endif /* #if ! defined APPL_OS_LINUX */

struct appl_context;

class appl_clock_std;

//
//
//
class appl_clock_std : public appl_clock
{
    friend struct appl_object;
    public:

        static
        enum appl_status
            s_create(
                struct appl_object * const
                    p_context,
                class appl_clock * * const
                    r_clock);

    protected:

        appl_clock_std();

        virtual
        ~appl_clock_std();

    private:

        appl_clock_std(
            class appl_clock_std const & r);

        class appl_clock_std &
            operator =(
                class appl_clock_std const & r);

        static
        void
            s_new(
                void * const
                    p_placement);

        virtual
        enum appl_status
        v_read(
            unsigned long int const
                i_time_freq,
            unsigned long int * const
                p_time_count);

        virtual
        enum appl_status
        v_delay(
            unsigned long int const
                i_time_freq,
            unsigned long int const
                i_time_count);

}; // class appl_clock_std

/* end-of-file: appl_clock_std.h */
