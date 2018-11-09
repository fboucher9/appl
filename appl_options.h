/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined(INC_APPL_OPTIONS_H)
#error include appl_options.h once
#endif /* #if defined(INC_APPL_OPTIONS_H) */

#define INC_APPL_OPTIONS_H

/* Header file dependency */
#if ! defined INC_APPL_OBJECT_H
#error include appl_object.h before
#endif /* #if ! defined INC_APPL_OBJECT_H */

/* Assert compiler */
#if !defined(__cplusplus)
#error use c++ compiler
#endif /* #if !defined(__cplusplus) */

struct appl_options;

//
//
//
struct appl_options : public appl_object
{
    public:

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
                    p_buf_max);

        virtual
        enum appl_status
            v_append_argument(
                unsigned char const * const
                    p_buf_min,
                unsigned char const * const
                    p_buf_max);

    protected:

        appl_options();

        virtual
        ~appl_options();

    private:

        appl_options(
            struct appl_options const & r);

        struct appl_options &
            operator =(
                struct appl_options const & r);

}; // struct appl_options

/* end-of-file: appl_options.h */
