/* See LICENSE for license details */

/*

*/

class appl_main_service
{
    public:

        static
        int
        s_main(
            int const
                i_arg_count,
            char * * const
                p_arg_vector,
            enum appl_status (*
                p_main_callback)(
                struct appl_context * const
                    p_context,
                struct appl_options const * const
                    p_options));

    protected:

    private:

        appl_main_service();

        ~appl_main_service();

        appl_main_service(
            class appl_main_service const & r);

        class appl_main_service &
            operator =(
                class appl_main_service const & r);

}; // class appl_main_service

/* end-of-file: appl_main_service.h */
