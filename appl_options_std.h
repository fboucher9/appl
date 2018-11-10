/* See LICENSE for license details */

/*

*/

#if defined(INC_APPL_OPTIONS_STD_H)
#error include appl_options_std.h once
#endif /* #if defined(INC_APPL_OPTIONS_STD_H) */

#define INC_APPL_OPTIONS_STD_H

#if !defined(__cplusplus)
#error use c++ compiler
#endif /* #if !defined(__cplusplus) */

struct appl_options;

class appl_options_std;

//
//
//
class appl_options_std : public appl_options
{
    public:

        static
        enum appl_status
        s_create(
            struct appl_allocator * const
                p_allocator,
            struct appl_options * * const
                r_options_std);

        appl_options_std();

        virtual
        ~appl_options_std();

        enum appl_status
            f_init(void);

    protected:

    private:

        // list of words
        struct appl_list
            m_list;

        // --

        unsigned long int
            m_count;

        unsigned long int
            ul_padding[1u];

        // --

        appl_options_std(
            class appl_options_std const & r);

        class appl_options_std &
            operator =(
                class appl_options_std const & r);

        virtual
        enum appl_status
            v_cleanup(void);

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

}; // class appl_options_std

/* end-of-file: appl_options_std.h */
