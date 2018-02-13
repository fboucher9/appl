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

class appl_context;

class appl_file_std_node;

//
//
//
class appl_file_std_node : public appl_file_node
{
    public:

        static
        enum appl_status
            create_instance(
                class appl_context * const
                    p_context,
                struct appl_file_descriptor const * const
                    p_file_descriptor,
                class appl_file_node * * const
                    r_file_node);

    protected:

        appl_file_std_node();

        virtual
        ~appl_file_std_node();

    private:

        int
            m_fd;

        unsigned int
            ui_padding[3u];

        bool
            m_close;

        unsigned char
            uc_padding[7u];

        appl_file_std_node(
            class appl_file_std_node const & r);

        class appl_file_std_node &
            operator =(
                class appl_file_std_node const & r);

        static
        void
            placement_new(
                void * const
                    p_placement);

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
            v_read(
                unsigned char * const
                    p_buf,
                unsigned long int const
                    i_buf_len,
                unsigned long int * const
                    r_actual_len);

        virtual
        enum appl_status
            v_write(
                unsigned char const * const
                    p_buf,
                unsigned long int const
                    i_buf_len,
                unsigned long int * const
                    r_actual_len);

}; // class appl_file_std_node

/* end-of-file: appl_file_std_node.h */
