/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_FILE_STD_NODE_H
#error include appl_file_std_node.h once
#endif /* #if defined INC_APPL_FILE_STD_NODE_H */

#define INC_APPL_FILE_STD_NODE_H

/* Header file dependency */
#if ! defined INC_APPL_FILE_NODE_H
#error include appl_file_node.h before
#endif /* #if ! defined INC_APPL_FILE_NODE_H */

struct appl_file_descriptor;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

struct appl_context;

class appl_file_std_node;

struct appl_file_std_node_descriptor;

//
//
//
class appl_file_std_node : public appl_file
{
    public:

        static
        enum appl_status
            s_create(
                struct appl_allocator * const
                    p_allocator,
                struct appl_file_descriptor const * const
                    p_file_descriptor,
                struct appl_file * * const
                    r_file_node);

        appl_file_std_node();

        virtual
        ~appl_file_std_node();

        enum appl_status
            f_init(
                struct appl_file_std_node_descriptor const * const
                    p_file_descriptor);

    protected:

    private:

        // --

        int
            m_fd;

        bool
            m_close;

#define PADDING (APPL_SIZEOF_INT + 1)
#include <appl_padding.h>

        // --

        appl_file_std_node(
            class appl_file_std_node const & r);

        class appl_file_std_node &
            operator =(
                class appl_file_std_node const & r);

        virtual
        enum appl_status
            v_cleanup(void);

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

}; // class appl_file_std_node

/* end-of-file: appl_file_std_node.h */
