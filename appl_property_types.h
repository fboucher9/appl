/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_PROPERTY_TYPES_H
#error include appl_property_types.h once
#endif /* #if defined INC_APPL_PROPERTY_TYPES_H */

#define INC_APPL_PROPERTY_TYPES_H

/* Header file dependency */
#if ! defined INC_APPL_BUF_H
#error include appl_buf.h before
#endif /* #if ! defined INC_APPL_BUF_H */

/*

Enumeration: appl_property_type

Description:

*/
enum appl_property_type
{
    appl_property_type_default = 0,

    appl_property_type_ptr = 1,

    appl_property_type_ulong = 3,

    appl_property_type_long = 4,

    appl_property_type_pfn = 5,

    appl_property_type_buf = 6

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

    unsigned long int
        u_value;

    signed long int
        i_value;

    void *
        (* p_func)(
            void * const
                p_args);

    struct appl_buf
        o_buf;

}; /* union appl_property_value */

/* end-of-file: appl_property_types.h */
