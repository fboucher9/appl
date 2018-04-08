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
#if ! defined INC_APPL_OBJECT_H
#error include appl_object.h before
#endif /* #if ! defined INC_APPL_OBJECT_H */

union appl_property_value;

struct appl_property_handle;

struct appl_property_node
{
    unsigned int
        i_id;

    enum appl_property_type
        e_type;

    union appl_property_value
        o_value;

}; /* struct appl_property_node */

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
        enum appl_status
            s_create(
                class appl_context * const
                    p_context,
                unsigned int const
                    i_id,
                class appl_property * * const
                    r_property);

        static
        class appl_property *
            convert_handle(
                struct appl_property_handle * const
                    p_property_handle);

        static
        class appl_property const *
            convert_const_handle(
                struct appl_property_handle const * const
                    p_property_handle);

        struct appl_property_handle *
            get_handle(void);

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

        unsigned int
            m_count;

        unsigned int
            ui_padding[3u];

        struct appl_property_node
            a_nodes[1u];

        appl_property(
            class appl_property const & r);

        class appl_property &
            operator =(
                class appl_property const & r);

        static
        void
            s_new(
                void * const
                    p_placement);

        virtual
        enum appl_status
            init(
                void const * const
                    p_descriptor);

        virtual
        enum appl_status
            cleanup(void);

}; // class appl_property

/* end-of-file: appl_property.h */
