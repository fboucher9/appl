/* See LICENSE for license details */

/*

*/

/* Included. */
#define INC_APPL_URL_TYPES_H

/*

Enumeration: appl_url_component_type

Description:
    Types of components that may be get and set with
    the appl_url interface.

*/
enum appl_url_component_type
{
    /* Leading component */
    appl_url_component_type_scheme = 1,

    /* Authority authentication information */
    appl_url_component_type_userinfo = 2,

    /* Authority host name or address */
    appl_url_component_type_host = 3,

    /* Authority port number */
    appl_url_component_type_port = 4,

    /* List of segments */
    appl_url_component_type_path = 5,

    /* Percent-encoded data after question mark */
    appl_url_component_type_quote = 6,

    /* Percent-encoded data after hash */
    appl_url_component_type_fragment = 7

}; /* enum appl_url_component_type */

/* Indicate presence of double-slash prefix */
#define APPL_URL_FLAG_AUTHORITY 1u

/* Indicate presence of leading slash for path */
#define APPL_URL_FLAG_ABSOLUTE 2u

/* Indicate presence of square brackets around host */
#define APPL_URL_FLAG_IPV6 4u

/* end-of-file: appl_url_types.h */
