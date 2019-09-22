/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_bytes_mem_h
{
    inc_appl_bytes_mem_h = 1
        /* Header file dependencies */
        + inc_appl_bytes_base_h
        + inc_appl_bytes_descriptor_h
        /* ... */
}; /* enum guard_appl_bytes_mem_h */

#include <appl_assert_cplusplus.h>

//
//
//
class appl_bytes_mem : public appl_bytes_base
{
    public:

        appl_bytes_mem(
            struct appl_context * const
                p_context);

        virtual
        ~appl_bytes_mem();

        enum appl_status
            f_init(
                struct appl_bytes_mem_descriptor const * const
                    p_descriptor);

        virtual
        appl_size_t
            v_cleanup(void);

    protected:

        struct appl_bytes_mem_descriptor
            m_descriptor;

        struct appl_buf
            m_iterator;

    private:

        appl_bytes_mem(
            class appl_bytes_mem const & r);

        class appl_bytes_mem &
            operator =(
                class appl_bytes_mem const & r);

        virtual
        enum appl_status
            v_consume(
                unsigned char * const
                    r_value);

        virtual
        enum appl_status
            v_produce(
                unsigned char const
                    i_value);

}; // class appl_bytes_mem

/* end-of-file: appl_bytes_mem.h */
