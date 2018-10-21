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

class appl_options;

class appl_options_std;

struct appl_options_std_descriptor
{
    unsigned char const * const *
        p_arg_min;

    unsigned char const * const *
        p_arg_max;

}; /* struct appl_options_std_descriptor */

//
//
//
class appl_options_std : public appl_options
{
    friend struct appl_object;
    public:

        static
        enum appl_status
        s_create(
            struct appl_object * const
                p_context,
            struct appl_options_std_descriptor const * const
                p_options_std_descriptor,
            class appl_options * * const
                r_options_std);

    protected:

        appl_options_std();

        virtual
        ~appl_options_std();

    private:

        struct appl_options_std_descriptor
            m_descriptor;

        appl_options_std(
            class appl_options_std const & r);

        class appl_options_std &
            operator =(
                class appl_options_std const & r);

        static
        void
            s_new(
                void * const
                    p_placement);

        enum appl_status
            f_init(
                struct appl_options_std_descriptor const * const
                    p_options_std_descriptor);

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

}; // class appl_options_std

/* end-of-file: appl_options_std.h */
