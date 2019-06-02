/* See LICENSE for license details */

/*

*/

/* Included. */
#define INC_APPL_MAIN_SERVICE_H

/* Reverse include guard */
enum guard_appl_main_service_h
{
    inc_appl_main_service_h =
        /* Header file dependencies */
        inc_appl_status_h
};

/* Predefine */
struct appl_context;

/* Predefine */
struct appl_options;

//
//
//
class appl_main_service
{
    public:

        static
        void
            s_init(
                struct appl_main_descriptor * const
                    p_main_descriptor);

        static
        void
            s_cleanup(
                struct appl_main_descriptor * const
                    p_main_descriptor);

        static
        void
            s_set_arg_vector(
                struct appl_main_descriptor * const
                    p_main_descriptor,
                char const * const * const
                    p_arg_vector_min,
                char const * const * const
                    p_arg_vector_max);

        static
        void
            s_set_callback(
                struct appl_main_descriptor * const
                    p_main_descriptor,
                appl_main_callback * const
                    p_main_callback);

        static
        int
        s_main(
            struct appl_main_descriptor const * const
                p_main_descriptor);

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
