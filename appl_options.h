/* See LICENSE for license details */

/*

*/

#if defined(INC_APPL_OPTIONS_H)
#error include appl_options.h once
#endif /* #if defined(INC_APPL_OPTIONS_H) */

#define INC_APPL_OPTIONS_H

struct appl_options_descriptor;

#if !defined(__cplusplus)
#error use c++ compiler
#endif /* #if !defined(__cplusplus) */

class appl_options;

//
//
//
class appl_options : public appl_object
{
    public:

        virtual
        enum appl_status
            query(
                struct appl_options_descriptor * const
                    p_options_descriptor);

    protected:

        appl_options();

        virtual
        ~appl_options();

    private:

        appl_options(
            class appl_options const & r);

        class appl_options &
            operator =(
                class appl_options const & r);

}; // class appl_options

/* end-of-file: appl_options.h */
