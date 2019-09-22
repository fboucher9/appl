/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_bytes_h
{
    inc_appl_bytes_h = 1
        + inc_appl_object_h
}; /* enum guard_appl_bytes_h */

/* Assert compiler */
#include <appl_assert_cplusplus.h>

//
//
//
struct appl_bytes : public appl_object
{
    public:

        appl_bytes(
            struct appl_context * const
                p_context);

        virtual
        ~appl_bytes();

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

    protected:

    private:

        appl_bytes(
            struct appl_bytes const & r);

        struct appl_bytes &
            operator =(
                struct appl_bytes const & r);

}; // struct appl_bytes

/* end-of-file: appl_bytes.h */
