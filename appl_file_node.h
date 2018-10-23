/* See LICENSE for license details */

/*

Module: appl_file_node.h

Description:

    Interface of file object.

*/

/* Reverse include guard */
#if defined INC_APPL_FILE_NODE_H
#error include appl_file_node.h once
#endif /* #if defined INC_APPL_FILE_NODE_H */

#define INC_APPL_FILE_NODE_H

struct appl_file;

/* Header file dependencies */
#if ! defined INC_APPL_OBJECT_H
#error include appl_object.h before
#endif /* #if ! defined INC_APPL_OBJECT_H */

//
//
//
struct appl_file : public appl_object
{
    public:

        virtual
        enum appl_status
            v_read(
                unsigned char * const
                    p_buf_min,
                unsigned char * const
                    p_buf_max,
                unsigned long int * const
                    r_count);

        virtual
        enum appl_status
            v_write(
                unsigned char const * const
                    p_buf_min,
                unsigned char const * const
                    p_buf_max,
                unsigned long int * const
                    r_count);

    protected:

        appl_file();

        virtual
        ~appl_file();

    private:

        appl_file(
            struct appl_file const & r);

        struct appl_file &
            operator =(
                struct appl_file const & r);

}; // struct appl_file

/* end-of-file: appl_file_node.h */
