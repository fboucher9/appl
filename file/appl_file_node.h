/* See LICENSE for license details */

/*

Module: appl_file_node.h

Description:

    Interface of file object.

*/

/* Reverse include guard */
enum guard_appl_file_node_h
{
    inc_appl_file_node_h =
        /* Header file dependencies */
        inc_appl_object_h
};

/* Predefine */
struct appl_file;

//
//
//
struct appl_file : public appl_object
{
    public:

        appl_file(
            struct appl_context * const
                p_context);

        virtual
        ~appl_file();

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

    private:

        appl_file(
            struct appl_file const & r);

        struct appl_file &
            operator =(
                struct appl_file const & r);

}; // struct appl_file

/* end-of-file: appl_file_node.h */
