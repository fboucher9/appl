/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_property_h
{
    inc_appl_property_h =
        /* Header file dependency */
        inc_appl_property_types_h
        + inc_appl_object_h
};

union appl_property_value;

/* Assert compiler */
#include <misc/appl_assert_cplusplus.h>

//
//
//
struct appl_property : public appl_object
{
    public:

        appl_property(
            struct appl_context * const
                p_context);

        virtual
        ~appl_property();

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

        enum appl_status
            get_ptr(
                unsigned int const
                    i_id,
                void * * const
                    r_value) const;

        enum appl_status
            get_ulong(
                unsigned int const
                    i_id,
                unsigned long int * const
                    r_value) const;

        enum appl_status
            get_long(
                unsigned int const
                    i_id,
                signed long int * const
                    r_value) const;

    protected:

    private:

        appl_property(
            struct appl_property const & r);

        struct appl_property &
            operator =(
                struct appl_property const & r);

}; // struct appl_property

/* end-of-file: appl_property.h */
