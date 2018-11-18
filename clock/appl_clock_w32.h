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
    public:

        static
        enum appl_status
            s_create(
                struct appl_allocator * const
                    p_allocator,
                class appl_clock * * const
                    r_clock);

        appl_clock_w32();

        virtual
        ~appl_clock_w32();

        enum appl_status
            f_init(void);

    protected:

    private:

        appl_clock_w32(
            class appl_clock_w32 const & r);

        class appl_clock_w32 &
            operator =(
                class appl_clock_w32 const & r);

        virtual
        enum appl_status
            v_cleanup(void);

        virtual
        enum appl_status
            v_read(
                unsigned long int const
                    i_time_freq,
                appl_ull_t * const
                    p_time_count);

        virtual
        enum appl_status
            v_delay(
                unsigned long int const
                    i_time_freq,
                appl_ull_t const
                    i_time_count);

}; // class appl_clock_w32

/* end-of-file: appl_clock_w32.h */