/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_file_service_h
{
    inc_appl_file_service_h = 1
        /* Header file dependencies */
        + inc_appl_status_h
        + inc_appl_predefines_h
};

/* Assert compiler */
#include <misc/appl_assert_cplusplus.h>

//
//
//
class appl_file_service
{
    public:

        static
        enum appl_status
            s_get_stdin(
                struct appl_context * const
                    p_context,
                struct appl_file * * const
                    r_file);

        static
        enum appl_status
            s_get_stdout(
                struct appl_context * const
                    p_context,
                struct appl_file * * const
                    r_file);

        static
        enum appl_status
            s_get_stderr(
                struct appl_context * const
                    p_context,
                struct appl_file * * const
                    r_file);

        static
        enum appl_status
            s_create(
                struct appl_context * const
                    p_context,
                struct appl_file_descriptor const * const
                    p_file_descriptor,
                struct appl_file * * const
                    r_file);

        static
        enum appl_status
            s_destroy(
                struct appl_file * const
                    p_file);

        static
        struct appl_object *
        s_parent(
            struct appl_file * const
                p_file);

        static
        struct appl_object const *
        s_const_parent(
            struct appl_file const * const
                p_file);

        static
        enum appl_status
            s_read(
                struct appl_file * const
                    p_file,
                unsigned char * const
                    p_buf_cur,
                unsigned char * const
                    p_buf_max,
                unsigned long int * const
                    r_count);

        static
        enum appl_status
            s_write(
                struct appl_file * const
                    p_file,
                unsigned char const * const
                    p_buf_cur,
                unsigned char const * const
                    p_buf_max,
                unsigned long int * const
                    r_count);

}; // class appl_file_service

/* end-of-file: appl_file_service.h */
