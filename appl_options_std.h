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

class appl_string;

struct appl_options_std_descriptor
{
    char const * const *
        p_arg_min;

    char const * const *
        p_arg_max;

}; /* struct appl_options_std_descriptor */

//
//
//
class appl_options_std : public appl_options
{
    public:

        static
        enum appl_status
        s_create(
            class appl_context * const
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

        void *
            m_placement_buf;

        class appl_string * *
            m_buf_min;

        class appl_string * *
            m_buf_max;

        appl_options_std(
            class appl_options_std const & r);

        class appl_options_std &
            operator =(
                class appl_options_std const & r);

        static
        void
            placement_new(
                void * const
                    p_placement)
        {
            new (p_placement) class appl_options_std;
        }

        virtual
        enum appl_status
            init(
                void const * const
                    p_descriptor);

        virtual
        enum appl_status
            cleanup(void);

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
