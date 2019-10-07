/* See LICENSE for license details */

/*

*/

#define INC_APPL_CHUNK_STD_H

enum guard_appl_chunk_std_h
{
    inc_appl_chunk_std_h = 1
        + inc_appl_chunk_h
        + inc_appl_list_h
};

//
//  Class: appl_chunk_std
//
//  Description:
//      Standard implementation for appl_chunk interface.
//
class appl_chunk_std : public appl_chunk
{
    public:

        static
        enum appl_status
        s_create(
            struct appl_allocator * const
                p_allocator,
            struct appl_chunk * * const
                r_chunk);

        static
        enum appl_status
        s_destroy(
            struct appl_allocator * const
                p_allocator,
            struct appl_chunk * const
                p_chunk);

        appl_chunk_std(
            struct appl_context * const
                p_context);

        virtual
        ~appl_chunk_std();

        enum appl_status
            f_init(void);

        virtual
        appl_size_t
            v_cleanup(void);

    protected:

    private:

        // --

        struct appl_list
            o_nodes;

        // --

        unsigned long int
            i_total_len;

#define PADDING (APPL_SIZEOF_LONG)
#include <misc/appl_padding.h>

        // --

        appl_chunk_std(
            class appl_chunk_std const & r);

        class appl_chunk_std &
            operator =(
                class appl_chunk_std const & r);

        virtual
        enum appl_status
            v_write(
                unsigned char const * const
                    p_buf_min,
                unsigned char const * const
                    p_buf_max);

        virtual
        enum appl_status
            v_length(
                unsigned long int * const
                    r_length) const;

        virtual
        enum appl_status
            v_read(
                unsigned char * const
                    p_buf_min,
                unsigned char * const
                    p_buf_max) const;

        virtual
        enum appl_status
            v_reset(void);

        enum appl_status
        f_append_node(
            unsigned char const
                c_value);

        enum appl_status
        f_write_char(
            unsigned char const
                c_value);

        void
        f_free_node_list(void);

}; // class appl_chunk_std

/* end-of-file: appl_chunk_std.h */
