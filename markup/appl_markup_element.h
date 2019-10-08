/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_markup_element_h
{
    inc_appl_markup_element_h = 1
        /* Header file dependencies */
        | inc_appl_types_h
        | inc_appl_buf_h
        /* ... */
}; /* enum guard_appl_markup_element_h */

/*

*/
enum appl_markup_element_type
{
    /* Element contains data payload */
    appl_markup_element_type_data = 1,

    /* Element marks beginning of a recursive object or array */
    appl_markup_element_type_begin = 2,

    /* Element marks end of a recursive object or array */
    appl_markup_element_type_end = 3

}; /* enum appl_markup_element_type */

/*

*/
struct appl_markup_element
{
    struct appl_buf
        o_data;

    /* -- */

    enum appl_markup_element_type
        e_type;

#define PADDING (APPL_SIZEOF_INT)
#include <misc/appl_padding.h>

}; /* struct appl_markup_element */

/* end-of-file: appl_markup_element.h */
