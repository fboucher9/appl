/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_bytes_custom_h
{
    inc_appl_bytes_custom_h = 1
        /* Header file dependencies */
        + inc_appl_bytes_base_h
        + inc_appl_bytes_descriptor_h
        /* ... */
}; /* enum guard_appl_bytes_custom_h */

#include <misc/appl_assert_cplusplus.h>

//
//
//
class appl_bytes_custom : public appl_bytes_base
{
    public:

        appl_bytes_custom(
            struct appl_context * const
                p_context);

        virtual
        ~appl_bytes_custom();

        enum appl_status
            f_init(
                struct appl_bytes_custom_descriptor const * const
                    p_descriptor);

        virtual
        appl_size_t
            v_cleanup(void);

    protected:

    private:

        struct appl_bytes_custom_descriptor
            m_descriptor;

        appl_bytes_custom(
            class appl_bytes_custom const & r);

        class appl_bytes_custom &
            operator =(
                class appl_bytes_custom const & r);

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

}; // class appl_bytes_custom

/* end-of-file: appl_bytes_custom.h */
