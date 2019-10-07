/* See LICENSE for license details */

/*

Insert padding into a structure.

Usage:

    #define PADDING (n)
    #include <misc/appl_padding.h>

*/

#if defined PADDING
#if ((PADDING) & 7u)
        unsigned char
            uc_padding[8u - ((PADDING) & 7u)];
#endif
#undef PADDING
#endif

/* end-of-file: appl_padding.h */
