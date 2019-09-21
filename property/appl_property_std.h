/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_property_std_h
{
    inc_appl_property_std_h =
        /* Header file dependency */
        inc_appl_property_types_h
        + inc_appl_property_h
};

/*

*/
struct appl_property_std_descriptor
{
    unsigned int
        i_count;

}; /* struct appl_property_descriptor */

/* Assert compiler */
#include <appl_assert_cplusplus.h>

//
//
//
struct appl_property_std : public appl_property
{
    public:

        static
        enum appl_status
            s_create(
                struct appl_allocator * const
                    p_allocator,
                unsigned int const
                    i_count,
                struct appl_property * * const
                    r_property);

        static
        enum appl_status
            s_destroy(
                struct appl_allocator * const
                    p_allocator,
                struct appl_property * const
                    p_property);

        appl_property_std(
            struct appl_context * const
                p_context);

        virtual
        ~appl_property_std();

        enum appl_status
            f_init(
                struct appl_property_std_descriptor const * const
                    p_property_std_descriptor);

    protected:

        virtual
        appl_size_t
            v_cleanup(void);

    private:

        // --

        union appl_property_value *
            a_values;

        unsigned char *
            a_types;

        // --

        unsigned int
            m_count;

        bool
            b_values_allocated;

        bool
            b_types_allocated;

#define PADDING (APPL_SIZEOF_INT + 2)
#include <appl_padding.h>

        // --

        appl_property_std(
            struct appl_property_std const & r);

        struct appl_property_std &
            operator =(
                struct appl_property_std const & r);

        virtual
        enum appl_status
            v_set(
                unsigned int const
                    i_id,
                enum appl_property_type const
                    e_type,
                union appl_property_value const * const
                    p_property_value);

        virtual
        enum appl_status
            v_get(
                unsigned int const
                    i_id,
                enum appl_property_type const
                    e_type,
                union appl_property_value * const
                    p_property_value) const;

}; // struct appl_property_std

/* end-of-file: appl_property_std.h */
