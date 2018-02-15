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

struct appl_buf;

struct appl_file_handle;

/* Header file dependencies */
#if ! defined INC_APPL_OBJECT_H
#error include appl_object.h before
#endif /* #if ! defined INC_APPL_OBJECT_H */

class appl_file_node;

//
//
//
class appl_file_node : public appl_object
{
    public:

        virtual
        enum appl_status
            v_read(
                struct appl_buf * const
                    p_buf);

        virtual
        enum appl_status
            v_write(
                struct appl_buf * const
                    p_buf);

        static
        class appl_file_node *
            convert_handle(
                struct appl_file_handle * const
                    p_file_handle);

    protected:

        appl_file_node();

        virtual
        ~appl_file_node();

    private:

        appl_file_node(
            class appl_file_node const & r);

        class appl_file_node &
            operator =(
                class appl_file_node const & r);

}; // class appl_file_node

/* end-of-file: appl_file_node.h */
