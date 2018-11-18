/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_property_types_h
{
    inc_appl_property_types_h =
        1
};

/*

Enumeration: appl_property_type

Description:

*/
enum appl_property_type
{
    appl_property_type_default = 0,

    appl_property_type_ptr = 1,

    appl_property_type_ulong = 3,

    appl_property_type_long = 4

}; /* enum appl_property_type */

union appl_property_value;

/*

Structure: appl_property_value

Description:

*/
union appl_property_value
{
    void *
        p_value;

    void const *
        pc_value;

    unsigned long int
        u_value;

    signed long int
        i_value;

}; /* union appl_property_value */

/* end-of-file: appl_property_types.h */
