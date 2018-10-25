/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_PROPERTY_STD_H
#error include appl_property_std.h once
#endif /* #if defined INC_APPL_PROPERTY_STD_H */

#define INC_APPL_PROPERTY_STD_H

/* Header file dependency */
#if ! defined INC_APPL_PROPERTY_TYPES_H
#error include appl_property_types.h before
#endif /* #if ! defined INC_APPL_PROPERTY_TYPES_H */

/* Header file dependency */
#if ! defined INC_APPL_PROPERTY_H
#error include appl_property.h before
#endif /* #if ! defined INC_APPL_PROPERTY_H */

struct appl_property_node;

/*

*/
struct appl_property_std_descriptor
{
    unsigned int
        i_count;

}; /* struct appl_property_descriptor */

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

struct appl_property_std;

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

        appl_property_std();

        virtual
        ~appl_property_std();

        enum appl_status
            f_init(
                struct appl_property_std_descriptor const * const
                    p_property_std_descriptor);

    protected:

        virtual
        enum appl_status
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

        unsigned int
            ui_padding[3u];

        // --

        bool
            b_values_allocated;

        bool
            b_types_allocated;

        bool
            ab_padding[6u];

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
