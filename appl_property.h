/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_PROPERTY_H
#error include appl_property.h once
#endif /* #if defined INC_APPL_PROPERTY_H */

#define INC_APPL_PROPERTY_H

/* Header file dependency */
#if ! defined INC_APPL_PROPERTY_TYPES_H
#error include appl_property_types.h before
#endif /* #if ! defined INC_APPL_PROPERTY_TYPES_H */

/* Header file dependency */
#if ! defined INC_APPL_HEAP_OBJECT_H
#error include appl_heap_object.h before
#endif /* #if ! defined INC_APPL_OBJECT_H */

union appl_property_value;

struct appl_property;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
struct appl_property : public appl_heap_object
{
    public:

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

        appl_property();

        virtual
        ~appl_property();

    private:

        appl_property(
            struct appl_property const & r);

        struct appl_property &
            operator =(
                struct appl_property const & r);

}; // struct appl_property

/* end-of-file: appl_property.h */
