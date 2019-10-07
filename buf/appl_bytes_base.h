/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_bytes_base_h
{
    inc_appl_bytes_base_h = 1
        /* Header file dependencies */
        + inc_appl_bytes_h
        /* ... */
}; /* enum guard_appl_bytes_base_h */

#include <misc/appl_assert_cplusplus.h>

//
//
//
class appl_bytes_base : public appl_bytes
{
    public:

        appl_bytes_base(
            struct appl_context * const
                p_context);

        virtual
        ~appl_bytes_base();

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

    protected:

        virtual
        enum appl_status
            v_write_raw(
                struct appl_buf const * const
                    p_buf);

        virtual
        enum appl_status
            v_write_int(
                unsigned char const
                    i_count,
                appl_ull_t const
                    i_value);

        virtual
        enum appl_status
            v_write_int8(
                unsigned char const
                    i_value);

        virtual
        enum appl_status
            v_write_int16(
                unsigned short int const
                    i_value);

        virtual
        enum appl_status
            v_write_int24(
                unsigned long int const
                    i_value);

        virtual
        enum appl_status
            v_write_int32(
                unsigned long int const
                    i_value);

        virtual
        enum appl_status
            v_write_int64(
                appl_ull_t const
                    i_value);

        virtual
        enum appl_status
            v_read_raw(
                struct appl_buf const * const
                    p_buf);

        virtual
        enum appl_status
            v_read_int(
                unsigned char const
                    i_count,
                appl_ull_t * const
                    r_value);

        virtual
        enum appl_status
            v_read_int8(
                unsigned char * const
                    r_value);

        virtual
        enum appl_status
            v_read_int16(
                unsigned short int * const
                    r_value);

        virtual
        enum appl_status
            v_read_int24(
                unsigned long int * const
                    r_value);

        virtual
        enum appl_status
            v_read_int32(
                unsigned long int * const
                    r_value);

        virtual
        enum appl_status
            v_read_int64(
                appl_ull_t * const
                    r_value);

    private:

        appl_bytes_base(
            class appl_bytes_base const & r);

        class appl_bytes_base &
            operator =(
                class appl_bytes_base const & r);

}; // class appl_bytes_base

/* end-of-file: appl_bytes_base.h */
