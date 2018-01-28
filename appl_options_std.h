/* See LICENSE for license details */

/*

*/

#if defined(INC_APPL_OPTIONS_STD_H)
#error include appl_options_std.h once
#endif /* #if defined(INC_APPL_OPTIONS_STD_H) */

#define INC_APPL_OPTIONS_STD_H

struct appl_options_descriptor;

#if !defined(__cplusplus)
#error use c++ compiler
#endif /* #if !defined(__cplusplus) */

class appl_options_std;

//
//
//
class appl_options_std : public appl_options
{
    public:

        static
        enum appl_status
        create_instance(
            class appl_client * const
                p_client,
            struct appl_options_descriptor const * const
                p_options_descriptor,
            class appl_options_std * * const
                r_options_std);

    protected:

        appl_options_std();

        virtual
        ~appl_options_std();

    private:

        void *
            m_placement_ptr;

        struct appl_buf *
            m_buf_min;

        struct appl_buf *
            m_buf_max;

        appl_options_std(
            class appl_options_std const & r);

        class appl_options_std &
            operator =(
                class appl_options_std const & r);

        enum appl_status
            init(
                class appl_client * const
                    p_client,
                struct appl_options_descriptor const * const
                    p_options_descriptor);

        enum appl_status
            cleanup(void);

        virtual
        enum appl_status
            destroy(void);

}; // class appl_options_std

/* end-of-file: appl_options_std.h */
