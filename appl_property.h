/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_PROPERTY_H
#error include appl_property.h once
#endif /* #if defined INC_APPL_PROPERTY_H */

#define INC_APPL_PROPERTY_H

/* Header file dependency */
#if ! defined INC_APPL_PROPERTY_HANDLE_H
#error include appl_property_handle.h before
#endif /* #if ! defined INC_APPL_PROPERTY_HANDLE_H */

/* Header file dependency */
#if ! defined INC_APPL_OBJECT_H
#error include appl_object.h before
#endif /* #if ! defined INC_APPL_OBJECT_H */

union appl_property_value;

struct appl_property_handle;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

class appl_property;

//
//
//
class appl_property : public appl_object
{
    public:

        static
        class appl_property *
            convert_handle(
                struct appl_property_handle * const
                    p_property_handle);

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
                    p_property_value);

    protected:

        appl_property();

        virtual
        ~appl_property();

    private:

        appl_property(
            class appl_property const & r);

        class appl_property &
            operator =(
                class appl_property const & r);

}; // class appl_property

/* end-of-file: appl_property.h */
