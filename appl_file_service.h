/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_FILE_SERVICE_H
#error include appl_file_service.h once
#endif /* #if defined INC_APPL_FILE_SERVICE_H */

#define INC_APPL_FILE_SERVICE_H

/* Header file dependency */
#if ! defined INC_APPL_STATUS_H
#error include appl_status.h before
#endif /* #if ! defined INC_APPL_STATUS_H */

struct appl_context_handle;

struct appl_file_handle;

struct appl_file_descriptor;

#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

class appl_file_service;

//
//
//
class appl_file_service
{
    public:

        static
        enum appl_status
            s_create(
                struct appl_context_handle * const
                    p_context_handle,
                struct appl_file_descriptor const * const
                    p_file_descriptor,
                struct appl_file_handle * * const
                    r_file_handle);

        static
        enum appl_status
            s_read(
                struct appl_file_handle * const
                    p_file_handle,
                unsigned char * const
                    p_buf_cur,
                unsigned char * const
                    p_buf_max,
                unsigned long int * const
                    r_count);

        static
        enum appl_status
            s_write(
                struct appl_file_handle * const
                    p_file_handle,
                unsigned char const * const
                    p_buf_cur,
                unsigned char const * const
                    p_buf_max,
                unsigned long int * const
                    r_count);

}; // class appl_file_service

/* end-of-file: appl_file_service.h */
