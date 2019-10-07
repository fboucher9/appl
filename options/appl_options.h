/* See LICENSE for license details */

/*

*/

/* Included. */
#define INC_APPL_OPTIONS_H

/* Reverse include guard */
enum guard_appl_options_h
{
    inc_appl_options_h =
        /* Header file dependency */
        inc_appl_object_h
};

/* Assert compiler */
#include <misc/appl_assert_cplusplus.h>

//
//
//
struct appl_options : public appl_object
{
    public:

        appl_options(
            struct appl_context * const
                p_context);

        virtual
        ~appl_options();

        virtual
        enum appl_status
            v_count(
                unsigned long int * const
                    r_count) const;

        virtual
        enum appl_status
            v_get(
                unsigned long int const
                    i_index,
                unsigned char const * * const
                    r_buf_min,
                unsigned char const * * const
                    r_buf_max) const;

        virtual
        enum appl_status
            v_write(
                unsigned char const * const
                    p_buf_min,
                unsigned char const * const
                    p_buf_max,
                unsigned long int * const
                    p_count,
                char * const
                    p_ready);

        virtual
        enum appl_status
            v_append_argument(
                unsigned char const * const
                    p_buf_min,
                unsigned char const * const
                    p_buf_max);

        virtual
        enum appl_status
            v_reset(void);

    protected:

    private:

        appl_options(
            struct appl_options const & r);

        struct appl_options &
            operator =(
                struct appl_options const & r);

}; // struct appl_options

/* end-of-file: appl_options.h */
