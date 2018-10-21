/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_CLOCK_W32_H
#error include appl_clock_w32.h once
#endif /* #if defined INC_APPL_CLOCK_W32_H */

#define INC_APPL_CLOCK_W32_H

/* Header file dependency */
#if ! defined INC_APPL_CLOCK_H
#error include appl_clock.h before
#endif /* #if ! defined INC_APPL_CLOCK_H */

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

/* Assert OS */
#if ! defined APPL_OS_WINDOWS
#error must define APPL_OS_WINDOWS
#endif /* #if ! defined APPL_OS_WINDOWS */

struct appl_context;

class appl_clock_w32;

//
//
//
class appl_clock_w32 : public appl_clock
{
    friend struct appl_object;

    public:

        static
        enum appl_status
            s_create(
                struct appl_heap * const
                    p_heap,
                class appl_clock * * const
                    r_clock);

    protected:

        appl_clock_w32();

        virtual
        ~appl_clock_w32();

    private:

        appl_clock_w32(
            class appl_clock_w32 const & r);

        class appl_clock_w32 &
            operator =(
                class appl_clock_w32 const & r);

        static
        void
            s_new(
                void * const
                    p_placement);

        enum appl_status
            f_init(void);

        virtual
        enum appl_status
            v_cleanup(void);

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

}; // class appl_clock_w32

/* end-of-file: appl_clock_w32.h */
